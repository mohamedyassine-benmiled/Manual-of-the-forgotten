#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main (int argc , char *argv[])
{
 SDL_Surface *ecran = NULL ; 
 SDL_Surface *menu = NULL ; 

 SDL_Rect positionMenu ; 
 int cont = 3 ; 
 SDL_Event event ; 

 SDL_Init(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(IMG_Load("Menu/Logo.png"),NULL);
        ecran = SDL_SetVideoMode(952,442,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        SDL_WM_SetCaption("",NULL);

menu = IMG_Load("Menu/Game_Background.png");
positionMenu.x=0;
positionMenu.y=0;
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
     case SDLK_ESCAPE:
         cont = 0 ; 
         break;
     }
    

        break;
    }





SDL_BlitSurface(menu,NULL,ecran,&positionMenu);
SDL_Flip(ecran);


}
SDL_FreeSurface(menu);
SDL_Quit();
return EXIT_SUCCESS;







}

