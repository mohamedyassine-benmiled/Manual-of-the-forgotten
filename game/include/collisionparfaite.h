#ifndef collisionparfaite_H_INCLUDED
#define collisionparfaite_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
 

SDL_Color getpixel(SDL_Surface *psurface,int x,int y);
int collisionparfaite(SDL_Surface *psurface,Personne perso);
void collision(SDL_Surface *psurface,Personne *perso);
#endif
