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

int onGround(Character *player)
{
	if (player->position.y>=515)
	{
		player->position.y = 515;
		if (player->input.jumpHeight>0)
			player->input.jumpHeight = 0;
        return 1;
	}

    return 0;
}
void animation(Game *g)
{

    if (g->player[0].input.right)
    {
        g->player[0].look=SPRITEX_Run;
        g->player[0].animation++;
        
        if (g->player[0].animation>=(SPRITEY_Run/2)+1)
        g->player[0].animation=0;
        g->player[0].spritestate=g->player[0].animation;
        return;
    }
    
    if (g->player[0].input.left)
    {
        g->player[0].look=SPRITEX_Run;
        if (g->player[0].animation<8)
        {
            g->player[0].animation=8;
        }
        g->player[0].animation++;
        
        if (g->player[0].animation>=(SPRITEY_Run+1))
        g->player[0].animation=8;

        g->player[0].spritestate=g->player[0].animation;
                return;
    }
    g->player[0].animation=0;
    if ((!g->player[0].input.left) && (!g->player[0].input.right))
    {
        g->player[0].look=SPRITEX_Idle;
        g->player[0].animation++;
        
        if (g->player[0].animation>=(SPRITEY_Idle+1))
            g->player[0].animation=0;
    g->player[0].spritestate=g->player[0].animation;
            return;
    }
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


            g->player[0].input.movement=1;

        }

        
        if ((g->player[0].input.up) && (g->player[0].input.fix==0))
        {
            g->player[0].input.startJump = 1;
            g->player[0].input.movement=2;
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
                g->player[0].input.movement=3;
            }
        }
        

        g->player[0].position.y+=GRAVITY;

        if (onGround(&g->player[0]))
        {
            g->player[0].position.y-=GRAVITY;
            g->player[0].input.fix=0;
            g->player[0].input.movement=0;
        }

        
        
    g->player[0].pos_cercle.x=g->player[0].position.x+g->bg.scroll_x;
    g->player[0].pos_cercle.y=g->player[0].position.y+40;
    g->player[0].pos_cercle.r=30;

}

