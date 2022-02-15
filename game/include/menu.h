#ifndef MENU_H
#define MENU_H

#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>

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
    image graphics;
    image sound;
    image buttons;
    image window;
    image buttoncircle;
    image border;
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
typedef struct 
{
	Mix_Chunk *sound;

}son;
typedef struct Music
{
	Mix_Music *ambient;

}Music;


void initPlayer(image *p);
void initBackground(image *b,char img[]);
void freesurface(image a);
void show (image p,SDL_Surface *screen);
void initson()
void freesound()
void play_music(Music *musique)

#endif // MENU_H