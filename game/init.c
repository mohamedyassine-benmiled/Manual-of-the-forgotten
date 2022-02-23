#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "include/menu.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include <SDL/SDL_ttf.h>
#include "include/init.h"
#include <string.h>

//To initialize Everything (What did it cost?)
void initcheck(CheckImage *assets)
{
    settings config;
        get_config(&config);
if (config.resolution_h==1080)
{
        assets->Window.surface=IMG_Load("graphics/1080/Check/Checkwindow.png");
        assets->Window.pos1.x=460;
        assets->Window.pos1.y=290;
        assets->Apply.surface=IMG_Load("graphics/1080/Check/Apply.png");
        assets->Apply.pos1.x=743;
        assets->Apply.pos1.y=435;
        assets->Quit.surface=IMG_Load("graphics/1080/Check/Quit.png");
        assets->Quit.pos1.x=686;
        assets->Quit.pos1.y=435;

        assets->Yes[0].surface=IMG_Load("graphics/1080/Check/Yes.png");
        assets->Yes[0].pos1.x=802;
        assets->Yes[0].pos1.y=597;
        assets->Yes[0].pos2=assets->Yes[0].pos1;
        assets->Yes[0].pos2.w=99;
        assets->Yes[0].pos2.h=78;

        assets->Yes[1].surface=IMG_Load("graphics/1080/Check/YesHover.png");
        assets->Yes[1].pos2= assets->Yes[0].pos2;
        assets->Yes[1].pos1= assets->Yes[0].pos1;


        assets->No[0].surface=IMG_Load("graphics/1080/Check/No.png");
        assets->No[0].pos1.x=1031;
        assets->No[0].pos1.y=597;
        assets->No[0].pos2=assets->No[0].pos1;
        assets->No[0].pos2.w=78;
        assets->No[0].pos2.h=78;
        
        assets->No[1].surface=IMG_Load("graphics/1080/Check/NoHover.png");
        assets->No[1].pos2= assets->No[0].pos2;
        assets->No[1].pos1= assets->No[0].pos1;
        }
else
if (config.resolution_h==720)
{
        assets->Window.surface=IMG_Load("graphics/720/Check/Checkwindow.png");
        assets->Window.pos1.x=306;
        assets->Window.pos1.y=193;
        assets->Apply.surface=IMG_Load("graphics/720/Check/Apply.png");
        assets->Apply.pos1.x=495;
        assets->Apply.pos1.y=290;
        assets->Quit.surface=IMG_Load("graphics/720/Check/Quit.png");
        assets->Quit.pos1.x=457;
        assets->Quit.pos1.y=290;

        assets->Yes[0].surface=IMG_Load("graphics/720/Check/Yes.png");
        assets->Yes[0].pos1.x=534;
        assets->Yes[0].pos1.y=398;
        assets->Yes[0].pos2=assets->Yes[0].pos1;
        assets->Yes[0].pos2.w=66;
        assets->Yes[0].pos2.h=52;

        assets->Yes[1].surface=IMG_Load("graphics/720/Check/YesHover.png");
        assets->Yes[1].pos2= assets->Yes[0].pos2;
        assets->Yes[1].pos1= assets->Yes[0].pos1;


        assets->No[0].surface=IMG_Load("graphics/720/Check/No.png");
        assets->No[0].pos1.x=687;
        assets->No[0].pos1.y=398;
        assets->No[0].pos2=assets->No[0].pos1;
        assets->No[0].pos2.w=52;
        assets->No[0].pos2.h=52;
        
        assets->No[1].surface=IMG_Load("graphics/720/Check/NoHover.png");
        assets->No[1].pos2= assets->No[0].pos2;
        assets->No[1].pos1= assets->No[0].pos1;
}
else
printf("\nError : Incorrect Resolution , Delete config.cfg and restart the game.");
}

