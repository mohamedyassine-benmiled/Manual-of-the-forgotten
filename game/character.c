#include "include/character.h"
#include "include/game.h"
#include "include/declarations.h"
#include "include/config.h"

int center_camera(Game *g)
{
    settings config;
    get_config(&config);
    return (g->player[0].position.x+32>config.resolution_w/2 && g->player[0].position.x-32<config.resolution_w/2);
}

int OnGround(Character *player)
{
	if (player->position.y>515)
	{
		player->position.y = 515;
		if (player->input.jumpHeight>0)
			player->input.jumpHeight = 0;
		player->input.startJump = 0;
        return 1;
	}
    return 0;
}


void movement(Game *g)
{
        settings config;
    get_config(&config);
        /* Right */

        if ((g->player[0].input.right))
        {
          
                if (g->player[0].position.x<config.resolution_w)
                {
                    g->player[0].position.x+=SPEED;
                }
            

            g->player[0].input.movement=0;
        }

        /* Left */

        else if ((g->player[0].input.left))
        {

                g->player[0].position.x-=SPEED;
                if (g->player[0].position.x<0)
                    g->player[0].position.x+=SPEED;
            g->player[0].input.left=0;

            g->player[0].input.movement=1;

        }

        else// if (!collision_pente(g))
        {
            if (g->global.movement==0)
            {
                g->player[0].look=4;
                g->player[0].spritestate=0;
            }
            else
            {
                g->player[0].look=9;
                g->player[0].spritestate=5;
            }
        }
        
        if ((g->player[0].input.up) && !g->player[0].input.fix)
        {
            g->player[0].input.startJump = 1;
        }
        
        /* JUMP START */
        
        if (g->player[0].input.startJump)
        {
            g->player[0].input.fix=1;

            if (g->player[0].input.jumpHeight < maxJmpH)
            {
                g->player[0].input.jumpHeight += JUMP_POWER;
                g->player[0].position.y -= JUMP_POWER + 2*GRAVITY;
            }
            else
            {
                g->player[0].input.startJump=0;
                g->player[0].input.jumpHeight=0;
            }
        }
        


        
        
    g->player[0].pos_cercle.x=g->player[0].position.x+g->bg.scroll_x;
    g->player[0].pos_cercle.y=g->player[0].position.y+40;
    g->player[0].pos_cercle.r=30;

}

