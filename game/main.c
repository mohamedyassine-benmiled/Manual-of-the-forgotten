#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"
#include "include/text.h"
#include "include/image.h"


int main (int argc , char *argv[])
{
//Definition Background
  image BackgroundMenu;
  image BackgroundOptions;
  image BackgroundGame;
//Definition Logo
  image LogoGame;
  image LogoGroup;

//Definition Buttons
  image BUTTON1;
  image BUTTON2;
  image BUTTON3;
//Definition Screens
 SDL_Surface *screenmenu = NULL ;
 SDL_Surface *screenoptions = NULL;
 SDL_Surface *screengame = NULL;

 int run = 3 ;
  int play = 0;
  int options = 0;
 SDL_Event event ;
//SDL_INIT and game caption and icon
   init();
   
//ScreenInit
  screenmenu = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
  screengame = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
  screenoptions = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
  


//Initialisation Background
//initBackground(&BackgroundMenu,"Menu/grey_background.png");
BackgroundMenu.surface = IMG_Load("Menu/grey_Background.png");
BUTTON1.pos1.x=0;
BUTTON1.pos1.y=0;

initBackground(&BackgroundOptions,"Menu/Placeholder_Background.png");
initBackground(&BackgroundGame,"Menu/Placeholder_Background.png");


BUTTON1.surface = IMG_Load("Menu/Play2.png");
BUTTON1.pos1.x=129;
BUTTON1.pos1.y=374;
BUTTON2.surface = IMG_Load("Menu/Options2.png");
BUTTON2.pos1.x=129;
BUTTON2.pos1.y=512;
BUTTON3.surface = IMG_Load("Menu/Quit2.png");
BUTTON3.pos1.x=129;
BUTTON3.pos1.y=661;
LogoGame.surface = IMG_Load("Menu/Logo.png");
LogoGame.pos1.x=220;
LogoGame.pos1.y=74;
LogoGroup.surface = IMG_Load("Menu/Logo.png");
LogoGroup.pos1.x=1690;
LogoGroup.pos1.y=857;
while(run)
{
    //waitforinput(run);
    SDL_WaitEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        run=0;
        break;
    case SDL_KEYDOWN:
    switch (event.key.keysym.sym)
     {
       case (SDLK_ESCAPE):
         run = 0;
         break;
       
         case (SDLK_o):
         run=2;
         options = 1;
         while(options)
        {
          show(BackgroundOptions,screenoptions);
          SDL_Flip(screenoptions);
        }
        freesurface(BackgroundOptions);
      
        break;
      case (SDLK_p):
        run=2;
        play=2;
        while (play)
        {
          show(BackgroundGame,screengame);
          SDL_Flip(screengame);
        }
        freesurface(BackgroundGame);
        break;
     }
        break;
    }


    SDL_BlitSurface(BackgroundMenu.surface,NULL,screenmenu,&BackgroundMenu.pos1);
   //show(BackgroundMenu,screenmenu);
   show(BUTTON1,screenmenu);
   show(BUTTON2,screenmenu);
   show(BUTTON3,screenmenu);
   show(LogoGame,screenmenu);
   show(LogoGroup,screenmenu);
   SDL_Flip(screenmenu);
   }
 freesurface(BackgroundMenu);
 freesurface(BUTTON1);
 freesurface(BUTTON2);
 freesurface(BUTTON3);
 freesurface(LogoGame);
 freesurface(LogoGroup);
 SDL_Quit();
 return EXIT_SUCCESS;

 }








