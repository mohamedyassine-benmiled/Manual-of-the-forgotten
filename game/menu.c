/**
 * @file menu.c
 * @author TMOF Team
 * @brief Menu Functions
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "include/menu.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "include/init.h"
#include "include/game.h"
#include "include/animation.h"
//Check
int check(SDL_Surface *screen,int *run,int state)
{
    //
    int x,y;
    CheckImage assets;
    initcheck(&assets);
    show(assets.Window,screen);
    //If 0 Quit else 1 Apply
    if (state)
        {
            show(assets.Apply,screen);
        }
        else
        {
            show(assets.Quit,screen);
        }
    //Showing Yes or No
    show(assets.Yes[0],screen);
    show(assets.No[0],screen);

    SDL_Event event;
        int check=3;
        //Init Loop
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
            //If hover on yes
            if (hoverbutton(x,y,assets.Yes[0]))
            {
                show(assets.Yes[1],screen);
            }
            else
            {
                show(assets.Yes[0],screen);
            }          
            //If hover on no
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
            //If Click on yes
            if (hoverbutton(x,y,assets.Yes[0]))
            {
                check=1;
            }
            //If Click on no
            if (hoverbutton(x,y,assets.No[0]))
            {
                check=0;
            }

      }  
            }
            //Update Screen
            SDL_Flip(screen);
        }
            //Return Result
            return check;
    
}
int fileexist(char c[])
{
    FILE *f=NULL;
    f=fopen(c,"r");
    if (f!=NULL)
    {
        return 1;
    }
    return 0;
}
//Menu
int menu(MenuGame *menugame,SDL_Surface *screen,int run,int *state)
{
    //Initiating config
        settings config;
        get_config(&config);
    //Variable definition for animation and mouse
      int x,y,i,j,k;
    SDL_Event event;
        MenuImage assets;
        int saveexist=fileexist("save/savefile");
        *state =0;
    //Showing Menu
        initmenu(&assets);
        menurefresh(&assets,screen);
    //Initiating Variables
        i=0;
        j=0;
        k=0;
    menugame->hover=0;
    menugame->press=0;
    menugame->state=-1;
    //Playing Music
    menugame->Music=Mix_LoadMUS("sfx/menu.ogg"); //Chargement de music
    menugame->soundbutton=Mix_LoadWAV("sfx/button.ogg"); //Chargement de sound effect
    Mix_VolumeMusic(set_audio(config.volume,config.audio)); //Changement de volume music
    Mix_VolumeChunk(menugame->soundbutton,set_audio(config.volume,config.audio)); //Changement de volume chunk
    Mix_PlayMusic(menugame->Music, -1); //Play Music
    //Menu Loop
    while(run==1)
    {
    //Logo Loop Animation
    i++;
    if(i==4)
    {
        i=0;
    }
    //Book Loop Animation 
    if (j==6 || j==12)
    {
        //If Frame = 6 or Frame = 12 , Wait until counter reaches 40 ; 40*50 = 2000 = 2s
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
    //Showing Animation
    show(assets.cbook[j],screen);
    show(assets.logo[i],screen);
    SDL_Delay(50);
    //While event queue
while (SDL_PollEvent(&event)) {
    switch (event.type)
        {
        //Close Program with X button
        case SDL_QUIT:
            run=0;
            break;
        //On Keyboard Press
        case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                    {
                    //On Enter Press
                    case(SDLK_RETURN):
                        switch (menugame->state)
                        {
                        case 0:
                            run=2;
                            break;
                        case 1:
                           run=2;
                           break;
                        case 2 :
                        if (check(screen,&run,0))
                           run=0; 
                           else
                           {
                                menurefresh(&assets,screen);
                                show(assets.quit[1],screen);
                           }  
                            break ; 
                        default:
                        printf("\nilyes was here");
                            break;
                        }
                        break;
                    //On Escape Press : Quit Check
                    case (SDLK_ESCAPE):
                        if (check(screen,&run,0))
                           run=0; 
                           else
                           {
                                menurefresh(&assets,screen);
                                show(assets.cbook[j],screen);
                                show(assets.logo[i],screen);
                           }  
                    break;
                    //On "o" press : Go to option
                    case (SDLK_o):
                        run=2;
                    break;
                    //On "p" press : Go to game
                    case (SDLK_p):
                        if (*state=playmenu(screen,&run,saveexist))
                        {
                        run=3;
                        }
                        else
                        {
                            menurefresh(&assets,screen);
                            show(assets.play[1],screen);
                        }  
                    break;
                    //On "f" press : Go fullscreen or windowed
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
                    //Select Menu Buttons
                    case (SDLK_UP):
                    if  (menugame->state <0)
                        menugame->state=2;
                    else
                      menugame-> state--;
                       if (menugame-> state<0)
                         {
                            menugame->state=2;
                         }
                    break; 
                    case (SDLK_DOWN):
                        if (menugame-> state<0)
                         {
                            menugame->state=0;
                         }else
                        menugame-> state++;
                        if (menugame->state>2)
                          {
                             menugame->state=0;
                          }
                    break;                           
                    default:
                        break;
                    }
                break;        
        case SDL_MOUSEMOTION:
        //Init Motion
        SDL_GetMouseState(&x,&y);
        if (menugame->state!=-1)
        {
          show(assets.quit[0],screen);
          show(assets.options[0],screen);
          show(assets.play[0],screen);
          menugame->state=-2 ;
        }
        

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
                //If click on play go to game
                    if(hoverbutton(x,y,assets.play[1]))
                    {
                        if (*state=playmenu(screen,&run,saveexist))
                                {
                                run=3;
                                }
                                else
                                {
                                    menurefresh(&assets,screen);
                                    show(assets.play[1],screen);
                                }  
                    }
                //If click on options go to options
                    if(hoverbutton(x,y,assets.options[1]))
                    run=2;
                //If click on quit go to check then quit
                    if (hoverbutton(x,y,assets.quit[1]))
                    {
                        if (check(screen,&run,0))
                           run=0; 
                           else
                           {
                                menurefresh(&assets,screen);
                           }  
                    }

                break;
        
        }
}
//Show buttons depending on state of Menu Select
      switch(menugame-> state)
      {
      case 0:
          show(assets.quit[0],screen);
          show(assets.options[0],screen);
          show(assets.play[1],screen);
          break;
      case 1: 
          show(assets.quit[0],screen);
          show(assets.options[1],screen);
          show(assets.play[0],screen); 
      break;
      case 2:
          show(assets.quit[1],screen);
          show(assets.options[0],screen);
          show(assets.play[0],screen);
          break;
         
      default:
        
          break;
      }

      //Screen Refresh
      SDL_Flip(screen);
    }
//Update Config
write_config(&config);
//Free Menu from memory
freemenu(assets);
 return run;
}

//List Resolution
int listres(OptionGame *optiongame,graphicimage *assets,SDL_Surface *screen,int *run)
{
    //Initialization variables
    int list=1;
    int x,y ;
    int res=0;
    SDL_Event event;
    //Show Check Images
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
          //If click on resolution change resolution else close list
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
    //Update
    SDL_Flip(screen);
    }
    return res;
    
}

//Graphics
int graphics(OptionGame *optiongame,OptionImage *assets,SDL_Surface *screen,int run)
{   
    //Declaration and Initializing
    int x,y,previousres,newres;
    text t;
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    graphicimage assetsg;
    //Initiating Config
        settings config;
        get_config(&config);
        //Initiating font
                    if (config.resolution_h==720)
                        {
                            t.font=TTF_OpenFont("ttf/alagard.ttf",24);
                        }
                    else
                    if (config.resolution_h==1080)
                        {
                            t.font=TTF_OpenFont("ttf/alagard.ttf",36);
                        }           
    //Initializing and showing images
    initgraphics(&assetsg);
    optionrefresh(assets,screen);
    graphicsrefresh(&assetsg,screen,config.fullscreen);
    show (assets->graphics[1],screen);
    //Update Screen
    SDL_Flip(screen);
    //Initializing variables for check
    optiongame->hover=0;       
    newres=0;
    SDL_Event event;
    //Graphics Loop
     while(optiongame->graphics==1)
    {
        //If quit then quit graphics and game
        if (run==0)
        {
            optiongame->graphics=0;
        }
        //Events
    while (SDL_PollEvent(&event)) 
    {
    switch (event.type)
        {
        //If click on close then close game
                case SDL_QUIT:
                    run=0;
                    optiongame->graphics=0;
                break;
                //On press key
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                        {
                        //On press Escape : Quit Game
                        case (SDLK_ESCAPE):
                            if (check(screen,&run,0))
                            {
                                optiongame->graphics=0;
                                run=0; 
                            }
                            else
                            {
                                optionrefresh(assets,screen);
                                graphicsrefresh(&assetsg,screen,config.fullscreen);
                                show(assets->graphics[1],screen);
                            }  
                        break;
                        //On Press M : Go back to menu
                        case (SDLK_m):
                            optiongame->graphics=0;
                            run=1;
                        break;
                        //On Press P : Go to play game
                        case (SDLK_p):
                            optiongame->graphics=0;
                            run=3;
                        break;       
                        default:
                        break;
                        }
                    break;
        case SDL_MOUSEMOTION:
        //Init Motion
        SDL_GetMouseState(&x,&y);
        //Audio Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets->audio[1],assets->audio[0],screen);
        //Keybinds Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets->keybinds[1],assets->keybinds[0],screen);
        //Arrow Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets->arrow[1],assets->arrow[0],screen);
        //Play button sound once
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
        //Init Mouse Position
        SDL_GetMouseState(&x,&y);
        //If Mouse Click On Audio
            if(hoverbutton(x,y,assets->audio[1]))
                {
                    optiongame->audio=1;
                    optiongame->graphics=0;
                }
        //If Mouse Click on Keybinds
            if (hoverbutton(x,y,assets->keybinds[1]))
                {
                    optiongame->keybinds=1;
                    optiongame->graphics=0;
                }
        //If Mouse Click on First Box : Go fullscreen
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
        //If Mouse Click on Second Box : Go fullscreen
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
        //If Mouse Click on Box Resolution : Open Resolution List
            if (hoverbutton(x,y,assetsg.boxresolution))
                {

                    previousres=config.resolution_h;
                    newres=listres(optiongame,&assetsg,screen,&run);
                    optionrefresh(assets,screen);
                    graphicsrefresh(&assetsg,screen,config.fullscreen);
                    show (assets->graphics[1],screen);
                }
        //If Mouse Click on Arrow : Go back to menu
            if(hoverbutton(x,y,assets->arrow[0]))
                {
                    optiongame->graphics=0;
                    run=1;
                }
        break;        
        }
    }
    //Check If change resolution needed
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
                graphicsrefresh(&assetsg,screen,config.fullscreen);
                show (assets->graphics[1],screen);
                newres=0;
    }
    //Update Screen
    SDL_Flip(screen);

}
//Update Config
    write_config(&config);
//Closing Font
    TTF_CloseFont(t.font);
//Freeing graphics memory
    freegraphics(assetsg);
//Refreshing option images
    optionrefresh(assets,screen);
    show(assets->graphics[0],screen);
    show(assets->audio[0],screen);
    show(assets->keybinds[0],screen);
return run;

}

//Audio
int audio(OptionGame *optiongame,OptionImage *assets,SDL_Surface *screen,int run)
{    
    //Initializing Variables
    int x,y;
    audioimage assetsa;
    //Initializing Config Values
    settings config;
    get_config(&config);
    //Initializing and showing Audio Images
    initaudio(&assetsa);
    show(assets->audio[1],screen);
    audiorefresh(&assetsa,screen,config.audio);
        //Showing volume level
    show(assetsa.circle[config.volume],screen);
    //Screen Update
    SDL_Flip(screen);
    //Initializing Hover
    optiongame->hover=0;       
    SDL_Event event;
    //Audio Loop
    while(optiongame->audio)
    {
        //If Quit then close audio and quit game
        if (run==0)
        {
            optiongame->audio=0;
        }
        //Event Queue
    while (SDL_PollEvent(&event)) 
    {
    switch (event.type)
        {
        //If pressed on program x exit
        case SDL_QUIT:
            run=0;
            optiongame->audio=0;
        break;
        //On Keyboard Press
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
                {
                    //On press Escape : Check if quit or not
                    case (SDLK_ESCAPE):
                        if (check(screen,&run,0))
                        {
                            optiongame->audio=0;
                            run=0; 
                        }
                        else
                        {
                            optionrefresh(assets,screen);
                            audiorefresh(&assetsa,screen,config.audio);
                            show(assets->audio[1],screen);
                            show(assetsa.circle[config.volume],screen);
                        }  
                    break;
                    //On press "m" : Go back to menu
                    case (SDLK_m):
                        optiongame->audio=0;
                        run=1;
                    break;
                    //On press "p" : Go to game
                    case (SDLK_p):
                        optiongame->audio=0;
                        run=3;
                    break;
                    //On press "f" : Go to fullscreen
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
            //Arrow Button
                optiongame->hover=optiongame->hover+animatehover(x,y,assets->arrow[1],assets->arrow[0],screen);
                if (!(hoverbutton(x,y,assets->graphics[1]) || hoverbutton(x,y,assets->keybinds[1]) || hoverbutton(x,y,assets->arrow[0])))
                    {
                        optiongame->hover=0;
                    }
                if  (optiongame->hover==1)
                    {
                        Mix_PlayChannel(-1,optiongame->soundbutton, 0); 
                    }
        break;
        case SDL_MOUSEBUTTONUP:
            //Init Motion With Sound
            SDL_GetMouseState(&x,&y);
            //On pressing Plus button : Increase Volume
                if (hoverbutton(x,y,assetsa.plus))
                    {
                        optiongame->audio=2;
                        if (config.volume!=9)
                        config.volume++;
                    }
            //On pressing Minus button : Decrease Volume
                if (hoverbutton(x,y,assetsa.minus))
                    {
                        optiongame->audio=2;
                        if (config.volume!=0)
                        config.volume--;
                    }
            //On Pressing First Box : Enable Audio
                if (hoverbutton(x,y,assetsa.onbox[0]))
                   {
                            if (!config.audio)
                                {
                                    optiongame->audio=2;
                                    config.audio=1;
                                }
                   }
            //On Pressing Second Box : Disable Audio
                if (hoverbutton(x,y,assetsa.offbox[0]))
                   {
                            if (config.audio)
                                {
                                    optiongame->audio=2;
                                    config.audio=0;
                                }
                   }
            //On pressing graphics : Go to graphics options
                if(hoverbutton(x,y,assets->graphics[1]))
                    {
                        optiongame->graphics=1;
                        optiongame->audio=0;
                    }
            //On pressing keybinds : Go to Keybinds options
                if (hoverbutton(x,y,assets->keybinds[1]))
                   {
                       optiongame->keybinds=1;
                       optiongame->audio=0;
                   }
            //On pressing Arrow : Go back to Menu
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
        //Refreshing Option Images
        optionrefresh(assets,screen);
        show(assets->graphics[0],screen);
        show(assets->audio[1],screen);
        show(assets->keybinds[0],screen);
        //Refreshing Audio Images
        audiorefresh(&assetsa,screen,config.audio);
        show(assetsa.circle[config.volume],screen);
        //Changing Volume Level
        Mix_VolumeMusic(set_audio(config.volume,config.audio));
        Mix_VolumeChunk(optiongame->soundbutton,set_audio(config.volume,config.audio));
    }
    //Update Screen
    SDL_Flip(screen);
    }
    //Update Config
    write_config(&config);
    //Free audio images from memory
    freeaudio(assetsa);
    //Refresh Option Images
    optionrefresh(assets,screen);
    show(assets->graphics[0],screen);
    show(assets->audio[0],screen);
    show(assets->keybinds[0],screen);
return run;
}

//Options
int options(OptionGame *optiongame,SDL_Surface *screen,int run)
{
    //Variable Definition
    OptionImage assets;
    int i,x,y;
    //Initiate Config Values
        settings config;
        get_config(&config);
    //Initializing Option Images and Showing them
    initoption(&assets);
    optionrefresh(&assets,screen);
    //Running Book Animation
        for ( i = 0; i < 15; i++)
            {
                show(assets.obook[i],screen);
                SDL_Delay(50);
                SDL_Flip(screen);
            } 
    //Showing Buttons
    show(assets.graphics[0],screen);
    show(assets.audio[0],screen);
    show(assets.keybinds[0],screen);
    //Update Screen
    SDL_Flip(screen);
    //Initiating Hover and Sound Button
    optiongame->hover=0;
    optiongame->soundbutton=Mix_LoadWAV("sfx/button.ogg"); //Chargement de sound effect
    Mix_VolumeChunk(optiongame->soundbutton,set_audio(config.volume,config.audio));
    SDL_Event event;
    //Option Loop
    while(run==2)
    {
    //Run Graphics
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
                    screen=SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_FULLSCREEN);
                else
                    screen=SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
            }
        optionrefresh(&assets,screen);
    }
    //Run Audio
    if (optiongame->audio)
    {
        run=audio(optiongame,&assets,screen,run);
        optionrefresh(&assets,screen);
    }
    //Wait for event
    while (SDL_PollEvent(&event)) {
    switch (event.type)
        {
        //On click on close windows : Quit Game
        case SDL_QUIT:
            run=0;
        break;
        //On Keyboard Press
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
                {
                    //On Keyboard press Escape : Check if Quit game
                    case (SDLK_ESCAPE):
                        if (check(screen,&run,0))
                            run=0; 
                        else
                            {
                            optionrefresh(&assets,screen);
                            }  
                    break;
                    //On Keyboard press m : Go to menu
                    case (SDLK_m):
                        run=1;
                    break;
                    //On Keyboard press p : Go to game
                    case (SDLK_p):
                        run=3;
                    break;
                    //On Keyboard press f : Go fullscreen
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
        //Init Motion
        SDL_GetMouseState(&x,&y);
        //Graphics Button
        optiongame->hover=optiongame->hover+animatehover(x,y,assets.graphics[1],assets.graphics[0],screen);
        //Audio Button
        optiongame->hover=optiongame->hover+animatehover(x,y,assets.audio[1],assets.audio[0],screen);
        //Keybinds Button
        optiongame->hover=optiongame->hover+animatehover(x,y,assets.keybinds[1],assets.keybinds[0],screen);
        //Arrow Button
        optiongame->hover=optiongame->hover+animatehover(x,y,assets.arrow[1],assets.arrow[0],screen);
        //Run Sound Once
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
        //Init Mouse Position
        SDL_GetMouseState(&x,&y);
        //On mouse click graphics : Run graphics
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
                            screen=SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_FULLSCREEN);
                        else
                            screen=SDL_SetVideoMode(config.resolution_w,config.resolution_h,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
                    }
                optionrefresh(&assets,screen);
            }
        //On mouse click arrow : Go back to menu
        if(hoverbutton(x,y,assets.arrow[0]))
            {
                run=1;
            }
        //On mouse click audio : Go to audio options
        if(hoverbutton(x,y,assets.audio[1]))
            {
                optiongame->audio=1;
                run=audio(optiongame,&assets,screen,run);
            }
        //On mouse click keybinds : Go to keybinds options
        if (hoverbutton(x,y,assets.keybinds[1]))
                run=1;


    break;
                    
        }
    }
        //Update Screen
        SDL_Flip(screen);
    }
    //Update Config
    write_config(&config);
    //Run Animation Backwards
    for ( i = 15; i> -1; i--)
            {
                show(assets.obook[i],screen);
                SDL_Delay(50);
                SDL_Flip(screen);
            } 
    //Free Options From Memory
    freeoption(assets);
    //Delay after running animation
    SDL_Delay(500);
return run;
}
// play 
int playmenu(SDL_Surface *screen,int *run,int state)
{
    //
    int x,y;
    playimage assets;
    initplay(&assets);
    show(assets.playwindow,screen);
    //
    if (state)
        {
            show(assets.cont[0],screen);
        }
        else
        {
            show(assets.cont[2],screen);
        }
    //
    show(assets.newgame[0],screen);
    show(assets.back[0],screen);

    SDL_Event event;
        int check=3;
        //Init Loop
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
            //If hover on yes
            if (hoverbutton(x,y,assets.newgame[0]))
            {
                show(assets.newgame[1],screen);
            }
            else
            {
                show(assets.newgame[0],screen);
            }          
            //If hover on no
            if (hoverbutton(x,y,assets.back[0]))
            {
                show(assets.back[1],screen);
            }
            else
            {
                show(assets.back[0],screen);
            }
            if (state)
            {
                if (hoverbutton(x,y,assets.cont[0]))
            {
                show(assets.cont[1],screen);
            }
            else
            {
                show(assets.cont[0],screen);
            } 
            }
            
            break;
            case SDL_MOUSEBUTTONUP:
            SDL_GetMouseState(&x,&y);
            //If Click on yes
            if (hoverbutton(x,y,assets.newgame[0]))
            {
                check=1;
            }
            //If Click on no
            if (hoverbutton(x,y,assets.back[0]))
            {
                check=0;
            }
            if (hoverbutton(x,y,assets.cont[0]))
            {
                check=2;
            }

      }  
            }
            //Update Screen
            SDL_Flip(screen);
        }
            //Return Result
            return check;
}