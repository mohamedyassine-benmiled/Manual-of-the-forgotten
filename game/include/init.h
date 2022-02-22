#ifndef INIT_H
#define INIT_H

#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "game.h"
#include "menu.h"
#include "text.h"
#include "config.h"



void initsettings();
void initvideo();
void initmenu(MenuImage *assets);
void initoption(OptionImage *assets);
void initaudio(audioimage *assets);
void initgraphics(graphicimage *assets);


#endif // INIT_H