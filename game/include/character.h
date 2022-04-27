/**
 * @file character.c
 * 
 * @author Mohamed Yassine Ben Miled
 * @brief Character Movement and Animation
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "collision.h"
#include "declarations.h"



typedef struct
{
    SDL_Surface *image;
    SDL_Rect position, src_pos, relativePos;
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