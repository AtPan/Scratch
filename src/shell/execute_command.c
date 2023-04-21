#include <Shell.h>
#include <Console.h>
#include <Library.h>
#include <Command.h>

int Scratch_execute_command(const char * command) {
    int first_space = 0;
    int code = 0;

    while(command[first_space] != 0 && command[first_space] != ' ') first_space++;

    if(first_space == 4 && strncmp(command, "exit", first_space) == 0) {
        print_string("Goodbye");
        code = -1;
    }
    else if(first_space == 23 && strncmp(command, "set-terminal-font-color", first_space) == 0) {
        code = set_terminal_font_color(command + first_space + 1);
    }
    else if(first_space == 5 && strncmp(command, "clear", first_space) == 0) {
        clear_screen();
    }
    else {
        printf("Unrecognized command: '%s'\n", command);
    }

    return code;
}
