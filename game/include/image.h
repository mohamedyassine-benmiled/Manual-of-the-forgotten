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
    image Window;
    image Apply;
    image Quit;
    image Yes[2];
    image No[2];
} CheckImage;

typedef struct 
{
    /* Menu Assets */
    image play[2];
    image options[2];
    image quit[2];
    image background;
    image cbook[13];
    image logo[4];
    image logogroup;
    image copyright;
} MenuImage;

typedef struct
{
    /* Options Assets */
    image logo;
    image logogroup;
    image graphics[2];
    image audio[2];
    image keybinds[2];
    //Graphics ****


    //Settings ****
    image background;
    image obook[15]; 
} OptionImage;

typedef struct 
{
    /* data */
    image selectresolution;
    image windowsettings;
    image firstbox[2];
    image secondbox[2];
    image fullscreen;
    image windowed;
    image boxresolution;
    image currentresolution;
    image listresolution;
    image listresolutionbox[2];
} graphicimage;


typedef struct 
{
    /* data */
    image volume;
    image audio;
    image onbox[2];
    image offbox[2];
    image on;
    image off;
    image circle[10];
    image audiobar;
    image plus;
    image minus;
} audioimage;

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
void freemenu(MenuImage assets);
void freeoption(OptionImage assets);
void freegraphics(graphicimage assets);
void freeaudio(audioimage assets);

int hoverbutton(int x,int y, image img );
#endif // IMAGE_H