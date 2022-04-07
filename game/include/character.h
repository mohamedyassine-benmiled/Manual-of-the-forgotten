#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED
#include "collision.h"
#include "game.h"

typedef struct
{
    SDL_Surface *image;
    SDL_Rect position, src_pos, relativePos;
    int look, spritestate;
    int life, died;
    int elapsed;
    /* Variables */
    int health, direction, speed, atk, hp;
    /* Inputs */
    int cda1; //Cooldown Attack1
    int cda2; //Cooldown Attack2
    int cdsj; //Cooldown Special Jump
    int cdjump; //Cooldown Jump
    Input input;
}Character;

#endif // CHAR_H_INCLUDED