#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "include/menu.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "include/init.h"
#include "include/game.h"


int menu(MenuGame *menugame,SDL_Surface *screen,int run)
{
      int x,y,ins ;
    image Play,PlayOnHover ; 
    initmenu(menugame);
    SDL_Event event;
        show(menugame->assets.background,screen);
                        
        show(menugame->assets.play[0],screen);
        show(menugame->assets.options,screen);
        show(menugame->assets.quit,screen);
        show(menugame->assets.logo,screen);
        show(menugame->assets.logogroup,screen);
      SDL_Flip(screen);
    Mix_PlayMusic(menugame->Music, -1);
    while(run==1)
    {
    //Wait for event
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
                        run=0;
                    break;
                    case (SDLK_DOWN):
                        run=2;
                    break;
                    case (SDLK_UP):
                        run=2;
                    break;
                                        
                    default:
                        break;
                    }
        case SDL_MOUSEMOTION:
         SDL_GetMouseState(&x,&y);
            
                 if (hoverbutton(x,y,menugame->assets.play[0]))
                    {
                        
                        show(menugame->assets.play[1],screen);
                        SDL_Flip(screen);

                    }
                    else
                    {
                        SDL_FreeSurface(menugame->assets.play[0].surface);
                        show(menugame->assets.play[0],screen);
                        SDL_Flip(screen);
                    }

                break;
        
         case SDL_MOUSEBUTTONUP:
         SDL_GetMouseState(&x,&y);
            
                 if (hoverbutton(x,y,menugame->assets.play[0]))
                    {

                        Mix_PlayChannel(-1,menugame->soundbutton, 0); 
                    }



            
                break;
        }


    }
 return run;

}

int options(OptionGame *optiongame,SDL_Surface *screen,int run)
{
    initoption(optiongame);
        show(optiongame->assets.background,screen);
        show(optiongame->assets.logo,screen);
        show(optiongame->assets.logogroup,screen);
        SDL_Flip(screen);
    SDL_Event event;
    while(run==2)
    {

    //Wait for event
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
                        run=0;
                    break;
                    case (SDLK_RIGHT):
                        run=1;
                    break;
                    case (SDLK_DOWN):
                        run=2;
                    break;
                    case (SDLK_UP):
                        run=2;
                    break;
                                        
                    default:
                        break;
                    }
        }


    }
return run;

}