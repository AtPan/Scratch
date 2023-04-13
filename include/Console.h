#ifndef SCRATCH_CONSOLE_H_
#define SCRATCH_CONSOLE_H_

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY ((char *)0xb8000)

#define DEFAULT_ATTR 0x07

#define print_character(c) print_character_color((char)c, DEFAULT_ATTR)
#define print_string(str) print_string_color((const char *)str, DEFAULT_ATTR)
#define print_line(str) print_line_color((const char *)str, DEFAULT_ATTR)
#define print_int(i) print_int_color((int)i, DEFAULT_ATTR)

void clear_screen(void);
void print_character_color(char character, unsigned char attribute);
void print_string_color(const char * str, unsigned char attribute);
void print_line_color(const char * str, unsigned char attribute);
void print_int_color(int i, unsigned char attribute);

void printf(const char * fmt, ...);

void __Scratch_print_character_color(char c, unsigned char a);
void __Scratch_set_terminal_position(unsigned short new_terminal_position);
unsigned short __Scratch_get_terminal_position(void);

#endif
