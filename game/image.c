#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/image.h"
#include "include/game.h"

void initPlayer(image *p)
{

}



void initBackground(image *b,char img[])
{
    b->surface= IMG_Load(img);
    b->pos1.x=0;
    b->pos1.y=0;
    b->pos2.x=0;
    b->pos2.y=0;
    b->pos2.w=1920;
    b->pos2.h=1080;
}



void freesurface(image a)
{
    SDL_FreeSurface(a.surface);
}



void show(image p,SDL_Surface *screen)
{
    SDL_BlitSurface(p.surface,NULL,screen,&p.pos1);
}

