/**
 * @file image.c
 * @author TMOF Team
 * @brief Image Functions
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/image.h"
#include "include/game.h"
#include "include/menu.h"
#include "include/declarations.h"
#include "include/config.h"
#include "include/enemy.h"
#include "include/minimap.h"
//Init to remove warnings
void gamerefresh(Game *g,SDL_Surface *screen);
void animationback(Background *bg);
void scrolling (Game *g);
void initminimap(Minimap *assets);
void updateminimap(Game *g);
void animation(Character *player);
void animationback2(Background *bg);


//Showing Graphics Images to refresh screen
void graphicsrefresh(graphicimage *assets,SDL_Surface *screen,int fullscreen)
{
    show(assets->boxresolution,screen);
    show(assets->selectresolution,screen);
    show(assets->windowsettings,screen);

    if (fullscreen)
    {
        show(assets->firstbox[0],screen);
        show(assets->secondbox[1],screen);
    }
    else
    {
        show(assets->firstbox[1],screen);
        show(assets->secondbox[0],screen);
    }

    show(assets->fullscreen,screen);
    show(assets->windowed,screen);
    show(assets->currentresolution,screen);
}
//Showing Menu Images to refresh screen
void menurefresh(MenuImage *assets,SDL_Surface *screen)
{
        show(assets->background,screen);
        show(assets->play[0],screen);
        show(assets->options[0],screen);
        show(assets->quit[0],screen);
        show(assets->logogroup,screen);
        show(assets->copyright,screen);
}
//Showing Option Images to refresh screen
void optionrefresh(OptionImage *assets,SDL_Surface *screen)
{
    show(assets->background,screen);
    show(assets->logogroup,screen); 
    show(assets->obook[14],screen);
    show(assets->arrow[0],screen);
    show (assets->graphics[0],screen);
    show (assets->audio[0],screen);
    show (assets->keybinds[0],screen);

}
//Showing Audio Images to refresh screen
void audiorefresh(audioimage *assets,SDL_Surface *screen,int audio)
{
    show(assets->volume,screen);
    show(assets->audio,screen);
    show(assets->on,screen);
    show(assets->off,screen);
    show(assets->minus,screen);
    show(assets->plus,screen);
    show(assets->audiobar,screen);
    if (audio)
    {
        show(assets->onbox[0],screen);
        show(assets->offbox[1],screen);
    }
    else
    {
        show(assets->onbox[1],screen);
        show(assets->offbox[0],screen);
    }
    
}
//Freeing Menu Images from memory
void freemenu(MenuImage assets)
{
SDL_FreeSurface(assets.play[0].surface);
SDL_FreeSurface(assets.options[0].surface);
SDL_FreeSurface(assets.quit[0].surface);
SDL_FreeSurface(assets.play[1].surface);
SDL_FreeSurface(assets.options[1].surface);
SDL_FreeSurface(assets.quit[1].surface);
SDL_FreeSurface(assets.background.surface);
SDL_FreeSurface(assets.logogroup.surface);
SDL_FreeSurface(assets.copyright.surface);
for (int i = 0; i < 4; i++)
{
    SDL_FreeSurface(assets.logo[i].surface);
}
for (int i = 0; i < 13; i++)
{
    SDL_FreeSurface(assets.cbook[i].surface);
}
}
//Freeing Game Images from memory

void freegame(Game assets)
{
SDL_FreeSurface(assets.player[0].image);
SDL_FreeSurface(assets.player[1].image);
}

//Freeing Option Images from memory
void freeoption(OptionImage assets)
{
    for (int i = 0; i < 15; i++)
    {
    SDL_FreeSurface(assets.obook[i].surface);
    }
    for (int i = 0; i < 2; i++)
    {
        SDL_FreeSurface(assets.graphics[i].surface);
                SDL_FreeSurface(assets.audio[i].surface);
                        SDL_FreeSurface(assets.keybinds[i].surface);
                            SDL_FreeSurface(assets.arrow[i].surface);
    }
SDL_FreeSurface(assets.background.surface);
SDL_FreeSurface(assets.logogroup.surface);
}
//Freeing Graphics Images from memory
void freegraphics(graphicimage assets)
{

    for (int i = 0; i < 2; i++)
    {
        SDL_FreeSurface(assets.firstbox[i].surface);
                SDL_FreeSurface(assets.secondbox[i].surface);
                        SDL_FreeSurface(assets.listresolutionbox[i].surface);
    }

SDL_FreeSurface(assets.selectresolution.surface);
SDL_FreeSurface(assets.windowsettings.surface);
SDL_FreeSurface(assets.fullscreen.surface);
SDL_FreeSurface(assets.windowed.surface);
SDL_FreeSurface(assets.boxresolution.surface);
SDL_FreeSurface(assets.currentresolution.surface);
SDL_FreeSurface(assets.listresolution.surface);

}
//Freeing Audio Images from memory
void freeaudio(audioimage assets)
{

    for (int i = 0; i < 2; i++)
    {
        SDL_FreeSurface(assets.onbox[i].surface);
                SDL_FreeSurface(assets.offbox[i].surface);
                        
    }
    for (int i = 0; i < 10; i++)
    {SDL_FreeSurface(assets.circle[i].surface);
    }
    

SDL_FreeSurface(assets.volume.surface);
SDL_FreeSurface(assets.audio.surface);
SDL_FreeSurface(assets.on.surface);
SDL_FreeSurface(assets.off.surface);
SDL_FreeSurface(assets.minus.surface);
SDL_FreeSurface(assets.plus.surface);
SDL_FreeSurface(assets.audiobar.surface);
}
//Freeing Check Images from memory
void freecheck(CheckImage assets)
{
SDL_FreeSurface(assets.Window.surface);
SDL_FreeSurface(assets.Apply.surface);
SDL_FreeSurface(assets.Quit.surface);
for (int i = 0; i < 2; i++)
{


SDL_FreeSurface(assets.No[i].surface);
SDL_FreeSurface(assets.Yes[i].surface);
}
}
//Freeing Background Images from memory
void freebackground(Background assets)
{
    SDL_FreeSurface(assets.img.surface);
}
//Showing an image on the screen
void show(image p,SDL_Surface *screen)
{
    SDL_BlitSurface(p.surface,NULL,screen,&p.pos1);
}
//Showing Characters and Enemies in game
void showgame(image p,SDL_Surface *screen)
{
    SDL_BlitSurface(p.surface,&p.pos2,screen,&p.pos1);
}
