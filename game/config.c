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
#include "include/game.h"
#include "include/config.h"

//Writing Config Values in config.cfg
int write_config(settings *config)
{
    config->f=NULL;
     config->f=fopen("config/config.cfg","w");
    if (config->f!=NULL)
    {
        fprintf(config->f,"[resolution]\n");
        fprintf(config->f,"w=%d\n",config->resolution_w);
        fprintf(config->f,"h=%d\n",config->resolution_h);
        fprintf(config->f,"fullscreen=%d\n",config->fullscreen);
        fprintf(config->f,"volume=%d\n",config->volume);
        fprintf(config->f,"audio=%d\n",config->audio);
        fclose(config->f);
        return 0;
    }
    else
    {
        return -1;
    }
}
//Reading Config Values from config.cfg
int get_config(settings *config)
{
  config->f=NULL;
   config->f=fopen("config/config.cfg","r");
    if (config->f!=NULL)
    {
        fscanf(config->f,"[resolution]\n");
        fscanf(config->f,"w=%d\n",&config->resolution_w);
        fscanf(config->f,"h=%d\n",&config->resolution_h);
        fscanf(config->f,"fullscreen=%d\n",&config->fullscreen);
        fscanf(config->f,"volume=%d\n",&config->volume);
        fscanf(config->f,"audio=%d\n",&config->audio);
        fclose(config->f);
        return 0;
    }
    else
        return -1;

}

int write_save(Game *g)
{
    FILE *f=NULL;
    f=fopen("save/savefile","w");
    if (f!=NULL)
    {
        fprintf(f,"[Game SaveFile]\n");
        fprintf(f,"player.health=%d\n",g->player[0].health);
        fprintf(f,"player.life=%d\n",g->player[0].life);
        fprintf(f,"player.x=%d\n",g->player[0].position.x);
        fprintf(f,"player.y=%d\n",g->player[0].position.y);
        fprintf(f,"background.x=%d\n",g->bg.img.pos2.x);
        fprintf(f,"background.y=%d\n",g->bg.img.pos2.y);
        fprintf(f,"score=%d\n",g->player[0].score);
        fclose(f);
        return 0;
    }
    else
    {
        return -1;
    }
}
int get_save(Game *g)
{
    int x,y;
    FILE *f=NULL;
    f=fopen("save/savefile","r");
    if (f!=NULL)
    {
        fscanf(f,"[Game SaveFile]\n");
        fscanf(f,"player.health=%d\n",&g->player[0].health);
        fscanf(f,"player.life=%d\n",&g->player[0].life);
        fscanf(f,"player.x=%d\n",&g->player[0].position.x);
        fscanf(f,"player.y=%d\n",&g->player[0].position.y);
        fscanf(f,"background.x=%d\n",&x);
        fscanf(f,"background.y=%d\n",&y);
        g->bg.img.pos2.x=x;
        g->bg.img.pos2.x=y;
        fscanf(f,"score=%d\n",&g->player[0].score);
        fclose(f);
        return 0;
    }
    else
    {
        return -1;
    }
}

void writescore(int score)
{
    int ps=0;
    FILE *f=NULL;
    f=fopen("save/score","r");
    if (f!=NULL)
    {
        fscanf(f,"Score=%d\n",&ps);
        fclose(f);
    }

    if (ps<score)
    {
            f=fopen("save/score","w");
            if (f!=NULL)
        {
            {
                    fprintf(f,"Score=%d\n",score);
                        fclose(f);
                                return 0;
            }
        }

    }
            return -1;



}