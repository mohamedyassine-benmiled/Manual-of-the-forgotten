
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
		x=player->position.x-40;
		y=player->position.y;
		w=player->src_pos.w;
		h=player->src_pos.h;
	SDL_Rect pos;


pos.x=x+w;
pos.y=y+h/2;
	int collision=0;

	obstacle=GetPixel(bg->collision,pos.x+bg->img.pos2.x,pos.y);

	if((obstacle.r==rgb.r) && (obstacle.g==rgb.g) && (obstacle.b==rgb.b))
	collision=1;
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
SDL_Rect pos;


pos.x=x;
pos.y=y+h/2;


int collision=0;
obstacle=GetPixel(bg->collision,pos.x+bg->img.pos2.x,pos.y);
if((obstacle.r==rgb.r) && (obstacle.g==rgb.g) && (obstacle.b==rgb.b))
collision=1;


return collision;
}

int CollisionTop(Character *player,Background *bg,SDL_Color rgb)
{
SDL_Color obstacle;
int x,y,w,h;
	x=player->position.x;
	y=player->position.y-17;
	w=player->src_pos.w;
	h=player->src_pos.h;
SDL_Rect pos[3];

pos[0].x=x;
pos[0].y=y;
pos[1].x=x+w/2;
pos[1].y=y;
pos[2].x=x+w;
pos[2].y=y;

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
	x=player->position.x;
	y=player->position.y-17;
	w=player->src_pos.w;
	h=player->src_pos.h;
SDL_Rect pos;


pos.x=x+w/2;
pos.y=y+h;

int collision=0;
int i=0;

	obstacle=GetPixel(bg->collision,pos.x+bg->img.pos2.x,pos.y);
if((obstacle.r==rgb.r) && (obstacle.g==rgb.g) && (obstacle.b==rgb.b))
collision=1;


return collision;
}

int collision_box(Box b1, Box b2)
{
    return(b1.x > b2.x-8 && b1.x < b2.x+8);
}


