#include <Command.h>
#include <Library.h>
#include <Console.h>

static const char * valid_colors[] = {
    "black",
    "blue",
    "green",
    "cyan",
    "red",
    "magenta",
    "brown",
    "white",
    "gray",
    "lightblue",
    "lightgreen",
    "lightcyan",
    "lightred",
    "lightmagenta",
    "yellow",
    "brightwhite"
};

int set_terminal_font_color(const char * color) {
    if(*color != '-') {
        print_line("USAGE: set-terminal-font-color -COLOR");
        return 1;
    }
    color++;

    int i = 0;
    while(i < 16 && strncmp(color, valid_colors[i], 12) != 0) i++;

    if(i == 16) {
        printf("set-terminal-font-: Color '%s' is not a valid color. Valid colors are:\n", color);
        for(i = 0; i < 16; i += 4) {
            printf("%s %s %s %s\n", valid_colors[i], valid_colors[i + 1], valid_colors[i + 2], valid_colors[i + 3]);
        }
        return 2;
    }

    Scratch_set_active_attribute(i);

    for(int j = __Scratch_get_terminal_position() + 1; j < VGA_WIDTH * VGA_HEIGHT; j += 2) {
        VGA_MEMORY[j] = i;
    }

    return 0;
}
