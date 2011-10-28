#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include "ppapi/c/pp_var.h"
#include "ringBufferMessaging.h"

static int32_t *s2b = NULL;
static int32_t *b2s = NULL;

static char *tmp_buffer = NULL;

static int32_t s2b_free_start = 0;
static int32_t s2b_free_end = 0;
static int32_t s2b_capacity = 0;
static int32_t s2b_is_full = 0;

static int32_t b2s_free_start = 0;
static int32_t b2s_free_end = 0;
static int32_t b2s_capacity = 0;
static int32_t b2s_is_full = 0;

static pthread_mutex_t s2b_mutex;
static pthread_mutex_t b2s_mutex;

void
ring_buffer_initialize()
{
  s2b_capacity = 4*sizeof(int32_t);
  s2b = malloc(s2b_capacity);
  tmp_buffer = malloc(s2b_capacity);
  s2b_free_start = 0;
  s2b_free_end = 0;
  s2b_is_full = 0;

  pthread_mutex_init(&s2b_mutex, NULL);
}

#define CEIL4(x) ((x)%4==0 ? x : ((x) + 4) & ~3)

int
send_from_sq_to_browser(char *aString, int32_t size)
{
  int free;
  int err = 0;
  pthread_mutex_lock(&s2b_mutex);

  if ((CEIL4(size) + 4) > s2b_capacity) {
    printf("just too big\n");
    err = 1;
  }
  
  free = s2b_is_full
    ? 0 : (s2b_free_end - s2b_free_start + (s2b_free_start >= s2b_free_end ? s2b_capacity : 0));
  if ((CEIL4(size) + 4) > free) {
    printf("overflow\n");
    err = 2;
  }

  if (!err) {
    int first_part_size, second_part_size;
    s2b[s2b_free_start/4] = size;

    s2b_free_start += 4;
    if (s2b_free_start == s2b_capacity) {
      s2b_free_start = 0;
    }
    
    first_part_size = (size < s2b_capacity - s2b_free_start)
      ? size : s2b_capacity - s2b_free_start;
    second_part_size = size - first_part_size > 0 ? size - first_part_size : 0;
    memcpy(&s2b[s2b_free_start/4], aString, first_part_size);
    s2b_free_start += CEIL4(first_part_size);
    if (second_part_size > 0) {
      //assert(s2b_free_start == s2b_capacity);
      s2b_free_start = 0;
      memcpy(&s2b[s2b_free_start/4], aString + first_part_size, second_part_size);
      s2b_free_start += CEIL4(second_part_size);
    }
    if (s2b_free_start == s2b_capacity) {
      s2b_free_start = 0;
    }
    if (s2b_free_start == s2b_free_end) {
      s2b_is_full = 1;
    }
  }
  pthread_mutex_unlock(&s2b_mutex);
  return err;
}

struct PP_Var
read_from_sq_to_browser(struct PP_Var (*func)(const char* str, int32_t size))
{
  int err = 0;
  int32_t size;

  pthread_mutex_lock(&s2b_mutex);
  if (!s2b_is_full && s2b_free_end == s2b_free_start) {
    err = 1;
  }

  if (!err) {
    int first_part_size, second_part_size;
    size = s2b[s2b_free_end/4];

    s2b_free_end += 4;
    if (s2b_free_end == s2b_capacity) {
      s2b_free_end = 0;
    }
    
    first_part_size = (size < s2b_capacity - s2b_free_end)
      ? size : s2b_capacity - s2b_free_end;
    second_part_size = size - first_part_size > 0 ? size - first_part_size : 0;
    
    memcpy(tmp_buffer, &s2b[s2b_free_end/4], size);
    s2b_free_end += CEIL4(first_part_size);
    if (second_part_size > 0) {
      s2b_free_end = 0;
      memcpy(tmp_buffer + first_part_size, &s2b[s2b_free_end/4], second_part_size);
      s2b_free_end += CEIL4(second_part_size);
    }
    
    s2b_is_full = 0;
    if (s2b_free_end == s2b_capacity) {
      s2b_free_end = 0;
    }
  }
  pthread_mutex_unlock(&s2b_mutex);
  if (!err)
    return func(tmp_buffer, size);

  return PP_MakeNull();
}
