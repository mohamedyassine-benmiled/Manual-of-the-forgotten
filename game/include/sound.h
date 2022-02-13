#ifndef SOUND_H
#define SOUND_H
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

typedef struct Music
{
	Mix_Music *ambient;

}Music;
#endif // SOUND_H