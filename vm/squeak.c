/* squeak.c -- The entry points of Squeak VM on Google Native Client.
 * 
 *   Copyright (C)  2011      by Yoshiki Ohshima
 *
 *   All rights reserved.
 *   
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 * 
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * 
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include <ppapi/c/dev/ppb_var_deprecated.h>
#include <ppapi/c/dev/ppp_class_deprecated.h>
#include <ppapi/c/pp_errors.h>
#include <ppapi/c/pp_var.h>
#include <ppapi/c/ppb_var.h>
#include "sqNaClWindow.h"

static PP_Bool Instance_DidCreate(PP_Instance instance,
                                  uint32_t argc,
                                  const char* argn[],
                                  const char* argv[]);
static void Instance_DidDestroy(PP_Instance instance);
static void Instance_DidChangeView(PP_Instance instance,
                                   const struct PP_Rect* position,
                                   const struct PP_Rect* clip);
static void Instance_DidChangeFocus(PP_Instance instance,
                                    PP_Bool has_focus);
static PP_Bool Instance_HandleInputEvent(PP_Instance instance,
                                         const struct PP_InputEvent* event);
static struct PP_Var Instance_GetInstanceObject(PP_Instance instance);

void* runInterpret(void *arg);

static struct PPB_Var_Deprecated* var_interface = NULL;
static struct PPP_Class_Deprecated ppp_class;
static PP_Module module_id = 0;
const struct PPB_Instance* instance_;

static const char* const kPaintMethodId = "paint";
static const char* const kGetStatusMethodId = "getStatus";
static const char* const kLoadImageMethodId = "loadImage";
static const char* const kSetImageSizeMethodId = "setImageSize";

static struct PPP_Instance instance_interface = {
  &Instance_DidCreate,
  &Instance_DidDestroy,
  &Instance_DidChangeView,
  &Instance_DidChangeFocus,
  &Instance_HandleInputEvent,
  NULL,  /* HandleDocumentLoad is not supported by NaCl modules. */
  &Instance_GetInstanceObject,
};

static int32_t
GetInteger(struct PP_Var var)
{
  uint32_t headerLen;
  int32_t len;
  char c;
  const char *cStr = var_interface->VarToUtf8(var, &headerLen);
  len = 0;
  c = *cStr++;
  while ('0' <= c && c <= '9') {
    len *= 10;
    len += (c - '0');
    c = *cStr++;
  }
  return len;
}

static const char cd64[]="|$$$}rstuvwxyz{$$$$$$$>?@ABCDEFGHIJKLMNOPQRSTUVW$$$$$$XYZ[\\]^_`abcdefghijklmnopq";

void
decodeblock(unsigned char in[4], unsigned char out[3])
{   
  out[ 0 ] = (unsigned char) (in[0] << 2 | in[1] >> 4);
  out[ 1 ] = (unsigned char) (in[1] << 4 | in[2] >> 2);
  out[ 2 ] = (unsigned char) (((in[2] << 6) & 0xc0) | in[3]);
}

int
decode(char *input, int input_size, char *output, int output_index)
{
  unsigned char in[4], out[3], v;
  int i, len;
  int s = 0;

  while (s < input_size) {
    for (len = 0, i = 0; i < 4 && s < input_size; i++) {
      v = 0;
      while (v == 0) {
	v = (unsigned char)input[s++];
	v = (unsigned char)((v < 43 || v > 122) ? 0 : cd64[v - 43]);
	if(v) {
	  v = (unsigned char)((v == '$') ? 0 : v - 61);
	}
      }
      if (s <= input_size) {
	len++;
	if (v) {
	  in[i] = (unsigned char)(v - 1);
	}
      } else {
	in[i] = 0;
      }
    }
    if (len) {
      decodeblock(in, out);
      for (i = 0; i < len - 1; i++) {
	output[output_index++] = out[i];
      }
    }
  }
  return output_index;
}

/**
 * Returns C string contained in the @a var or NULL if @a var is not string.
 * @param[in] var PP_Var containing string.
 * @return a C string representation of @a var.
 * @note Returned pointer will be invalid after destruction of @a var.
 */
static const char*
VarToCStr(struct PP_Var var)
{
  uint32_t len = 0;
  if (NULL != var_interface)
    return var_interface->VarToUtf8(var, &len);
  return NULL;
}

/**
 * Creates new string PP_Var from C string. The resulting object will be a
 * refcounted string object. It will be AddRef()ed for the caller. When the
 * caller is done with it, it should be Release()d.
 * @param[in] str C string to be converted to PP_Var
 * @return PP_Var containing string.
 */
static struct
PP_Var StrToVar(const char* str)
{
  if (NULL != var_interface)
    return var_interface->VarFromUtf8(module_id, str, strlen(str));
  return PP_MakeUndefined();
}

extern unsigned char default_image_file_buffer[];
extern int32_t default_image_file_size;

unsigned char *image_file_buffer = NULL;
int32_t image_file_size;
static int32_t image_file_index = 0;

struct PP_Var
SetImageSize(struct PP_Var data)
{
  image_file_size = GetInteger(data);
  fprintf(stderr, "set size %d\n", (int)image_file_size);

  if ((image_file_buffer = malloc(image_file_size)) == NULL) {
    fprintf(stderr, "malloc failed\n");
  }
  image_file_index = 0;
  return PP_MakeInt32(image_file_size);
}

