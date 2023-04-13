#include <Console.h>
#include <Keyboard.h>

static unsigned short terminal_position = 0;

void __Scratch_set_terminal_position(unsigned short pos) {
    terminal_position = pos;
}

unsigned short __Scratch_get_terminal_position() {
    return terminal_position;
}

void print_character_color(char c, unsigned char a) {
    __Scratch_print_character_color(c, a);
    update_cursor();
}

void __Scratch_print_character_color(char c, unsigned char a) {
    switch (c) {
        case '\n':
            terminal_position += 160 - (terminal_position % 160);
            break;
        case '\t':
            terminal_position += 8 - (terminal_position % 8);
            break;
        default:
            VGA_MEMORY[terminal_position] = c;
            VGA_MEMORY[terminal_position + 1] = a;
            terminal_position += 2;
            break;
    }
}
