/**
 * @file animation.h
 * @author TMOF Team
 * @brief States and button hover
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ANIMATION_H
#define ANIMATION_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "image.h"

typedef struct 
{
    /* data */
    int stopdisplay;
    int EOL;
    int level;
    int firstplayer;
    int lastplayer;
    int cinematic;
    int checkpoint;
    int dropboss;
    int movement;
    int elapsed;
} States;


int hoverbutton(int x,int y, image img);
int animatehover(int x,int y,image img,image img2,SDL_Surface *screen);

#endif // ANIMATION_H