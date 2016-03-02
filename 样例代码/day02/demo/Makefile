compile:
	gcc -c -fpic input.c
	gcc -c -fpic primer.c
lnk:compile
	gcc -shared -olibdemo.so input.o primer.o
demo:lnk
	gcc demo.c -ldemo -L. -omain
