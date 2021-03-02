#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
// #define GLEW_STATIC
// #include <GL/glew.h>

typedef struct
{
  float x;
  float y;
  float z;
} Vertex;

typedef Vertex Triangle[3];

int main()
{
  // glewExperimental = GL_TRUE;
  // glewInit();

  // GLuint vertexBuffer;
  // glGenBuffers(1, &vertexBuffer);

  // printf("%u\n", vertexBuffer);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  Vertex v = {
      1.3,
      1.9,
      4.1};

  printf("point X: %.2f \n", v.x);

  Triangle t = {v, v, v};

  printf("vertex 0_Z: %.2f \n", t[0].z);

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window *window = SDL_CreateWindow("Hello SDL!", 200, 200, 900, 500, SDL_WINDOW_MAXIMIZED);
  SDL_GLContext *context = SDL_GL_CreateContext(window);

  // SDL_Delay(5000);
  // if (windowEvent.type == SDL_KEYUP &&
  // windowEvent.key.keysym.sym == SDLK_ESCAPE) break;
  SDL_Event event;

  while (true)
  {
    if (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
        break;
    }

    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(context);
  SDL_Quit();

  return 0;
}