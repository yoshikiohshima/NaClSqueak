extern pthread_mutex_t image_mutex;
extern pthread_t interpret_thread;
extern int32_t flush_pending;
extern int32_t toQuit;

extern int flush_display_requested;

struct SqModule * nacl_display_module();
struct SqModule * nacl_sound_module();

extern int sqMain(int argc, char **argv, char **envp);
extern void FlushPixelBuffer();

extern char LogBuffer[1024];
void Log(char* message);
char *NaClStatus();


void NaCl_DidChangeView(PP_Instance instance,
		       const struct PP_Rect* position,
			const struct PP_Rect* clip);

PP_Bool NaCl_HandleInputEvent(PP_Instance instance,
			      const struct PP_InputEvent* evt);

void NaCl_InitializeModule(PPB_GetInterface get_browser_interface);

