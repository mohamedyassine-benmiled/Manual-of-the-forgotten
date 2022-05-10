/**
 * @file init.h
 * @author TMOF Team
 * @brief Initializing Initial Values
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
#include "enemy.h"
#include "character.h"
#include "declarations.h"

void initcharacter(Character *player);
void initcheck(CheckImage *assets);
void initvideo();
void initmenu(MenuImage *assets);
void initoption(OptionImage *assets);
void initaudio(audioimage *assets);
void initgraphics(graphicimage *assets);
void initbackground(Background *assets);
void initennemy (Enemy *enemi);
void initplay (playimage *assets);
#endif // INIT_H