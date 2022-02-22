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
#include "include/config.h"


int main (int argc , char *argv[])
{
  FILE *f;
//Definition MenuGame
  MenuGame mainmenu;
  OptionGame optionmenu;
  settings config;
//Definition Screens
 SDL_Surface *screenmenu = NULL ;
 SDL_Surface *screengame = NULL;
  
 int run = 1 ;
 f = fopen("config/config.cfg", "r");
    if (f) 
    {
        fclose(f);
        get_config(&config);
    }
    else
    {
      config.resolution_w=1920;
      config.resolution_h=1080;
      config.fullscreen=0;
      config.volume=5;
      config.audio=1;
      write_config(&config);
    }

//SDL_INIT and game caption and icon
   initvideo();

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) //SDL_Mixer Init
    {
        printf("[-] %s", Mix_GetError());
    }
   
    Mix_VolumeMusic(set_audio(config.volume,config.audio));
            optionmenu.soundbutton=Mix_LoadWAV("sfx/button.ogg"); //Chargement de sound effect
            mainmenu.Music=Mix_LoadMUS("sfx/menu.ogg");
            mainmenu.soundbutton=Mix_LoadWAV("sfx/button.ogg"); //Chargement de sound effect
    	Mix_VolumeChunk(mainmenu.soundbutton,set_audio(config.volume,config.audio));
          	Mix_VolumeChunk(optionmenu.soundbutton,set_audio(config.volume,config.audio));
//ScreenInit
if (config.fullscreen)
{
  screenmenu = SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_FULLSCREEN);
    screengame = SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_FULLSCREEN);
}
else
{
    screenmenu = SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
      screengame = SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
}
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
        run=2;
        //run=game();
    break;

  }
}

  SDL_FreeSurface(screenmenu);
  SDL_FreeSurface(screengame);
 SDL_CloseAudio();
 SDL_Quit();
 return EXIT_SUCCESS;

 }









