
#include"include/game.h"

SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{	
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}

int  collisionparfaite(SDL_Surface *psurface,Character player)
{	
	int tabx[7],taby[7],i,collision=0;
	SDL_Color color1,color;
	color1.r = 0;
	color1.g = 0;
	color1.b = 0;
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




