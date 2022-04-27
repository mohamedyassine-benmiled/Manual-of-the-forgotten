/**
 * @file enigme.h
 * @author Eya Nehdi
 * @brief Enigmes
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
typedef struct 
{
char question[100];
char rep1[100];
char rep2[100];
char rep3[100];
int rep;
SDL_Surface *surfacequestion;
SDL_Surface *surfacereponse1;
SDL_Surface *surfacereponse2;
SDL_Surface *surfacereponse3;
SDL_Rect posquestion;
SDL_Rect posreponse1;
SDL_Rect posreponse2;
SDL_Rect posreponse3;
}enigme;
void init_enigme(enigme *e);
void afficherenigme(enigme e,SDL_Surface * screen);
void animer (enigme *e);
//void sauvegarder (personne p,background b,char * f);
//int charger (personne *p,background *b , char * f);