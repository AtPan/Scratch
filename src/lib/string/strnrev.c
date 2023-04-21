#include <Library.h>

char * strnrev(char * buf, unsigned int len) {
    char c;

    for(unsigned int i = 0; i < len / 2; i++) {
        c = buf[i];
        buf[i] = buf[len - i - 1];
        buf[len - i - 1] = c;
    }

    return buf;
}
