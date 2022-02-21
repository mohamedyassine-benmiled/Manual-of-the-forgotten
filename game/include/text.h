#ifndef TEXT_H
#define TEXT_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "image.h"
typedef struct {
TTF_Font *font;
SDL_Color textColor;
char texte [75];
}text;
void initText (text *t);
void freeText(text t);
void displayText (text t,image img);

#endif // TEXT_H