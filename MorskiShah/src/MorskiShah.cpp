//============================================================================
// Name        : MorskiShah.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

SDL_Window *gWindow;
SDL_Renderer *gRenderer;
SDL_Texture *gTexture;

const int SCREEN_FPS = 50;
const int SCREEN_TICS_PER_FRAME = 1000 / SCREEN_FPS;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 650;

bool init();
void close();
SDL_Texture* loadTexture(string path);

int main(int argc, char* args[]) {

	if(init())
	{
		bool quit = false;
		SDL_Event e;
		long oldTime = SDL_GetTicks();
		SDL_Rect daskaDestination = {0, 0, 600, 600};
		SDL_Rect xDestination = {0, 600, 300, 650};
		SDL_Rect oDestination = {300, 600, 650, 650};
		while( !quit )
		{
			if(SDL_GetTicks() - oldTime >= SCREEN_TICS_PER_FRAME)
			{
				oldTime = SDL_GetTicks();
				while(SDL_PollEvent( &e ) != 0)
				{
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				SDL_RenderClear(gRenderer);
				SDL_RenderCopy(gRenderer, gTexture, NULL, &daskaDestination);
				SDL_RenderCopy(gRenderer, gTexture, NULL, &xDestination);
				SDL_RenderCopy(gRenderer, gTexture, NULL, &oDestination);
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	close();

	return 0;
}

bool init()
{
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == NULL)
		{
            cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
            success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED);
			if(gRenderer == NULL)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				 SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				 int imgFlags = IMG_INIT_PNG;
				 if(!( IMG_Init( imgFlags ) & imgFlags ))
				 {
	                	cout << "SDL_image could not initialize! SDL_image Error: %s" << IMG_GetError() << endl;
	                    success = false;
				 }

	                gTexture = loadTexture("images.png");
	                if(gTexture == NULL)
	                {
	                	success = false;
	                }

			}
		}
	}
	return success;
}

SDL_Texture* loadTexture(string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        cout << "Unable to load image %s! SDL_image Error: " << path.c_str() << " " << IMG_GetError()  << endl;
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
        	cout << "Unable to create texture from %s! SDL Error: " << path.c_str() << " " << SDL_GetError() << endl;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

void close()
{
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    IMG_Quit();
    SDL_Quit();
}
