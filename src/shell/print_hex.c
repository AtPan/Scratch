#include <Console.h>
#include <Keyboard.h>

void print_hex_color(unsigned int a, int lower, unsigned char attribute) {
    unsigned char b;

    for(unsigned char i = 8; i > 0; i--) {
        b = (a >> ((i-1) << 2)) & 0xf;
        b += '0';
        if(b > 57) b += lower == 0 ? 7 : 39;
        __Scratch_print_character_color(b, attribute);
    }

    update_cursor();
}
