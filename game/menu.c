#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "include/menu.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
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
void initson()
{
    
  son *sound;
    sound= Mix_LoadWAV("soundeffect.wav"); //Chargement de sound effect
    Mix_PlayChannel(-1,sound, 0); 
}
void freesound()
{son sound;
    Mix_FreeChunk(sound);
}
void play_music(Music *musique)
{
    Mix_PlayMusic(musique->ambient, -1);
	Mix_VolumeMusic(MIX_MAX_VOLUME/5);
}