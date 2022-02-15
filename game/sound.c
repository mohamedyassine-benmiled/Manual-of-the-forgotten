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