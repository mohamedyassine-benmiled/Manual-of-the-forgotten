#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"

//To initialize Everything (What did it cost?)
void init()
{
     SDL_Init(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(IMG_Load("Menu/Logo.png"),NULL);
                SDL_WM_SetCaption("Manual of the forgotten",NULL);
}



int menu(MenuGame *menugame,SDL_Surface *screen,int run)
{
    initBackground(&menugame->assets.background,"Menu/grey.png");
    menugame->assets.play[1].surface = IMG_Load("Menu/Play2.png");
    menugame->assets.play[1].pos1.x=129;
    menugame->assets.play[1].pos1.y=374;
    menugame->assets.play[1].pos2.w=209;
    menugame->assets.play[1].pos2.h=118;
    menugame->assets.play[2].surface = IMG_Load("Menu/PlayOnHover.png");
    menugame->assets.play[2].pos1.x=129;
    menugame->assets.play[2].pos1.y=374;
    menugame->assets.play[2].pos2.w=209;
    menugame->assets.play[2].pos2.h=118;
    menugame->assets.options.surface = IMG_Load("Menu/Options2.png");
    menugame->assets.options.pos1.x=129;
    menugame->assets.options.pos1.y=512;
    menugame->assets.quit.surface = IMG_Load("Menu/Quit2.png");
    menugame->assets.quit.pos1.x=129;
    menugame->assets.quit.pos1.y=661;
    menugame->assets.logo.surface = IMG_Load("Menu/Logo.png");
    menugame->assets.logo.pos1.x=220;
    menugame->assets.logo.pos1.y=74;
    menugame->assets.logogroup.surface = IMG_Load("Menu/Logo.png");
    menugame->assets.logogroup.pos1.x=1690;
    menugame->assets.logogroup.pos1.y=857;
    SDL_Event event;
        show(menugame->assets.background,screen);
        show(menugame->assets.play[1],screen);
        show(menugame->assets.options,screen);
        show(menugame->assets.quit,screen);
        show(menugame->assets.logo,screen);
        show(menugame->assets.logogroup,screen);
      SDL_Flip(screen);
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
                        run=3;
                    break;
                                        
                    default:
                        break;
                    }
        case SDL_MOUSEMOTION:
                if(event.motion.x>=menugame->assets.play[1].pos1.x && event.motion.x<=menugame->assets.play[1].pos1.x+menugame->assets.play[1].pos2.w && event.motion.y>=menugame->assets.play[1].pos1.y&& event.motion.y<=menugame->assets.play[1].pos1.y+menugame->assets.play[1].pos2.h)
                {

                }

                break;
        
        case SDL_MOUSEBUTTONUP:
                if(event.motion.x>=menugame->assets.play[1].pos1.x && event.motion.x<=menugame->assets.play[1].pos1.x+menugame->assets.play[1].pos2.w && event.motion.y>=menugame->assets.play[1].pos1.y&& event.motion.y<=menugame->assets.play[1].pos1.y+menugame->assets.play[1].pos2.h)
                {
                    run=3;
                }
                break;
        }


    }
return run;

}

int options(int run)
{
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
                        run=3;
                    break;
                                        
                    default:
                        break;
                    }
        }


    }
return run;

}

int game(int run)
{
    SDL_Event event;
    while(run==3)
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
                        run=3;
                    break;

                    default:
                        break;
                    }
        }


    }
return run;

}


void InitOptions()
{

}