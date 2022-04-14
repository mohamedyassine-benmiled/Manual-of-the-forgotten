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
    image bg;
    Character player[4];
    Enemy enemy[10];
    int scroll_x;
    int scroll_y;
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

int game(SDL_Surface *screen,int run);
SDL_Color getpixel(SDL_Surface *psurface,int x,int y);
int collisionparfaite(SDL_Surface *psurface,Game p);
void initBack (Game *b);
void afficheBack (Game b, SDL_Surface *ecran);

#endif // GAME_H