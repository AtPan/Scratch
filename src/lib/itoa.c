#include <Library.h>
#include <Console.h>
#include <Keyboard.h>
#include <io.h>

char * itoa (char * buf, int a) {
    if(a == 0) {
        buf[0] = '0';
        buf[1] = 0;
        return buf;
    }

    int i = 0, negative = 0;
    if (a < 0) {
        a *= -1;
        negative = 1;
    }

    while(a) {
        buf[i++] = (a % 10) + '0';
        a /= 10;
    }

    if(negative) buf[i++] = '-';

    buf[i] = 0;

    buf = strnrev(buf, i);

    return buf;
}
