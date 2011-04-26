/** @file squeak.c
 * This example demonstrates loading, running and scripting a very simple
 * NaCl module.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

#include <ppapi/c/dev/ppb_var_deprecated.h>
#include <ppapi/c/dev/ppp_class_deprecated.h>
#include <ppapi/c/pp_errors.h>
#include <ppapi/c/pp_var.h>
#include <ppapi/c/pp_module.h>
#include <ppapi/c/ppb.h>
#include <ppapi/c/ppb_instance.h>
#include <ppapi/c/ppp.h>
#include <ppapi/c/ppp_instance.h>
#include <ppapi/c/pp_size.h>
#include <ppapi/c/pp_rect.h>
#include <ppapi/c/pp_point.h>
#include <ppapi/c/ppb_image_data.h>
#include <ppapi/c/ppb_graphics_2d.h>
#include <ppapi/c/ppb_core.h>

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

static const char* const kPaintMethodId = "paint";
static const char* const kGetStatusMethodId = "getStatus";

static struct PPP_Instance instance_interface = {
  &Instance_DidCreate,
  &Instance_DidDestroy,
  &Instance_DidChangeView,
  &Instance_DidChangeFocus,
  &Instance_HandleInputEvent,
  NULL,  /* HandleDocumentLoad is not supported by NaCl modules. */
  &Instance_GetInstanceObject,
};

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

static PP_Bool
Instance_DidCreate(PP_Instance instance,
                                  uint32_t argc,
                                  const char* argn[],
                                  const char* argv[])
{
  return pthread_create(&interpret_thread, NULL, runInterpret, NULL) == 0;
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
  Log("run interpret\n");
  char *argv[] = {"squeak", NULL};
  sqMain(1, argv, NULL);
  return NULL;
}