void initvideo()
{
    TTF_Init();
     SDL_Init(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(IMG_Load("graphics/1080/Logo.png"),NULL);
                SDL_WM_SetCaption("Manual of the forgotten",NULL);
                TTF_Init();
}

void initmenu(MenuImage *assets)
{
text t;
settings config;
        get_config(&config);
if (config.resolution_h==1080)
{
     //Background
        assets->background.surface=IMG_Load("graphics/1080/Texture.png");
        assets->background.pos1.x=0;
        assets->background.pos1.y=0;
    //Logo Game
    char logo [50];
    for(int i=0;i<4;i++)
    {
    sprintf(logo,"graphics/1080/Logo/Logo%d.png",i);
    assets->logo[i].surface=IMG_Load(logo);
    assets->logo[i].pos1.x=619;
    assets->logo[i].pos1.y=47;
    }
    //Book
    for(int i=0;i<13;i++)
    {
    sprintf(logo,"graphics/1080/Kteb/ClosedBook%d.png",i);
    assets->cbook[i].surface=IMG_Load(logo);
    assets->cbook[i].pos1.x=1374;
    assets->cbook[i].pos1.y=408;
    }

    //Play Button
    assets->play[0].surface = IMG_Load("graphics/1080/Buttons/Play.png");
    assets->play[0].pos1.x=181;
    assets->play[0].pos1.y=408;
    assets->play[0].pos2.x=316;
    assets->play[0].pos2.y=417;
    assets->play[0].pos2.w=206;
    assets->play[0].pos2.h=120;
    assets->play[1].surface = IMG_Load("graphics/1080/Buttons/PlayOnHover.png");
    assets->play[1].pos1=assets->play[0].pos1;
    assets->play[1].pos2=assets->play[0].pos2;

    //Options Button
    assets->options[0].surface = IMG_Load("graphics/1080/Buttons/Option.png");
    assets->options[0].pos1.x=181;
    assets->options[0].pos1.y=578;
    assets->options[0].pos2.x=324;
    assets->options[0].pos2.y=586;
    assets->options[0].pos2.w=350;
    assets->options[0].pos2.h=122;
    assets->options[1].surface = IMG_Load("graphics/1080/Buttons/OptionOnHover.png");
    assets->options[1].pos1=assets->options[0].pos1;
    assets->options[1].pos2=assets->options[0].pos2;

    //Quit Button
    assets->quit[0].surface = IMG_Load("graphics/1080/Buttons/Quit.png");
    assets->quit[0].pos1.x=181;
    assets->quit[0].pos1.y=754;
    assets->quit[0].pos2.x=324;
    assets->quit[0].pos2.y=765;
    assets->quit[0].pos2.w=250;
    assets->quit[0].pos2.h=131;
    assets->quit[1].surface = IMG_Load("graphics/1080/Buttons/QuitOnHover.png");
    assets->quit[1].pos1=assets->quit[0].pos1;
    assets->quit[1].pos2=assets->quit[0].pos2;

    //Logo Group
    assets->logogroup.surface = IMG_Load("graphics/1080/Logo/Logo.png");
    assets->logogroup.pos1.x=1658;
    assets->logogroup.pos1.y=909;
    //Text copyrights
    
    assets->copyright.pos1.x=661;
    assets->copyright.pos1.y=992;
    //color
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    strcpy(t.texte,"TMOF beta version 1.0/2022||Created by NEMESIS inc.");
t.font=TTF_OpenFont("ttf/alagard.ttf",30);
if (!(assets->copyright.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)))
{
    printf("Wow an error ? I love this : %s",TTF_GetError());
};
}
else
if (config.resolution_h==720)
{
         //Background
        assets->background.surface=IMG_Load("graphics/720/Texture.png");
        assets->background.pos1.x=0;
        assets->background.pos1.y=0;
    //Logo Game
    char logo [50];
    for(int i=0;i<4;i++)
    {
    sprintf(logo,"graphics/720/Logo/Logo%d.png",i);
    assets->logo[i].surface=IMG_Load(logo);
    assets->logo[i].pos1.x=413;
    assets->logo[i].pos1.y=31;
    }
    //Book
    for(int i=0;i<13;i++)
    {
    sprintf(logo,"graphics/720/Kteb/ClosedBook%d.png",i);
    assets->cbook[i].surface=IMG_Load(logo);
    assets->cbook[i].pos1.x=916;
    assets->cbook[i].pos1.y=272;
    }

    //Play Button
    assets->play[0].surface = IMG_Load("graphics/720/Buttons/Play.png");
    assets->play[0].pos1.x=120;
    assets->play[0].pos1.y=272;
    assets->play[0].pos2.x=210;
    assets->play[0].pos2.y=278;
    assets->play[0].pos2.w=137;
    assets->play[0].pos2.h=80;
    assets->play[1].surface = IMG_Load("graphics/720/Buttons/PlayOnHover.png");
    assets->play[1].pos1=assets->play[0].pos1;
    assets->play[1].pos2=assets->play[0].pos2;

    //Options Button
    assets->options[0].surface = IMG_Load("graphics/720/Buttons/Option.png");
    assets->options[0].pos1.x=120;
    assets->options[0].pos1.y=385;
    assets->options[0].pos2.x=216;
    assets->options[0].pos2.y=390;
    assets->options[0].pos2.w=233;
    assets->options[0].pos2.h=81;
    assets->options[1].surface = IMG_Load("graphics/720/Buttons/OptionOnHover.png");
    assets->options[1].pos1=assets->options[0].pos1;
    assets->options[1].pos2=assets->options[0].pos2;

    //Quit Button
    assets->quit[0].surface = IMG_Load("graphics/720/Buttons/Quit.png");
    assets->quit[0].pos1.x=120;
    assets->quit[0].pos1.y=502;
    assets->quit[0].pos2.x=216;
    assets->quit[0].pos2.y=510;
    assets->quit[0].pos2.w=166;
    assets->quit[0].pos2.h=74;
    assets->quit[1].surface = IMG_Load("graphics/720/Buttons/QuitOnHover.png");
    assets->quit[1].pos1=assets->quit[0].pos1;
    assets->quit[1].pos2=assets->quit[0].pos2;

    //Logo Group
    assets->logogroup.surface = IMG_Load("graphics/720/Logo/Logo.png");
    assets->logogroup.pos1.x=1105;
    assets->logogroup.pos1.y=606;
    //Text copyrights
    
    assets->copyright.pos1.x=440;
    assets->copyright.pos1.y=661;
    //color
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    strcpy(t.texte,"TMOF beta version 1.0/2022||Created by NEMESIS inc.");
t.font=TTF_OpenFont("ttf/alagard.ttf",20);
if (!(assets->copyright.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)))
{
    printf("Wow an error ? I love this : %s",TTF_GetError());
};
}
else
printf("\nError : Incorrect Resolution , Delete config.cfg and restart the game.");
}

