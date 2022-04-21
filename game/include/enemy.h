#ifndef ENEMY_H
#define ENEMY_H
#include "collision.h"


typedef struct
{
SDL_Surface *image;
SDL_Rect position;
SDL_Rect position2;
SDL_Rect rpos ;
int right , left ;
int mouvement ;
int posMax ;
int posMin ;
int reset ; 
int look, spritestate;
int animation ;
int direction ;  
}Enemy;
typedef struct{
int x;
int y;
int w;
int h;
}box;
void deplacement_enemy (Enemy *enemi );
void animationenemy(Enemy *enemi);
#endif // ENEMY_H