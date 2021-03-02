FILE=main

make:
	gcc ${FILE}.c -o ${FILE} `sdl2-config --cflags --libs`

print: $(wildcard *.c)
	ls -1 $?