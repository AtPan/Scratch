#include <Console.h>
#include <Keyboard.h>
#include <stdint.h>

void print_int_color(int i, unsigned char attribute) {
    if(i < 0) {
        __Scratch_print_character_color('-', attribute);
        i *= -1;
    }

    uint8_t buf[20];
    uint8_t count = 0;

    while(i) {
        buf[count++] = (uint8_t)(i % 10) + '0';
        i /= 10;
    }

    if(count == 0) __Scratch_print_character_color('0', attribute);
    else {
        for(i = count - 1; i >= 0; i--) {
            __Scratch_print_character_color(buf[i], attribute);
        }
    }
    update_cursor();
}
