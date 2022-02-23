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

        while (check==3)
        {
            while (SDL_PollEvent(&event))
            {
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
                check=0;
            }

      }  
            }
            SDL_Flip(screen);
        }

            return check;




}





int menu(MenuGame *menugame,SDL_Surface *screen,int run)
{
        settings config;
        get_config(&config);
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
    Mix_VolumeMusic(set_audio(config.volume,config.audio));
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
                            if (config.fullscreen)
                                        {
                                            config.fullscreen=0;
                                        }
                                        else
                                        {
                                            config.fullscreen=1;
                                        } 
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
                if  (menugame->hover==1)
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
write_config(&config);
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
    SDL_Flip(screen);
    }
    return res;
    
}

int graphics(OptionGame *optiongame,OptionImage *assets,SDL_Surface *screen,int run)
{     int x,y,previousres,newres;
    text t;
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    graphicimage assetsg;
        settings config;
        get_config(&config);
                    if (config.resolution_h==720)
                        {
                            t.font=TTF_OpenFont("ttf/alagard.ttf",24);
                        }
                    else
                    if (config.resolution_h==1080)
                        {
                            t.font=TTF_OpenFont("ttf/alagard.ttf",36);
                        }           

    initgraphics(&assetsg);
    show(assetsg.boxresolution,screen);
    show(assetsg.selectresolution,screen);
    show(assetsg.windowsettings,screen);
    show (assets->graphics[1],screen);
    if (config.fullscreen)
    {
        show(assetsg.firstbox[0],screen);
        show(assetsg.secondbox[1],screen);
    }
    else
    {
        show(assetsg.firstbox[1],screen);
        show(assetsg.secondbox[0],screen);
    }

    show(assetsg.fullscreen,screen);
    show(assetsg.windowed,screen);
    show(assetsg.currentresolution,screen);
    SDL_Flip(screen);
    optiongame->hover=0;       
    newres=0;
    SDL_Event event;
     while(optiongame->graphics==1)
    {
        if (run==0)
        {
            optiongame->graphics=0;
        }
     while (SDL_PollEvent(&event)) 
    {
    switch (event.type)
        {
        case SDL_QUIT:
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
                    default:
                        break;
                    }
                    break;
        case SDL_MOUSEMOTION:
        //Init Motion With Sound
        SDL_GetMouseState(&x,&y);
                
        //Audio Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets->audio[1],assets->audio[0],screen);
        //Keybinds Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets->keybinds[1],assets->keybinds[0],screen);
                optiongame->hover=optiongame->hover+animatehover(x,y,assets->arrow[1],assets->arrow[0],screen);
                if (!(hoverbutton(x,y,assets->audio[1]) || hoverbutton(x,y,assets->keybinds[1]) || hoverbutton(x,y,assets->arrow[0])))
                {
                    optiongame->hover=0;
                }
                if  (optiongame->hover==1)
                {
                    Mix_PlayChannel(-1,optiongame->soundbutton, 0); 
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
                   if (hoverbutton(x,y,assetsg.firstbox[0]))
                   {
                            if (!config.fullscreen)
                            {
                                show(assetsg.firstbox[0],screen);
                                show(assetsg.secondbox[1],screen);
                                SDL_Flip(screen);
                                SDL_WM_ToggleFullScreen(screen); 
                                config.fullscreen=1;
                            }

                   }
                    if (hoverbutton(x,y,assetsg.secondbox[0]))
                   {
                            if (config.fullscreen)
                            {
                                show(assetsg.firstbox[1],screen);
                                show(assetsg.secondbox[0],screen);
                                SDL_Flip(screen);
                                SDL_WM_ToggleFullScreen(screen); 
                                config.fullscreen=0;
                            }
                   }
                   if (hoverbutton(x,y,assetsg.boxresolution))
                   {

                       previousres=config.resolution_h;
                        newres=listres(optiongame,&assetsg,screen,&run);
                        optionrefresh(assets,screen);
                        show(assets->graphics[0],screen);
                        show(assets->audio[0],screen);
                        show(assets->keybinds[0],screen);
                        if (config.fullscreen)
                            {
                                show(assetsg.firstbox[0],screen);
                                show(assetsg.secondbox[1],screen);
                            }
                            else
                            {
                                show(assetsg.firstbox[1],screen);
                                show(assetsg.secondbox[0],screen);
                            }
                        show(assetsg.boxresolution,screen);
                        show(assetsg.selectresolution,screen);
                        show(assetsg.windowsettings,screen);
                        show(assetsg.fullscreen,screen);
                        show(assetsg.windowed,screen);
                        show(assetsg.currentresolution,screen);
                   }
                if(hoverbutton(x,y,assets->arrow[0]))
                    {
                        optiongame->graphics=0;
                        run=1;
                    }
                break;
                    
        }
    }
    if (newres)
    {
        if (check(screen,&run,1))
        {
                SDL_FreeSurface(assetsg.currentresolution.surface);
                SDL_FreeSurface(assetsg.listresolution.surface);     
                optiongame->graphics=2;
                             if (previousres==720)
                             {
                                 config.resolution_h=1080;
                                 config.resolution_w=1920;
                                  strcpy(t.texte,"1920x1080");
                                  assetsg.currentresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
                                  strcpy(t.texte,"1280x720");
                                  assetsg.listresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);                                
                             }
                             else
                             if (previousres==1080)
                             {
                                 config.resolution_h=720;
                                 config.resolution_w=1280;
                                  strcpy(t.texte,"1920x1080");
                                  assetsg.listresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor); 
                                  strcpy(t.texte,"1280x720");
                                  assetsg.currentresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
                             }


        }
        
                optionrefresh(assets,screen);
                show(assets->graphics[1],screen);
                show(assets->audio[0],screen);
                show(assets->keybinds[0],screen);
                if (config.fullscreen)
                {
                    show(assetsg.firstbox[0],screen);
                    show(assetsg.secondbox[1],screen);
                }
                else
                {
                    show(assetsg.firstbox[1],screen);
                    show(assetsg.secondbox[0],screen);
                }

                show(assetsg.boxresolution,screen);
                show(assetsg.selectresolution,screen);
                show(assetsg.windowsettings,screen);
                show(assetsg.fullscreen,screen);
                show(assetsg.windowed,screen);
                show(assetsg.currentresolution,screen);
                newres=0;
    }
    
    SDL_Flip(screen);

}
    write_config(&config);
    TTF_CloseFont(t.font);
    freegraphics(assetsg);
    optionrefresh(assets,screen);
    show(assets->graphics[0],screen);
    show(assets->audio[0],screen);
    show(assets->keybinds[0],screen);