struct PP_Var
#ifdef EMBEDDED_IMAGE_FILE
LoadImage()
#else
LoadImage(struct PP_Var data)
#endif
{
  Log("load image\n");
#if EMBEDDED_IMAGE_FILE
  image_file_buffer = default_image_file_buffer;
  image_file_size = default_image_file_size;
  sprintf(LogBuffer, "%x %d\n", (unsigned int)image_file_buffer, (int)image_file_size);
  Log(LogBuffer);
  pthread_create(&interpret_thread, NULL, runInterpret, NULL);
#else
  const char *buf = VarToCStr(data);
  //  fprintf(stderr, "buf size %d\n", (int)strlen(buf));
  image_file_index = decode((char*)buf, strlen(buf), (char*)image_file_buffer, image_file_index);
  //  fprintf(stderr, "file index %d\n", (int)image_file_index);
  if (image_file_index == image_file_size) {
    pthread_create(&interpret_thread, NULL, runInterpret, NULL);
  }
#endif
  return PP_MakeInt32(image_file_index);
}

static PP_Bool
Instance_DidCreate(PP_Instance instance,
                                  uint32_t argc,
                                  const char* argn[],
                                  const char* argv[])
{
  return PP_TRUE;
}

static void Instance_DidDestroy(PP_Instance instance) {
}

static void
Instance_DidChangeView(PP_Instance instance,
		       const struct PP_Rect* position,
		       const struct PP_Rect* clip)
{
  NaCl_DidChangeView(instance, position, clip);
}

static void
Instance_DidChangeFocus(PP_Instance instance,
                                    PP_Bool has_focus)
{
}

static PP_Bool
Instance_HandleInputEvent(PP_Instance instance,
                                         const struct PP_InputEvent* event)
{
  return NaCl_HandleInputEvent(instance, event);
}

/**
 * Create scriptable object for the given instance.
 * @param[in] instance The instance ID.
 * @return A scriptable object.
 */
static struct
PP_Var Instance_GetInstanceObject(PP_Instance instance)
{
  if (var_interface)
    return var_interface->CreateObject(instance, &ppp_class, NULL);
  return PP_MakeUndefined();
}

/**
 * Check existence of the function associated with @a name.
 * @param[in] object unused
 * @param[in] name method name
 * @param[out] exception pointer to the exception object, unused
 * @return If the method does exist, return true.
 * If the method does not exist, return false and don't set the exception.
 */
static bool
Squeak_HasMethod(void* object,
		 struct PP_Var name,
		 struct PP_Var* exception)
{
  const char* method_name = VarToCStr(name);
  if (NULL != method_name) {
    if (strcmp(method_name, kPaintMethodId) == 0)
      return true;
    if (strcmp(method_name, kGetStatusMethodId) == 0)
      return true;
    /*    if (strcmp(method_name, kGetLoaderStatusMethodId) == 0)
	  return true; */
    if (strcmp(method_name, kLoadImageMethodId) == 0)
      return true;
    if (strcmp(method_name, kSetImageSizeMethodId) == 0)
      return true;
  }
  return false;
}


/**
 * Invoke the function associated with @a name.
 * @param[in] object unused
 * @param[in] name method name
 * @param[in] argc number of arguments
 * @param[in] argv array of arguments
 * @param[out] exception pointer to the exception object, unused
 * @return If the method does exist, return true.
 */
static struct PP_Var
Squeak_Call(void* object,
	    struct PP_Var name,
	    uint32_t argc,
	    struct PP_Var* argv,
	    struct PP_Var* exception)
{
  struct PP_Var v = PP_MakeInt32(0);
  const char* method_name = VarToCStr(name);
  if (NULL != method_name) {
    if (strcmp(method_name, kPaintMethodId) == 0) {
      Paint();
      return v;
    }
    if (strcmp(method_name, kGetStatusMethodId) == 0)
      return StrToVar(NaClStatus());
    /*if (strcmp(method_name, kGetLoaderStatusMethodId) == 0)
      return loader_status; */
    if (strcmp(method_name, kLoadImageMethodId) == 0) {
#ifdef EMBEDDED_IMAGE_FILE
      return LoadImage();
#else
      return LoadImage(argv[0]);
#endif
    }
    if (strcmp(method_name, kSetImageSizeMethodId) == 0) {
      return SetImageSize(argv[0]);
    }
  }
  return v;
}

/**
 * Entrypoints for the module.
 * Initialize instance interface and scriptable object class.
 * @param[in] a_module_id module ID
 * @param[in] get_browser pointer to PPB_GetInterface
 * @return PP_OK on success, any other value on failure.
 */

PP_EXPORT int32_t
PPP_InitializeModule(PP_Module a_module_id, PPB_GetInterface get_browser_interface)
{
  module_id = a_module_id;
  var_interface = 
      (struct PPB_Var_Deprecated*)(get_browser_interface(PPB_VAR_DEPRECATED_INTERFACE));
  NaCl_InitializeModule(get_browser_interface);
  memset(&ppp_class, 0, sizeof(ppp_class));
  ppp_class.Call = Squeak_Call;
  ppp_class.HasMethod = Squeak_HasMethod;
  return PP_OK;
}

/**
 * Returns an interface pointer for the interface of the given name, or NULL
 * if the interface is not supported.
 * @param[in] interface_name name of the interface
 * @return pointer to the interface
 */
PP_EXPORT const void*
PPP_GetInterface(const char* interface_name)
{
  if (strcmp(interface_name, PPP_INSTANCE_INTERFACE) == 0)
    return &instance_interface;
  return NULL;
}

/**
 * Called before the plugin module is unloaded.
 */
PP_EXPORT void
PPP_ShutdownModule()
{
  toQuit = true;
  void *null;
  pthread_join(interpret_thread, &null);
  pthread_mutex_destroy(&image_mutex);
}

void*
runInterpret(void *arg)
{
  char *argv[] = {"squeak", NULL};
    sqMain(1, argv, NULL);
  return NULL;
}
