#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include "ppapi/c/pp_var.h"
#include "ringBufferMessaging.h"
#include "sq.h"

struct messaging {
  int32_t capacity;
  int32_t *buffer;
  int32_t free_start;
  int32_t free_end;
  int32_t is_full;
  pthread_mutex_t mutex;
};

extern struct VirtualMachine *interpreterProxy;
static struct messaging s2b, b2s;

static char *tmp_buffer = NULL;

#define CEIL4(x) ((x)%4==0 ? x : ((x) + 4) & ~3)

static sqInt (*signaler)() = NULL;

void
ring_buffer_initialize()
{
  s2b.capacity = 1024*sizeof(int32_t);
  s2b.buffer = malloc(s2b.capacity);
  s2b.free_start = 0;
  s2b.free_end = 0;
  s2b.is_full = 0;
  pthread_mutex_init(&s2b.mutex, NULL);

  tmp_buffer = malloc(s2b.capacity);

  b2s.capacity = 1024*sizeof(int32_t);
  b2s.buffer = malloc(b2s.capacity);
  b2s.free_start = 0;
  b2s.free_end = 0;
  b2s.is_full = 0;
  pthread_mutex_init(&b2s.mutex, NULL);
}

struct PP_Var
read_from_sq_to_browser(struct PP_Var (*func)(const char* str, int32_t size))
{
  int err = 0;
  int32_t size;

  pthread_mutex_lock(&s2b.mutex);
  if (!s2b.is_full && s2b.free_end == s2b.free_start) {
    err = 1;
  }

  if (!err) {
    int first_part_size, second_part_size;
    size = s2b.buffer[s2b.free_end/4];

    s2b.free_end += 4;
    if (s2b.free_end == s2b.capacity) {
      s2b.free_end = 0;
    }
    
    first_part_size = (size < s2b.capacity - s2b.free_end)
      ? size : s2b.capacity - s2b.free_end;
    second_part_size = size - first_part_size > 0 ? size - first_part_size : 0;
    
    memcpy(tmp_buffer, &s2b.buffer[s2b.free_end/4], size);
    s2b.free_end += CEIL4(first_part_size);
    if (second_part_size > 0) {
      s2b.free_end = 0;
      memcpy(tmp_buffer + first_part_size, &s2b.buffer[s2b.free_end/4], second_part_size);
      s2b.free_end += CEIL4(second_part_size);
    }
    
    s2b.is_full = 0;
    if (s2b.free_end == s2b.capacity) {
      s2b.free_end = 0;
    }
  }
  pthread_mutex_unlock(&s2b.mutex);
  if (!err)
    return func(tmp_buffer, size);

  return PP_MakeNull();
}

sqInt
read_from_browser_to_sq(sqInt (*newString)(sqInt))
{
  int err = 0;
  int32_t size;

  sqInt sqString = 0;

  pthread_mutex_lock(&b2s.mutex);
  if (!b2s.is_full && b2s.free_end == b2s.free_start) {
    err = 1;
  }

  if (!err) {
    int first_part_size, second_part_size;
    char *buffer;
    size = b2s.buffer[b2s.free_end/4];

    b2s.free_end += 4;
    if (b2s.free_end == b2s.capacity) {
      b2s.free_end = 0;
    }

    sqString = (*newString)(size);
    buffer = (char*)interpreterProxy->firstIndexableField(sqString);

    first_part_size = (size < b2s.capacity - b2s.free_end)
      ? size : b2s.capacity - b2s.free_end;
    second_part_size = size - first_part_size > 0 ? size - first_part_size : 0;
    
    memcpy(buffer, &b2s.buffer[b2s.free_end/4], size);
    b2s.free_end += CEIL4(first_part_size);
    if (second_part_size > 0) {
      b2s.free_end = 0;
      memcpy(buffer + first_part_size, &b2s.buffer[b2s.free_end/4], second_part_size);
      b2s.free_end += CEIL4(second_part_size);
    }
    
    b2s.is_full = 0;
    if (b2s.free_end == b2s.capacity) {
      b2s.free_end = 0;
    }
  }
  pthread_mutex_unlock(&b2s.mutex);
  if (!err)
    return sqString;

  return interpreterProxy->nilObject;
}

static int
send_buffer(char *aString, int32_t size, struct messaging *m)
{
  int free;
  int err = 0;
  pthread_mutex_lock(&m->mutex);

  if ((CEIL4(size) + 4) > m->capacity) {
    printf("just too big\n");
    err = 1;
  }
  
  free = m->is_full
    ? 0 : (m->free_end - m->free_start + (m->free_start >= m->free_end ? m->capacity : 0));
  if ((CEIL4(size) + 4) > free) {
    printf("overflow\n");
    err = 2;
  }

  if (!err) {
    int first_part_size, second_part_size;
    m->buffer[m->free_start/4] = size;

    m->free_start += 4;
    if (m->free_start == m->capacity) {
      m->free_start = 0;
    }
    
    first_part_size = (size < m->capacity - m->free_start)
      ? size : m->capacity - m->free_start;
    second_part_size = size - first_part_size > 0 ? size - first_part_size : 0;
    memcpy(&m->buffer[m->free_start/4], aString, first_part_size);
    m->free_start += CEIL4(first_part_size);
    if (second_part_size > 0) {
      //assert(b2s_free_start == b2s_capacity);
      m->free_start = 0;
      memcpy(&m->buffer[m->free_start/4], aString + first_part_size, second_part_size);
      m->free_start += CEIL4(second_part_size);
    }
    if (m->free_start == m->capacity) {
      m->free_start = 0;
    }
    if (m->free_start == m->free_end) {
      m->is_full = 1;
    }
  }
  pthread_mutex_unlock(&m->mutex);
  return err;
}

int
send_from_sq_to_browser(char *aString, int32_t size)
{
  return send_buffer(aString, size, &s2b);
}

int
send_from_browser_to_sq(char *aString, int32_t size)
{
  return send_buffer(aString, size, &b2s);
}

void
set_signaler(sqInt (*func)())
{
  signaler = func;
}

void
signalMessagingSemaphore()
{
  if (signaler != NULL) {
    (*signaler)();
  }
}


