#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "include/menu.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "include/init.h"

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

void initmenu(MenuGame *menugame)
{
    menugame->Music=Mix_LoadMUS("sfx/menu.ogg");
    menugame->soundbutton=Mix_LoadWAV("sfx/button.ogg"); //Chargement de sound effect
    //Background
    initBackground(&menugame->assets.background,"graphics/1080/Texture.png");
    //Logo Game
    menugame->assets.logo.pos1.x=291;
    menugame->assets.logo.pos1.y=0;
    //Book
    menugame->assets.book.pos1.x=941;
    menugame->assets.book.pos1.y=140;

    //Play Button
    menugame->assets.play[0].surface = IMG_Load("graphics/1080/Buttons/Play.png");
    menugame->assets.play[0].pos1.x=0;
    menugame->assets.play[0].pos1.y=359;
    menugame->assets.play[0].pos2.x=255;
    menugame->assets.play[0].pos2.y=381;
    menugame->assets.play[0].pos2.w=237;
    menugame->assets.play[0].pos2.h=139;
    menugame->assets.play[1].surface = IMG_Load("graphics/1080/Buttons/PlayOnHover.png");
    menugame->assets.play[1].pos1=menugame->assets.play[0].pos1;
    menugame->assets.play[1].pos2=menugame->assets.play[0].pos2;

    //Options Button
    menugame->assets.options[0].surface = IMG_Load("graphics/1080/Buttons/Option.png");
    menugame->assets.options[0].pos1.x=0;
    menugame->assets.options[0].pos1.y=547;
    menugame->assets.options[0].pos2.x=255;
    menugame->assets.options[0].pos2.y=574;
    menugame->assets.options[0].pos2.w=424;
    menugame->assets.options[0].pos2.h=142;
    menugame->assets.options[1].surface = IMG_Load("graphics/1080/Buttons/OptionOnHover.png");
    menugame->assets.options[1].pos1=menugame->assets.options[0].pos1;
    menugame->assets.options[1].pos2=menugame->assets.options[0].pos2;

    //Quit Button
    menugame->assets.quit[0].surface = IMG_Load("graphics/1080/Buttons/Quit.png");
    menugame->assets.quit[0].pos1.x=0;
    menugame->assets.quit[0].pos1.y=734;
    menugame->assets.quit[0].pos2.x=255;
    menugame->assets.quit[0].pos2.y=771;
    menugame->assets.quit[0].pos2.w=250;
    menugame->assets.quit[0].pos2.h=131;
    menugame->assets.quit[1].surface = IMG_Load("graphics/1080/Buttons/QuitOnHover.png");
    menugame->assets.quit[1].pos1=menugame->assets.quit[0].pos1;
    menugame->assets.quit[1].pos2=menugame->assets.quit[0].pos2;

    //Logo Group
    menugame->assets.logogroup.surface = IMG_Load("graphics/1080/Logo/Logo.png");
    menugame->assets.logogroup.pos1.x=1690;
    menugame->assets.logogroup.pos1.y=857;
}

void initoption(OptionGame *optiongame)
{
    initBackground(&optiongame->assets.background,"graphics/1080/Texture.png");
    optiongame->assets.logo.surface = IMG_Load("graphics/1080/Logo/Logo.png");
    optiongame->assets.logo.pos1.x=220;
    optiongame->assets.logo.pos1.y=74;
    optiongame->assets.logogroup.surface = IMG_Load("graphics/1080/Logo/Logo.png");
    optiongame->assets.logogroup.pos1.x=1690;
    optiongame->assets.logogroup.pos1.y=857;
}

void initgame(Game *game)
{
    initBackground(&game->assets.background,"graphics/1080/Game_Background.png");
}

