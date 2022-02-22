#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "include/game.h"
#include "include/text.h"
#include "include/image.h"
#include "include/sound.h"
    /*
void initson()
{

  son sound;
    sound= Mix_LoadWAV("soundeffect.wav"); //Chargement de sound effect
    Mix_PlayChannel(-1,sound, 0); 
}

void freesound()
{
    Mix_FreeChunk(sound);
}

}
void play_music(Music *musique)
{
    Mix_PlayMusic(musique->ambient, -1);
	Mix_VolumeMusic(MIX_MAX_VOLUME/5);

}    */
int set_audio(int volume,int audio)
{    if (audio)
{
switch (volume)
    {
        case 1:
            return(0);
        case 2:
            return(13);
        case 3:
            return(26);
        case 4:
            return(38);
        case 5:
            return(51);
        case 6:
            return(64);
        case 7:
            return(77);
        case 8:
            return(90);
        case 9:
            return(102);
        case 10:
            return(115);
    }
}
    else
    return 0;
    return 128;

}