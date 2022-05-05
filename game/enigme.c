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


//text color
t.textColor.r=0;
t.textColor.g=0;
t.textColor.b=0;


f=fopen("enigmes","r");

srand(time(NULL));
alea=rand()%4;
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

e->q.pos1.x=0;
e->q.pos1.y=0;
e->r1.pos1.x=0;
e->r1.pos1.y=0;
e->r2.pos1.x=0;
e->r2.pos1.y=0;
e->r3.pos1.x=0;
e->r3.pos1.y=0;
t1.font=TTF_OpenFont ("alagard.ttf",30);
t2.font=TTF_OpenFont("alagard.ttf",20);
SDL_Color black={0,0,0};
SDL_Color white={255,255,255};
e->q.surface=TTF_RenderText_Blended(t2.font,e->q,black);
e->r1.surface=TTF_RenderText_Blended(t1.font,e->r1,white);
e->r2.surface=TTF_RenderText_Blended(t1.font,e->r2,white);
e->r3.surface=TTF_RenderText_Blended(t1.font,e->r3,white);
 for(int i=0;i<4;i++)
    {
    sprintf(logo,"graphics/1080/Logo/Logo%d.png",i);
    assets->logo[i].surface=IMG_Load(logo);
    assets->logo[i].pos1.x=619;
    assets->logo[i].pos1.y=47;
    }
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
