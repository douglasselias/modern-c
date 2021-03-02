FILE=main

sdlFlags=`sdl2-config --cflags --libs`
glewFlags=-DGLEW_STATIC -lGLEW -lGLU -lGL

make:
	gcc ${FILE}.c -o ${FILE} $(sdlFlags) -Werror

run:
	clear && ./main

print: $(wildcard *.c)
	ls -1 $?