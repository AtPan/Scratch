#include <Console.h>
#include <Keyboard.h>

void clear_screen() {
    unsigned char a = Scratch_get_active_attribute();
    for(int i = 0; i < VGA_HEIGHT * VGA_WIDTH * 2; i+=2) {
        VGA_MEMORY[i] = 0;
        VGA_MEMORY[i+1] = a;
    }

    __Scratch_set_terminal_position(0);
    update_cursor();
}
