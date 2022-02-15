#ifndef SOUND_H
#define SOUND_H
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
typedef struct 
{
	Mix_Chunk *sound;

}son;
typedef struct Music
{
	Mix_Music *ambient;

}Music;
void initson();
void freesound();
void play_music(Music *musique);

#endif // SOUND_H