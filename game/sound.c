#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "include/game.h"
#include "include/text.h"
#include "include/image.h"
#include "include/sound.h"

//Volume Set
int set_audio(int volume,int audio)
{    
//If audio on
if (audio)
{
    //Return Volume
    switch (volume)
        {
            case 0:
                return(0);
            case 1:
                return(13);
            case 2:
                return(26);
            case 3:
                return(38);
            case 4:
                return(51);
            case 5:
                return(64);
            case 6:
                return(77);
            case 7:
                return(90);
            case 8:
                return(102);
            case 9:
                return(115);
        }
}
else
    {
    return 0;
    }
    //Return if no volume
    return 128;

}