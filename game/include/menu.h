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
    int hover;
    int run;
    int press;
    int state;
    Mix_Music *Music;
    Mix_Chunk *soundbutton;

} MenuGame;

typedef struct
{
    OptionImage assets;
    int graphics;
    int hover;
    int sound;
    int buttons;
    int menu;
    Mix_Chunk *soundbook;
    Mix_Chunk *soundflip;
} OptionGame;


int menu(MenuGame *menugame,SDL_Surface *screen,int run);
int options(OptionGame *optiongame,SDL_Surface *screen,int run);


#endif // MENU_H