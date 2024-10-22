/**
 * @file enemy.h
 * @author Ilyes Chaabani
 * @brief Enemy Animation and Movement
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ENEMY_H
#define ENEMY_H
#include "collision.h"


typedef struct
{
SDL_Surface *image;
SDL_Rect position;
SDL_Rect position2;
SDL_Rect rpos;
Box pos_box;
int right , left ;
int elapsed;
int mouvement ;
int posMax ;
int posMin ;
int enemy;
int spotted;
int reset ; 
int look, spritestate;
int attack;
int animation ;
int direction ;  
}Enemy;
void animationenemy(Enemy *enemi);
#endif // ENEMY_H