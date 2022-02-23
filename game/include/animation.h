#ifndef ANIMATION_H
#define ANIMATION_H
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "game.h"
#include "image.h"

int hoverbutton(int x,int y, image img );
int animatehover(int x,int y,image img,image img2,SDL_Surface *screen);

#endif // ANIMATION_H