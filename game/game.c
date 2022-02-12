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



int menu(int run)
{
    SDL_Event event;
    while(run==1)
    {

    //Wait for event
    SDL_WaitEvent(&event);

    switch (event.type)
        {
        case SDL_QUIT:
            run=0;
            break;
        case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                    {
                    case (SDLK_ESCAPE):
                        run=0;
                    break;
                    case (SDLK_DOWN):
                        run=2;
                    break;
                    case (SDLK_UP):
                        run=3;
                    break;
                    }
        }


    }
return run;

}

int options(int run)
{
    SDL_Event event;
    while(run==2)
    {

    //Wait for event
    SDL_WaitEvent(&event);

    switch (event.type)
        {
        case SDL_QUIT:
            run=0;
            break;
        case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                    {
                    case (SDLK_ESCAPE):
                        run=0;
                    break;
        
                    case (SDLK_DOWN):
                        run=2;
                    break;
                    case (SDLK_UP):
                        run=3;
                    break;
                    }
        }


    }
return run;

}

int game(int run)
{
    SDL_Event event;
    while(run==3)
    {

    //Wait for event
    SDL_WaitEvent(&event);

    switch (event.type)
        {
        case SDL_QUIT:
            run=0;
            break;
        case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                    {
                    case (SDLK_ESCAPE):
                        run=0;
                    break;
        
                    case (SDLK_DOWN):
                        run=2;
                    break;

                    case (SDLK_UP):
                        run=3;
                    break;

                    }
        }


    }
return run;

}


void InitOptions()
{

}