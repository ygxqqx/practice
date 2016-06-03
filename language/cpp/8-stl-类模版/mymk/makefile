main:main.o sub.o add.o
	gcc -g -Wall main.o sub.o add.o -o main

main.o:main.c
	gcc -g -Wall -c main.c -o main.o
sub.o:sub.c sub.h
	gcc -g -Wall -c sub.c -o sub.o

add.o:add.c add.h
	gcc -g -Wall -c add.c -o add.o

clean:
	rm -f *.o


