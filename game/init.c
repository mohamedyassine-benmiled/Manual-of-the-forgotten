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
    TTF_Init();
     SDL_Init(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(IMG_Load("graphics/1080/Logo.png"),NULL);
                SDL_WM_SetCaption("Manual of the forgotten",NULL);
                TTF_Init();
}

void initmenu(MenuImage *assets)
{
text t;

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
    assets->book.pos1.x=1374;
    assets->book.pos1.y=408;

    //Play Button
    assets->play[0].surface = IMG_Load("graphics/1080/Buttons/Play.png");
    assets->play[0].pos1.x=181;
    assets->play[0].pos1.y=477;
    assets->play[0].pos2.x=316;
    assets->play[0].pos2.y=417;
    assets->play[0].pos2.w=237;
    assets->play[0].pos2.h=139;
    assets->play[1].surface = IMG_Load("graphics/1080/Buttons/PlayOnHover.png");
    assets->play[1].pos1=assets->play[0].pos1;
    assets->play[1].pos2=assets->play[0].pos2;

    //Options Button
    assets->options[0].surface = IMG_Load("graphics/1080/Buttons/Option.png");
    assets->options[0].pos1.x=181;
    assets->options[0].pos1.y=578;
    assets->options[0].pos2.x=324;
    assets->options[0].pos2.y=586;
    assets->options[0].pos2.w=424;
    assets->options[0].pos2.h=142;
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
    text t;
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
    t.font=TTF_OpenFont("ttf/alagard.ttf",60);
    
    
    
    
    
    
    strcpy(t.texte,"Graphics");
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    assets->Graphics[0].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->Graphics[0].pos1.x=580;
    assets->Graphics[0].pos1.y=403;
    assets->Graphics[0].pos2.x=580;
    assets->Graphics[0].pos2.y=403;  
    assets->Graphics[0].pos2.w=264;
    assets->Graphics[0].pos2.h=67; 
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    assets->Graphics[1].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->Graphics[1].pos1->Graphics[0].pos1;

    
    
    
    
    
    
    
    
    
    strcpy(t.texte,"Audio");
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    assets->Audio[0].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->Audio[0].pos1.x=620;
    assets->Audio[0].pos1.y=512;
    assets->Audio[0].pos2.x=620;
    assets->Audio[0].pos2.y=512;  
    assets->Audio[0].pos2.w=159;
    assets->Audio[0].pos2.h=53;      
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    assets->Audio[1].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->Audio[1].pos1->Audio[0].pos1;

    
    
    strcpy(t.texte,"Keybinds");  
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;
    
    assets->Keybinds[0].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->keybinds[0].pos1.x=580;
    assets->Keybinds[0].pos1.y=608;
    assets->keybinds[0].pos2.x=580;
    assets->Keybinds[0].pos2.y=608;  
    assets->keybinds[0].pos2.w=246;
    assets->Keybinds[0].pos2.h=67;       
    t.textColor.r=164;
    t.textColor.g=164;
    t.textColor.b=164;
    assets->Keybinds[1].surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->keybinds[1].pos1->keybinds[0].pos1



//Graphics Init
    //Graphics Init

    assets->selectres.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->selectres[.pos1.x=1063;
    assets->selectres[.pos1.y=387;         
    

    
    assets->windowsettings.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->windowsettings.pos1.x=1066;
    assets->windowsettings.pos1.y=566;


    assets->firstbox.surface=IMG_Load("");
    assets->firstbox.pos1.x=1066;
    assets->firstbox.pos1.y=655;
    assets->firstbox.pos2.x=25;
    assets->firstbox.pos2.y=25;




    assets->secondbox.surface=IMG_Load("");
    assets->secondbox.pos1.x=1235;
    assets->secondbox.pos1.y=655;
    assets->secondbox.pos2.x=25;
    assets->secondbox.pos2.y=25;





    assets->fullscreen.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->fullscreen.pos1.x=1092;
    assets->fullscreen.pos1.y=655;




    assets->windowed.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->windowed.pos1.x=1261;
    assets->windowed.pos1.y=655;




    assets->boxresolution.surface=IMG_Load("");
    assets->boxresolution.pos1.x=1060;
    assets->boxresolution.pos1.y=453;
    assets->boxresolution.pos2.x=291;
    assets->boxresolution.pos2.y=65;





    assets->currentresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->currentresolution.pos1.x=1101;
    assets->currentresolution.pos1.y=462;
    




    assets->listresolution.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)));
    assets->listresolution.pos1.x=1130;
    assets->listresolution.pos1.y=526;






    
    assets->listresolutionbox.surface=IMG_Load("");
    assets->listresolutionbox.pos1.x=1060;
    assets->listresolutionbox.pos1.y=518;
    assets->listresolutionbox.pos2.x=291;
    assets->listresolutionbox.pos2.y=65;






    


    
    
  
 
}




