#include <Console.h>
#include <Keyboard.h>

int main(void);

int main() {
    clear_screen();
    unsigned char byte;
    while(1) {
        while((byte = scan())) {
            print_character(charmap[byte]);
        }
    }

    return 0;
}
