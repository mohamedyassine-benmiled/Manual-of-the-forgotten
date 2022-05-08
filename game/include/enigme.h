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
char question2[100];
char rep1[100];
char rep2[100];
char rep3[100];
int rep;
int repuser;
int score;
image q;
image q2;
image r1[2];
image r2[2];
image r3[2];
image correct;
image incorrect;
image sc;
image animation[4];
image bg;
int animelapsed;
int elapsed;
}Enigme;
void init_enigme(Enigme *e);
//void sauvegarder (personne p,background b,char * f);
//int charger (personne *p,background *b , char * f);