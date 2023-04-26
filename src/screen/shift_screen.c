#include <Console.h>
#include <Keyboard.h>

void shift_screen_up() {
    for(int row = 1; row < VGA_HEIGHT; row++) {
        for(int i = 0; i < VGA_WIDTH * 2; i++) {
            VGA_MEMORY[(VGA_WIDTH * row * 2) + i - (VGA_WIDTH * 2)] = VGA_MEMORY[(VGA_WIDTH * row * 2) + i];
        }
    }

    for(int i = 0; i < VGA_WIDTH * 2; i+=2) {
        VGA_MEMORY[(2 * VGA_WIDTH * (VGA_HEIGHT - 1)) + i] = 0;
        VGA_MEMORY[(2 * VGA_WIDTH * (VGA_HEIGHT - 1)) + i + 1] = Scratch_get_active_attribute();
    }

    __Scratch_set_terminal_position(__Scratch_get_terminal_position() - (VGA_WIDTH * 2));
    update_cursor();
}
