#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <sdl_image.h>

int main (int argc , char *argv)[])
{
 SDL_Surface *ecran =NULL ; 
 SDL_Surface *menu = NULL ; 

 SDL_Rect positionMenu ; 
 int continue = 3 ; 
 SDL_Event event ; 

 SDL_INIT(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(IMG_Load(),NULL);
        ecran = SDL_SetVideoMode(,,,,SDL_Surface|SDL_DOUBLEBUF);
        SDL_WM_SetCaption("",NULL);

menu = IMG_Load("");
positionMenu.x=0;
positionMenu.y=0;
while(continue)
{
    SDL_WaitEvent(&event);
    switch (even.type)
    {
    case SDL_Quit:
        continue=0; 
        break;
     case SDL_KEYDOWN:
     switch (event.key.keysym.sym)
     {
     case sdlk_escape:
         continue =0 ; 
         break;
     
     }
    

        break;
    }





SDL_BlitSurface( menu,NULL,ecran,&positionMenu);
SDL_Flip(ecran);


}
SDL_FreeSurface(menu);
SDL_quit();
return EXIT_SUCCESS;







})

