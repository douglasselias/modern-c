#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct
{
  float x;
  float y;
  float z;
} Vertex;

typedef Vertex Triangle[3];

int main()
{
  Vertex v = {
      1.3,
      1.9,
      4.1};

  printf("point X: %.2f \n", v.x);

  Triangle t = {v, v, v};

  printf("vertex 0_Z: %.2f \n", t[0].z);

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Delay(1000);

  SDL_Quit();

  return 0;
}