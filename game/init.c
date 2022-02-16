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
        SDL_WM_SetIcon(IMG_Load("Menu/Logo.png"),NULL);
                SDL_WM_SetCaption("Manual of the forgotten",NULL);
}

void initmenu(MenuGame *menugame)
{
    menugame->Music=Mix_LoadMUS("sfx/menu.ogg");
    menugame->soundbutton=Mix_LoadWAV("sfx/button.ogg"); //Chargement de sound effect
    initBackground(&menugame->assets.background,"Menu/BackgroundTest1.png");
    menugame->assets.play[1].surface = IMG_Load("Menu/Play2.png");
    menugame->assets.play[1].pos1.x=129;
    menugame->assets.play[1].pos1.y=374;
    menugame->assets.play[1].pos2.w=209;
    menugame->assets.play[1].pos2.h=118;
    menugame->assets.play[2].surface = IMG_Load("Menu/PlayOnHover.png");
    menugame->assets.play[2].pos1.x=129;
    menugame->assets.play[2].pos1.y=374;
    menugame->assets.play[2].pos2.w=209;
    menugame->assets.play[2].pos2.h=118;
    menugame->assets.options.surface = IMG_Load("Menu/Options2.png");
    menugame->assets.options.pos1.x=129;
    menugame->assets.options.pos1.y=512;
    menugame->assets.quit.surface = IMG_Load("Menu/Quit2.png");
    menugame->assets.quit.pos1.x=129;
    menugame->assets.quit.pos1.y=661;
    menugame->assets.logo.surface = IMG_Load("Menu/Logo.png");
    menugame->assets.logo.pos1.x=220;
    menugame->assets.logo.pos1.y=74;
    menugame->assets.logogroup.surface = IMG_Load("Menu/Logo.png");
    menugame->assets.logogroup.pos1.x=1690;
    menugame->assets.logogroup.pos1.y=857;
}

void initoption(OptionGame *optiongame)
{
    initBackground(&optiongame->assets.background,"Menu/Placeholder_Background.png");
    optiongame->assets.logo.surface = IMG_Load("Menu/Logo.png");
    optiongame->assets.logo.pos1.x=220;
    optiongame->assets.logo.pos1.y=74;
    optiongame->assets.logogroup.surface = IMG_Load("Menu/Logo.png");
    optiongame->assets.logogroup.pos1.x=1690;
    optiongame->assets.logogroup.pos1.y=857;
}

void initgame(Game *game)
{
    initBackground(&game->assets.background,"Menu/Game_Background.png");

}