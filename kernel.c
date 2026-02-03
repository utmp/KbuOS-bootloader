#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
uint16_t* terminal_buffer = (uint16_t*) 0xB8000; 

void terminal_writestring(const char* data, uint8_t color) {
    size_t index = 0;
    while (data[index] != 0) {
        terminal_buffer[index] = (uint16_t)data[index] | (uint16_t)color << 8;
        index++;
    }
}

void kernel_main(void) {
   
    
    terminal_writestring("    MERHABA! KbuOS isletim sistemine hos geldin!    ", VGA_COLOR_LIGHT_CYAN);
    
    terminal_buffer += 80; 
    terminal_writestring("    GRUB ile boot edildi - Debian uzerinden yapildi! ", VGA_COLOR_LIGHT_GREEN);
}