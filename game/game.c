#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"
#include "include/enigme.h"

int game(SDL_Surface *screen,int run)
{
    Game g;
    enigme e;
    initbackground(&g.bg);
    SDL_Event event;
    showgame(g.bg.img,screen);
    init_enigme(&e);
    afficherenigme(e,screen);
    SDL_Flip(screen);
    while(run==3)
    {

    //Wait for event
    while (SDL_PollEvent(&event))
    {

    switch (event.type)
        {
        case SDL_QUIT:
            run=0;
            break;
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                    {
                    //On Escape Press : Quit Check
                    case (SDLK_ESCAPE):
                        if (check(screen,&run,0))
                           run=0; 
                           else
                           {
                                showgame(g.bg.img,screen);
                           }  
                    break;
                    //On "m" Press : Go back to Menu
                    case (SDLK_m):
                        run=1;
                    break;
                    //On "o" press : Go to option
                    case (SDLK_o):
                        run=2;
                    break;
                    //On "p" press : Go to game
                    case (SDLK_p):
                        run=3;
                    break;
                    default:
                    break;
                    }


        }
    }
    }
    freebackground(g.bg);
return run;

}


