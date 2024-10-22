/**
 * @file menu.h
 * @author TMOF Team
 * @brief Menu Functions
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MENU_H
#define MENU_H

#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "image.h"
#include "sound.h"

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
    int audio;
    int keybinds;
    int hover;
    int sound;
    int menu;
    Mix_Chunk *soundbutton;
    Mix_Chunk *soundbook;
    Mix_Chunk *soundflip;
} OptionGame;

int check(SDL_Surface *screen,int *run,int state);
int menu(MenuGame *menugame,SDL_Surface *screen,int run,int *state);
int options(OptionGame *optiongame,SDL_Surface *screen,int run);
int listres(OptionGame *optiongame,graphicimage *assets,SDL_Surface *screen,int *run);
int graphics(OptionGame *optiongame,OptionImage *assets,SDL_Surface *screen,int run);
int audio(OptionGame *optiongame,OptionImage *assets,SDL_Surface *screen,int run);
int playmenu(SDL_Surface *screen,int *run,int state);

#endif // MENU_H