return run;

}




int audio(OptionGame *optiongame,OptionImage *assets,SDL_Surface *screen,int run)
{     int x,y;
    audioimage assetsa;
    settings config;
    get_config(&config);
    initaudio(&assetsa);
    show(assets->audio[1],screen);
    audiorefresh(&assetsa,screen);
        if (config.audio)
    {
        show(assetsa.onbox[0],screen);
        show(assetsa.offbox[1],screen);
    }
    else
    {
        show(assetsa.onbox[1],screen);
        show(assetsa.offbox[0],screen);
    }

    show(assetsa.circle[config.volume],screen);

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
                                    if (config.fullscreen)
                                        {
                                            config.fullscreen=0;
                                        }
                                        else
                                        {
                                            config.fullscreen=1;
                                        } 
                    break;         
                    default:
                        break;
                    }
                    break;
        case SDL_MOUSEMOTION:
        //Init Motion With Sound
        SDL_GetMouseState(&x,&y);
                
        //Graphics Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets->graphics[1],assets->graphics[0],screen);
        //Keybinds Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets->keybinds[1],assets->keybinds[0],screen);
                if (!(hoverbutton(x,y,assets->graphics[1]) || hoverbutton(x,y,assets->keybinds[1])))
                {
                    optiongame->hover=0;
                }
                if  (optiongame->hover==1)
                {
                    Mix_PlayChannel(-1,optiongame->soundbutton, 0); 
                }
        break;
        case SDL_MOUSEBUTTONUP:
                     SDL_GetMouseState(&x,&y);
                    if (hoverbutton(x,y,assetsa.plus))
                    {
                        optiongame->audio=2;
                        if (config.volume!=9)
                        config.volume++;
                    }
                    if (hoverbutton(x,y,assetsa.minus))
                    {
                        optiongame->audio=2;
                        if (config.volume!=0)
                        config.volume--;

                    }
                    if (hoverbutton(x,y,assetsa.onbox[0]))
                   {
                            if (!config.audio)
                            {
                                optiongame->audio=2;
                                config.audio=1;
                            }

                   }
                    if (hoverbutton(x,y,assetsa.offbox[0]))
                   {
                            if (config.audio)
                            {
                                optiongame->audio=2;
                                config.audio=0;
                            }
                   }
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
                    if(hoverbutton(x,y,assets->arrow[0]))
                    {
                        optiongame->audio=0;
                        run=1;
                    }
                break;
                    
        }
         
        
    }    
    //Refresh
    if (optiongame->audio==2)
    {
        optiongame->audio=1;
    optionrefresh(assets,screen);
    show(assets->graphics[0],screen);
    show(assets->audio[1],screen);
    show(assets->keybinds[0],screen);
    audiorefresh(&assetsa,screen);
        if (config.audio)
    {
        show(assetsa.onbox[0],screen);
        show(assetsa.offbox[1],screen);
    }
    else
    {
        show(assetsa.onbox[1],screen);
        show(assetsa.offbox[0],screen);
    }

    show(assetsa.circle[config.volume],screen);
    Mix_VolumeMusic(set_audio(config.volume,config.audio));
    Mix_VolumeChunk(optiongame->soundbutton,set_audio(config.volume,config.audio));
    }
    SDL_Flip(screen);

}
    write_config(&config);
    freeaudio(assetsa);

    optionrefresh(assets,screen);
    show(assets->graphics[0],screen);
    show(assets->audio[0],screen);
    show(assets->keybinds[0],screen);

