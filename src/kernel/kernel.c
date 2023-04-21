#include <Console.h>
#include <Keyboard.h>
#include <Library.h>
#include <Shell.h>

int main(void);

int main() {
    clear_screen();

    Scratch_set_console_prompt("~$ ");

    while(1) {
        Scratch_display_console_prompt();
        const char * command = Scratch_shell_listen();
        if(Scratch_execute_command(command) < 0) break;
    }

    return 0;
}
