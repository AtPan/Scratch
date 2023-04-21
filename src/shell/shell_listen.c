#include <Shell.h>
#include <Console.h>
#include <Keyboard.h>
#include <io.h>

static int handle_byte(char *, int, unsigned char);
static char command_buf[MAX_COMMAND_LEN] = {0};

const char * Scratch_shell_listen() {
    int count = 0;
    unsigned char byte = 0;

    for(int i = 0; i < MAX_COMMAND_LEN; i++) command_buf[i] = 0;

    while(1) {
        while((byte = charmap[scan()])) {
            if(count == MAX_COMMAND_LEN - 1) {
                command_buf[MAX_COMMAND_LEN - 1] = 0;
                return command_buf;
            }

            if((count = handle_byte(command_buf, count, byte)) < 0) {
                return command_buf;
            }
        }
    }

    return command_buf;
}

static int handle_byte(char * command_buf, int count, unsigned char byte) {
    print_character(byte);
    switch(byte) {
        case '\n':
            return -1;
            break;
        case '\b':
            for(int i = MAX_COMMAND_LEN - 1; i >= count; i--) {
                command_buf[i - 1] = command_buf[i];
            }
            count--;
            //command_buf[--count] = 0;
            break;
        default:
            command_buf[count++] = byte;
    }

    return count;
}

char * Scratch_get_command_buf() {
    return command_buf;
}
