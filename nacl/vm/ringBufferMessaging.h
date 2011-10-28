void ring_buffer_initialize();
int send_from_sq_to_browser(char *aString, int32_t size);
int send_from_browser_to_sq(char *aString, int32_t size);
struct PP_Var read_from_sq_to_browser(struct PP_Var (*func)(const char* str, int32_t size));
int read_from_browser_to_sq(int (*newString)(int));
void signalMessagingSemaphore();
