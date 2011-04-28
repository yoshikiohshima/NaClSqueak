#include <pthread.h>

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
#include <ppapi/c/ppb_graphics_2d.h>
#include <ppapi/c/ppb_core.h>
#include <ppapi/c/pp_input_event.h>
#include <ppapi/c/pp_completion_callback.h>


extern pthread_mutex_t image_mutex;
extern pthread_t interpret_thread;
extern int32_t flush_pending;
extern int32_t toQuit;

extern int flush_display_requested;

struct SqModule * nacl_display_module();
struct SqModule * nacl_sound_module();

extern int sqMain(int argc, char **argv, char **envp);
extern void FlushPixelBuffer();

extern char LogBuffer[];
void Log(char* message);
char *NaClStatus();
void MainLog(char *message, int32_t i);

void NaCl_DidChangeView(PP_Instance instance,
		       const struct PP_Rect* position,
			const struct PP_Rect* clip);

PP_Bool NaCl_HandleInputEvent(PP_Instance instance,
			      const struct PP_InputEvent* evt);

void NaCl_InitializeModule(PPB_GetInterface get_browser_interface);

