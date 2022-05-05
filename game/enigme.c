/**
 * @file enigme.c
 * @author Eya Nehdi
 * @brief Enigmes
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "include/enigme.h"
#include "include/text.h"

void init_enigme(enigme *e )
{
    text t;
//text color
t.textColor.r=0;
t.textColor.g=0;
t.textColor.b=0;
TTF_Font *fontquest;
int check=0;
int alea;
int nbligne=0;

int reponse;
FILE *f=NULL;
f=fopen("enigmes","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d\n",e->question,e->rep1,e->rep2,e->rep3,&reponse)!=EOF)
{
nbligne++;
}
fclose(f);
}
srand(time(NULL));
alea=rand()%4;
f=fopen("enigme","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d\n",e->question,e->rep1,e->rep2,e->rep3)!=EOF)
{
check++;
if(check==alea){break;}
}
fclose(f);
}
//Affichage
e->posquestion.x=50;
e->posquestion.y=20;
e->posreponse1.x=400;
e->posreponse1.y=50;
e->posreponse2.x=400;
e->posreponse2.y=100;
e->posreponse3.x=400;
e->posreponse3.y=150;
fontquest=TTF_OpenFont ("Trajan Pro.ttf",30);
t.font=TTF_OpenFont("Trajan Pro.ttf",20);
SDL_Color black={0,0,0};
SDL_Color white={255,255,255};
e->surfacequestion=TTF_RenderText_Blended(fontquest,e->question,black);
e->surfacereponse1=TTF_RenderText_Blended(t.font,e->rep1,white);
e->surfacereponse2=TTF_RenderText_Blended(t.font,e->rep2,white);
e->surfacereponse3=TTF_RenderText_Blended(t.font,e->rep3,white);
}
//Score
void Game_Score (image *s,int *score,int response)
{
        text t;
        
//text color
t.textColor.r=0;
t.textColor.g=0;
t.textColor.b=0;
t.font=TTF_OpenFont("alagard.ttf",20);
if (reponse==1)
{
    *score-=10;
}

if (reponse==2)
{
    *score+=10;
}
sprintf(t.texte,"Score: %d",score);
s->surface=TTF_RenderText_Blended(t.font,t.texte,t.textColor);
}

void afficherenigme(enigme e,SDL_Surface *screen)
{
SDL_BlitSurface(e.surfacequestion,NULL,screen,&e.posquestion);
SDL_BlitSurface(e.surfacereponse1,NULL,screen,&e.posreponse1);
SDL_BlitSurface(e.surfacereponse2,NULL,screen,&e.posreponse2);
SDL_BlitSurface(e.surfacereponse3,NULL,screen,&e.posreponse3);
}
//Animation
/*
void animer(enigme *e,SDL_Rect *pos_sprite,int j)
{
pos_sprite->x=j*pos_sprite->w;
}
*/
