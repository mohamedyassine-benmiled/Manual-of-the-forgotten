#include "include/refresh.h"
void gamerefresh(Game *g,SDL_Surface *screen);
void animationback(Background *bg);
void scrolling (Game *g);
void initminimap(Minimap *assets);
void updateminimap(Game *g);
void animation(Character *player);
void animationback2(Background *bg);
void rpos_enemy (Enemy *enemi,Background *bg);
int collision_box(Box *b1,Box *b2);


void playerrefresh(Character *player)
{
        animation(player);
        player->src_pos.x=CHAR_W*player->spritestate;
        player->src_pos.y=CHAR_H*player->look;
        player->src_pos.h=CHAR_H;
        player->src_pos.w=CHAR_W;
        player->pos_box.x=player->position.x;
        player->pos_box.y=player->position.y;
}

void enemyrefresh(Enemy *enemi)
{
    if (!enemi->attack)
        animationenemy (enemi);
        enemi->position2.x=CHAR_W*enemi->spritestate;
        enemi->position2.y=CHAR_H*enemi->look;
        enemi->position2.h=CHAR_H;
        enemi->position2.w=CHAR_W;
        enemi->pos_box.x=enemi->rpos.x;
        enemi->pos_box.y=enemi->rpos.y;
}

void BlitGame(Game *g,SDL_Surface *screen)
{
    showgame(g->bg.img,screen);
    showgame(g->minimap.bg,screen);
    show(g->bg.an[0],screen);
    show(g->bg.an[1],screen);
    if (g->bg.i)
    SDL_BlitSurface(g->bg.an2.surface,NULL,screen,&g->bg.an2.pos2);
    SDL_BlitSurface(g->minimap.player[0].image,NULL,screen,&g->minimap.player[0].position);
    if (g->global.nbplayers==2)
    SDL_BlitSurface(g->minimap.player[1].image,NULL,screen,&g->minimap.player[1].position);
    if ((g->minimap.enemy[0].rpos.x >= g->minimap.bg.pos1.x)&&(g->minimap.enemy[0].rpos.x<g->minimap.bg.pos1.x+g->minimap.bg.pos2.w))
    SDL_BlitSurface(g->minimap.enemy[0].image,NULL,screen,&g->minimap.enemy[0].rpos);
    if (!g->player[0].death)
    {
    SDL_BlitSurface(g->player[0].image,&g->player[0].src_pos,screen,&g->player[0].position);
    }
    else
    {
        g->global.lastplayer=1;
        g->global.firstplayer=1;
    }
    if (!g->player[1].death)
    {
    SDL_BlitSurface(g->player[1].image,&g->player[1].src_pos,screen,&g->player[1].position);
    }
    else
    {
        g->global.lastplayer=0;
        g->global.firstplayer=0;
    }
    SDL_BlitSurface(g->enemy[0].image,&g->enemy[0].position2,screen,&g->enemy[0].rpos);	
    for (int i=0;i<g->global.nbplayers;i++)
    {
        g->health[i].l=g->player[i].life;
        show(g->health[i].life,screen);
        for (int j=0;j<g->player[i].health;j++)
        {
            show(g->health[i].heart[j],screen);
        }

    }
    show(g->minimap.score,screen);
    show(g->minimap.time,screen);
}

void BoxGame(Game *g)
{
    int collision=-1;
    for (int i=0;i<g->global.nbplayers;i++)
    {
        if ((collision_box(&g->enemy[0].pos_box,&g->player[i].pos_box))&&(!g->player[i].death))
        {
            collision=i;
        }
    }
    if ((collision==0)||(collision==1))
    {
        if (g->enemy[0].attack==2)
        {
            g->enemy[0].attack=0;
            g->player[collision].health--;
            if (g->player[collision].health==0)
            {
                g->player[collision].death=1;
            }
            if (g->player[collision].direction==0)
            g->player[collision].position.x-=50;
            if (g->player[collision].direction==1)
            g->player[collision].position.x+=50;
        }
        else
        if(g->enemy[0].attack==0)
        {
         g->enemy[0].attack=1;
         g->enemy[0].elapsed=0;
        }

    }
    else
    {
        if (g->enemy[0].attack==2)
        {
            g->enemy[0].attack=0;
        }
    }
    
}

void deathrefresh(Game *g)
{
    int death=0;
    for (int i=0;i<g->global.nbplayers;i++)
    if ((g->player[i].death))
    {
        death++;
    }
    if (death==g->global.nbplayers)
    {
        get_save(g);
        for (int i=0;i<g->global.nbplayers;i++)
        {
        g->player[i].death=0;
        g->player[i].life--;
        }
        write_save(g);
    }
}
void gamerefresh(Game *g,SDL_Surface *screen)
{
    settings config;
    get_config(&config);
    unsigned int elapsed;
    unsigned int lasttime = SDL_GetTicks();
    deathrefresh(g);
    deplacement_enemy(g);
    for (int i=0;i<g->global.nbplayers;i++)
    {
    initlife(&g->health[i],i);
    }
    scrolling(g);

    animationback(&g->bg);
    animationback2(&g->bg);
    collisionarduino(g);
    g->bg.an2.pos2.x=relative_x(&g->bg,g->bg.an2.pos1);
    rpos_enemy(&g->enemy[0],&g->bg);

    playerrefresh(&g->player[0]);
        if (g->global.nbplayers==2)
            playerrefresh(&g->player[1]);
    enemyrefresh(&g->enemy[0]);
    
    updateminimap(g);
    
    BoxGame(g);

    BlitGame(g,screen);

    /* Fixing fps */
    elapsed = SDL_GetTicks()-lasttime;
    if (elapsed<1000/FPS)
    SDL_Delay(1000/FPS-elapsed);
    SDL_Flip(screen);
}
