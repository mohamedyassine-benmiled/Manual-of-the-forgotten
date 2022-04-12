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
void Game_Score (int score)
{
        text t;
//text color
t.textColor.r=0;
t.textColor.g=0;
t.textColor.b=0;
t.font=TTF_OpenFont("Trajan Pro.ttf",20);
SDL_Surface *surface_score=NULL;

SDL_Color blue={0,0,155};
SDL_Color green={0,200,0};

surface_score=TTF_RenderText_Blended(t.font,"score :",blue);
SDL_Rect position_score; 

position_score.x=50;
position_score.y=80;
}

void afficherenigme(enigme e,SDL_Surface *screen)
{
SDL_BlitSurface(e.surfacequestion,NULL,screen,&e.posquestion);
SDL_BlitSurface(e.surfacereponse1,NULL,screen,&e.posreponse1);
SDL_BlitSurface(e.surfacereponse2,NULL,screen,&e.posreponse2);
SDL_BlitSurface(e.surfacereponse3,NULL,screen,&e.posreponse3);
SDL_Flip(screen);
}
//Animation
/*
void animer(enigme *e,SDL_Rect *pos_sprite,int j)
{
pos_sprite->x=j*pos_sprite->w;
}
*/
