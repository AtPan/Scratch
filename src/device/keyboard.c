#include <Keyboard.h>
#include <Console.h>
#include <Ports.h>

unsigned char scan(void) {
    /*
    static unsigned char key = 0;
    unsigned char c = inb(0x60);

    if(c & 0x80) return key = 0;
    else if (c != key) return key = c;
    else return 0;
    */
    unsigned char brk;
    static unsigned char key = 0;
    unsigned char scan = inb(0x60);
    brk = scan & 0x80;
    scan = scan & 0x7f;

    if (brk)
        return key = 0;
    else if (scan != key)
        return key = scan;
    else
        return 0;
}

void update_cursor() {
    unsigned short position = __Scratch_get_terminal_position();
    position >>= 1;

    outb(0x3D4, 0x0f);
    outb(0x3D5, (uint8_t)(position));

    outb(0x3D4, 0x0e);
    outb(0x3D5, (uint8_t)(position >> 8));
}

uint16_t get_cursor_position() {
    uint16_t pos = 0;

    outb(0x3D4, 0x0f);
    pos |= inb(0x3D5);

    outb(0x3D4, 0x0e);
    pos |= (((uint16_t)inb(0x3D5)) << 8);

    return pos;
}
