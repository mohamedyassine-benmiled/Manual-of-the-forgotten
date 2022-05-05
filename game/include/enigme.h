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
#include "image.h"
typedef struct 
{
char question[100];
char rep1[100];
char rep2[100];
char rep3[100];
int rep;
image q;
image r1;
image r2;
image r3;
image score;
}Enigme;
void init_enigme(Enigme *e);
void afficherenigme(Enigme e,SDL_Surface * screen);
void animer (Enigme *e);
//void sauvegarder (personne p,background b,char * f);
//int charger (personne *p,background *b , char * f);