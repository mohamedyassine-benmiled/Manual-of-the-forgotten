#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "include/menu.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "include/init.h"
#include "include/game.h"
#include "include/animation.h"

int menu(MenuGame *menugame,SDL_Surface *screen,int run)
{
      int x,y,i,j,k;
    SDL_Event event;
        MenuImage assets;
            menugame->Music=Mix_LoadMUS("sfx/menu.ogg");
    menugame->soundbutton=Mix_LoadWAV("sfx/button.ogg"); //Chargement de sound effect
        initmenu(&assets);
        show(assets.background,screen);
        show(assets.play[0],screen);
        show(assets.options[0],screen);
        show(assets.quit[0],screen);
        show(assets.logogroup,screen);
        show(assets.copyright,screen);
    i=0;
    j=0;
    k=0;
    menugame->hover=0;
    menugame->press=0;
    Mix_PlayMusic(menugame->Music, -1);

    while(run==1)
    {
    //Logo Loop
    i++;
    if(i==4)
    {
        i=0;
    }
    //Book Loop
    if (j==6 || j==12)
    {
        k++;
        if (k==40)
        {
            k=0;
            if (j==12)
            j=0;
            else
            j++;
        }
    }
    else
    {
        j++;
    }

    show(assets.cbook[j],screen);
    show(assets.logo[i],screen);
    SDL_Delay(50);
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
                    case (SDLK_UP):
                      menugame-> state--;
                       if (menugame-> state<0)
                         {
                            menugame->state=2;
                         }
                    break; 
                    case (SDLK_DOWN):
                       menugame-> state++;
                        if (menugame->state<0)
                          {
                             menugame->state=0;
                          }
                    break;                           
                    default:
                        break;
                    }
                break;        
        case SDL_MOUSEMOTION:
        //Init Motion With Sound
        SDL_GetMouseState(&x,&y);

        //Play Button
                menugame->hover=menugame->hover+animatehover(x,y,assets.play[1],assets.play[0],screen);
        //Options Button
                menugame->hover=menugame->hover+animatehover(x,y,assets.options[1],assets.options[0],screen);
        //Quit Button
                menugame->hover=menugame->hover+animatehover(x,y,assets.quit[1],assets.quit[0],screen);
                if (!(hoverbutton(x,y,assets.play[1]) || hoverbutton(x,y,assets.options[1]) || hoverbutton(x,y,assets.quit[1])))
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

                    if(hoverbutton(x,y,assets.play[1]))
                    run=2;
                    
                    if(hoverbutton(x,y,assets.options[1]))
                    run=2;

                    if (hoverbutton(x,y,assets.quit[1]))
                    run=0;


                break;
        
        }
}
      SDL_Flip(screen);
    }
freemenu(assets);
 return run;

}




//menu graphics

int graphics(OptionGame *optiongame,OptionImage *assets,SDL_Surface *screen,int run)
{     int x,y;
    show(assets->selectres,screen);
    show(assets->windowsettings,screen);
    show(assets->firstbox[0],screen);
    show(assets->secondbox[0],screen);
    show(assets->fullscreen,screen);
    show(assets->windowed,screen);
    show(assets->currentresolution,screen);
    SDL_Flip(screen);
    optiongame->hover=0;       
    SDL_Event event;
     while(optiongame->graphics)
    {
     while (SDL_PollEvent(&event)) 
    {
    switch (event.type)
        {case SDL_QUIT:
        run=0;
        optiongame->graphics=0;
        break;
        case SDL_MOUSEBUTTONUP:
                     SDL_GetMouseState(&x,&y);

                    
                    
                    if(hoverbutton(x,y,assets->audio[1]))
                    {
                        optiongame->audio=1;
                        optiongame->graphics=0;
                    }

                    if (hoverbutton(x,y,assets->keybinds[1]))
                   {
                       optiongame->keybinds=1;
                       optiongame->graphics=0;
                   }

                break;
                    
        }
         
        
    }
}SDL_Flip(screen);
return run;

}









int options(OptionGame *optiongame,SDL_Surface *screen,int run)
{
    OptionImage assets;
    int i,x,y;
        optiongame->soundbutton=Mix_LoadWAV("sfx/button.ogg"); //Chargement de sound effect

     initoption(&assets);
        show(assets.background,screen);
        show(assets.logogroup,screen); 
        //show(assets.obook,screen);
         for ( i = 0; i < 15; i++)

            {
                show(assets.obook[i],screen);
                SDL_Delay(50);
                SDL_Flip(screen);
            } 
            show(assets.graphics[0],screen);
            show(assets.audio[0],screen);
            show(assets.keybinds[0],screen);

        SDL_Flip(screen);
             optiongame->hover=0;
    SDL_Event event;
     
     while(run==2)
    {
    
     
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
                    break;
                    


 case SDL_MOUSEMOTION:
        //Init Motion With Sound
        SDL_GetMouseState(&x,&y);

        //Play Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets.graphics[1],assets.graphics[0],screen);
        //Options Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets.audio[1],assets.audio[0],screen);
        //Quit Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets.keybinds[1],assets.keybinds[0],screen);
                if (!(hoverbutton(x,y,assets.graphics[1]) || hoverbutton(x,y,assets.audio[1]) || hoverbutton(x,y,assets.keybinds[1])))
                {
                    optiongame->hover=0;

                }
                if(optiongame->hover==1)
                {
                    Mix_PlayChannel(-1,optiongame->soundbutton, 0); 
                }

                break;
         


        case SDL_MOUSEBUTTONUP:
                     SDL_GetMouseState(&x,&y);

                    if(hoverbutton(x,y,assets.graphics[1]))
                     {
                        optiongame->graphics=1;
                        run=graphics(optiongame,&assets,screen,run);
                    } 
                    
                    if(hoverbutton(x,y,assets.audio[1]))
                    run=1;

                    if (hoverbutton(x,y,assets.keybinds[1]))
                    run=1;


                break;
                    
        }
         }
        SDL_Flip(screen);
    }
    for ( i = 15; i> -1; i--)
            {
                show(assets.obook[i],screen);
                SDL_Delay(50);
                SDL_Flip(screen);
            } 
     freeoption(assets);
     SDL_Delay(500);

return run;

}















































