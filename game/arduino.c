#include <stdio.h>
#include "include/game.h"

int CollisionRight(Character *player,Background *bg,SDL_Color rgb);
int CollisionLeft(Character *player,Background *bg,SDL_Color rgb);
int CollisionGround(Character *player,Background *bg,SDL_Color rgb);
int CollisionTop(Character *player,Background *bg,SDL_Color rgb);




int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE *f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}
int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE *f;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}

void collisionarduino(Game *g)
{
    SDL_Color rgb;
    rgb.r=0;
    rgb.g=0;
    rgb.b=0;
    if (CollisionLeft(&g->player[0],&g->bg,rgb))
    {
        arduinoWriteData(0);
        return;
    }
    if (CollisionRight(&g->player[0],&g->bg,rgb))
    {
        arduinoWriteData(1);
        return;
    }
    arduinoWriteData(5);
    return;
}