#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/game.h"
#include "include/enemy.h"


/*int spotted(Game *game, int i)
{
    return ((game->player->position.x+game->bg.scroll_x < game->enemy->position.x && game->enemy->behavior == -1) || (game->player->position.x+game->bg.scroll_x > game->enemy->position.x && game->enemy->direction == 1) ) ;
}*/

int deplacement_alea (int posmax,int posmin)
{
	int pos;
	srand(time(NULL));
	pos=rand()%(posmax-posmin+1)+posmin;
	return pos;
}

void deplacement_enemy (Enemy *enemi )
{
	if(enemi->position.x==enemi->posMax)
	{
		enemi->right=0;
		enemi->left=1;
	}
		if(enemi->position.x==enemi->posMin)
	{
		enemi->right=1;
		enemi->left=0;

	}
	if(enemi->right)
	if(enemi->position.x<=enemi->posMax)
	{
			(enemi->position.x)+=5;
		
	}
	
	if(enemi->left)
		if(enemi->position.x>enemi->posMin)
		{

		(enemi->position.x)-=5;
			
		}
	

}