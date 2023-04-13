#include <Console.h>
#include <Keyboard.h>
#include <stdarg.h>

void printf(const char * fmt, ...) {
    va_args args;
    va_start(args, fmt);

    char c;

    while((c = *fmt++)) {
        if(c != '%') {
            __Scratch_print_character_color(c, DEFAULT_ATTR);
            continue;
        }

        c = *fmt++;

        switch(c) {
            case 'c':
                __Scratch_print_character_color(va_next(args, char), DEFAULT_ATTR);
                break;
            case 'd':
                print_int(va_next(args, int));
                break;
            case 's':
                print_string(va_next(args, const char *));
                break;
            case 'X':
            case 'x':
                print_hex(va_next(args, int), c == 'X');
                break;
            default:
                __Scratch_print_character_color(c, DEFAULT_ATTR);
        }
    }

    update_cursor();
}
