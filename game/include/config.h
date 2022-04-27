/**
 * @file config.c
 * @author TMOF Team
 * @brief Config file
 * @version 0.5
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
    int volume;
} settings;
int write_config(settings *config);
int get_config(settings *config);
#endif