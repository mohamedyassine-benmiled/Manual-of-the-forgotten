#ifndef ENEMY_H
#define ENEMY_H
#include "collision.h"


typedef struct
{
SDL_Surface *image;
SDL_Rect position;
SDL_Rect position2;
int right , left ;
int mouvement ;
int posMax ;
int posMin ;
int reset ; 
int look, spritestate;
int animation ;
int direction ;  
}Enemy;
void deplacement_enemy (Enemy *enemi );
void animationenemy(Enemy *enemi);
#endif // ENEMY_H