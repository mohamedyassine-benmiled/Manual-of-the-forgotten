/**
 * @file collision.c
 * @author Wael Bechraoui
 * @brief Collision Perfect Pixel
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
int x,y,h;
	x=player->position.x+40;
	y=player->position.y;
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
int x,y,w;
	x=player->position.x;
	y=player->position.y-17;
	w=player->src_pos.w;
SDL_Rect pos;
pos.x=x+w/2;
pos.y=y;

int collision=0;
obstacle=GetPixel(bg->collision,pos.x+bg->img.pos2.x,pos.y);
if((obstacle.r==rgb.r) && (obstacle.g==rgb.g) && (obstacle.b==rgb.b))
collision=1;

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

	obstacle=GetPixel(bg->collision,pos.x+bg->img.pos2.x,pos.y);
if((obstacle.r==rgb.r) && (obstacle.g==rgb.g) && (obstacle.b==rgb.b))
collision=1;


return collision;
}

int CollisionGroundEnemy(Enemy *enemy,Background *bg,SDL_Color rgb)
{
SDL_Color obstacle;
int x,y,w,h;
	x=enemy->rpos.x;
	y=enemy->rpos.y-17;
	w=enemy->position2.w;
	h=enemy->position2.h;
SDL_Rect pos;


pos.x=x+w/2;
pos.y=y+h;

int collision=0;

	obstacle=GetPixel(bg->collision,pos.x+bg->img.pos2.x,pos.y);
if((obstacle.r==rgb.r) && (obstacle.g==rgb.g) && (obstacle.b==rgb.b))
collision=1;


return collision;
}

int collision_box(Box *b1,Box *b2)
{
if((b1->x > b2->x+b2->w)|| (b1->x + b1->w < b2->x) || (b1->y + b1->h < b2->y) || (b1->y > b2->y+b2->h))
{
return 0;
}
else
return 1;
}