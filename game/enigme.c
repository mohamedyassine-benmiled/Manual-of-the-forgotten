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


void init_enigme(Enigme *e )
{
FILE *f=NULL;
text t1, t2 ;
char logo [50];
int check=0;
int alea;
int nbligne=0;
int reponse;
e->score=0;

//text color question
t1.textColor.r=0;
t1.textColor.g=0;
t1.textColor.b=0;
//text color response
t2.textColor.r=0;
t2.textColor.g=0;
t2.textColor.b=0;


f=fopen("enigmes","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d\n")!=EOF)
{
nbligne++;
}
fclose(f);
}
f=fopen("enigmes","r");

srand(time(NULL));
alea=rand()%nbligne;
nbligne=0;
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d\n",e->question,e->rep1,e->rep2,e->rep3,&reponse)!=EOF)
{
nbligne++;
if (nbligne == alea)
{
    break;
}

}
fclose(f);
}
else
{
    printf("\n Enigmes doesn't exist");
}
e->q.pos1.x=0;
e->q.pos1.y=0;
e->r1[0].pos1.x=0;
e->r1[0].pos1.y=0;
e->r2[0].pos1.x=0;
e->r2[0].pos1.y=0;
e->r3[0].pos1.x=0;
e->r3[0].pos1.y=0;


e->r1[1].pos1.x=0;
e->r1[1].pos1.y=0;
e->r2[1].pos1.x=0;
e->r2[1].pos1.y=0;
e->r3[1].pos1.x=0;
e->r3[1].pos1.y=0;
e->sc.pos1.x=0;
e->sc.pos1.y=0;
t1.font=TTF_OpenFont ("alagard.ttf",30);
t2.font=TTF_OpenFont("alagard.ttf",20);
e->q.surface=TTF_RenderText_Blended(t1.font,e->question,t1.textColor);
e->r1[0].surface=TTF_RenderText_Blended(t1.font,e->rep1,t2.textColor);
e->r2[0].surface=TTF_RenderText_Blended(t1.font,e->rep2,t2.textColor);
e->r3[0].surface=TTF_RenderText_Blended(t1.font,e->rep3,t2.textColor);
t2.textColor.r=100;
t2.textColor.g=100;
t2.textColor.b=100;
e->r1[1].surface=TTF_RenderText_Blended(t1.font,e->rep1,t2.textColor);
e->r2[1].surface=TTF_RenderText_Blended(t1.font,e->rep2,t2.textColor);
e->r3[1].surface=TTF_RenderText_Blended(t1.font,e->rep3,t2.textColor);
 for(int i=0;i<4;i++)
    {
    sprintf(logo,"graphics/720/Logo/Logo%d.png",i);
    e->animation[i].surface=IMG_Load(logo);
    e->animation[i].pos1.x=619;
    e->animation[i].pos1.y=47;
    }
}
//Score
void Game_Score (image *sc,int *score,int reponse)
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
sprintf(t.texte,"Score: %d",*score);
sc->surface=TTF_RenderText_Blended(t.font,t.texte,t.textColor);
}

void afficherenigme(Enigme *e,SDL_Surface *screen)
{
show(e->q,screen);
show(e->r1[0],screen);
show(e->r2[0],screen);
show(e->r3[0],screen);
}
//Animation

void animate_enigme(Enigme *e,SDL_Surface *screen)
{
    e->elapsed++;
    if (e->elapsed==4)
    {
        e->elapsed=0;
    }
    show(e->animation[e->elapsed],screen);
}


