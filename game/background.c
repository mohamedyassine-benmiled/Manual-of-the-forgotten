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
        assets->scroll_x=0;
        assets->scroll_y=0;

	 //Son
	 	

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

	
	
        }
else if((g->player[0].input.left) &&(!CollisionLeft(&g->player[0],&g->bg,rgb)))
{          
	g->bg.img.pos2.x-=SPEED; 

	
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
/*
void initanimationback()
{
char logo [50];
    for(int i=0;i<4;i++)
    {
    sprintf(logo,"graphics/1080/Logo/Logo%d.png",i);
    assets->logo[i].surface=IMG_Load(logo);
    assets->logo[i].pos1.x=619;
    assets->logo[i].pos1.y=47;
    }



}
void animationback()
{
        i++;
    if(i==4)
    {
        i=0;
    }
     show(assets.cbook[j],screen);
}


*/















