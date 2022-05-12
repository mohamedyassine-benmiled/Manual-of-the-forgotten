#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"
#include "include/declarations.h"
#include "include/collision.h"
//Init to remove warnings
int CollisionRight(Character *player,Background *bg,SDL_Color rgb);
int CollisionLeft(Character *player,Background *bg,SDL_Color rgb);
int CollisionGround(Character *player,Background *bg,SDL_Color rgb);


int bordercheck(Background *bg)
{ 
    if(bg->img.pos2.x<=0)
    {
        collisionleft=1;
        collisionright=0;
        return 0;
        
    }

    if (bg->img.pos2.x>=6395-1280)
    {
        collisionleft=0;
        collisionright=1;
        return -1;
    }
    collisionleft=0;
    collisionright=0;
    return 1;
}


void initbackground(Background *assets)
{
    

     //Background
        assets->img.surface=IMG_Load("graphics/720/Level/Level1_0.png");
        assets->collision=IMG_Load("graphics/720/Level/Levelcollision1_0.png");
        assets->img.pos1.x=0;
        assets->img.pos1.y=0;
        assets->img.pos2.w=SCREENDIF;
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
        assets->an2.pos2.y=assets->an2.pos1.y;
	 //Son
	 	assets->son=Mix_LoadMUS("sfx/game.ogg");

}



void scrolling (Game *g)
{
     SDL_Color rgb;
     rgb.r=0;
    rgb.g=0;
    rgb.b=0;
    int x = 0;
    int i = g->global.firstplayer;
    int j = g->global.lastplayer;
        if (!(g->player[j].position.x==4+(SCREENDIF*g->global.screen)))
        {

                if ((g->player[i].input.right)&&(!CollisionRight(&g->player[i],&g->bg,rgb)))
                {
                        g->bg.img.pos2.x+=SPEED;          
                }
                // if (!((g->player[i].input.right) && (g->player[j].input.right)))
                // {
                //         g->player[j].position.x=relative_x(&g->bg,g->player[j].position);
                // }
        }
        
        if (!(g->player[i].position.x==1276+(SCREENDIF*g->global.screen)))

                if((g->player[j].input.left) &&(!CollisionLeft(&g->player[j],&g->bg,rgb)))
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
                bg->elapsed=0;
        }
}
void animationback2(Background *bg)
{

        if ((bg->elapsed%30)==0)
        {
                bg->i=0;
        }
        else
        {
                bg->i=1;
        }
}


void fixposition1(Game *g)
{

    g->bg.img.pos1.x=g->bg.img.pos1.x+(SCREENDIF*g->global.screen);
    printf("\n %d",g->bg.img.pos1.x);
    g->player[0].position.x=g->player[0].position.x+(SCREENDIF*g->global.screen);
        printf("\n %d",g->player[0].position.x);
         g->minimap.bg.pos1.x=g->minimap.bg.pos1.x+(SCREENDIF*g->global.screen);
}

void fixposition2(Game *g)
{
        g->enemy[0].rpos.x=g->enemy[0].rpos.x+(SCREENDIF*g->global.screen);
}












