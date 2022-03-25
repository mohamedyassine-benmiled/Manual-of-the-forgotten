#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
#include <SDL/SDL.h>
#include "image.h"
#include "init.h"
#include "menu.h"
#include "animation.h"
#include "collision.h"

typedef enum Behavior
{
PATROL, FOLLOW, ATTACK, REFRACT
}Behavior;

typedef struct Character
{
    SDL_Surface *image;
    SDL_Rect pos, src_pos, relativePos;
    Cercle pos_cercle;
    int life, died;
    int elapsed;
    int direction, speed;
    Behavior behavior;
}Character;


int game(SDL_Surface *screen,int run);


#endif // GAME_H