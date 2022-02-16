#ifndef IMAGE_H
#define IMAGE_H
#include <SDL/SDL_image.h>
typedef struct
{
    SDL_Surface *surface ;
    SDL_Rect pos1;
    SDL_Rect pos2;
} image;

typedef struct 
{
    /* Menu Assets */
    image play[2];
    image options;
    image quit;
    image background;
    image logo;
    image logogroup;
} MenuImage;

typedef struct
{
    /* Options Assets */
    image logo;
    image logogroup;
    image graphics;
    image sound;
    image buttons;
    image window;
    image buttoncircle;
    image border;
    image background;
} OptionImage;

typedef struct
{
    /* Options Assets */
    image background;
    image character;
    image health;
    image itemholding;
    image inventory;
} GameImage;
void initPlayer(image *p);
void initBackground(image *b,char img[]);
void freesurface(image a);
void show (image p,SDL_Surface *screen);
int hoverbutton(int x,int y, image img );
#endif // IMAGE_H