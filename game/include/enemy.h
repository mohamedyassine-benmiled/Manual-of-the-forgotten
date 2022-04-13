#ifndef ENEMY_H
#define ENEMY_H
#include "game.h"
typedef struct
{
SDL_Surface *mvt_av[8];
SDL_Surface *mvt_back[8];
}mouvement;

typedef struct
{
SDL_Surface *image;
SDL_Rect position;
int direc;
int i;
int j;
int posMax;
int posMin;
int actif;
mouvement mvt;
}enemy;

#endif // ENEMY_H