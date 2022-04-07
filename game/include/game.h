#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
#include <SDL/SDL.h>
#include "image.h"
#include "init.h"
#include "menu.h"
#include "animation.h"
#include "collision.h"

typedef struct
{
    //Movement
    int up;
    int down;
    int right;
    int left;
    int startjump;
    int reset;
    //Attacks
    int a1; //ATTACK1
    int a2; //ATTACK2
    int sj; //SPECIAL JUMP
    //Cheats for developer testing
    int ih;
    } Input;

int game(SDL_Surface *screen,int run);


#endif // GAME_H