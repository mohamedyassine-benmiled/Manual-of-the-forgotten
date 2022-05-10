/**
 * @file game.h
 * @author TMOF Team
 * @brief Game Management
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
#include <SDL/SDL.h>
#include "image.h"
#include "init.h"
#include "menu.h"
#include "animation.h"
#include "collision.h"
#include "enemy.h"
#include "animation.h"
#include "character.h"

typedef struct
{
    image bg,score;
    Character player[4];
    Enemy enemy[10];
    int elapsed;
    int level;
} Minimap;

typedef struct
{
    Character player[4];
    Enemy enemy[10];
    Background bg;
    Minimap minimap;
    States global;
} Game;

int game(SDL_Surface *screen,int run,int state);
SDL_Color getpixel(SDL_Surface *psurface,int x,int y);
int collisionparfaite(SDL_Surface *psurface,Game p);
void initBack (Game *b);
void afficheBack (Game b, SDL_Surface *ecran);
int relative_x( Background *bg , SDL_Rect position);
#endif // GAME_H