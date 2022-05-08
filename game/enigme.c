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
#include "include/declarations.h"

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



f=fopen("enigme/enigmes","r");

srand(time(NULL));
alea=rand()%4;
nbligne=0;
e->animelapsed=0;
e->elapsed=0;
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d\n",e->question,e->rep1,e->rep2,e->rep3,&e->rep)!=EOF)
{
nbligne++;
printf("\n%d %s %s %s %s",nbligne,e->question,e->rep1,e->rep2,e->rep3);
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
printf("\n%d %s %s %s %s",nbligne,e->question,e->rep1,e->rep2,e->rep3);
e->bg.surface= IMG_Load("graphics/720/enigme/bg.png");
e->bg.pos1.x=310;
e->bg.pos1.y=112;
e->q.pos1.x=385;
e->q.pos1.y=300;
e->q2.pos1.x=550;
e->q2.pos1.y=350;
e->time.pos1.x=479;
e->time.pos1.y=524;
e->r1[0].pos1.x=400;
e->r1[0].pos1.y=420;
e->r2[0].pos1.x=600;
e->r2[0].pos1.y=420;
e->r3[0].pos1.x=800;
e->r3[0].pos1.y=420;


e->r1[1].pos1.x=399;
e->r1[1].pos1.y=382;
e->r2[1].pos1.x=584;
e->r2[1].pos1.y=382;
e->r3[1].pos1.x=766;
e->r3[1].pos1.y=382;
e->sc.pos1.x=379;
e->sc.pos1.y=524;
t1.font=TTF_OpenFont ("ttf/alagard.ttf",30);
t2.font=TTF_OpenFont("ttf/alagard.ttf",20);
strcpy(e->question2,"");
fixtext(e->question,e->question2);
e->q.surface=TTF_RenderText_Blended(t1.font,e->question,t1.textColor);
e->q2.surface=TTF_RenderText_Blended(t1.font,e->question2,t1.textColor);
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
    sprintf(logo,"graphics/720/enigme/Logo%d.png",i);
    e->animation[i].surface=IMG_Load(logo);
    e->animation[i].pos1.x=512;
    e->animation[i].pos1.y=150;
    }
}
void fixtext(char text[],char text2[])
{
    if (strlen(text)>38)
    {
        for (int i=38;i>0;i--)
        {
            if (text[i]=='-')
            {
                int k=0;
                for (int j=i;j<strlen(text);j++)
                {

                    text2[k]=text[j];
                    k++;
                }
                text2[k]='\0';
                text[i]='\0';
                break;
            }
        }
    }
    for (int i=0;i<strlen(text);i++)
    {
        if (text[i]=='-')
            text[i]=' ';

    }
    for (int i=0;i<strlen(text2);i++)
    {
        if (text2[i]=='-')
            text2[i]=' ';

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
t.font=TTF_OpenFont("ttf/alagard.ttf",20);
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
show(e->bg,screen);
show(e->sc,screen);
show(e->q,screen);
show(e->q2,screen);
show(e->r1[0],screen);
show(e->r2[0],screen);
show(e->r3[0],screen);
show(e->animation[e->animelapsed],screen);
show(e->time,screen);
}
//Animation

void animate_enigme(Enigme *e)
{
    e->animelapsed++;     


    if (e->animelapsed==4)
    {
        e->animelapsed=0;
    }

}

void timeenigme(Enigme *e) 
{
    text t ;
    char c [50];
    e->elapsed++;
    
    t.font=TTF_OpenFont("ttf/alagard.ttf",30);
    sprintf(c,"Time : %d",e->elapsed/30);
    t.textColor.r=0;
    t.textColor.g=0;
    t.textColor.b=0;
    strcpy(t.texte,c);
    if (!(e->time.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)))
     { 
         printf("Wow an error ? I love this : %s",TTF_GetError());
      };
    TTF_CloseFont(t.font);

}



int enigmestart(SDL_Surface *screen,int run,int *score)
{
        SDL_Event event;
        unsigned int elapsed;
        unsigned int lasttime;
        Enigme e;
        e.repuser=0;
        init_enigme(&e);
        Game_Score(&e.sc,score,0);
        run++;
        
        while(run==4)
        {
                lasttime = SDL_GetTicks();
                run=handleenigme(&e,&event,screen,run);
                Game_Score(&e.sc,score,e.repuser);
                animate_enigme(&e);
                timeenigme(&e);
                afficherenigme(&e,screen);
                SDL_Flip(screen);
                if (e.repuser==2)
                {
                    run=3;
                }
                else
                {
                    e.repuser=0;
                }
                    /* Fixing fps */
                    elapsed = SDL_GetTicks()-lasttime;
                if (elapsed<1000/FPS)
                SDL_Delay(1000/FPS-elapsed);
                SDL_Flip(screen);
        }
        return run;

}