void initoption(OptionImage *assets)
{
    settings config;
        get_config(&config);
            text t;
if (config.resolution_h==1080)
{
    char logo[50];
    assets->background.surface=IMG_Load("graphics/1080/Texture.png");
    assets->background.pos1.x=0;
    assets->background.pos1.y=0;
    assets->logogroup.surface = IMG_Load("graphics/1080/Logo/Logo.png");
    assets->logogroup.pos1.x=1658;
    assets->logogroup.pos1.y=909;
    for(int i=0;i<15;i++)
    {
    sprintf(logo,"graphics/1080/Kteb/OpeningBook%d.png",i);
    assets->obook[i].surface=IMG_Load(logo);
    assets->obook[i].pos1.x=423;
    assets->obook[i].pos1.y=-8;
    }
    assets->arrow[0].surface=IMG_Load("graphics/1080/Options/arrow.png");
    assets->arrow[0].pos1.x=1516;
    assets->arrow[0].pos1.y=454;
    assets->arrow[0].pos2.x=1516;
    assets->arrow[0].pos2.y=454;  
    assets->arrow[0].pos2.w=180;
    assets->arrow[0].pos2.h=170; 
    assets->arrow[1].surface=IMG_Load("graphics/1080/Options/arrow.png");
    assets->arrow[1].pos1=assets->arrow[0].pos1;
    assets->arrow[1].pos2=assets->arrow[0].pos2;
    t.font=TTF_OpenFont("ttf/alagard.ttf",65);
    
    strcpy(t.texte,"Graphics");
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    assets->graphics[0].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->graphics[0].pos1.x=580;
    assets->graphics[0].pos1.y=403;
    assets->graphics[0].pos2.x=580;
    assets->graphics[0].pos2.y=403;  
    assets->graphics[0].pos2.w=264;
    assets->graphics[0].pos2.h=67; 
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    assets->graphics[1].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->graphics[1].pos1=assets->graphics[0].pos1;
    assets->graphics[1].pos2=assets->graphics[0].pos2;

    
    
    
    
    
    
    
    
    strcpy(t.texte,"Audio");
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    assets->audio[0].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->audio[0].pos1.x=620;
    assets->audio[0].pos1.y=512;
    assets->audio[0].pos2.x=620;
    assets->audio[0].pos2.y=512;  
    assets->audio[0].pos2.w=159;
    assets->audio[0].pos2.h=53;      
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    assets->audio[1].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->audio[1].pos1=assets->audio[0].pos1;
    assets->audio[1].pos2=assets->audio[0].pos2;

    
    strcpy(t.texte,"Keybinds");  
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    
    assets->keybinds[0].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->keybinds[0].pos1.x=580;
    assets->keybinds[0].pos1.y=608;
    assets->keybinds[0].pos2.x=580;
    assets->keybinds[0].pos2.y=608;  
    assets->keybinds[0].pos2.w=246;
    assets->keybinds[0].pos2.h=67;       
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    assets->keybinds[1].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->keybinds[1].pos1=assets->keybinds[0].pos1;
    assets->keybinds[1].pos2=assets->keybinds[0].pos2;






   


   TTF_CloseFont(t.font);
}
else
if (config.resolution_h==720)
{

    char logo[50];
    assets->background.surface=IMG_Load("graphics/720/Texture.png");
    assets->background.pos1.x=0;
    assets->background.pos1.y=0;
    assets->logogroup.surface = IMG_Load("graphics/720/Logo/Logo.png");
    assets->logogroup.pos1.x=1105;
    assets->logogroup.pos1.y=606;
    for(int i=0;i<15;i++)
    {
    sprintf(logo,"graphics/720/Kteb/OpeningBook%d.png",i);
    assets->obook[i].surface=IMG_Load(logo);
    assets->obook[i].pos1.x=282;
    assets->obook[i].pos1.y=-3;
    }
    assets->arrow[0].surface=IMG_Load("graphics/720/Options/arrow.png");
    assets->arrow[0].pos1.x=1010;
    assets->arrow[0].pos1.y=302;
    assets->arrow[0].pos2.x=1010;
    assets->arrow[0].pos2.y=302;  
    assets->arrow[0].pos2.w=120;
    assets->arrow[0].pos2.h=113; 
    assets->arrow[1].surface=IMG_Load("graphics/720/Options/arrow.png");
    assets->arrow[1].pos1=assets->arrow[0].pos1;
    assets->arrow[1].pos2=assets->arrow[0].pos2;
    t.font=TTF_OpenFont("ttf/alagard.ttf",43);
    
    strcpy(t.texte,"Graphics");
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    assets->graphics[0].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->graphics[0].pos1.x=386;
    assets->graphics[0].pos1.y=268;
    assets->graphics[0].pos2=assets->graphics[0].pos1;
    assets->graphics[0].pos2.w=164;
    assets->graphics[0].pos2.h=44; 
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    assets->graphics[1].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->graphics[1].pos1=assets->graphics[0].pos1;
    assets->graphics[1].pos2=assets->graphics[0].pos2;

    
    
    
    
    
    
    
    
    strcpy(t.texte,"Audio");
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    assets->audio[0].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->audio[0].pos1.x=413;
    assets->audio[0].pos1.y=341;
    assets->audio[0].pos2=assets->audio[0].pos1;
    assets->audio[0].pos2.w=106;
    assets->audio[0].pos2.h=35;      
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    assets->audio[1].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->audio[1].pos1=assets->audio[0].pos1;
    assets->audio[1].pos2=assets->audio[0].pos2;

    
    strcpy(t.texte,"Keybinds");  
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    
    assets->keybinds[0].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->keybinds[0].pos1.x=386;
    assets->keybinds[0].pos1.y=405;
    assets->keybinds[0].pos2=assets->keybinds[0].pos1;
    assets->keybinds[0].pos2.w=170;
    assets->keybinds[0].pos2.h=44;       
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    assets->keybinds[1].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->keybinds[1].pos1=assets->keybinds[0].pos1;
    assets->keybinds[1].pos2=assets->keybinds[0].pos2;






   


   TTF_CloseFont(t.font);
}
else
printf("\nError : Incorrect Resolution , Delete config.cfg and restart the game.");
}




