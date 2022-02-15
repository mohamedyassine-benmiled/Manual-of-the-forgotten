#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
#include <SDL/SDL.h>
#include "image.h"

typedef struct
{
    /* data */
    GameImage assets;
    int death;
    int health;
} Game;




//int game(int run);


#endif // GAME_H