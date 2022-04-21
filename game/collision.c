
#include "include/collision.h"
#include "include/game.h"
#include "include/config.h"





SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}

int CollisionRight(Character *player,Background *bg,SDL_Color rgb)
{
	SDL_Color obstacle;
	int x,y,w,h;
		x=player->position.x-35;
		y=player->position.y;
		w=player->src_pos.w;
		h=player->src_pos.h;
	SDL_Rect pos[3];

pos[0].x=x+w/2;
pos[0].y=y+h;
pos[1].x=x+w;
pos[1].y=y+h;
pos[2].x=x+w;
pos[2].y=y+h/2;
	int collision=0;
	int i=0;
	while((i<3) && (collision==0))
	{
	obstacle=GetPixel(bg->collision,pos[i].x+bg->img.pos2.x,pos[i].y);

	if((obstacle.r==rgb.r) && (obstacle.g==rgb.g) && (obstacle.b==rgb.b))
	collision=1;
	i++;
	}
	return collision;
}

int CollisionLeft(Character *player,Background *bg,SDL_Color rgb)
{
SDL_Color obstacle;
int x,y,w,h;
	x=player->position.x+40;
	y=player->position.y;
	w=player->src_pos.w;
	h=player->src_pos.h;
SDL_Rect pos[6];

pos[0].x=x+w;
pos[0].y=y;
pos[1].x=x;
pos[1].y=y+h/2;
pos[2].x=x;
pos[2].y=y+h;

int collision=0;
int i=0;
while((i<3) && (collision==0))
{
obstacle=GetPixel(bg->collision,pos[i].x+bg->img.pos2.x,pos[i].y);
if((obstacle.r==rgb.r) && (obstacle.g==rgb.g) && (obstacle.b==rgb.b))
collision=1;
i++;
}
return collision;
}

int CollisionGround(Character *player,Background *bg,SDL_Color rgb)
{
SDL_Color obstacle;
int x,y,w,h;
	x=player->position.x+40;
	y=player->position.y;
	w=player->src_pos.w;
	h=player->src_pos.h;
SDL_Rect pos[5];

pos[0].x=x;
pos[0].y=y+h;
pos[1].x=x+w/2;
pos[1].y=y+h;
pos[2].x=x+w;
pos[3].y=y+h;
pos[4].x=x+w;
pos[4].y=y+h/2;
int collision=0;
int i=0;
while((i<5) && (collision==0))
{
	obstacle=GetPixel(bg->collision,pos[i].x+bg->img.pos2.x,pos[i].y);
if((obstacle.r==rgb.r) && (obstacle.g==rgb.g) && (obstacle.b==rgb.b))
collision=1;
i++;
}
return collision;
}

int collision_box(Box b1, Box b2)
{
    return(b1.x > b2.x-8 && b1.x < b2.x+8);
}
/*
int Collision_PPP(SDL_Surface *psurface,Character player)
{	
int tabx[7],taby[7],i,collision=0;
	SDL_Color color1,color;
	color1.r = 255;
	color1.g = 255;
	color1.b = 255;
	tabx[0]=player.position.x;
	tabx[1]=(player.position.x)+((player.position.w)/2);
	tabx[2]=(player.position.x+player.position.w);
	tabx[3]=player.position.x;
	tabx[4]=player.position.x;
	tabx[5]=(player.position.x)+((player.position.w)/2);
	tabx[6]=(player.position.x+player.position.w);
	tabx[7]=(player.position.x+player.position.w);
	taby[0]=player.position.y;
	taby[1]=player.position.y;
	taby[2]=player.position.y;
	taby[3]=(player.position.y)+((player.position.h)/2);
	taby[4]=(player.position.y+player.position.h);
	taby[5]=(player.position.y+player.position.h);
	taby[6]=(player.position.y+player.position.h);
	taby[7]=(player.position.y)+((player.position.h)/2);
	
	for(i=0;i<8;i++)
	{
	color=getpixel(psurface,tabx[i],taby[i]);
	if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
	{
		collision=1;

	}
	}
	return collision;
	
}	
*/

