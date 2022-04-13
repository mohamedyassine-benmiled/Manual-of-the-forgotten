#include "include/character.h"
#include "include/game.h"
#include "include/declarations.h"
#include "include/config.h"

int center_camera(Character *player,int x)
{
    settings config;
    get_config(&config);
    if (x)
    {
    return (player->position.x+32>config.resolution_w/2 && player->position.x-32<config.resolution_w/2);
    }
    else
    {
        return 1;
    }
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
void animation(Character *player)
{
    //Jump Right
    if ((player->input.fix) && (player->direction==0))
    {
        if (!(player->look==SPRITEX_Jump))
            player->animation=0;
        player->look=SPRITEX_Jump;
        player->animation++;

        if (player->animation>=(SPRITEY_Jump/2)+1)
        {
        player->animation=0;
        }
        player->spritestate=player->animation;
        return;
    }
    else
    //Jump Left
    if ((player->input.fix) && (player->direction==1))
    {
        if (!(player->look==SPRITEX_Jump))
            player->animation=0;
        player->look=SPRITEX_Jump;
        player->animation--;
        if (player->animation<(SPRITEY_Jump/2)+1)
        {
        player->animation=SPRITEY_Jump;
        }
        player->spritestate=player->animation;
        return;
    }
    else
    //Jump Idle
    if (player->input.fix)
    {
        if (!(player->look==SPRITEX_Jump))
            player->animation=0;
        player->look=SPRITEX_Jump;
        player->animation++;

        if (player->animation>=(SPRITEY_Jump/2)+1)
        {
        player->animation=0;
        }
        player->spritestate=player->animation;
        return;
    }
    //Idle Right
    if ((player->input.movement==0) && (player->direction==0))
    {
        if (!(player->look==SPRITEX_Idle))
            player->animation=0;
        player->look=SPRITEX_Idle;
        player->animation++;
        
        if (player->animation>=(SPRITEY_Idle/2)+1)
        {
            player->animation=0;
        }
            player->spritestate=player->animation;
            return;
    }
    else
    //Idle Left
    if ((player->input.movement==0) && (player->direction==1))
    {
        if (!(player->look==SPRITEX_Idle))
            player->animation=0;
        player->look=SPRITEX_Idle;
        player->animation--;

        if (player->animation<(SPRITEY_Idle/2)+1)
        {
        player->animation=SPRITEY_Idle;
        }
            player->spritestate=player->animation;
            return;
    }
    else
    //Run Right
    if ((player->input.right) && (player->input.movement==1))
    {
        if (!(player->look==SPRITEX_Run))
            player->animation=0;
        player->look=SPRITEX_Run;
        player->animation++;

        if (player->animation>=(SPRITEY_Run/2)+1)
        {
        player->animation=0;
        }
        player->spritestate=player->animation;
        return;
    }
    else
    //Run Left
    if ((player->input.left) && (player->input.movement==1))
    {
        if (!(player->look==SPRITEX_Run))
            player->animation=0;
        player->look=SPRITEX_Run;
        player->animation--;
        if (player->animation<(SPRITEY_Run/2)+1)
        {
        player->animation=SPRITEY_Run;
        }
        player->spritestate=player->animation;
        return;
    }
}

void movement(Character *player,SDL_Surface *collision,SDL_Rect *pos,int x)
{
        settings config;
    get_config(&config);
        /* Right */

        if ((player->input.right)&&(!Collision_PPP(collision,player[0])))
        {
          
                if (player->position.x<config.resolution_w/2)
                {
                    player->position.x+=SPEED;
                }
                            player->direction=0;
            
        if (!center_camera(player,x))
            {
                if (player->position.x<config.resolution_w/2)
                {
                    player->position.x+=SPEED;
                    pos->x-=SPEED;
                }
            }
            player->input.movement=1;
        }

        /* Left */

        else if ((player->input.left)&&(!Collision_PPP(collision,player[0])))
        {

                player->position.x-=SPEED;
                if (player->position.x<0)
                    player->position.x+=SPEED;
                    player->direction=1;

        if (!center_camera(player,x))
            {
                if (player->position.x>config.resolution_w/2)
                {
                    player->position.x-=SPEED;
                    pos->x+=SPEED;
                }
            }
            player->input.movement=1;

        }
        else
        {
            player->input.movement=0;
        }
        
        if ((player->input.up) && (player->input.fix==0))
        {
            player->input.startJump = 1;
            player->input.movement=2;
        }
        
        /* JUMP START */
        
        if (player->input.startJump)
        {
            player->input.fix=1;

            if (player->input.jumpHeight < maxJmpH)
            {
                player->input.jumpHeight += JUMP_POWER;
                player->position.y -= JUMP_POWER + 2*GRAVITY;
            }
            else
            {
                player->input.startJump=0;
                player->input.jumpHeight=0;
                player->input.movement=3;
            }
        }
        

        player->position.y+=GRAVITY;

        if (onGround(player))
        {
            player->position.y-=GRAVITY;
            player->input.fix=0;

        }

        
        
    player->pos_cercle.x=player->position.x;
    player->pos_cercle.y=player->position.y+40;
    player->pos_cercle.r=30;

}

