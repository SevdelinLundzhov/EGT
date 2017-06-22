//============================================================================
// Name        : ZADACHA1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <stdio.h>

SDL_Window *window;
SDL_Renderer *renderer;
int done;

void
DrawChessBoard(SDL_Renderer * renderer)
{
    int row = 0;
    int column = 0;
	int x = 0;
    SDL_Rect rect, darea;

    /* Get the Size of drawing surface */
    SDL_RenderGetViewport(renderer, &darea);

    for (row = 0 ; row < 55; row++)
    {
        column = row % 2;
        x = column;
        for ( column = 0; column < 55 + (row % 2); column++)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

            rect.w = darea.w/55;
            rect.h = darea.h/55;
            rect.x = x * rect.w;
            rect.y = row * rect.h;
            x = x + 2;
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void
loop()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            done = 1;
            return;
        }

        if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_ESCAPE)) {
            done = 1;
            return;
        }
    }

    DrawChessBoard(renderer);

    /* Got everything on rendering surface,
       now Update the drawing image on window screen */
    SDL_UpdateWindowSurface(window);
}

int
main(int argc, char *argv[])
{
    SDL_Surface *surface;

    /* Enable standard application logging */
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init fail : %s\n", SDL_GetError());
        return 1;
    }

    /* Create window and renderer for given surface */
    window = SDL_CreateWindow("Chess Board", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    if (!window)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window creation fail : %s\n",SDL_GetError());
        return 1;
    }
    surface = SDL_GetWindowSurface(window);
    renderer = SDL_CreateSoftwareRenderer(surface);
    if (!renderer)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Render creation for surface fail : %s\n",SDL_GetError());
        return 1;
    }

    /* Clear the rendering surface with the specified color */
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    /* Draw the Image on rendering surface */
    done = 0;

    while (!done)
    {
        loop();
    }

    SDL_Quit();
    return 0;
}
