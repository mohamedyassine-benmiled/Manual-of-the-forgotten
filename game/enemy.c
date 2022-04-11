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
void movement_enemy(Game *game, int n)
{

        if (game->enemy[n].behavior==PATROL || game->enemy[n].behavior==REFRACT)
        {
            
            game->enemy[n].position.x+=game->enemy[n].speed*game->enemy[n].direction;

           

            if (game->enemy[n].direction==1)
                game->enemy[n].look=0;

            else
                game->enemy[n].look=1;

            game->enemy[n].spritestate++;
            if (game->enemy[n].spritestate>4)
                game->enemy[n].spritestate=0;
        }

        else if (game->enemy[n].behavior==ATTACK)
        {
            if (game->enemy[0].direction==1)
            {
                game->enemy[0].look=2;
                game->enemy[0].spritestate=0;
            }
            else
            {
                game->enemy[0].look=2;
                game->enemy[0].spritestate=1;
            }

	

        }


}