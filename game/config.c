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