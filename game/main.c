#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"
#include "include/text.h"
#include "include/image.h"
#include "include/sound.h"
#include "include/menu.h"
#include "include/init.h"

int main (int argc , char *argv[])
{
//Definition MenuGame
  MenuGame mainmenu;
  OptionGame optionmenu;
  
//Definition Screens
 SDL_Surface *screenmenu = NULL ;
 SDL_Surface *screengame = NULL;
  
 int run = 1 ;

//SDL_INIT and game caption and icon
   initvideo();
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) //SDL_Mixer Init
    {
        printf("[-] %s", Mix_GetError());
    }
    	Mix_VolumeMusic(MIX_MAX_VOLUME/8);
//ScreenInit
  screenmenu = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
  screengame = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
//Initialisation Buttons
while(run)
{
switch (run)
  {
    case 1:
        run=menu(&mainmenu,screenmenu,run);
    break;
    case 2:
        run=options(&optionmenu,screenmenu,run);
    break;
    case 3:
        run=0;
        //run=game();
    break;

  }
}

 SDL_Quit();
 return EXIT_SUCCESS;

 }









