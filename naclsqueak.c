/* @file naclsqueak.c -- The entry points of Squeak VM on Google Native Client.
 * 
 *   Copyright (C)  2011      by Yoshiki Ohshima, incorporating changes from Javier
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
#include <string.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>

#include "ppapi/c/pp_errors.h"
#include "ppapi/c/pp_module.h"
#include "ppapi/c/pp_var.h"
#include "ppapi/c/ppb.h"
#include "ppapi/c/ppb_instance.h"
#include "ppapi/c/ppb_messaging.h"
#include "ppapi/c/ppb_var.h"
#include "ppapi/c/ppp.h"
#include "ppapi/c/ppp_instance.h"
#include "ppapi/c/ppp_messaging.h"
#include "ppapi/c/ppp_input_event.h"
#include "sqNaClWindow.h"

struct MessageInfo {
  PP_Instance instance;
  struct PP_Var message;
};

static struct PPB_Messaging* ppb_messaging_interface = NULL;
static struct PPB_Var* ppb_var_interface = NULL;
static PP_Module module_id = 0;

static const char* const kPaintMethodId = "paint";
static const char* const kGetStatusMethodId = "getStatus";
static const char* const kLoadImageMethodId = "loadImage";
static const char* const kSetImageSizeMethodId = "setImageSize";
static const char kMessageArgumentSeparator = ':';
static const char kNullTerminator = '\0';

void* runInterpret(void *arg);

static int32_t
GetInteger(char *start)
{
  int32_t len = 0;
  char c = *start;
  while ('0' <= c && c <= '9') {
    len *= 10;
    len += (c - '0');
    c = *++start;
  }
  return len;
}

char*
CStrFromVar(struct PP_Var var)
{
  static char c_str[4096];
  uint32_t len = 0;
  if (ppb_var_interface != NULL) {
    const char* var_c_str = ppb_var_interface->VarToUtf8(var, &len);
    if (len >= 0 && len < sizeof(c_str)) {
      memcpy(c_str, var_c_str, len);
      c_str[len] = kNullTerminator;
      return c_str;
    }
  }
  return "";
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
 * Creates a new string PP_Var from C string. The resulting object will be a
 * refcounted string object. It will be AddRef()ed for the caller. When the
 * caller is done with it, it should be Release()d.
 * @param[in] str C string to be converted to PP_Var
 * @return PP_Var containing string.
 */
static struct PP_Var
AllocateVarFromCStr(const char* str)
{
  if (ppb_var_interface != NULL)
    return ppb_var_interface->VarFromUtf8(module_id, str, strlen(str));
  return PP_MakeUndefined();
}

extern unsigned char default_image_file_buffer[];
extern int32_t default_image_file_size;

unsigned char *image_file_buffer = NULL;
static int32_t image_file_index = 0;

int32_t image_file_size = 0;


