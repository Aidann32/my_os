#include "kernel_files/tty.h"
#include "kernel_files/io.h"
#include "kernel_files/kbd.h"
#include "libc/include/string.h"

static char* const VGA_MEMORY = (char*)0xb8000;
static int const VGA_WIDTH = 80;
static int const VGA_HEIGHT = 25;


void kernel_early(void){
    terminal_initialize();
}

__attribute__((noreturn))
int main(void){
    char* buff;
    strcpy(&buff[strlen(buff)], "");
    printprompt();
    while (1){
        uint8_t byte;
        while(byte=scan()) {
            if (byte == 0x1c){
                if (strlen(buff) > 0 && strcmp(buff, "shutdown") == 0) printf("\nShutting down");
                printprompt();
                memset(&buff[0], 0 ,sizeof(buff));
                break;
            } else{
                char c = normalmap[byte];
                char* s;
                s = ctos(s, c);
                printf("%s", s);
                strcpy(&buff[strlen(buff)], s);
            }
            move_cursor(get_terminal_row(), get_terminal_col());
        }
    }
    return 0;
}