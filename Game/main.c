#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main (int argc , char *argv[])
{
 SDL_Surface *ecran = NULL ; 
 SDL_Surface *menu = NULL ; 
 SDL_Surface *button1 = NULL ; 
 SDL_Rect positionMenu ; 
 SDL_Rect positionButton1 ; 
 int cont = 3 ; 
 SDL_Event event ; 

 SDL_Init(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(IMG_Load("Menu/Logo.png"),NULL);
        ecran = SDL_SetVideoMode(1920,1080,32, SDL_HWSURFACE | SDL_DOUBLEBUF );
        SDL_WM_SetCaption("Manual of the forgotten",NULL);

menu = IMG_Load("Menu/grey_Background.png");
positionMenu.x=0;
positionMenu.y=0;
button1 = IMG_Load("Menu/PlayFirstTest.png");
positionButton1.x=129;
positionButton1.y=374;
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
       case (SDLK_f):
        cont = 1; 
        break ;
       case (SDLK_o):
        cont=2; 
        break ; 
     }
    

        break;
    }





SDL_BlitSurface(menu,NULL,ecran,&positionMenu);
SDL_BlitSurface(button1,NULL,ecran,&positionButton1);
SDL_Flip(ecran);


}
SDL_FreeSurface(menu);
SDL_FreeSurface(button1);
SDL_Quit();
return EXIT_SUCCESS;







}

