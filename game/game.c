/**
 * @file game.c
 * @author TMOF Team
 * @brief Game Management
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"

//Init to remove warnings
void initbackground(Background *assets);
void initminimap(Minimap *assets);
void initplayer(Character *player);
void updateminimap(Game *g);
void movement(Character *player,Background *bg,int x);
void gamerefresh(Game *g,SDL_Surface *screen);
void freegame(Game assets);

void handlemovement(Game *g)
{
        if (g->global.firstplayer==0)
        {
        movement(&g->player[0],&g->bg,1);
        }
        else
        {
        movement(&g->player[0],&g->bg,0);            
        }
        /*
        if (g->global.firstplayer==1)
        {
        movement(&g->player[1],&g->bg,1);
        }
        else
        {
        movement(&g->player[1],&g->bg,0);            
        }
        */
}
void handlescrolling(Game *g)
{
        if (g->player[0].position.x>g->player[1].position.x)
        {
                g->global.firstplayer=0;
        }
        if (g->player[1].position.x>g->player[0].position.x)
        {
                g->global.firstplayer=1;
        }
        if (g->player[1].position.x<g->player[0].position.x)
        {
                g->global.lastplayer=1;
        }
        if (g->player[0].position.x<g->player[1].position.x)
        {
                g->global.lastplayer=0;
        }
}
int game(SDL_Surface *screen,int run)
{
    Game g[2];
        g[0].global.screen=0;
        g[1].global.screen=1;
        initgame(&g[0]);
        initgame(&g[1]);
    SDL_Event event;

    Mix_PlayMusic(g[0].bg.son, -1);
    SDL_Flip(screen);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
    while(run==3)
    {
        //printf("\n%d",g[0].player[0].position.x+g[0].bg.img.pos2.x);
        if (g[0].player[0].position.x+g[0].bg.img.pos2.x>=5764-(SCREENDIF*g[0].global.screen))
        run=enigmestart(screen,run,&g[0].player[0].score);
        if (g[1].player[0].position.x+g[1].bg.img.pos2.x>=5764-(SCREENDIF*g[1].global.screen))
        run=enigmestart(screen,run,&g[0].player[0].score);
        run=handlegame(&g[0],&g[1],&event,screen,run);
        handlemovement(&g[0]);
        handlemovement(&g[1]);
        gamerefresh(&g[0],screen);
        gamerefresh(&g[1],screen);
        //handlescrolling(&g[0]);

    }
    freegame(g[0]);
    freebackground(g[0].bg);
return run;

}
int relative_x(Background *bg , SDL_Rect position)
{
    return (position.x-bg->img.pos2.x);
}