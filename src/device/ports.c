#include <Ports.h>

uint8_t inb(uint16_t port) {
    uint8_t ret;
    __asm__ __volatile__("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

void outb(uint16_t port, uint8_t data) {
    __asm__ __volatile__("out %0, %1" : : "a" (data), "Nd" (port));
}
