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
void inithealth(Health *health,int player);
void initbackground(Background *assets);
void initminimap(Minimap *assets);
void initplayer(Character *player);
void updateminimap(Game *g);
void writescore(int score);
int handlegame(Game *g,SDL_Event *event,SDL_Surface *screen,int run);
int enigmestart(SDL_Surface *screen,int run,int *score);
void movement(Character *player,Background *bg,int x);
void gamerefresh(Game *g,SDL_Surface *screen);
void freegame(Game assets);
int get_save(Game *g);
int write_save(Game *g);
void handlemovement(Game *g)
{
        if (g->global.firstplayer==0)
        {
        if (!g->player[0].death)
        movement(&g->player[0],&g->bg,1);
        }
        else
        {
        if (!g->player[0].death)
        movement(&g->player[0],&g->bg,0);            
        }
        if (g->global.nbplayers==2)
        {
        if (g->global.firstplayer==1)
        {
        if (!g->player[1].death)
        movement(&g->player[1],&g->bg,1);
        }
        else
        {
        if (!g->player[1].death)
        movement(&g->player[1],&g->bg,0);            
        }

        }
        
}
void handlescrolling(Game *g)
{
        if ((g->global.nbplayers==2) && (!g->player[0].death) && (!g->player[1].death))
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
}
int game(SDL_Surface *screen,int run,int state)
{
    Game g;
    initbackground(&g.bg);
    g.global.firstplayer=0;
    g.global.lastplayer=0;
    g.global.checkpoint=5;
    g.global.nbenemies=5;
    g.global.level=1;
    g.global.elapsed=0;
    if (state==3)
        {
                g.global.nbplayers=2;
                        g.global.lastplayer=1;
        }
        else
        {
                g.global.nbplayers=1;

        }
        if (state==2)
        {
                get_save(&g);
        }
        for (int i=0;i<g.global.nbplayers;i++)
        {
        g.player[i].player=i;
        initplayer(&g.player[i]);
        }
    initminimap(&g.minimap);
    for (int i=0;i<g.global.nbenemies;i++)
        {
                g.enemy[i].enemy=i;
                initennemy(&g.enemy[i]);
        }
    for (int i=0;i<g.global.nbplayers;i++)
        inithealth(&g.health[i],i);

if (state==2)
        {
                get_save(&g);
        }
        else
        if (state)
        {
                write_save(&g);
        }
    SDL_Event event;
    showgame(g.bg.img,screen);
    Mix_PlayMusic(g.bg.son, -1);
    SDL_Flip(screen);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
    while(run==3)
    {

        if (g.player[g.global.firstplayer].position.x+g.bg.img.pos2.x>=5764)
        {
        run=enigmestart(screen,run,&g.player[g.global.firstplayer].score);
                if (run==3)
                {
                        writescore(g.player[g.global.firstplayer].score);
                        run=1;
                }
                if (run==5)
                {
                        get_save(&g);
                        run=3;
                }
        }
        run=handlegame(&g,&event,screen,run);
        if (run == 0)
        {
                write_save(&g);
        }
        handlemovement(&g);
        for (int i=0;i<g.global.nbplayers;i++)
        if (g.player[i].life==0)
        {
                run = 1;
        }
        gamerefresh(&g,screen);
        handlescrolling(&g);


    }
    freegame(g);
    freebackground(g.bg);
return run;

}
int relative_x(Background *bg , SDL_Rect position)
{
    return (position.x-bg->img.pos2.x);
}