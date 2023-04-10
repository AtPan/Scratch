#ifndef SCRATCH_KEYBOARD_H__
#define SCRATCH_KEYBOARD_H__

#include <io.h>

unsigned char inb(unsigned short port);
unsigned char scan(void);

#endif
