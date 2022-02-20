#ifndef INIT_H
#define INIT_H

#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "game.h"
#include "menu.h"

typedef struct 
{
    /* data */
    FILE *f;
    int resolution_w;
    int resolution_h;
    int fullscreen;
    int audio;
} settings;


void initsettings();
void initvideo();
void initmenu(MenuImage *assets);
void initoption(OptionImage *assets);



#endif // INIT_H