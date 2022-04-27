/**
 * @file enemy.c
 * @author Ilyes Chaabani
 * @brief Enemy Animation and Movement
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
	enemi->position.x=2500;
	enemi->position.y=START_y-10;
    enemi->position2.x=0;
    enemi->position2.y=0;
    enemi->position2.w=90;
    enemi->position2.h=90;
    enemi->pos_box.w=90;
    enemi->pos_box.h=90;
    enemi->right =0;
    enemi->left=0;
    enemi->posMax=3000;
    enemi->posMin=2500;
    enemi->mouvement=1;
    enemi->reset=0;
    enemi->look=0;
    enemi->spritestate=0;
    enemi->animation=0;
    }

/*int deplacement_alea (int posmax,int posmin)
{
	int pos;
	srand(time(NULL));
	pos=rand()%(posmax-posmin+1)+posmin;
	return pos;
}*/

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
    enemi->elapsed++;
    if (enemi->elapsed==5)
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
    if (enemi->elapsed>=5)
    {
        enemi->elapsed=0;
    }
     
}

void rpos_enemy (Enemy *enemi , Background *bg )
{
    enemi->rpos.x=relative_x(bg,enemi->position); 
    enemi->rpos.y=enemi->position.y; 
}