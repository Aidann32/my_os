CC=gcc
TARGET=myos
C_FILES= ./libc/string/ctos.c \
		./libc/string/memcmp.c \
		./libc/string/memset.c \
		./libc/string/strcat.c \
		./libc/string/strchr.c \
		./libc/string/strcmp.c \
		./libc/string/strcpy.c \
		./libc/string/strlen.c \
		./libc/string/strncmp.c \
		./libc/string/strstr.c \
		./libc/string/strutil.c \
		./kernel_files/tty.c \
		./kernel_files/io.c \
		./kernel.c
OBJS=$(C_FILES:.c=.o)

all compile: $(TARGET)
all: finale 
.PHONY: all compile clean finale

%.o:
	$(CC) -c $(@:.o=.c) -o $@ -ffreestanding -fno-exceptions -m32

$(TARGET): $(OBJS)
	$(shell nasm -f elf start.asm -o start.o)
	$(CC) -m32 -nostdlib -nodefaultlibs start.o $? -T linker.ld -o $(TARGET)

finale:
	$(shell cd /home/aidan/my_os/)
	$(shell cp $(TARGET) /home/aidan/my_os/iso/boot/$(TARGET))
	$(shell grub2-mkrescue -o $(TARGET).iso iso)

clean:
	rm -f *.o $(TARGET) $(TARGET).iso
