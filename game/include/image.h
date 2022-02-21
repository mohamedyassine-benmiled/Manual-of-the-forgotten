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
    image play[3];
    image options[3];
    image quit[3];
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
    //image window;
    //image buttoncircle;
    //image border;
    //Graphics ****
    image selectres;
    image windowsettings;
    image firstbox[2];
    image secondbox[2];
    image fullscreen;
    image windowed;
    image boxresolution;
    image currentresolution;
    image listresolution;
    image listresolutionbox[2];
    //Audio ****
    image volume;
    image audiotext;
    image onbox[2];
    image offbox[2];
    image on;
    image off;
    image circle[10];
    image bar;
    image plus;
    image minus;
    //Keybinds ****
    image table;
    image textbutton[9];
    image keybind[9];

    //Settings ****
    image background;
    image obook[15]; 
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
void freemenu(MenuImage assets);
void freeoption(OptionImage assets);
int hoverbutton(int x,int y, image img );
#endif // IMAGE_H