return run;

}







int options(OptionGame *optiongame,SDL_Surface *screen,int run)
{
    OptionImage assets;
    int i,x,y;
        settings config;
        get_config(&config);

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
    
     if (optiongame->graphics==1)
     {
                        run=graphics(optiongame,&assets,screen,run);
                        get_config(&config);


                        if(optiongame->graphics==2)
                        {
                        freeoption(assets);
                        initoption(&assets);
                        SDL_FreeSurface(screen);
                        if (config.fullscreen)
                        SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_FULLSCREEN);
                        else
                        SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
                        }
                        show(assets.background,screen);
                        show(assets.logogroup,screen); 
                        show(assets.obook[14],screen);
                        show(assets.graphics[0],screen);
                        show(assets.audio[0],screen);
                        show(assets.keybinds[0],screen);
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
                                if (config.fullscreen)
                                        {
                                            config.fullscreen=0;
                                        }
                                        else
                                        {
                                            config.fullscreen=1;
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
                optiongame->hover=optiongame->hover+animatehover(x,y,assets.graphics[1],assets.graphics[0],screen);
        //Options Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets.audio[1],assets.audio[0],screen);
        //Quit Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets.keybinds[1],assets.keybinds[0],screen);
                optiongame->hover=optiongame->hover+animatehover(x,y,assets.arrow[1],assets.arrow[0],screen);
                if (!(hoverbutton(x,y,assets.graphics[1]) || hoverbutton(x,y,assets.audio[1]) || hoverbutton(x,y,assets.keybinds[1]) || hoverbutton(x,y,assets.arrow[0])))
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
                        get_config(&config);
                        freeoption(assets);
                        initoption(&assets);

                        if(optiongame->graphics==2)
                        {
                        SDL_FreeSurface(screen);
                        if (config.fullscreen)
                        SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_FULLSCREEN);
                        else
                        SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
                        }
                        show(assets.background,screen);
                        show(assets.logogroup,screen); 
                        show(assets.obook[14],screen);
                        show(assets.graphics[0],screen);
                        show(assets.audio[0],screen);
                        show(assets.keybinds[0],screen);
                    } 
                    if(hoverbutton(x,y,assets.arrow[0]))
                    {
                        run=1;
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
    write_config(&config);
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















































