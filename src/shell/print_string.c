#include <Console.h>

void print_string_color(const char * str, unsigned char a) {
    char c;
    while((c = *str++)) {
        print_character_color(c, a);
    }
}

void print_line_color(const char * str, unsigned char a) {
    print_string_color(str, a);
    print_character('\n');
}
