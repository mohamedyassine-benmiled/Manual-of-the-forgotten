#include <math.h>

#include "include/collision.h"

int collision_cercle(Cercle c1, Cercle c2)
{
    return(sqrt(pow((c1.x-c2.x),2)+pow((c1.y-c2.y),2)) <= (c1.r+c2.r));
}


int collision_box(Box b1, Box b2)
{
    return(b1.x > b2.x-8 && b1.x < b2.x+8);
}

int onGround(GAME *game, int n)
{
    return 1;
    /*
    SDL_Color PixelToCompare;
    PixelToCompare = GetPixel(g->bg.levelCollision /*Background*/, g->player[n].position.x + g->bg.scroll_x + g->player[n].position.w / 2, g->player[n].position.y+g->player[n].position.h-(game->config.resolution_h-g->bg.levelCollision->h)/2);
    return ((PixelToCompare.r == 255) && (PixelToCompare.b == 255) && (PixelToCompare.g == 255));
    */
}