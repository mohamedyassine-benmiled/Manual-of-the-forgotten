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
int game(SDL_Surface *screen,int run,int state)
{
    Game g[2];
    initbackground(&g[0].bg);
        initbackground(&g[1].bg);
g[0].global.screen=0;
g[1].global.screen=1;
    g[0].global.firstplayer=0;
    g[0].global.lastplayer=0;
    g[0].global.checkpoint=5;
    g[0].global.level=1;
    g[0].global.elapsed=0;
    g[1].global.firstplayer=0;
    g[1].global.lastplayer=0;
    g[1].global.checkpoint=5;
    g[1].global.level=1;
    g[1].global.elapsed=0;
    initplayer(&g[0].player[0]);
    initminimap(&g[0].minimap);
    initennemy(&g[0].enemy[0]);
        initplayer(&g[1].player[0]);
    initminimap(&g[1].minimap);
    initennemy(&g[1].enemy[0]);
        if (state==2)
        {
                get_save(&g[0]);
                get_save(&g[1]);
        }
    SDL_Event event;
    showgame(g[0].bg.img,screen);
        showgame(g[1].bg.img,screen);
    Mix_PlayMusic(g[0].bg.son, -1);
    SDL_Flip(screen);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
    while(run==3)
    {


        if (g[0].player[0].position.x+g[0].bg.img.pos2.x>=5764-(SCREENDIF*g[0].global.screen))
        {
        run=enigmestart(screen,run,&g[0].player[0].score);
                if (run==3)
                {
                        writescore(g[0].player[0].score);
                        run=1;
                }
                if (run==5)
                {
                        get_save(&g[0]);
                        run=3;
                }
        }
        if (g[1].player[0].position.x+g[1].bg.img.pos2.x>=5764-(SCREENDIF*g[1].global.screen))
                {
        run=enigmestart(screen,run,&g[1].player[0].score);
                if (run==3)
                {
                        writescore(g[1].player[0].score);
                        run=1;
                }
                if (run==5)
                {
                        get_save(&g[1]);
                        run=3;
                }
        }
        run=handlegame(&g[0],&g[1],&event,screen,run);
        if (run == 0)
        {
                write_save(&g[0]);
        }
        handlemovement(&g[0]);
        handlemovement(&g[1]);
        gamerefresh(&g[0],screen);
        gamerefresh(&g[1],screen);
        //handlescrolling(&g);


    }
    freegame(g[0]);
    freebackground(g[0].bg);
        freegame(g[1]);
    freebackground(g[1].bg);
return run;

}
int relative_x(Background *bg , SDL_Rect position)
{
    return (position.x-bg->img.pos2.x);
}