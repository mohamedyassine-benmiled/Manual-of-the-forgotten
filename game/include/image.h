#ifndef IMAGE_H
#define IMAGE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct
{
    SDL_Surface *surface ;
    SDL_Rect pos1;
    SDL_Rect pos2;
} image;

void initPlayer(image *p);
void initBackground(image *b,char img[]);
void freesurface(image a);
void show (image p,SDL_Surface *screen);


#endif // IMAGE_H