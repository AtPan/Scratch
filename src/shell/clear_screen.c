#include <Console.h>
#include <Keyboard.h>

void clear_screen() {
    for(int i = 0; i < VGA_HEIGHT * VGA_WIDTH * 2; i+=2) {
        VGA_MEMORY[i] = 0;
        VGA_MEMORY[i+1] = 0x07;
    }

    __Scratch_set_terminal_position(0);
    update_cursor(__Scratch_get_terminal_position());
}
