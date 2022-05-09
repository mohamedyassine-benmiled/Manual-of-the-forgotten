/**
 * @file config.h
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
#include "declarations.h"


typedef struct 
{
    /* File Data */
    FILE *f;
    /* Settings Data */
    int resolution_w;
    int resolution_h;
    int fullscreen;
    int audio;
    int volume;
} settings;
typedef struct 
{
    /* File Data */
    FILE *f;
    /* Input Keybinds Data */
    Input player[4];
} keybinds;
int write_config(settings *config);
int get_config(settings *config);
#endif