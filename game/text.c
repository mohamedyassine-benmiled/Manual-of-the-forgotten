#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/text.h"
#include "include/image.h"
void inittext(text *t)
{

// font

}
void displaytext (text t, image img)
{
img.surface=TTF_RenderText_Solid (t.font,t.texte,t.textColor);
}