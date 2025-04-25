all: main

main: f.o main.o root.o integral.o
	gcc -m32 -o main main.o f.o
main.o: main.c
	gcc -m32 -o main.o -c -std=c99 main.c
f.o: f.asm
	nasm -f elf32 -o f.o f.asm
root.o: root.c 
	gcc -m32 -o root.o -c  -std=c99 root.c
integral.o: integral.c
	gcc -m32 -o integral.o -c -std=c99 integral.c
clean:
	rm *.o
	rm main
