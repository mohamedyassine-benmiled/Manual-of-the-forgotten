#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"
#include "include/declarations.h"
#include "include/collision.h"

void initbackground(Background *assets)
{
    

     //Background
        assets->img.surface=IMG_Load("graphics/720/Level/Level1_0.png");
        assets->collision=IMG_Load("graphics/720/Level/Levelcollision1_0.png");
        assets->img.pos1.x=0;
        assets->img.pos1.y=0;
        assets->img.pos2.w=1280;
        assets->img.pos2.h=720;
        assets->img.pos2.x=0;
        assets->img.pos2.y=0;
        assets->elapsed=0;
        assets->an[0].surface=IMG_Load("graphics/720/Gameanimation/bird.png");
        assets->an[0].pos1.x=1280;
        assets->an[0].pos1.y=150;
        assets->an[1].surface=IMG_Load("graphics/720/Gameanimation/second_bird.png");
        assets->an[1].pos1=assets->an[0].pos1;
        assets->an2.surface=IMG_Load("graphics/720/Gameanimation/pointdex.png");
        assets->an2.pos1.x=1046;
        assets->an2.pos1.y=356;

	 //Son
	 	assets->son=Mix_LoadMUS("sfx/WeAreTheChampions.mp3");

}






/* Moved to image.c
void showgame(image p,SDL_Surface *screen)
{
    SDL_BlitSurface(p.surface,&p.pos2,screen,&p.pos1);
}
*/

void scrolling (Game *g)
{
     SDL_Color rgb;
     rgb.r=255;
    rgb.g=255;
    rgb.b=255;
if ((g->player[0].input.right)&&(!CollisionRight(&g->player[0],&g->bg,rgb)))
{
	g->bg.img.pos2.x+=SPEED;          
        g->bg.an2.pos1.x+=SPEED;
        }
else if((g->player[0].input.left) &&(!CollisionLeft(&g->player[0],&g->bg,rgb)))
{          
	g->bg.img.pos2.x-=SPEED; 
        g->bg.an2.pos1.x-=SPEED;

	}
        
/*

else if (direction ==2){          
        b->bg.img.pos2.y+= SPEED;

	 
	 }
else if (direction ==3){  
        b->bg.img.pos2.y-=SPEED;

         
	}
        */
}


void animationback(Background *bg)
{
        bg->elapsed++;
        if (bg->elapsed!=500)
        {
                if(bg->an[0].pos1.x!=-500)
                {
                        bg->an[0].pos1.x-=10;
                }
        }
        if ((bg->elapsed!=1000) && (bg->elapsed>=500))
        {
                if(bg->an[1].pos1.x!=-500)
                {
                        bg->an[1].pos1.x-=10;
                }
        }
        if (bg->elapsed==1000)
        {
                bg->an[0].pos1.x=1280;
                bg->an[0].pos1.y=150;
                bg->an[1].pos1.x=1280;
                bg->an[1].pos1.y=150;
                bg->elapsed==0;
        }
}
void animationback2(Background *bg)
{

        if (bg->elapsed!=100)
        {
                bg->i=0;
        }
        if ((bg->elapsed!=100) && (bg->elapsed>=200))
        {
                bg->i=1;
        }
}

















