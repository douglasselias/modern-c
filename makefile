FILE=main

sdlFlags=`sdl2-config --cflags --libs`
glewFlags=-DGLEW_STATIC -lGLEW -lGLU -lGL
errorFlags=-Werror

make:
	clear && gcc ${FILE}.c -o ${FILE} $(sdlFlags) $(glewFlags)

run:
	clear && ./main

print: $(wildcard *.c)
	ls -1 $?