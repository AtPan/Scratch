#include <Shell.h>
#include <Console.h>
#include <Library.h>

static const char * console_prompt = "~$ ";

const char * Scratch_get_console_prompt() {
    return console_prompt;
}

void Scratch_set_console_prompt(const char * a) {
    if(a == NULL) return;

    console_prompt = a;
}

unsigned int Scratch_get_console_prompt_length() {
    return strlen(console_prompt);
}

void Scratch_display_console_prompt() {
    print_string(console_prompt);
}
