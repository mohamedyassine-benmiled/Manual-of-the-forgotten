/**
 * @file collision.c
 * @author Wael Bechraoui
 * @brief Collision Structures
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct Box
{
int x,y;
int h,w;
}Box;


typedef struct Cercle
{
int x,y;
int r;
}Cercle;



#endif // COLLISION_H_INCLUDED