struct PP_Var
SetImageSize(int32_t size)
{
  fprintf(stderr, "set size %d\n", (int)size);

  image_file_size = size;
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
LoadImage(char* buf)
#endif
{
#if EMBEDDED_IMAGE_FILE
  image_file_buffer = default_image_file_buffer;
  image_file_size = default_image_file_size;
  fprintf(stderr, "%x %d\n", (unsigned int)image_file_buffer, (int)image_file_size);
  pthread_create(&interpret_thread, NULL, runInterpret, NULL);
#else
  image_file_index = decode((char*)buf, strlen(buf), (char*)image_file_buffer, image_file_index);
  if ((image_file_index % 120000) == 0) {
    fprintf(stderr, "file index %d\n", (int)image_file_index);
  }
  if (image_file_index >= image_file_size) {
    pthread_create(&interpret_thread, NULL, runInterpret, NULL);
  }
#endif
  return PP_MakeInt32(image_file_index);
}


/**
 * Called when the NaCl module is instantiated on the web page. The identifier
 * of the new instance will be passed in as the first argument (this value is
 * generated by the browser and is an opaque handle).  This is called for each
 * instantiation of the NaCl module, which is each time the <embed> tag for
 * this module is encountered.
 *
 * If this function reports a failure (by returning @a PP_FALSE), the NaCl
 * module will be deleted and DidDestroy will be called.
 * @param[in] instance The identifier of the new instance representing this
 *     NaCl module.
 * @param[in] argc The number of arguments contained in @a argn and @a argv.
 * @param[in] argn An array of argument names.  These argument names are
 *     supplied in the <embed> tag, for example:
 *       <embed id="nacl_module" dimensions="2">
 *     will produce two arguments, one named "id" and one named "dimensions".
 * @param[in] argv An array of argument values.  These are the values of the
 *     arguments listed in the <embed> tag.  In the above example, there will
 *     be two elements in this array, "nacl_module" and "2".  The indices of
 *     these values match the indices of the corresponding names in @a argn.
 * @return @a PP_TRUE on success.
 */
static PP_Bool
Instance_DidCreate(PP_Instance instance,
		   uint32_t argc,
		   const char* argn[],
		   const char* argv[])
{
  return PP_TRUE;
}

/**
 * Called when the NaCl module is destroyed. This will always be called,
 * even if DidCreate returned failure. This routine should deallocate any data
 * associated with the instance.
 * @param[in] instance The identifier of the instance representing this NaCl
 *     module.
 */
static void
Instance_DidDestroy(PP_Instance instance)
{
}

/**
 * Called when the position, the size, or the clip rect of the element in the
 * browser that corresponds to this NaCl module has changed.
 * @param[in] instance The identifier of the instance representing this NaCl
 *     module.
 * @param[in] position The location on the page of this NaCl module. This is
 *     relative to the top left corner of the viewport, which changes as the
 *     page is scrolled.
 * @param[in] clip The visible region of the NaCl module. This is relative to
 *     the top left of the plugin's coordinate system (not the page).  If the
 *     plugin is invisible, @a clip will be (0, 0, 0, 0).
 */
static void
Instance_DidChangeView(PP_Instance instance,
		       const struct PP_Rect* position,
		       const struct PP_Rect* clip)
{
  NaCl_DidChangeView(instance, position, clip);
}

/**
 * Notification that the given NaCl module has gained or lost focus.
 * Having focus means that keyboard events will be sent to the NaCl module
 * represented by @a instance. A NaCl module's default condition is that it
 * will not have focus.
 *
 * Note: clicks on NaCl modules will give focus only if you handle the
 * click event. You signal if you handled it by returning @a true from
 * HandleInputEvent. Otherwise the browser will bubble the event and give
 * focus to the element on the page that actually did end up consuming it.
 * If you're not getting focus, check to make sure you're returning true from
 * the mouse click in HandleInputEvent.
 * @param[in] instance The identifier of the instance representing this NaCl
 *     module.
 * @param[in] has_focus Indicates whether this NaCl module gained or lost
 *     event focus.
 */
static void
Instance_DidChangeFocus(PP_Instance instance,
			PP_Bool has_focus)
{
}

static PP_Bool
InputEvent_HandleInputEvent(PP_Instance instance,
			    const PP_Resource evt)
{
  return NaCl_HandleInputEvent(instance, evt);
}

/**
 * Handler that gets called after a full-frame module is instantiated based on
 * registered MIME types.  This function is not called on NaCl modules.  This
 * function is essentially a place-holder for the required function pointer in
 * the PPP_Instance structure.
 * @param[in] instance The identifier of the instance representing this NaCl
 *     module.
 * @param[in] url_loader A PP_Resource an open PPB_URLLoader instance.
 * @return PP_FALSE.
 */
static PP_Bool
Instance_HandleDocumentLoad(PP_Instance instance,
			    PP_Resource url_loader)
{
  /* NaCl modules do not need to handle the document load function. */
  return PP_FALSE;
}


/**
 * Handler for messages coming in from the browser via postMessage.  The
 * @a var_message can contain anything: a JSON string; a string that encodes
 * method names and arguments; etc.  For example, you could use JSON.stringify
 * in the browser to create a message that contains a method name and some
 * parameters, something like this:
 *   var json_message = JSON.stringify({ "myMethod" : "3.14159" });
 *   nacl_module.postMessage(json_message);
 * On receipt of this message in @a var_message, you could parse the JSON to
 * retrieve the method name, match it to a function call, and then call it with
 * the parameter.
 * @param[in] instance The instance ID.
 * @param[in] message The contents, copied by value, of the message sent from
 *     browser via postMessage.
 */
void
Messaging_HandleMessage(PP_Instance instance, struct PP_Var var_message)
{
  if (var_message.type != PP_VARTYPE_STRING) {
    /* Only handle string messages */
    return;
  }
  char* message = CStrFromVar(var_message);
  struct PP_Var var_result = PP_MakeUndefined();
  if (message == NULL)
    return;
  if (strncmp(message, kPaintMethodId, strlen(kPaintMethodId)) == 0) {
    Paint();
  } else if (strncmp(message, kGetStatusMethodId, strlen(kGetStatusMethodId)) == 0) {
    ppb_messaging_interface->PostMessage(instance, AllocateVarFromCStr(NaClStatus()));
  } else if (strncmp(message, kSetImageSizeMethodId, strlen(kSetImageSizeMethodId)) == 0) {
    SetImageSize(GetInteger(message + strlen(kSetImageSizeMethodId) + 1));
  }

  if (strncmp(message, kLoadImageMethodId, strlen(kLoadImageMethodId)) == 0) {
#ifdef EMBEDDED_IMAGE_FILE
    LoadImage();
#else
    LoadImage(message + strlen(kLoadImageMethodId) + 1);
#endif
  }

  if (var_result.type == PP_VARTYPE_STRING) {
    ppb_var_interface->Release(var_result);
  }
}

/**
 * Entry points for the module.
 * Initialize instance interface and scriptable object class.
 * @param[in] a_module_id Module ID
 * @param[in] get_browser_interface Pointer to PPB_GetInterface
 * @return PP_OK on success, any other value on failure.
 */
PP_EXPORT int32_t
PPP_InitializeModule(PP_Module a_module_id,
		     PPB_GetInterface get_browser)
{
  module_id = a_module_id;
  ppb_var_interface = (struct PPB_Var*)(get_browser(PPB_VAR_INTERFACE));
  NaCl_InitializeModule(get_browser);
  ppb_messaging_interface = (struct PPB_Messaging*)(get_browser(PPB_MESSAGING_INTERFACE));
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
  if (strcmp(interface_name, PPP_INSTANCE_INTERFACE) == 0) {
    static struct PPP_Instance instance_interface = {
      &Instance_DidCreate,
      &Instance_DidDestroy,
      &Instance_DidChangeView,
      &Instance_DidChangeFocus,
      &Instance_HandleDocumentLoad
    };
    return &instance_interface;
  } else if (strcmp(interface_name, PPP_MESSAGING_INTERFACE) == 0) {
    static struct PPP_Messaging messaging_interface = {
      &Messaging_HandleMessage
    };
    return &messaging_interface;
  } else if (strcmp(interface_name, PPP_INPUT_EVENT_INTERFACE) == 0) {
    static struct PPP_InputEvent input_event_interface = {
      &InputEvent_HandleInputEvent
    };
    return &input_event_interface;
  }
  return NULL;
}

/**
 * Called before the plugin module is unloaded.
 */
PP_EXPORT void
PPP_ShutdownModule()
{
  toQuit = 1;
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
