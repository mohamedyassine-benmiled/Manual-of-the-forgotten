#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
#include <SDL/SDL.h>

void InitOptions();
void screeninit(SDL_Surface *screen);
void init();
void menu(int cont);
#endif // GAME_H