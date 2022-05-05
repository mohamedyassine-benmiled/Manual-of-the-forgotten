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
#include "include/game.h"

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
void Game_Score (image *s,int *score,int reponse)
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

void afficherenigme(Enigme e,SDL_Surface *screen)
{
show(e->q,screen);
show(e->score,screen);
show(e->r1[0],screen);
show(e->r2[0],screen);
show(e->r3[0],screen);
}
//Animation

void animer(Enigme *e,SDL_Surface *screen)
{
    e->elapsed++;
    if (e->elapsed==4)
    {
        e->elapsed=0;
    }
    show(e->animation[e->elapsed],screen);
}


int sauvegarder(Game *g)
{
    FILE *f=NULL;
    f=fopen("save/savefile","w");
    if (f!=NULL)
    {
        fprintf(f,"[Game SaveFile]\n");
        fprintf(f,"player.health=%d\n",g->player[0].health);
        fprintf(f,"player.life=%d\n",g->player[0].life);
        fprintf(f,"checkpoint=%d\n",g->global.checkpoint);
        fprintf(f,"score=%d\n",g->player[0].score);
        fprintf(f,"level=%d\n",g->global.level);
        fclose(f);
        return 0;
    }
    else
    {
        return -1;
    }
}
int charger(Game *g)
{
    FILE *f=NULL;
    f=fopen("save/savefile","w");
    if (f!=NULL)
    {
        fscanf(f,"[Game SaveFile]\n");
        fscanf(f,"player.health=%d\n",g->player[0].health);
        fscanf(f,"player.life=%d\n",g->player[0].life);
        fscanf(f,"checkpoint=%d\n",g->global.checkpoint);
        fscanf(f,"score=%d\n",g->player[0].score);
        fscanf(f,"level=%d\n",g->global.level);
        fclose(f);
        return 0;
    }
    else
    {
        return -1;
    }
}