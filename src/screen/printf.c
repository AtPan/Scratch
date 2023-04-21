#include <Console.h>
#include <Keyboard.h>
#include <stdarg.h>

void printf(const char * fmt, ...) {
    va_args args;
    va_start(args, fmt);

    unsigned char attr = Scratch_get_active_attribute();
    char c;

    while((c = *fmt++)) {
        if(c != '%') {
            __Scratch_print_character_color(c, attr);
            continue;
        }

        c = *fmt++;

        switch(c) {
            case 'c':
                __Scratch_print_character_color(va_next(args, char), attr);
                break;
            case 'u':
                print_uint_color(va_next(args, unsigned int), attr);
                break;
            case 'd':
                print_int_color(va_next(args, int), attr);
                break;
            case 's':
                print_string_color(va_next(args, const char *), attr);
                break;
            case 'X':
            case 'x':
                print_hex_color(va_next(args, int), c == 'X', attr);
                break;
            default:
                __Scratch_print_character_color(c, Scratch_get_active_attribute());
        }
    }

    update_cursor();
}
