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
            


            if (g->player[0].look>5)
            {
                g->player[0].look=0;
                g->player[0].spritestate=0;
            }

            g->player[0].spritestate++;
            if (g->player[0].spritestate>5)
            {
                g->player[0].spritestate=0;
                g->player[0].look++;
            }
            if (g->player[0].look>3)
                g->player[0].look=0;

            g->global.movement=0;
        }

        /* Left */

        else if ((g->player[0].input.left))
        {

                g->player[0].position.x-=SPEED;
                if (g->player[0].position.x<0)
                    g->player[0].position.x+=SPEED;



            if (g->player[0].look<5)
            {
                g->player[0].look=5;
                g->player[0].spritestate=5;
            }

            g->player[0].spritestate--;
            if (g->player[0].spritestate<1)
            {
                g->player[0].spritestate=5;
                g->player[0].look++;
            }
            if (g->player[0].look>8)
                g->player[0].look=4;


            g->global.movement=1;

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
                g->player[0].position.y -= JUMP_POWER + GRAVITY;
            }
            else
            {
                g->player[0].input.startJump=0;
                g->player[0].input.jumpHeight=0;
            }
        }
        
        /* JUMP END */



        /* GRAVITY */
        
        //g->player[0].position.y+=GRAVITY;

        if (g->player[0].position.y!=515)//ONGROUND
        {
            g->player[0].position.y-=GRAVITY;
            g->player[0].input.fix=0;
        }

        
        
    g->player[0].pos_cercle.x=g->player[0].position.x+g->bg.scroll_x;
    g->player[0].pos_cercle.y=g->player[0].position.y+40;
    g->player[0].pos_cercle.r=30;

}

