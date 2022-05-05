/**
 * @file character.c
 * 
 * @author Mohamed Yassine Ben Miled
 * @brief Character Movement and Animation
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "include/character.h"
#include "include/game.h"
#include "include/declarations.h"
#include "include/config.h"

//Init to remove warnings
int CollisionRight(Character *player,Background *bg,SDL_Color rgb);
int CollisionLeft(Character *player,Background *bg,SDL_Color rgb);
int CollisionGround(Character *player,Background *bg,SDL_Color rgb);
int CollisionTop(Character *player,Background *bg,SDL_Color rgb);
int bordercheck(Background *bg);



void animation(Character *player)
{
        //Jump Right
        if ((player->input.fix) && (player->direction==0))
        {
            if (!(player->look==SPRITEXP0_Jump))
                player->animation=0;

            player->look=SPRITEXP0_Jump;
            player->animation++;

            if (player->animation>=(SPRITEYP0_Jump/2)+1)
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
            if (!(player->look==SPRITEXP0_Jump))
                player->animation=0;
            player->look=SPRITEXP0_Jump;
            player->animation--;
            if (player->animation<(SPRITEYP0_Jump/2)+1)
            {
            player->animation=SPRITEYP0_Jump;
            }
            player->spritestate=player->animation;
            return;
        }
        else
        //Jump Idle
        if (player->input.fix)
        {
            if (!(player->look==SPRITEXP0_Jump))
                player->animation=0;
            player->look=SPRITEXP0_Jump;
            player->animation++;

            if (player->animation>=(SPRITEYP0_Jump/2)+1)
            {
            player->animation=0;
            }
            player->spritestate=player->animation;
            return;
        }
        //Idle Right
        if ((player->input.movement==0) && (player->direction==0))
        {
            if (!(player->look==SPRITEXP0_Idle))
                player->animation=0;
            player->look=SPRITEXP0_Idle;
            player->animation++;
            
            if (player->animation>=(SPRITEYP0_Idle/2)+1)
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
            if (!(player->look==SPRITEXP0_Idle))
                player->animation=0;
            player->look=SPRITEXP0_Idle;
            player->animation--;

            if (player->animation<(SPRITEYP0_Idle/2)+1)
            {
            player->animation=SPRITEYP0_Idle;
            }
                player->spritestate=player->animation;
                return;
        }
        else
        //Run Right
        if ((player->input.right) && (player->input.movement==1))
        {
            if (!(player->look==SPRITEXP0_Run))
                player->animation=0;
            player->look=SPRITEXP0_Run;
            player->animation++;

            if (player->animation>=(SPRITEYP0_Run/2)+1)
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
            if (!(player->look==SPRITEXP0_Run))
                player->animation=0;
            player->look=SPRITEXP0_Run;
            player->animation--;
            if (player->animation<(SPRITEYP0_Run/2)+1)
            {
            player->animation=SPRITEYP0_Run;
            }
            player->spritestate=player->animation;
            return;
        }


}

void movement(Character *player,Background *bg,int x)
{
    SDL_Color rgb;
        settings config;
    get_config(&config);
    rgb.r=0;
    rgb.g=0;
    rgb.b=0;
    if (x==1)
    {
        x=bordercheck(bg);
    }
    /* Right Fast */
        if (((player->input.right)&&(player->input.fast))&&(!CollisionRight(player,bg,rgb)))
        {
          
                if (player->position.x<config.resolution_w/2)
                {
                    player->position.x+=SPEED*2;
                }
                            player->direction=0;
        //OLD CENTER CAMERA
        /*    
        if (!center_camera(player,x))
            {
                if (player->position.x<config.resolution_w/2)
                {
                    player->position.x+=SPEED*2;
                    bg->img.pos2.x-=SPEED*2;
                }
            }
            */
            player->input.movement=1;
        }
        
        /* Left Fast */
        else if (((player->input.left)&&(player->input.fast))&&(!CollisionLeft(player,bg,rgb)))
        {
                player->position.x-=2*SPEED;

                if (player->position.x<0)
                {
                    player->position.x+=2*SPEED;
                }

                player->direction=1;
        //OLD CENTER CAMERA
        /*
        if (!center_camera(player,x))
            {
                if (player->position.x>config.resolution_w/2)
                {
                    player->position.x-=2*SPEED;
                    bg->img.pos2.x+=2*SPEED;
                }
            }
            */
            player->input.movement=1;

        }
        
        else 
        /* Right */
        if ((player->input.right)&&(!CollisionRight(player,bg,rgb)))
        {
                if (player->position.x<config.resolution_w/2)
                {
                    player->position.x+=SPEED;
                }
                player->direction=0;
        //OLD CENTER CAMERA
        /*
        if (!center_camera(player,x))
            {
                if (player->position.x<config.resolution_w/2)
                {
                    player->position.x+=SPEED;
                    bg->img.pos2.x-=SPEED;
                }
            }
            */
            player->input.movement=1;
        }
        
        /* Left */

        else if ((player->input.left)&&(!CollisionLeft(player,bg,rgb)))
        {

                player->position.x-=SPEED;
                if (player->position.x<0)
                {
                    player->position.x+=SPEED;
                }
                player->direction=1;
        //OLD CENTER CAMERA
        /*
        if (!center_camera(player,x))
            {
                if (player->position.x>config.resolution_w/2)
                {
                    player->position.x-=SPEED;
                    bg->img.pos2.x+=SPEED;
                }
            }
        */
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

            if ((player->input.jumpHeight < maxJmpH))
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
            if (CollisionTop(player,bg,rgb))
            {
                player->input.startJump=0;
                player->input.jumpHeight=maxJmpH;
                player->input.movement=3;
            }
        }
        player->position.y+=GRAVITY;
        
        if ((CollisionGround(player,bg,rgb)))
        {
            player->position.y-=GRAVITY;
            player->input.fix=0;
        }
        
        
        
    player->pos_cercle.x=player->position.x;
    player->pos_cercle.y=player->position.y+40;
    player->pos_cercle.r=30;

}

