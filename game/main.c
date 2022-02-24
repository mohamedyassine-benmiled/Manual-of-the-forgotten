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

//Main Code
int main (int argc , char *argv[])
{
  FILE *f;
//Definition MenuGame
  MenuGame mainmenu;
  OptionGame optionmenu;
  settings config;
//Definition Screens
 SDL_Surface *screenmenu = NULL ;
//Initialize on Menu
 int run = 1 ;
 //Check if config file exits else create it
 f = fopen("config/config.cfg", "r");
    //Get Config Values
    if (f) 
    {
        fclose(f);
        get_config(&config);
    }
    else
    //Set Default Config and Write it
    {
      config.resolution_w=1920;
      config.resolution_h=1080;
      config.fullscreen=0;
      config.volume=5;
      config.audio=1;
      write_config(&config);
    }

//SDL_INIT and game caption and icon and sound
   initvideo();
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) //SDL_Mixer Init
    {
        printf("[-] %s", Mix_GetError());
    }
    Mix_VolumeMusic(set_audio(config.volume,config.audio));

//ScreenInit
if (config.fullscreen)
{
    screenmenu = SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
    SDL_WM_ToggleFullScreen(screenmenu);
}
else
{
    screenmenu = SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
}
//Game Loop
while(run)
{
switch (run)
  {
    case 1://Menu Run
        run=menu(&mainmenu,screenmenu,run);
    break;
    case 2://Menu Option
        run=options(&optionmenu,screenmenu,run);
    break;
    case 3://Game
        run=game(screenmenu,run);
    break;

  }
}
//Freeing Screens
SDL_FreeSurface(screenmenu);
//Closing Audio
SDL_CloseAudio();
//Quitting
SDL_Quit();
 return EXIT_SUCCESS;
 }
