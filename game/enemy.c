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
void initennemy (Enemy *enemi)
{
    enemi->image = IMG_Load("graphics/720/Spritesheet/Enemy.png");
	enemi->position.x=400;
	enemi->position.y=START_y-10;
    enemi->position2.x=0;
    enemi->position2.y=0;
    enemi->position2.w=90;
    enemi->position2.h=90;
    enemi->rect.x=500;
    enemi->rect.y=320;
    enemi->right =0;
    enemi->left=0;
    enemi->posMax=600;
    enemi->posMin=400;
    enemi->mouvement=1;
    enemi->reset=0;
    enemi->look=0;
    enemi->spritestate=0;
    enemi->animation=0;
    }

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
void animationenemy(Enemy *enemi)
{
    //Run Right
    if ((enemi->right) && (enemi->mouvement==1))
    {
        if (!(enemi->look==SPRITEXE0_Run))
        enemi->animation=0;
        enemi->look=SPRITEXE0_Run;
        enemi->animation++;

        if (enemi->animation>=(SPRITEYE0_Run/2)+1)
        {
        enemi->animation=0;
        }
        enemi->spritestate=enemi->animation;
        return;
    }
    else
    //Run Left
    if ((enemi->left) && (enemi->mouvement==1))
    {
        if (!(enemi->look==SPRITEXE0_Run))
        enemi->animation=0;
        enemi->look=SPRITEXE0_Run;
        enemi->animation--;
        if (enemi->animation<(SPRITEYE0_Run/2)+1)
        {
        enemi->animation=SPRITEYE0_Run;
        }
        enemi->spritestate=enemi->animation;
        return;
    }
     
}
int collision(box *b,Enemy *e){
b->x=698;
b->y=600;
b->w=60;
b->h=75;

if(e->rect.x > b->x+b->w|| e->rect.x + e->rect.w < b->x || e->rect.y + e->rect.h < b->y || e->rect.y > b->y+b->h)
{
return 0;
}
else
return 1;
}