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

  SDL_Event event;

  float vertices[] = {
      0.0f, 0.5f,  // Vertex 1 (X, Y)
      0.5f, -0.5f, // Vertex 2 (X, Y)
      -0.5f, -0.5f // Vertex 3 (X, Y)
  };

  GLuint vbo;
  glGenBuffers(1, &vbo); // Generate 1 buffer
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  const GLchar *vertexSource = "#version 150 core\
        in vec2 position;\
        void main()\
        {   gl_Position = vec4(position, 0.0, 1.0);}";

  const GLchar *fragmentSource = "#version 150 core\
        out vec4 outColor;\
        void main()\
        {outColor = vec4(1.0, 1.0, 1.0, 1.0);}";

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexSource, NULL);
  glCompileShader(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  glCompileShader(fragmentShader);

  GLint status;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
  char buffer[512];
  glGetShaderInfoLog(vertexShader, 512, NULL, buffer);

  GLint statusFrag;
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &statusFrag);
  char bufferFrag[512];
  glGetShaderInfoLog(fragmentShader, 512, NULL, bufferFrag);

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);

  glLinkProgram(shaderProgram);
  glUseProgram(shaderProgram);

  GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(posAttrib);

  GLuint vao;
  glGenVertexArrays(1, &vao);

  // glDrawArrays(GL_TRIANGLES, 0, 3);

  while (true)
  {
    if (SDL_PollEvent(&event))
    {
      // if (windowEvent.type == SDL_KEYUP && windowEvent.key.keysym.sym == SDLK_ESCAPE) break;
      if (event.type == SDL_QUIT)
        break;
    }

    // Clear the screen to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a triangle from the 3 vertices
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Swap buffers
    // window.display();

    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(context);
  SDL_Quit();

  return EXIT_SUCCESS;
}