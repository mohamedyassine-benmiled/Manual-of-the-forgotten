#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED
#include "collision.h"
#include "game.h"

typedef struct Character
{
    SDL_Surface *image;
    SDL_Rect position, src_pos, relativePos;
    int look, spritestate;
    int life, died;
    int elapsed;
    /* Variables */
    int health, direction, speed, atk, hp;
    /* Inputs */
    int cda1;
    int cda2;
    int cdjump;
    Input input;
}Character;

#endif // CHAR_H_INCLUDED