#include <Library.h>
#include <Console.h>

int strcmp(const char * a, const char * b) {
    while(*a && *b && *a == *b) {
        a++;
        b++;
    }

    return *a - *b;
}

int strncmp(const char * a, const char * b, int l) {
    while(*a && *a == *b && l) {
        a++;
        b++;
        l--;
    }

    if(l == 0 && (*a == 0 || *b == 0)) {
        a--;
        b--;
    }

    if((l == 0 || *a == 0) && *a == *b) return 0;
    else return *a - *b;
}
