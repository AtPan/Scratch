#include <Console.h>
#include <Keyboard.h>
#include <Library.h>

int main(void);
void hang(void);

int main() {
    clear_screen();

    char buf[20];
    int start = 123;
    for(int k = 0; k < 5; k++) {
        print_line(itoa(buf, start * k * (k % 2 == 0 ? -1 : 1)));
    }

    unsigned int position = get_cursor_position();
    printf("Old Cursor Position: %d\n", position);

    position = get_cursor_position();
    printf("New Cursor Position: %d\n", position);

    printf("%d %d\n%s\n%s: %d\n", -1893, -4407, "Hello World!", "Final Cursor Position", get_cursor_position());

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
