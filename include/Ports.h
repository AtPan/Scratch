#ifndef SCRATCH_PORTS_H_
#define SCRATCH_PORTS_H_

#include <stdint.h>

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t data);

#endif
