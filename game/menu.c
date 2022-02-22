#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "include/menu.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "include/init.h"
#include "include/game.h"
#include "include/animation.h"

int check(SDL_Surface *screen,int *run,int state)
{
    int x,y;
    CheckImage assets;
    initcheck(&assets);
    show(assets.Window,screen);
    if (state)
        {
            show(assets.Apply,screen);
        }
        else
        {
            show(assets.Quit,screen);
        }
                show(assets.Yes[0],screen);
                show(assets.No[0],screen);

    SDL_Event event;
        int check=3;

        while (check==0)
        {
            SDL_WaitEvent(&event);
            switch(event.type)
            {
            case SDL_QUIT:
                *run=0;
                check=0;
                break;
            case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x,&y);


            if (hoverbutton(x,y,assets.Yes[0]))
            {
                show(assets.Yes[1],screen);
            }
            else
            {
                show(assets.Yes[0],screen);
            }          
            if (hoverbutton(x,y,assets.No[0]))
            {
                show(assets.No[1],screen);
            }
            else
            {
                show(assets.No[0],screen);
            }
            break;
            case SDL_MOUSEBUTTONUP:
            SDL_GetMouseState(&x,&y);
            if (hoverbutton(x,y,assets.Yes[0]))
            {
                check=1;
            }
            if (hoverbutton(x,y,assets.No[0]))
            {
                check=2;
            }

      }  
        }
        if (check==2)
        {
            return 0;
        }
        else
        return 1;


}





int menu(MenuGame *menugame,SDL_Surface *screen,int run)
{
      int x,y,i,j,k;
    SDL_Event event;
        MenuImage assets;

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
int listres(OptionGame *optiongame,graphicimage *assets,SDL_Surface *screen,int *run)
{
    int list=1;
    int x,y ;
    int res=0;
    SDL_Event event;
        show(assets->listresolutionbox[0],screen);
        show(assets->listresolution,screen);
        SDL_Flip(screen);
    while (list)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
          case SDL_QUIT:
               run=0;
               list=0;
               break;
          case SDL_MOUSEBUTTONUP:
          SDL_GetMouseState(&x,&y);


          if (!hoverbutton(x,y,assets->listresolutionbox[0]))
          {
              list =0;
          }
          else
          {
              res=1;
              list=0;
          }
          break;
      }  
    }
    return res;
    
}

int graphics(OptionGame *optiongame,OptionImage *assets,SDL_Surface *screen,int run)
{     int x,y,previousres,newres;
    graphicimage assetsg;
        settings config;
        get_config(&config);
    initgraphics(&assetsg);
    show(assetsg.boxresolution,screen);
    show(assetsg.selectresolution,screen);
    show(assetsg.windowsettings,screen);
    show(assetsg.firstbox[0],screen);
    show(assetsg.secondbox[0],screen);
    show(assetsg.fullscreen,screen);
    show(assetsg.windowed,screen);
    show(assetsg.currentresolution,screen);
    SDL_Flip(screen);
    optiongame->hover=0;       
    SDL_Event event;
     while(optiongame->graphics)
    {
        if (run==0)
        {
            optiongame->graphics=0;
        }
     while (SDL_PollEvent(&event)) 
    {
    switch (event.type)
        {case SDL_QUIT:
        run=0;
        optiongame->graphics=0;
        break;
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                    {
                    case (SDLK_ESCAPE):
                    optiongame->graphics=0;
                        run=0;
                    break;
                    case (SDLK_m):
                    optiongame->graphics=0;
                        run=1;
                    break;
                    case (SDLK_p):
                    optiongame->graphics=0;
                        run=2;
                    break;
                    case (SDLK_f):
                        SDL_WM_ToggleFullScreen(screen); 
                    break;         
                    default:
                        break;
                    }
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
                   if (hoverbutton(x,y,assetsg.boxresolution))
                   {
                       check(screen,&run,1);
                       previousres=config.resolution_h;
                        newres=listres(optiongame,&assetsg,screen,&run);
                        
                        show(assets->background,screen);
                        show(assets->logogroup,screen); 
                        show(assets->obook[14],screen);
                        show(assets->graphics[0],screen);
                        show(assets->audio[0],screen);
                        show(assets->keybinds[0],screen);
                        show(assetsg.boxresolution,screen);
                        show(assetsg.selectresolution,screen);
                        show(assetsg.windowsettings,screen);
                        show(assetsg.firstbox[0],screen);
                        show(assetsg.secondbox[0],screen);
                        show(assetsg.fullscreen,screen);
                        show(assetsg.windowed,screen);
                        show(assetsg.currentresolution,screen);
                   }
                  
                break;
                    
        }
         
        
    }

    SDL_Flip(screen);

}

    freegraphics(assetsg);
    show(assets->background,screen);
    show(assets->logogroup,screen); 
    show(assets->obook[14],screen);
    show(assets->graphics[0],screen);
    show(assets->audio[0],screen);
    show(assets->keybinds[0],screen);
return run;

}




int audio(OptionGame *optiongame,OptionImage *assets,SDL_Surface *screen,int run)
{     int x,y;
    audioimage assetsa;
    initaudio(&assetsa);
    show(assetsa.volume,screen);
    show(assetsa.audio,screen);
    show(assetsa.onbox[0],screen);
    show(assetsa.offbox[0],screen);
    show(assetsa.on,screen);
    show(assetsa.off,screen);
    show(assetsa.minus,screen);
    show(assetsa.plus,screen);
    show(assetsa.audiobar,screen);
    for (int i=0;i<10;i++)
    {
        show (assetsa.circle[i],screen);
    }
    SDL_Flip(screen);
    optiongame->hover=0;       
    SDL_Event event;
     while(optiongame->audio)
    {
     while (SDL_PollEvent(&event)) 
    {
    switch (event.type)
        {case SDL_QUIT:
        run=0;
        optiongame->audio=0;
        break;
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                    {
                    case (SDLK_ESCAPE):
                    optiongame->audio=0;
                        run=0;
                    break;
                    case (SDLK_m):
                    optiongame->audio=0;
                        run=1;
                    break;
                    case (SDLK_p):
                    optiongame->audio=0;
                        run=2;
                    break;
                    case (SDLK_f):
                        SDL_WM_ToggleFullScreen(screen); 
                    break;         
                    default:
                        break;
                    }
                    break;
        case SDL_MOUSEBUTTONUP:
                     SDL_GetMouseState(&x,&y);

                    
                    
                    if(hoverbutton(x,y,assets->graphics[1]))
                    {
                        optiongame->graphics=1;
                        optiongame->audio=0;
                    }

                    if (hoverbutton(x,y,assets->keybinds[1]))
                   {
                       optiongame->keybinds=1;
                       optiongame->audio=0;
                   }

                break;
                    
        }
         
        
    }

    SDL_Flip(screen);

}
    freeaudio(assetsa);
    show(assets->background,screen);
    show(assets->logogroup,screen); 
    show(assets->obook[14],screen);
    show(assets->graphics[0],screen);
    show(assets->audio[0],screen);
    show(assets->keybinds[0],screen);
return run;

}







int options(OptionGame *optiongame,SDL_Surface *screen,int run)
{
    OptionImage assets;
    int i,x,y;


     initoption(&assets);
        show(assets.background,screen);
        show(assets.logogroup,screen); 
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
    
     if (optiongame->graphics)
     {
         run=graphics(optiongame,&assets,screen,run);
     }
     if (optiongame->audio)
     {
         run=audio(optiongame,&assets,screen,run);
     }
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
                    {
                            optiongame->audio=1;
                        run=audio(optiongame,&assets,screen,run);
                    }

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















































