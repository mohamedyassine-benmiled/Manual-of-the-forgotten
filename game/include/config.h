#ifndef CONFIG_H
#define CONFIG_H
#include <stdbool.h>
#include <SDL/SDL.h>



typedef struct 
{
    /* data */
    FILE *f;
    int resolution_w;
    int resolution_h;
    int fullscreen;
    int audio;
} settings;
int write_config(settings *config);
int get_config(settings *config);
#endif