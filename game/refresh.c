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
        animationenemy (enemi);
        enemi->position2.x=CHAR_W*enemi->spritestate;
        enemi->position2.y=CHAR_H*enemi->look;
        enemi->position2.h=CHAR_H;
        enemi->position2.w=CHAR_W;
        enemi->pos_box.x=enemi->rpos[0].x;
        enemi->pos_box.y=enemi->rpos[0].y;
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
    SDL_BlitSurface(g->minimap.player[1].image,NULL,screen,&g->minimap.player[1].position);
    SDL_BlitSurface(g->minimap.enemy[0].image,NULL,screen,&g->minimap.enemy[0].rpos[0]);
    SDL_BlitSurface(g->player[0].image,&g->player[0].src_pos,screen,&g->player[0].position);
    SDL_BlitSurface(g->player[1].image,&g->player[1].src_pos,screen,&g->player[1].position);
    SDL_BlitSurface(g->enemy[0].image,&g->enemy[0].position2,screen,&g->enemy[0].rpos[0]);	
    show(g->minimap.score,screen);
}

void BoxGame(Game *g)
{
    if (collision_box(&g->enemy[0].pos_box,&g->player[0].pos_box))
    {
         g->player[0].position.x-=100;
    }
}

void gamerefresh(Game *g,SDL_Surface *screen)
{
    settings config;
    get_config(&config);
    unsigned int elapsed;
    unsigned int lasttime = SDL_GetTicks();

    deplacement_enemy(&g->enemy[0]);

    scrolling(g);

    animationback(&g->bg);
    animationback2(&g->bg);

    g->bg.an2.pos2.x=relative_x(&g->bg,g->bg.an2.pos1);
    rpos_enemy(&g->enemy[0],&g->bg);

    playerrefresh(&g->player[0]);

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
