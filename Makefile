CC = gcc
CFLAGS = -m32 -std=c99 -Wall -Wextra -g
LDFLAGS = -m32 
NASM = nasm
NASMFLAGS = -f elf32

SRC = main.c root.c integral.c search_root_interval.c count.c test_root.c test_integral.c
OBJ = $(SRC:.c=.o) f.o
TARGET = main

.PHONY: all clean

all: $(TARGET) 

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ -lm 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

f.o: f.asm
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)