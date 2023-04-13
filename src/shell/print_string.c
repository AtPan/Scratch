#include <Console.h>
#include <Keyboard.h>

void print_string_color(const char * str, unsigned char a) {
    char c;
    while((c = *str++)) {
        print_character_color(c, a);
    }
    update_cursor(__Scratch_get_terminal_position());
}

void print_line_color(const char * str, unsigned char a) {
    print_string_color(str, a);
    print_character('\n');
}
