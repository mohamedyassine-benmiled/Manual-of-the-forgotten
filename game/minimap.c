
#include "include/minimap.h"
#include "include/game.h"
#include "include/declarations.h"
#include "include/text.h"

/* MOVED TO image.c
    Fixing fps
    elapsed = SDL_GetTicks()-lasttime;
    if (elapsed<1000/FPS)
        SDL_Delay(1000/FPS-elapsed);
*/



void updateminimap(Game *g)
{
        TTF_Init();
        text t;
        char c[50];
g->minimap.bg.pos2.w=g->bg.img.pos2.w*MINIMAP/100;
g->minimap.bg.pos2.h=g->bg.img.pos2.h*MINIMAP/100;
g->minimap.bg.pos2.x=g->bg.img.pos2.x*MINIMAP/100;
g->minimap.bg.pos2.y=g->bg.img.pos2.y*MINIMAP/100; //position background
g->minimap.player[0].position.x=g->player[0].position.x*20/100+g->minimap.bg.pos1.x;
g->minimap.player[0].position.y=g->player[0].position.y*20/100+g->minimap.bg.pos1.y;
g->minimap.player[1].position.x=g->player[1].position.x*20/100+g->minimap.bg.pos1.x;
g->minimap.player[1].position.y=g->player[1].position.y*20/100+g->minimap.bg.pos1.y;
g->minimap.enemy[0].position.x=g->enemy[0].position.x*20/100+g->minimap.bg.pos1.x;
g->minimap.enemy[0].position.y=g->enemy[0].position.y*20/100+g->minimap.bg.pos1.y;
g->minimap.elapsed++;
    printf("%d\n",g->minimap.elapsed);
    //color
    sprintf(c,"Score : %d",g->minimap.elapsed);
    t.textColor.r=207;
    t.textColor.g=175;
    t.textColor.b=70;

    strcpy(t.texte,c);
t.font=TTF_OpenFont("ttf/alagard.ttf",30);
if (!(g->minimap.score.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor)))
{
    printf("Wow an error ? I love this : %s",TTF_GetError());
};
TTF_CloseFont(t.font);
}


void initminimap(Minimap *assets)
{
    

     //Background
        assets->bg.surface=IMG_Load("graphics/720/Level/Levelminimap1_0.png");
        assets->bg.pos1.x=500;
        assets->bg.pos1.y=100;
        assets->elapsed=0;
    //Player
	assets->player[0].image=IMG_Load("graphics/720/Minimap/player.png");
	assets->player[1].image=IMG_Load("graphics/720/Minimap/player.png");	
	assets->enemy[0].image=IMG_Load("graphics/720/Minimap/enemy.png");
    //Score
    assets->score.pos1.x=600;
    assets->score.pos1.x=200;

}






























