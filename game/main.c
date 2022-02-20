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

int write_config(settings *config)
{
    config->f=NULL;
     config->f=fopen("config/config.cfg","w");
    if (config->f!=NULL)
    {
        fprintf(config->f,"[resolution]\n");
        fprintf(config->f,"w=%d\n",config->resolution_w);
        fprintf(config->f,"h=%d\n",config->resolution_h);
        fprintf(config->f,"fullscreen=%d\n",config->fullscreen);
        return 0;
        fclose(config->f);
    }
    else
    {
        fclose(config->f);
        return -1;
    }
}

int get_config(settings *config)
{
  config->f=NULL;
   config->f=fopen("config/config.cfg","r");
    if (config->f!=NULL)
    {
        fscanf(config->f,"[resolution]\n");
        fscanf(config->f,"w=%d\n",&config->resolution_w);
        fscanf(config->f,"h=%d\n",&config->resolution_h);
        fscanf(config->f,"fullscreen=%d\n",&config->fullscreen);
        return 0;
    }
    else
        return -1;

}

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
    if (f = fopen("config/config.cfg", "r")) 
    {
        fclose(f);
        get_config(&config);
    }
    else
    {
      config.resolution_w=1920;
      config.resolution_h=1080;
      config.fullscreen=0;
      write_config(&config);
    }

//SDL_INIT and game caption and icon
   initvideo();
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) //SDL_Mixer Init
    {
        printf("[-] %s", Mix_GetError());
    }
    	Mix_VolumeMusic(MIX_MAX_VOLUME/8);
//ScreenInit
if (config.fullscreen)
{
  screenmenu = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_FULLSCREEN);
    screengame = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_FULLSCREEN);
}
else
{
    screenmenu = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
      screengame = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
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









