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
SDL_Color getpixel(SDL_Surface *pSurface,int x,int y);


#endif // COLLISION_H_INCLUDED
