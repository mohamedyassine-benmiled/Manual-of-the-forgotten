#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "include/menu.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "include/init.h"
#include "include/game.h"
#include "include/fgifsdl.h"
#include "include/animation.h"

int menu(MenuGame *menugame,SDL_Surface *screen,int run)
{
      int x,y,ins ;
    SDL_Event event;
    SDL_Gif *closedbook,*logo;

        closedbook=SDLLoadGif("graphics/1080/Menu/ClosedBook.gif");
        logo=SDLLoadGif("graphics/1080/Menu/LogoGame.gif");

        show(menugame->assets.background,screen);
        show(menugame->assets.play[0],screen);
        show(menugame->assets.options[0],screen);
        show(menugame->assets.quit[0],screen);
        show(menugame->assets.logogroup,screen);

    menugame->hover=0;
    menugame->press=0;
    Mix_PlayMusic(menugame->Music, -1);

    while(run==1)
    {
    animatebackground(menugame->assets.book,closedbook,screen);
    animatebackground(menugame->assets.logo,logo,screen);
    
    //Wait for event
while (SDL_PollEvent(&event)) {
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
                    case (SDLK_o):
                        run=2;
                    break;
                    case (SDLK_p):
                        run=2;
                    break;
                    case (SDLK_f):
                        SDL_WM_ToggleFullScreen(screen); 
                    break;                             
                    default:
                        break;
                    }
                break;
        case SDL_MOUSEMOTION:
        //Init Motion With Sound
        SDL_GetMouseState(&x,&y);

        //Play Button
                menugame->hover=menugame->hover+animatehover(x,y,menugame->assets.play[1],menugame->assets.play[0],screen);
        //Options Button
                menugame->hover=menugame->hover+animatehover(x,y,menugame->assets.options[1],menugame->assets.options[0],screen);
        //Quit Button
                menugame->hover=menugame->hover+animatehover(x,y,menugame->assets.quit[1],menugame->assets.quit[0],screen);
                if (!(hoverbutton(x,y,menugame->assets.play[1]) || hoverbutton(x,y,menugame->assets.options[1]) || hoverbutton(x,y,menugame->assets.quit[1])))
                {
                    menugame->hover=0;

                }
                if(menugame->hover==1)
                {
                    Mix_PlayChannel(-1,menugame->soundbutton, 0); 
                }
                break;
         case SDL_MOUSEBUTTONUP:
         menugame->press=true;
         SDL_GetMouseState(&x,&y);

                    if(hoverbutton(x,y,menugame->assets.play[1]))
                    run=2;


                    if(hoverbutton(x,y,menugame->assets.options[1]))
                    run=2;


                    if (hoverbutton(x,y,menugame->assets.quit[1]))
                    run=0;


                break;
        }
}
      SDL_Flip(screen);
    }
SDLFreeGif(closedbook);
SDLFreeGif(logo);
 return run;

}

int options(OptionGame *optiongame,SDL_Surface *screen,int run)
{
        show(optiongame->assets.background,screen);
        show(optiongame->assets.logogroup,screen); 
        show(optiongame->assets.obook,screen); 
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
                    case (SDLK_m):
                        run=1;
                    break;
                    case (SDLK_p):
                        run=2;
                    break;
                    case (SDLK_f):
                        SDL_WM_ToggleFullScreen(screen); 
                    break;         
                    default:
                        break;
                    }
        }


    }
return run;

}