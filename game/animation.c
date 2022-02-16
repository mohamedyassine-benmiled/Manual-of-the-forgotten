#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "include/game.h"
#include "include/image.h"

int hoverbutton(int x,int y, image img )
{

        int inside = true;

        if( x < img.pos1.x )
        {
            inside = false;
        }
        else if( x > img.pos1.x + img.pos2.w )
        {
            inside = false;
        }

        else if( y < img.pos1.y )
        {
            inside = false;
        }
        else if( y > img.pos1.y + img.pos2.h )
        {
            inside = false;
        }
        return inside ;
}
void  button(int inside)
{
SDL_Surface *anim ; 
if (inside =true)
{
    anim = IMG_Load(animation/000000)
}
}