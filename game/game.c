#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"

//To initialize Everything (What did it cost?)
void init()
{
     SDL_Init(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(IMG_Load("Menu/Logo.png"),NULL);
                SDL_WM_SetCaption("Manual of the forgotten",NULL);
}
/* ScreenInit is bugged out
void screeninit(SDL_Surface *screen)
{
    screen = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
}
*/



void options(int opt)
{

}

void InitOptions()
{

}