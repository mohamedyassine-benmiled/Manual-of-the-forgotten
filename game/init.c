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
void initsettings()
{

}

void initvideo()
{
     SDL_Init(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(IMG_Load("graphics/1080/Logo.png"),NULL);
                SDL_WM_SetCaption("Manual of the forgotten",NULL);
}

void initmenu(MenuImage *assets)
{
text t;
TTF_Init();
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
    assets->logo[i].pos1.x=291;
    assets->logo[i].pos1.y=0;
    }
    //Book
    assets->book.pos1.x=941;
    assets->book.pos1.y=140;

    //Play Button
    assets->play[0].surface = IMG_Load("graphics/1080/Buttons/Play.png");
    assets->play[0].pos1.x=0;
    assets->play[0].pos1.y=359;
    assets->play[0].pos2.x=255;
    assets->play[0].pos2.y=381;
    assets->play[0].pos2.w=237;
    assets->play[0].pos2.h=139;
    assets->play[1].surface = IMG_Load("graphics/1080/Buttons/PlayOnHover.png");
    assets->play[1].pos1=assets->play[0].pos1;
    assets->play[1].pos2=assets->play[0].pos2;

    //Options Button
    assets->options[0].surface = IMG_Load("graphics/1080/Buttons/Option.png");
    assets->options[0].pos1.x=0;
    assets->options[0].pos1.y=547;
    assets->options[0].pos2.x=255;
    assets->options[0].pos2.y=574;
    assets->options[0].pos2.w=424;
    assets->options[0].pos2.h=142;
    assets->options[1].surface = IMG_Load("graphics/1080/Buttons/OptionOnHover.png");
    assets->options[1].pos1=assets->options[0].pos1;
    assets->options[1].pos2=assets->options[0].pos2;

    //Quit Button
    assets->quit[0].surface = IMG_Load("graphics/1080/Buttons/Quit.png");
    assets->quit[0].pos1.x=0;
    assets->quit[0].pos1.y=734;
    assets->quit[0].pos2.x=255;
    assets->quit[0].pos2.y=771;
    assets->quit[0].pos2.w=250;
    assets->quit[0].pos2.h=131;
    assets->quit[1].surface = IMG_Load("graphics/1080/Buttons/QuitOnHover.png");
    assets->quit[1].pos1=assets->quit[0].pos1;
    assets->quit[1].pos2=assets->quit[0].pos2;

    //Logo Group
    assets->logogroup.surface = IMG_Load("graphics/1080/Logo/Logo.png");
    assets->logogroup.pos1.x=1690;
    assets->logogroup.pos1.y=857;
    //Text copyrights
    
    assets->copyright.pos1.x=565;
    assets->copyright.pos1.y=1045;
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

void initoption(OptionImage *assets)
{
    assets->background.surface=IMG_Load("graphics/1080/Texture.png");
    assets->background.pos1.x=0;
    assets->background.pos1.y=0;
    assets->logo.surface = IMG_Load("graphics/1080/Logo/Logo.png");
    assets->logo.pos1.x=220;
    assets->logo.pos1.y=74;
    assets->logogroup.surface = IMG_Load("graphics/1080/Logo/Logo.png");
    assets->logogroup.pos1.x=1690;
    assets->logogroup.pos1.y=857;
    assets->obook.surface = IMG_Load("graphics/1080/Options/openbook.png");
    assets->obook.pos1.x=401;
    assets->obook.pos1.y=-55;
}




