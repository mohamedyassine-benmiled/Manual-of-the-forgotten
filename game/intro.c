#include "include/config.h"
#include <smpeg/smpeg.h>

void get_out()
{
    //TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();
}
int play_video(SDL_Surface *screen, char filename[30]);

int intro(SDL_Surface *screen)
{
    int x=play_video(screen,"Cinematic.mpg");
    if ((x==0)||(x==2))
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

int play_video(SDL_Surface *screen, char filename[30])
{
    settings config;
    get_config(&config);
    SDL_Surface *surfaceVideo = NULL;
    SDL_Rect position;

    int continuer = 2;
    SDL_Event event;
    char file[100]=" ";
    sprintf(file,"graphics/cinematics/%s",filename);
    SMPEG_Info mpg_info;
    SMPEG *mpg = NULL;

    mpg = SMPEG_new(file, &mpg_info,1);

    surfaceVideo = SDL_AllocSurface(SDL_HWSURFACE, mpg_info.width, mpg_info.height, screen->format->BitsPerPixel, screen->format->Rmask, screen->format->Gmask, screen->format->Bmask, screen->format->Amask);
    if (surfaceVideo == NULL)
    {
        fprintf(stderr, "Impossible d'allouer la surface vidéo");
        exit(EXIT_FAILURE);
    }

    SMPEG_setdisplay(mpg, surfaceVideo, NULL, NULL);
    SMPEG_play(mpg);

    position.x=(config.resolution_w-surfaceVideo->w)/2;
    position.y=(config.resolution_h-surfaceVideo->h)/2;

    while (continuer==2)
    {
         if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 1;
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym==SDLK_SPACE)
                    continuer=0;
                if (event.key.keysym.sym==SDLK_ESCAPE)
                    continuer=0;
                break;
            }
        }
        

        if (SMPEG_status(mpg) != SMPEG_PLAYING)
            continuer = 0;

        SDL_BlitSurface(surfaceVideo, NULL, screen, &position);
        SDL_Flip(screen);
    }

    SMPEG_stop(mpg);
    SMPEG_delete(mpg);
    mpg = NULL;

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_FreeSurface(surfaceVideo);
    surfaceVideo = NULL;
    return continuer;
}
