
#include "include/minimap.h"
#include "include/game.h"
#include "include/declarations.h"

void updateminimap(Game *g)
{
g->minimap.bg.pos2.w=g->bg.img.pos2.w*MINIMAP/100;
g->minimap.bg.pos2.h=g->bg.img.pos2.h*MINIMAP/100;
g->minimap.bg.pos2.x=g->bg.img.pos2.x*MINIMAP/100;
g->minimap.bg.pos2.y=g->bg.img.pos2.y*MINIMAP/100; //position background
g->minimap.player[0].position.x=g->player[0].position.x*20/100+g->minimap.bg.pos1.x;
g->minimap.player[0].position.y=g->player[0].position.y*20/100+g->minimap.bg.pos1.y;

}


void initminimap(Minimap *assets)
{
    

     //Background
        assets->bg.surface=IMG_Load("graphics/720/Level/Levelminimap1_0.png");
        assets->bg.pos1.x=500;
        assets->bg.pos1.y=100;

	 
	 	

}































