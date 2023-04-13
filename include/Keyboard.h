#ifndef SCRATCH_KEYBOARD_H__
#define SCRATCH_KEYBOARD_H__

#include <io.h>
#include <stdint.h>

unsigned char scan(void);
uint16_t get_cursor_position(void);
void update_cursor(uint16_t position);

#endif
