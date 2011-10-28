void ring_buffer_initialize();
int send_from_sq_to_browser(char *aString, int32_t size);
struct PP_Var read_from_sq_to_browser(struct PP_Var (*func)(const char* str, int32_t size));

