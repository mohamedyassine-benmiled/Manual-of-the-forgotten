#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
#include <SDL/SDL.h>
#include "image.h"
typedef struct
{
    /* data */
    MenuImage assets;
    int run;
    int quit;
    int play;
} MenuGame;

typedef struct
{
    OptionImage assets;
    int graphics;
    int sound;
    int buttons;
    int menu;
} OptionGame;

typedef struct
{
    /* data */
    GameImage assets;
    int death;
    int health;
} Game;


void InitOptions();
void screeninit(SDL_Surface *screen);
void init();
void menup(SDL_Event event,int run);
int menu(MenuGame *menugame,SDL_Surface *screen,int run);
int game(int run);
int options(int run);

#endif // GAME_H