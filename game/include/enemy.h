#ifndef ENEMY_H
#define ENEMY_H
#include "game.h"
typedef enum Behavior
{
PATROL, FOLLOW, ATTACK, REFRACT
}Behavior;

typedef struct 
{
    SDL_Surface *image;
    SDL_Rect pos, src_pos, relativePos;
    Cercle pos_cercle;
    int life, died;
    int elapsed;
    int direction, speed;

}Enemy;



typedef struct Character
{
    SDL_Surface *image;
    SDL_Rect position, src_pos, relativePos;
    int look, spritestate;
    int state;
    /* Variables */
    int health, direction, speed, atk, health;
    /* Inputs For Developers*/
    Input input;
    /* Behavior */
    Behavior behavior;
}Character;

#endif // ENEMY_H