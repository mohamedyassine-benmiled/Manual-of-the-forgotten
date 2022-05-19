/**
 * @file event.c
 * @author TMOF Team
 * @brief Handling game events
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "include/game.h"

int handleenigme(Enigme *e,SDL_Event *event,SDL_Surface *screen,int run)
{

            if (SDL_PollEvent(event))
                {
                switch ((*event).type)
                            {
                                case SDL_QUIT:
                                    run=0;
                                break;
                                case SDL_KEYDOWN:
                                    switch ((*event).key.keysym.sym)
                                    {
                                        /*** Normal Screen Handling ***/
                                        //On Escape Press : Quit Check
                                        case (SDLK_ESCAPE):
                                            if (check(screen,&run,0))
                                            run=0; 
                                            else
                                            {
                                                    afficherenigme(e,screen);
                                            }  
                                        break;
                                        //On "A" Press : Go back to Menu
                                        case (SDLK_a):
                                            if (e->rep==1)
                                            {
                                                e->repuser=2;
                                            }
                                            else
                                            {
                                                e->repuser=1;
                                            }
                                        break;
                                        //On "B" press : Go to option
                                        case (SDLK_b):
                                            if (e->rep==2)
                                            {
                                                e->repuser=2;
                                            }
                                            else
                                            {
                                                e->repuser=1;
                                            }
                                        break;
                                        //On "C" press : Go to game
                                        case (SDLK_c):
                                            if (e->rep==3)
                                            {
                                                e->repuser=2;
                                            }
                                            else
                                            {
                                                e->repuser=1;
                                            }
                                        break;
                                    }
                            }        
                }
                return run;
}

int handlegame(Game *g,SDL_Event *event,SDL_Surface *screen,int run)
{
int arduino;
            if (SDL_PollEvent(event))
                {
                            arduinoReadData(&arduino);
                            switch (arduino)
                                {
                                    case (1):
                                        g->player[0].input.right=1;
                                        break;
                                    case (2):
                                        g->player[0].input.left=1;
                                        break;
                                    case (3):
                                        g->player[0].input.startJump=1;
                                        break;
                                    default:
                                        break;
                                }
                                if  ((*event).type==SDL_QUIT)
                                    run=0;

                                if  ((*event).type==SDL_KEYDOWN)
                                    switch ((*event).key.keysym.sym)
                                    {
                                        /*** Normal Screen Handling ***/
                                        //On Escape Press : Quit Check
                                        case (SDLK_ESCAPE):
                                            if (check(screen,&run,0))
                                            run=0; 
                                            else
                                            {
                                                    showgame(g->bg.img,screen);
                                            }  
                                        break;
                                        //On "m" Press : Go back to Menu
                                        case SDLK_m:
                                            run=1;
                                        break;
                                        //On "o" press : Go to option
                                        case SDLK_o:
                                            run=2;
                                        break;
                                        //On "p" press : Go to game
                                        case SDLK_r:
                                            run=3;
                                        break;
                                        /*** Player[0] Handling ***/
                                        case SDLK_RIGHT:
                                        {
                                            g->player[0].input.right=1;
                                            g->player[0].input.left=0;
                                        }
                                        break;
                                        case SDLK_LEFT:
                                        {
                                            g->player[0].input.left=1;
                                            g->player[0].input.right=0;
                                        }
                                        break;

                                        case SDLK_UP:
                                        {
                                            g->player[0].input.up=1;
                                        }
                                        break;

                                        case SDLK_RSHIFT:
                                        {
                                            g->player[0].input.fast=1;
                                        }
                                        break;
                                        /*** Player[1] Handling ***/
                                        case SDLK_d:
                                        {
                                            g->player[1].input.right=1;
                                            g->player[1].input.left=0;
                                        }
                                        break;

                                        case SDLK_a:
                                        {
                                            g->player[1].input.left=1;
                                            g->player[1].input.right=0;
                                        }
                                        break;

                                        case SDLK_w:
                                        {
                                            g->player[1].input.up=1;
                                        }
                                        break;
                                        case SDLK_x:
                                        {
                                            g->player[1].input.fast=1;
                                        }
                                        break;
                                    /*** Default Handling ***/
                                    default:
                                    break;
                                    }   
                                
                                if  ((*event).type==SDL_KEYUP)
                                switch ((*event).key.keysym.sym)
                                    {
                                        /*** Player[0] Handling ***/
                                        case SDLK_RIGHT:
                                        {
                                            g->player[0].input.right=0;
                                        }
                                        break;

                                        case SDLK_LEFT:
                                        {
                                            g->player[0].input.left=0;
                                        }
                                        break;

                                        case SDLK_UP:
                                        {
                                            g->player[0].input.up=0;
                                        }
                                        break;
                                        case SDLK_RSHIFT:
                                        {
                                            g->player[0].input.fast=0;
                                        }
                                        break;
                                        /*** Player[1] Handling ***/
                                        case SDLK_d:
                                        {
                                            g->player[1].input.right=0;
                                        }
                                        break;
                                        case SDLK_a:
                                        {
                                            g->player[1].input.left=0;
                                        }
                                        break;
                                        case SDLK_w:
                                        {
                                            g->player[1].input.up=0;
                                        }
                                        break;    
                                        case SDLK_x:
                                        {
                                            g->player[1].input.fast=0;
                                        }
                                        break; 
                                    /*** Default Handling ***/                                   
                                    default:
                                    break;
                                    }
                                
                            }
                 
        return run;
}


