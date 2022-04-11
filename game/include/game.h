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
    Character player[4];
    Enemy enemy[10];
    Background bg;
    Minimap minimap;
    States global;
} Game;

int game(SDL_Surface *screen,int run);


#endif // GAME_H