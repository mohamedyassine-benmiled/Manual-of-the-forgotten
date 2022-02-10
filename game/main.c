#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main (int argc , char *argv[])
{

 SDL_Surface *ecran = NULL ;
 SDL_Surface *ecran2 = NULL;
 SDL_Surface *ecran3 = NULL;
 SDL_Surface *menu = NULL ;
 SDL_Surface *BUTTON1 = NULL ;
 SDL_Surface *BUTTON2 = NULL ;
 SDL_Surface *BUTTON3 = NULL ;
 SDL_Surface *LOGO1 = NULL ;
 SDL_Surface *LOGO2 = NULL ;
 SDL_Surface *BackgroundOptions = NULL ;
 SDL_Surface *GameBackground = NULL ;
 SDL_Rect positionMenu ;
 SDL_Rect positionBackgroundOptions;
 SDL_Rect positionGameBackground;
 SDL_Rect positionButton1;
 SDL_Rect positionButton2;
 SDL_Rect positionButton3;
 SDL_Rect positionLogo1;
 SDL_Rect positionLogo2;
 int cont = 3 ;
 int options = 0;
 int play = 0;
 SDL_Event event ;

 SDL_Init(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(IMG_Load("Menu/Logo.png"),NULL);
        ecran = SDL_SetVideoMode(1920,1080,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        SDL_WM_SetCaption("Manual of the forgotten",NULL);
        ecran2 = SDL_SetVideoMode(1920,1080,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        ecran3 = SDL_SetVideoMode(1920,1080,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
menu = IMG_Load("Menu/grey_Background.png");
positionMenu.x=0;
positionMenu.y=0;
BackgroundOptions = IMG_Load("Menu/Placeholder_Background.png");
positionBackgroundOptions.x=0;
positionBackgroundOptions.y=0;
GameBackground = IMG_Load("Menu/Game_Background.png");
positionGameBackground.x=0;
positionGameBackground.y=0;
BUTTON1 = IMG_Load("Menu/Play2.png");
positionButton1.x=129;
positionButton1.y=374;
BUTTON2 = IMG_Load("Menu/Options2.png");
positionButton2.x=129;
positionButton2.y=512;
BUTTON3 = IMG_Load("Menu/Quit2.png");
positionButton3.x=129;
positionButton3.y=661;
LOGO1 = IMG_Load("Menu/Logo.png");
positionLogo1.x=220;
positionLogo1.y=74;
LOGO2 = IMG_Load("Menu/Logo.png");
positionLogo2.x=1690;
positionLogo2.y=857;
while(cont)
{

    SDL_WaitEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        cont=0;
        break;
     case SDL_KEYDOWN:

     switch (event.key.keysym.sym)
     {
       case (SDLK_ESCAPE):
         cont = 0;
         break;
       
         case (SDLK_o):
         cont=2;
         options = 1;
         while(options)
        {
          SDL_BlitSurface(BackgroundOptions,NULL,ecran2,&positionBackgroundOptions);
          SDL_Flip(ecran2);
        }
        SDL_FreeSurface(BackgroundOptions);
        break;
      case (SDLK_p):
        cont=2;
        play=2;
        while (play)
        {
          SDL_BlitSurface(GameBackground,NULL,ecran3,&positionGameBackground);
          SDL_Flip(ecran3);
        }
        SDL_FreeSurface(GameBackground);
        break;
     }


        break;
    }





SDL_BlitSurface(menu,NULL,ecran,&positionMenu);
SDL_BlitSurface(menu,NULL,ecran,&positionMenu);
SDL_BlitSurface(BUTTON1,NULL,ecran,&positionButton1);
SDL_BlitSurface(BUTTON2,NULL,ecran,&positionButton2);
SDL_BlitSurface(BUTTON3,NULL,ecran,&positionButton3);
SDL_BlitSurface(LOGO1,NULL,ecran,&positionLogo1);
SDL_BlitSurface(LOGO2,NULL,ecran,&positionLogo2);

SDL_Flip(ecran);


}
SDL_FreeSurface(menu);
SDL_FreeSurface(BUTTON1);
SDL_FreeSurface(BUTTON2);
SDL_FreeSurface(BUTTON3);
SDL_FreeSurface(LOGO1);
SDL_FreeSurface(LOGO2);
SDL_Quit();
return EXIT_SUCCESS;







}

