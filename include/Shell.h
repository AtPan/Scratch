#ifndef SCRATCH_SHELL_H_
#define SCRATCH_SHELL_H_

#define MAX_COMMAND_LEN 255

const char * Scratch_shell_listen(void);
int Scratch_execute_command(const char * command);

const char * Scratch_get_console_prompt(void);
void Scratch_set_console_prompt(const char * a);
unsigned int Scratch_get_console_prompt_length(void);
void Scratch_display_console_prompt(void);
char * Scratch_get_command_buf(void);

#endif
