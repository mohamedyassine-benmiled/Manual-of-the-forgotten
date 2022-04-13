#ifndef ENEMY_H
#define ENEMY_H
#include "image.h"
typedef enum Behavior
{
PATROL, FOLLOW, ATTACK, REFRACT
}Behavior;



typedef struct
{
    SDL_Surface *image;
    SDL_Rect position, src_pos, relativePos;
    int look, spritestate;
    int state;
    /* Variables */
    int health, direction, speed, atk;
    /* Inputs For Developers*/
    //Input input;
    /* Behavior */
    Behavior behavior;
} Enemy;

#endif // ENEMY_H