#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "include/menu.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "include/init.h"
#include "include/game.h"
#include "include/animation.h"
int game(RunGame *rungame,SDL_Surface *screen,int run)
{
    
    SDL_Event event;
    
    RunGame rungame;
    initgame(&rungame);
    show(rungame->gamebackground,screen);
    while(run==3)
    {

    //Wait for event
    SDL_WaitEvent(&event);

    switch (event.type)
        {
        case SDL_QUIT:
            run=0;
            break;
        default:
            break;
        }


    }
return run;

