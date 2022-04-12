#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"
#include "include/enemy.h"


int spotted(Game *game, int i)
{
    return ((game->player->position.x+game->bg.scroll_x < game->enemy->position.x && game->enemy->behavior == -1) || (game->player->position.x+game->bg.scroll_x > game->enemy->position.x && game->enemy->direction == 1) ) ;
}

int deplacement_alea (int posmax,int posmin)
{
	int pos;
	srand(time(NULL));
	pos=rand()%(posmax-posmin+1)+posmin;
	return pos;
}
void Remplissage_animation (mouvement *mvt)
{
 mvt-> mvt_av [0]=IMG_Load("walk1.png");
 mvt-> mvt_av [1]=IMG_Load("walk2.png");
 mvt-> mvt_av [2]=IMG_Load("walk3.png");
 mvt-> mvt_av [3]=IMG_Load("walk4.png");
 mvt-> mvt_av [4]=IMG_Load("walk5.png");
 mvt-> mvt_av [5]=IMG_Load("walk6.png");
 mvt-> mvt_av [6]=IMG_Load("walk7.png");

 mvt-> mvt_back [0]=IMG_Load("walk8.png");
 mvt-> mvt_back [1]=IMG_Load("walk9.png");
 mvt-> mvt_back [2]=IMG_Load("walk10.png");
 mvt-> mvt_back [3]=IMG_Load("walk11.png");
 mvt-> mvt_back [4]=IMG_Load("walk12.png");
 mvt-> mvt_back [5]=IMG_Load("walk13.png");
 mvt-> mvt_back [6]=IMG_Load("walk14.png");
}