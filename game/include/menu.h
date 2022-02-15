#ifndef MENU_H
#define MENU_H

#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
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

int menu(MenuGame *menugame,SDL_Surface *screen,int run);
int options(OptionGame *optiongame,SDL_Surface *screen,int run);


#endif // MENU_H