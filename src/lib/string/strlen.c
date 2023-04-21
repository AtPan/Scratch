#include <Library.h>

unsigned int strlen(const char * a) {
    const char * b = a;
    while(*b++);
    return b - a - 1;
}
