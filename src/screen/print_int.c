#include <Console.h>
#include <Keyboard.h>
#include <stdint.h>

void print_int_color(int i, unsigned char attribute) {
    char is_negative = 0;
    if(i < 0) {
        __Scratch_print_character_color('-', attribute);
        is_negative = 1;
    }
    print_uint_color(is_negative ? (i * -1) : i, attribute);
}

void print_uint_color(unsigned int i, unsigned char attribute) {
    uint8_t buf[11];
    uint8_t count = 0;

    while(i) {
        buf[count++] = (uint8_t)(i % 10) + '0';
        i /= 10;
    }

    if(count == 0) __Scratch_print_character_color('0', attribute);
    else {
        for(int j = count - 1; j >= 0; j--) {
            __Scratch_print_character_color(buf[j], attribute);
        }
    }
    update_cursor();
}
