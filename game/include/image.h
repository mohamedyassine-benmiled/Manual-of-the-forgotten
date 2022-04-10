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
    image img;
    SDL_Surface *collision;
    int scroll_x;
    int scroll_y;
} Background;

typedef struct
{
    image bg;
    image pp[4];
    image enemy[10];
    int scroll_x;
    int scroll_y;
    int level;
} Minimap;
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
    image arrow[2];
    image graphics[2];
    image audio[2];
    image keybinds[2];
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
    image circle[11];
    image audiobar;
    image plus;
    image minus;
} audioimage;

typedef struct 
{   
    image playwindow;
    image newgame[2];
    image cont[3];
    image back[2]; 
} playimage;

void menurefresh(MenuImage *assets,SDL_Surface *screen);
void graphicsrefresh(graphicimage *assets,SDL_Surface *screen,int fullscreen);
void audiorefresh(audioimage *assets,SDL_Surface *screen,int audio);
void optionrefresh(OptionImage *assets,SDL_Surface *screen);
void show (image p,SDL_Surface *screen);
void showgame (image p,SDL_Surface *screen);
void freemenu(MenuImage assets);
void freeoption(OptionImage assets);
void freegraphics(graphicimage assets);
void freebackground(Background assets);
void freeaudio(audioimage assets);
void freecheck(CheckImage assets);
int hoverbutton(int x,int y, image img );
#endif // IMAGE_H