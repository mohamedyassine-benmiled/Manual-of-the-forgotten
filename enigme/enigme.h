#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
typedef struct enigme
{
char question[100];
char reponse1[100];
char reponse2[100];
char reponse3[100];
int reponse;


SDL_Surface *surfacequestion;
SDL_Surface *surfacereponse1;
SDL_Surface *surfacereponse2;
SDL_Surface *surfacereponse3;

SDL_Rect positionquestion;
SDL_Rect positionreponse1;
SDL_Rect positionreponse2;
SDL_Rect positionreponse3;

}enigme;
void init_enigmes(enigme *e);
void afficherenigme(enigme e,SDL_Surface * screen);
void animer (enigme *e);
//void sauvegarder (personne p,background b,char * f);
//int charger (personne *p,background *b , char * f);
