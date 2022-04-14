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
int handlegame(Game *g,SDL_Event *event,SDL_Surface *screen,int run);
void movement(Character *player,Background *bg,int x);
void gamerefresh(Game *g,SDL_Surface *screen);
void freegame(Game assets);

int game(SDL_Surface *screen,int run)
{
    Game g;
    
    initbackground(&g.bg);
    initplayer(&g.player[0]);
    initplayer(&g.player[1]);
    initminimap(&g.minimap);
    initennemy(&g.enemy[0]);
    SDL_Event event;
    showgame(g.bg.img,screen);
    Mix_PlayMusic(g.bg.son, -1);
    SDL_Flip(screen);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
    while(run==3)
    {
        run=handlegame(&g,&event,screen,run);
        movement(&g.player[0],&g.bg,1);
        movement(&g.player[1],&g.bg,0);
        gamerefresh(&g,screen);
    }
    freegame(g);
    freebackground(g.bg);
return run;

}


