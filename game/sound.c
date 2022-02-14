#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "include/game.h"
#include "include/text.h"
#include "include/image.h"
#include "include/sound.h"
void initson()
{
  son * sound;
    sound= Mix_LoadWAV("soundeffect.wav"); //Chargement de sound effect
    Mix_PlayChannel(-1,sound, 0); 
}
void freesound()
{
    Mix_FreeChunk(sound);
}
int Mix_OpenAudio()
{
    music *musique;
    musique = Mix_LoadMUS("backgroundmusic.mp3"); //Chargement de la musique

    Mix_VolumeChunk(son, MIX_MAX_VOLUME/8);
    Mix_VolumeMusic(MIX_MAX_VOLUME/4);
    Mix_PlayMusic(musique, -1);
}