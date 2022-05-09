/**
 * @file sound.h
 * @author TMOF Team
 * @brief Sound Functions
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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

}music;
int set_audio(int volume,int audio);

#endif // SOUND_H