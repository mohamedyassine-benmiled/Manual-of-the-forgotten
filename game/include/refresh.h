/**
 * @file refresh.h
 * @author TMOF Team
 * @brief Refresh management
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "character.h"
#include "enemy.h"
#include "game.h"
#ifndef REFRESH_H
#define REFRESH_H
void playerrefresh(Character *player);
void enemyrefresh(Enemy *enemi);
void gamerefresh(Game *g,SDL_Surface *screen);


#endif