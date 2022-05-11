#ifndef texte_H
#define texte_H 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>




typedef struct 
{ 
	SDL_Rect position ; 
	SDL_Rect position2 ; 
	SDL_Rect position3 ; 
	TTF_Font *font ; 
	SDL_Surface * surfaceTexte ;
	SDL_Color textColor ; 
	SDL_Color textColor2 ;
	SDL_Color textColor3 ;
	char texte[50] ; 

}Text; 

void initText(Text *A) ; 
void freeText(Text A) ; 

void displayTextplayer(Text t,SDL_Surface *screen) ;
void displayTextenemy(Text t,SDL_Surface *screen) ;
void displayTextwin(Text t,SDL_Surface *screen) ;
void displayTextenemywin(Text t,SDL_Surface *screen) ;
void displayTextrounddraw(Text t,SDL_Surface *screen) ;

#endif 