void initgraphics(graphicimage *assets)
{
    text t;
    settings config;
        get_config(&config);

    if (config.resolution_h==1080)
    {
    //Graphics Init
    t.font=TTF_OpenFont("ttf/alagard.ttf",36);
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    strcpy(t.texte,"Select Resolution");
    assets->selectresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->selectresolution.pos1.x=1063;
    assets->selectresolution.pos1.y=395;         
    

    strcpy(t.texte,"Window Settings");
    assets->windowsettings.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->windowsettings.pos1.x=1066;
    assets->windowsettings.pos1.y=574;


    assets->firstbox[0].surface=IMG_Load("graphics/1080/Options/unbox.png");
    assets->firstbox[0].pos1.x=1066;
    assets->firstbox[0].pos1.y=655;
    assets->firstbox[0].pos2.x=1066;
    assets->firstbox[0].pos2.y=655;
    assets->firstbox[0].pos2.w=25;
    assets->firstbox[0].pos2.h=25;
    assets->firstbox[1].surface=IMG_Load("graphics/1080/Options/box.png");
    assets->firstbox[1].pos1.x=1066;
    assets->firstbox[1].pos1.y=655;
    assets->firstbox[1].pos2.x=1066;
    assets->firstbox[1].pos2.y=655;
    assets->firstbox[1].pos2.w=25;
    assets->firstbox[1].pos2.h=25;




    assets->secondbox[0].surface=IMG_Load("graphics/1080/Options/unbox.png");
    assets->secondbox[0].pos1.x=1235;
    assets->secondbox[0].pos1.y=655;
    assets->secondbox[0].pos2.x=1235;
    assets->secondbox[0].pos2.y=655;
    assets->secondbox[0].pos2.w=25;
    assets->secondbox[0].pos2.h=25;
    assets->secondbox[1].surface=IMG_Load("graphics/1080/Options/box.png");
    assets->secondbox[1].pos1.x=1235;
    assets->secondbox[1].pos1.y=655;
    assets->secondbox[1].pos2.x=1235;
    assets->secondbox[1].pos2.y=655;
    assets->secondbox[1].pos2.w=25;
    assets->secondbox[1].pos2.h=25;







    assets->boxresolution.surface=IMG_Load("graphics/1080/Options/ResolutionBox.png");
    assets->boxresolution.pos1.x=1060;
    assets->boxresolution.pos1.y=453;
    assets->boxresolution.pos2.x=1060;
    assets->boxresolution.pos2.y=453;
    assets->boxresolution.pos2.w=291;
    assets->boxresolution.pos2.h=65;



    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    strcpy(t.texte,"1920x1080");
    assets->currentresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->currentresolution.pos1.x=1101;
    assets->currentresolution.pos1.y=468;
    


    strcpy(t.texte,"1280x720");
    assets->listresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->listresolution.pos1.x=1130;
    assets->listresolution.pos1.y=531;

    t.font=TTF_OpenFont("ttf/alagard.ttf",24);
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;

    strcpy(t.texte,"Fullscreen");
    assets->fullscreen.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->fullscreen.pos1.x=1092;
    assets->fullscreen.pos1.y=657;



    strcpy(t.texte,"Windowed");
    assets->windowed.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->windowed.pos1.x=1261;
    assets->windowed.pos1.y=657;




    
    assets->listresolutionbox[0].surface=IMG_Load("graphics/1080/Options/ListResolution.png");
    assets->listresolutionbox[0].pos1.x=1060;
    assets->listresolutionbox[0].pos1.y=518;
    assets->listresolutionbox[0].pos2= assets->listresolutionbox[0].pos1;
    assets->listresolutionbox[0].pos2.w=291;
    assets->listresolutionbox[0].pos2.h=65;
    assets->listresolutionbox[1].surface=IMG_Load("graphics/1080/Options/ListResolutionHover.png");
    assets->listresolutionbox[1].pos1.x=1060;
    assets->listresolutionbox[1].pos1.y=518;
    assets->listresolutionbox[1].pos2= assets->listresolutionbox[1].pos1;
    assets->listresolutionbox[1].pos2.w=291;
    assets->listresolutionbox[1].pos2.h=65;

    

    TTF_CloseFont(t.font);
    }
    else
    if (config.resolution_h==720)
    {
    //Graphics Init
    t.font=TTF_OpenFont("ttf/alagard.ttf",24);
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    strcpy(t.texte,"Select Resolution");
    assets->selectresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->selectresolution.pos1.x=708;
    assets->selectresolution.pos1.y=263;         
    

    strcpy(t.texte,"Window Settings");
    assets->windowsettings.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->windowsettings.pos1.x=710;
    assets->windowsettings.pos1.y=382;


    assets->firstbox[0].surface=IMG_Load("graphics/720/Options/unbox.png");
    assets->firstbox[0].pos1.x=710;
    assets->firstbox[0].pos1.y=436;
    assets->firstbox[0].pos2.x=710;
    assets->firstbox[0].pos2.y=436;
    assets->firstbox[0].pos2.w=16;
    assets->firstbox[0].pos2.h=16;
    assets->firstbox[1].surface=IMG_Load("graphics/720/Options/box.png");
    assets->firstbox[1].pos1.x=710;
    assets->firstbox[1].pos1.y=436;
    assets->firstbox[1].pos2.x=710;
    assets->firstbox[1].pos2.y=436;
    assets->firstbox[1].pos2.w=16;
    assets->firstbox[1].pos2.h=16;




    assets->secondbox[0].surface=IMG_Load("graphics/720/Options/unbox.png");
    assets->secondbox[0].pos1.x=823;
    assets->secondbox[0].pos1.y=436;
    assets->secondbox[0].pos2.x=823;
    assets->secondbox[0].pos2.y=436;
    assets->secondbox[0].pos2.w=16;
    assets->secondbox[0].pos2.h=16;
    assets->secondbox[1].surface=IMG_Load("graphics/720/Options/box.png");
    assets->secondbox[1].pos1.x=823;
    assets->secondbox[1].pos1.y=436;
    assets->secondbox[1].pos2.x=823;
    assets->secondbox[1].pos2.y=436;
    assets->secondbox[1].pos2.w=16;
    assets->secondbox[1].pos2.h=16;







    assets->boxresolution.surface=IMG_Load("graphics/720/Options/ResolutionBox.png");
    assets->boxresolution.pos1.x=706;
    assets->boxresolution.pos1.y=302;
    assets->boxresolution.pos2.x=706;
    assets->boxresolution.pos2.y=302;
    assets->boxresolution.pos2.w=194;
    assets->boxresolution.pos2.h=43;



    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    
    strcpy(t.texte,"1280x720");
    assets->currentresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->currentresolution.pos1.x=734;
    assets->currentresolution.pos1.y=312;
    

    strcpy(t.texte,"1920x1080");
    assets->listresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->listresolution.pos1.x=753;
    assets->listresolution.pos1.y=354;

    t.font=TTF_OpenFont("ttf/alagard.ttf",16);
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;

    strcpy(t.texte,"Fullscreen");
    assets->fullscreen.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->fullscreen.pos1.x=728;
    assets->fullscreen.pos1.y=438;



    strcpy(t.texte,"Windowed");
    assets->windowed.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->windowed.pos1.x=840;
    assets->windowed.pos1.y=438;




    
    assets->listresolutionbox[0].surface=IMG_Load("graphics/720/Options/ListResolution.png");
    assets->listresolutionbox[0].pos1.x=706;
    assets->listresolutionbox[0].pos1.y=345;
    assets->listresolutionbox[0].pos2= assets->listresolutionbox[0].pos1;
    assets->listresolutionbox[0].pos2.w=194;
    assets->listresolutionbox[0].pos2.h=43;
    assets->listresolutionbox[1].surface=IMG_Load("graphics/720/Options/ListResolutionHover.png");
    assets->listresolutionbox[1].pos1.x=706;
    assets->listresolutionbox[1].pos1.y=345;
    assets->listresolutionbox[1].pos2= assets->listresolutionbox[1].pos1;
    assets->listresolutionbox[1].pos2.w=194;
    assets->listresolutionbox[1].pos2.h=43;

    

    TTF_CloseFont(t.font);
    }
    else
    printf("\nError : Incorrect Resolution , Delete config.cfg and restart the game.");


}


