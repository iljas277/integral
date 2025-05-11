CC = gcc
CFLAGS = -m32 -std=c99 -Wall -Wextra -g
LDFLAGS = -m32 
NASM = nasm
NASMFLAGS = -f elf32

SRC = main.c root_functions/root.c integral_functions/integral.c print_test/test_root.c print_test/test_integral.c print_test/print.c
OBJ = $(SRC:.c=.o) f.o
TARGET = main

.PHONY: all clean

all: $(TARGET) 

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ -lm 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

f.o: asm_functions/f.asm
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)