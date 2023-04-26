#ifndef SCRATCH_CONSOLE_H_
#define SCRATCH_CONSOLE_H_

#define NULL ((void *)0)

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY ((char *)0xb8000)

#define print_character(c) print_character_color((char)c, Scratch_get_active_attribute())
#define print_string(str) print_string_color((const char *)str, Scratch_get_active_attribute())
#define print_line(str) print_line_color((const char *)str, Scratch_get_active_attribute())
#define print_int(i) print_int_color((int)i, Scratch_get_active_attribute())
#define print_uint(i) print_uint_color((unsigned int)i, Scratch_get_active_attribute())
#define print_hex(a, b) print_hex_color((unsigned int)a, (int)b, Scratch_get_active_attribute())

unsigned char Scratch_get_active_attribute(void);
void Scratch_set_active_attribute(unsigned char a);
void clear_screen(void);
void print_character_color(char character, unsigned char attribute);
void print_string_color(const char * str, unsigned char attribute);
void print_line_color(const char * str, unsigned char attribute);
void print_int_color(int i, unsigned char attribute);
void print_uint_color(unsigned int i, unsigned char attribute);
void print_hex_color(unsigned int a, int lower, unsigned char attribute);

void printf(const char * fmt, ...);

void shift_screen_up(void);

void __Scratch_print_character_color(char c, unsigned char a);
void __Scratch_set_terminal_position(unsigned short new_terminal_position);
unsigned short __Scratch_get_terminal_position(void);

#endif
