#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
#include <SDL/SDL.h>
#include "image.h"
#define true 1
#define false 0


typedef struct
{
    /* data */
    GameImage assets;
    int death;
    int health;
} Game;




//int game(int run);


#endif // GAME_H