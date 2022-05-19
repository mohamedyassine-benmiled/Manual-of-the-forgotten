/**
 * @file enemy.c
 * @author ILYES CHAABANI (you@domain.com)
 * @brief ENEMY FUNCTION / mvt /collision / ATTACK 
 * @version 0.1
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
void animateattack(Enemy *enemy)
{
    enemy->elapsed++;
    if (enemy->elapsed==50)
    {
        enemy->elapsed=0;
        enemy->attack=2;
    }

}
void followplayer(Character *player, Enemy *enemy)
{
    if ((player->position.x-enemy->rpos.x)<0)
    {
        enemy->left=1;
        enemy->right=0;
    }
    if ((player->position.x-enemy->rpos.x)>=0)
    {
        enemy->right=1;
        enemy->left=0;
    }
    if ((enemy->left) && ((player->position.x-enemy->rpos.x)<0))
    {
        enemy->position.x-=5;
    }
    
    if ((enemy->right) && ((player->position.x-enemy->rpos.x)>=0))
    {
        enemy->position.x+=5;
    }
}

int spotted(Character *player, Enemy *enemy)
{
    if ((player->position.x-enemy->rpos.x)<0)
    {
        if ((enemy->left) && (enemy->rpos.x-player->position.x<=350))
        {
            return 1;
        }
    }
    if ((player->position.x-enemy->rpos.x)>=0)
    {
        if ((enemy->right) && (player->position.x-enemy->rpos.x<=350))
        {
            return 1;
        }
    }
    return 0;
}
/*
int spotted(Game *game, int i)
{
    return ((game->player->position.x+game->bg.scroll_x < game->enemy->position.x && game->enemy->behavior == -1) || (game->player->position.x+game->bg.scroll_x > game->enemy->position.x && game->enemy->direction == 1) ) ;
}
*/
void initennemy (Enemy *enemi)
{
    enemi->image = IMG_Load("graphics/720/Spritesheet/Enemy.png");
	enemi->position.x=2500;
	enemi->position.y=START_y+40;
    enemi->position2.x=0;
    enemi->position2.y=0;
    enemi->position2.w=90;
    enemi->position2.h=90;
    enemi->pos_box.w=90;
    enemi->pos_box.h=90;
    enemi->right=0;
    enemi->left=0;
    enemi->spotted=-1;
    enemi->posMax=3000;
    enemi->posMin=2500;
    enemi->attack=0;
    enemi->mouvement=1;
    enemi->reset=0; 
    enemi->look=0;
    enemi->spritestate=0;
    enemi->animation=0;
}

/*
int deplacement_alea (int posmax,int posmin)
{
	int pos;
	srand(time(NULL));
	pos=rand()%(posmax-posmin+1)+posmin;
	return pos;
}
*/

void deplacementalea_enemy (Enemy *enemi)
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
void deplacement_enemy (Game *g) //DEPLACEMENT IA
{
    for (int i=0;i<g->global.nbplayers;i++)
    {
    if ((spotted(&g->player[i],&g->enemy[0]))&&(!g->player[i].death))
    {
        g->enemy[0].spotted=i;
    }
    }
    if (g->enemy[0].attack)
    {
        animateattack(&g->enemy[0]);
    }
    else
    if (g->enemy[0].spotted==-1)
        deplacementalea_enemy(&g->enemy[0]);
    else
    {
        followplayer(&g->player[g->enemy[0].spotted],&g->enemy[0]);
        if ((g->enemy[0].rpos.x-g->player[g->enemy[0].spotted].position.x>=1280) || (g->player[g->enemy[0].spotted].position.x-g->enemy[0].rpos.x>=500))
        {
             initennemy (&g->enemy[0]);
        }
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
void rpos_enemy (Enemy *enemi , Background *bg)
{
    enemi->rpos.x=relative_x(bg,enemi->position); 
    enemi->rpos.y=enemi->position.y; 
}