void initaudio(audioimage *assets)
{
    text t;
        settings config;
        get_config(&config);
    //Audio Init
if (config.resolution_h==1080)
{
    t.font=TTF_OpenFont("ttf/alagard.ttf",36);
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;


    strcpy(t.texte,"Volume");
    assets->volume.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->volume.pos1.x=1150;
    assets->volume.pos1.y=427;       
    


    strcpy(t.texte,"Audio");
    assets->audio.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->audio.pos1.x=1167;
    assets->audio.pos1.y=550;



    assets->onbox[0].surface=IMG_Load("graphics/1080/Options/unbox.png");
    assets->onbox[0].pos1.x=1142;
    assets->onbox[0].pos1.y=598;
    assets->onbox[0].pos2=assets->onbox[0].pos1;
    assets->onbox[0].pos2.w=25;
    assets->onbox[0].pos2.h=25;    
    
    assets->onbox[1].surface=IMG_Load("graphics/1080/Options/box.png");
    assets->onbox[1].pos1.x=1142;
    assets->onbox[1].pos1.y=598;
    assets->onbox[1].pos2=assets->onbox[1].pos1;
    assets->onbox[1].pos2.w=25;
    assets->onbox[1].pos2.h=25;    
    


    assets->offbox[0].surface=IMG_Load("graphics/1080/Options/unbox.png");
    assets->offbox[0].pos1.x=1265;
    assets->offbox[0].pos1.y=598;
    assets->offbox[0].pos2=assets->offbox[0].pos1;
    assets->offbox[0].pos2.w=25;
    assets->offbox[0].pos2.h=25;
    assets->offbox[1].surface=IMG_Load("graphics/1080/Options/box.png");
    assets->offbox[1].pos1.x=1265;
    assets->offbox[1].pos1.y=598;
    assets->offbox[1].pos2=assets->offbox[1].pos1;
    assets->offbox[1].pos2.w=25;
    assets->offbox[1].pos2.h=25;

    t.font=TTF_OpenFont("ttf/alagard.ttf",18);
    strcpy(t.texte,"on");
    assets->on.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->on.pos1.x=1143;
    assets->on.pos1.y=625;    



    strcpy(t.texte,"off");
    assets->off.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->off.pos1.x=1264;
    assets->off.pos1.y=625;


     t.font=TTF_OpenFont("ttf/alagard.ttf",36);
    strcpy(t.texte,"+");
    assets->plus.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->plus.pos1.x=1378;
    assets->plus.pos1.y=472;
    assets->plus.pos2=assets->plus.pos1;
    assets->plus.pos2.w=30;
    assets->plus.pos2.h=30;

    strcpy(t.texte,"-");
    assets->minus.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->minus.pos1.x=1040;
    assets->minus.pos1.y=472;
    assets->minus.pos2=assets->minus.pos1;
    assets->minus.pos2.w=30;
    assets->minus.pos2.h=30;
            assets->circle[0].surface=IMG_Load("graphics/1080/Options/Circle.png");
            assets->circle[0].pos1.x=1060;
            assets->circle[0].pos1.y=477;
        for(int i=1;i<10;i++)
        {
            assets->circle[i].surface=IMG_Load("graphics/1080/Options/Circle.png");
            assets->circle[i].pos1.x=assets->circle[i-1].pos1.x+32;
            assets->circle[i].pos1.y=477;
        }
            assets->circle[10].surface=IMG_Load("graphics/1080/Options/HideCircles.png");
            assets->circle[10].pos1.x=1062;
            assets->circle[10].pos1.y=473;
    assets->audiobar.surface=IMG_Load("graphics/1080/Options/AudioBar.png");
            assets->audiobar.pos1.x=1076;
            assets->audiobar.pos1.y=483;
    TTF_CloseFont(t.font);
}
else
if (config.resolution_h==720)
{
    t.font=TTF_OpenFont("ttf/alagard.ttf",24);
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;


    strcpy(t.texte,"Volume");
    assets->volume.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->volume.pos1.x=766;
    assets->volume.pos1.y=284;       
    


    strcpy(t.texte,"Audio");
    assets->audio.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->audio.pos1.x=778;
    assets->audio.pos1.y=366;



    assets->onbox[0].surface=IMG_Load("graphics/720/Options/unbox.png");
    assets->onbox[0].pos1.x=761;
    assets->onbox[0].pos1.y=398;
    assets->onbox[0].pos2=assets->onbox[0].pos1;
    assets->onbox[0].pos2.w=16;
    assets->onbox[0].pos2.h=16;    
    
    assets->onbox[1].surface=IMG_Load("graphics/720/Options/box.png");
    assets->onbox[1].pos1.x=761;
    assets->onbox[1].pos1.y=398;
    assets->onbox[1].pos2=assets->onbox[1].pos1;
    assets->onbox[1].pos2.w=16;
    assets->onbox[1].pos2.h=16;    
    


    assets->offbox[0].surface=IMG_Load("graphics/720/Options/unbox.png");
    assets->offbox[0].pos1.x=842;
    assets->offbox[0].pos1.y=398;
    assets->offbox[0].pos2=assets->offbox[0].pos1;
    assets->offbox[0].pos2.w=16;
    assets->offbox[0].pos2.h=16;
    assets->offbox[1].surface=IMG_Load("graphics/720/Options/box.png");
    assets->offbox[1].pos1.x=842;
    assets->offbox[1].pos1.y=398;
    assets->offbox[1].pos2=assets->offbox[1].pos1;
    assets->offbox[1].pos2.w=16;
    assets->offbox[1].pos2.h=16;

    t.font=TTF_OpenFont("ttf/alagard.ttf",12);
    strcpy(t.texte,"on");
    assets->on.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->on.pos1.x=762;
    assets->on.pos1.y=416;    



    strcpy(t.texte,"off");
    assets->off.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->off.pos1.x=842;
    assets->off.pos1.y=416;


     t.font=TTF_OpenFont("ttf/alagard.ttf",24);
    strcpy(t.texte,"+");
    assets->plus.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->plus.pos1.x=918;
    assets->plus.pos1.y=314;
    assets->plus.pos2=assets->plus.pos1;
    assets->plus.pos2.w=20;
        assets->plus.pos2.h=20;

    strcpy(t.texte,"-");
    assets->minus.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
    assets->minus.pos1.x=693;
    assets->minus.pos1.y=314;
    assets->minus.pos2=assets->minus.pos1;
    assets->minus.pos2.w=20;
    assets->minus.pos2.h=20;

            assets->circle[0].surface=IMG_Load("graphics/720/Options/Circle.png");
            assets->circle[0].pos1.x=706;
            assets->circle[0].pos1.y=318;
        for(int i=1;i<10;i++)
        {
            assets->circle[i].surface=IMG_Load("graphics/720/Options/Circle.png");
            assets->circle[i].pos1.x=assets->circle[i-1].pos1.x+21;
            assets->circle[i].pos1.y=318;
        }

    assets->audiobar.surface=IMG_Load("graphics/720/Options/AudioBar.png");
            assets->audiobar.pos1.x=713;
            assets->audiobar.pos1.y=322;
    TTF_CloseFont(t.font);
}
else
printf("\nError : Incorrect Resolution , Delete config.cfg and restart the game.");
}
