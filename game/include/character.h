#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "collision.h"


typedef struct
{
    //Movement
    int up;
    int down;
    int right;
    int left;
    int startJump;
    int jumpHeight;
    int reset;
    int fix;
    int movement;
    //Attacks
    int a1; //ATTACK1
    int a2; //ATTACK2
    int sj; //SPECIAL JUMP
    //Cheats for developer testing
    int ih;
    } Input;

typedef struct
{
    SDL_Surface *image;
    SDL_Rect position, src_pos, relativePos;
    Box pos_box;
    Cercle pos_cercle;
    int look, spritestate;
    int animation;
    int life, died;
    int elapsed;
    /* Variables */
    int health, direction, speed, atk;
    /* Inputs */
    int cda1; //Cooldown Attack1
    int cda2; //Cooldown Attack2
    int cdsj; //Cooldown Special Jump
    int cdjump; //Cooldown Jump
    //Input input;
    Input input;
}Character;

#endif // CHAR_H_INCLUDED