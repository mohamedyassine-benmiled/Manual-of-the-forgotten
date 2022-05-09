#include <stdio.h>
#include "include/game.h"

int CollisionRight(Character *player,Background *bg,SDL_Color rgb);
int CollisionLeft(Character *player,Background *bg,SDL_Color rgb);
int CollisionGround(Character *player,Background *bg,SDL_Color rgb);
int CollisionTop(Character *player,Background *bg,SDL_Color rgb);
void collisionarduino(Game *g)
{
    SDL_Color rgb;
    rgb.r=0;
    rgb.g=0;
    rgb.b=0;
    if (CollisionLeft(&g->player[0],&g->bg,rgb))
    {
        arduinoWriteData(0);
    }
    if (CollisionRight(&g->player[0],&g->bg,rgb))
    {
        arduinoWriteData(1);
    }

}

void movementarduino(Game *g)
{
    int x=0;
    arduinoReadData(x);
    printf("\n%d",x);
    if (x==1)
    {
        g->player[0].input.right=1;
    }
    if (x==2)
    {
        g->player[0].input.left=1;
    }
    if (x==3)
    {
        g->player[0].input.startJump=1;
    }

}

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
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}