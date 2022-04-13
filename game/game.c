#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"


int game(SDL_Surface *screen,int run)
{
    Game g;
    initbackground(&g.bg);
    initplayer(&g.player[0]);
    initplayer(&g.player[1]);
    SDL_Event event;
    showgame(g.bg.img,screen);
    SDL_Flip(screen);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
    while(run==3)
    {
        run=handlegame(&g,&event,screen,run);
        movement(&g.player[0]);
        movement(&g.player[1]);
        gamerefresh(&g,screen);
    }
    freebackground(g.bg);
return run;

}


