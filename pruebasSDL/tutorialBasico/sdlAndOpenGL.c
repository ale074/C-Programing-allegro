#include "SDL2/SDL.h"   /* All SDL App's need this */
#include <GL/gl.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    /* Initialize the SDL library */
    if( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        fprintf(stderr,
                "Couldn't initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    
    SDL_Window *window;
    window = SDL_CreateWindow(
        "SDl + OpenGL Tutorial",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1366,
        768,
        SDL_WINDOW_OPENGL);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_MASK);

    SDL_GLContext mainContext = SDL_GL_CreateContext(window);

    // gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    SDL_Event event;
    int running = 1;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
        }
        glClearColor(1.0f, 0.0, 0.0, 1.0);
        glCleat(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);        
    }
    printf("%s\n", glGetString(GL_VERSION));

    SDL_DestroyWindow(window);

    /* Shutdown all subsystems */
    SDL_Quit();

    return 0;
}