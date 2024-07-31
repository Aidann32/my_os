static char* const VGA_MEMORY = (char*)0xb8000;
static int const VGA_WIDTH = 80;
static int const VGA_HEIGHT = 25;


void kernel_early(void){

}

int main(void *){
    const char* str = "Hello world!";
    
    unsigned int i = 0; // for text string
    unsigned int j = 0; // for video memory

    while(str[i] != '\0'){
        // VGA_MEMORY[j] - character itself
        // VGA_MEMORY[j+1] - color of character
        // Video memory accepts two bytes for each character, first byte for character and second is color

        VGA_MEMORY[j] = str[i];
        VGA_MEMORY[j+1] = 0x07;

        i++;
        j += 2; 
    }

    return 0;
}