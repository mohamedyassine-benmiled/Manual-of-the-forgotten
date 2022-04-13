#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"
#include "include/declarations.h"

int game(SDL_Surface *screen,int run)
{ int direction;
    Game g,b;
    initBack(&b.bg);
    
    initplayer(&g);
    SDL_Event event;
    afficher_back(&b.bg,screen);
    
    SDL_Flip(screen);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
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
                        case SDLK_RIGHT:
                      direction=0;
                     

                            g.player[0].input.right=1;
                            g.player[0].input.left=0;
                        }
                        break;

                        case SDLK_LEFT:
                        { direction=1;
                     

                            g.player[0].input.left=1;
                            g.player[0].input.right=0;
                        }
                        break;

                        case SDLK_UP:
                        { direction=2;
                      

                            g.player[0].input.up=1;
                        }
                        break;
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
                break;
                case SDL_KEYUP:
                switch (event.key.keysym.sym)
                    {
                        case SDLK_RIGHT:
                        {
                            g.player[0].input.right=0;
                        }
                        break;

                        case SDLK_LEFT:
                        {
                            g.player[0].input.left=0;
                        }
                        break;

                        case SDLK_UP:
                        {
                            g.player[0].input.up=0;
                        }
                        break;

                    default:
                    break;
                    }
                break;

        }
        
    }
    movement(&g);
    gamerefresh(&g,screen);
    
    freebackground(g.bg);
return run;

}


