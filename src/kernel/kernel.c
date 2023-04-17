#include <Console.h>
#include <Keyboard.h>
#include <Library.h>

int main(void);
void hang(void);

int main() {
    clear_screen();

    printf("Printing 0x80000000 as signed decimal: %d\n", 0x80000000);
    printf("Printing 0x80000000 as an unsigned decimal: %u\n", 0x80000000);

    printf("Expecting 4294967295 & -1: %u -- %d\n", 0xffffffff, 0xffffffff);
    printf("Longest unsigned / signed number: %u -- %d\n", 0xffffffff, 0x80000000);

    unsigned int position = get_cursor_position();
    printf("Old Cursor Position: %d\n", position);

    position = get_cursor_position();
    printf("New Cursor Position: %d\n", position);

    printf("%d %d\n%s\n%s: %d\n", -1893, -4407, "Hello World!", "Final Cursor Position", get_cursor_position());

    printf("0x%x -- 0x%X", 1234, 1234);

    hang();

    return 0;
}

void hang() {
    unsigned char byte;
    while(1) {
        while((byte = scan())) {
            print_character(charmap[byte]);
        }
    }
}
