#include <SDL/SDL.h> 
#include "include/textetictac.h" 
#include <SDL/SDL_image.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initText(Text *A) 
{

	A->position.x=0 ; 
	A->position.y=0 ; 
	A->position2.x=700 ; 
	A->position2.y=0 ; 
	A->position3.x=450 ; 
	A->position3.y=300 ; 
	A->textColor.r=255;
	A->textColor.g=255 ;
	A->textColor.b=255 ; 
	A->textColor2.r=255;
	A->textColor2.g=255 ;
	A->textColor2.b=255 ; 
	A->textColor3.r= 0;
	A->textColor3.g=0 ;
	A->textColor3.b=0 ; 
     A->font = TTF_OpenFont("ttf/UbuntuMono.ttf",50) ; 
    
} 

void freeText(Text A) 
{ 
	SDL_FreeSurface(A.surfaceTexte) ; 
}




void displayTextplayer(Text t,SDL_Surface *screen) 
{

t.surfaceTexte = TTF_RenderText_Solid(t.font , "player 1 playing...", t.textColor) ; 
SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position) ;
 SDL_Flip(screen);
}




void displayTextenemy(Text t,SDL_Surface *screen) 
{

t.surfaceTexte = TTF_RenderText_Solid(t.font , "player 2 playing...", t.textColor2) ; 
SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position2) ;
SDL_Flip(screen);
}




void displayTextwin(Text t,SDL_Surface *screen) 
{

t.surfaceTexte = TTF_RenderText_Solid(t.font , "player 1 won !", t.textColor) ; 
SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position3) ;
}





void displayTextenemywin(Text t,SDL_Surface *screen) 
{

t.surfaceTexte = TTF_RenderText_Solid(t.font , "player 2 won !", t.textColor2) ; 
SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position3) ;
}





void displayTextrounddraw(Text t,SDL_Surface *screen) 
{

t.surfaceTexte = TTF_RenderText_Solid(t.font , "Round draw", t.textColor3) ; 
SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position3) ;
}

