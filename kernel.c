#include "kernel_files/tty.h"

static char* const VGA_MEMORY = (char*)0xb8000;
static int const VGA_WIDTH = 80;
static int const VGA_HEIGHT = 25;


void kernel_early(void){
    terminal_initialize();
}

__attribute__((noreturn))
int main(void *){
    printf("Hello world!\n");
    while (1){}
    return 0;
}