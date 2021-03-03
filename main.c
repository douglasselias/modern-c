#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

void printProgramLog(GLuint program);
void printShaderLog(GLuint shader);

int main()
{
  //Graphics program
  GLuint gProgramID = 0;
  GLint gVertexPos2DLocation = -1;
  GLuint gVBO = 0;
  GLuint gIBO = 0;

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  // SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  // Double buffering
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Use double buffering (0 to not use it)
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);  // Buffer has a depth of 24 bits

  int init = SDL_Init(SDL_INIT_EVERYTHING);
  if (init < 0)
  {
    printf("Init SDL error");
    SDL_Quit();

    return EXIT_SUCCESS;
  }

  SDL_Window *window = SDL_CreateWindow("Hello SDL!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 2560, 1080, SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED);
  SDL_GLContext *context = SDL_GL_CreateContext(window);

  if (context == NULL)
  {
    printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  glewExperimental = GL_TRUE;
  glewInit();
  GLenum glewError = glewInit();

  if (glewError != GLEW_OK)
  {
    printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
  }

  // GLuint vertexBuffer;
  // auto result = glGenBuffers(1, &vertexBuffer);
  // glBindBuffer(GL_ARRAY_BUFFER, 0);

  // printf("%u\n", vertexBuffer);

  SDL_Event event;

  while (true)
  {
    if (SDL_PollEvent(&event))
    {
      // if (windowEvent.type == SDL_KEYUP && windowEvent.key.keysym.sym == SDLK_ESCAPE) break;
      if (event.type == SDL_QUIT)
        break;
    }

    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(context);
  SDL_Quit();

  return EXIT_SUCCESS;
}