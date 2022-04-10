#include "include/game.h"


void initBack (Game *b)
{
//background
b->bg.img.surface=IMG_Load("level1.png");
b->bg.img.pos1.x=0;
b->bg.img.pos1.y=0;
//camera
b->bg.img.pos2.x=0;
b->bg.img.pos2.y=0;
b->bg.img.pos2.w=1920; 
b->bg.img.pos2.h=1080;
//musique
b->bg.son=Mix_LoadMUS("musique.mp3"); //Chargement de la musique

}

void initBackMasque (Game *m)
{
//background
m->bg.img.surface=IMG_Load("level1MASQ.png");
m->bg.img.pos1.x=0;
m->bg.img.pos1.y=0;

//camera
m->bg.img.pos2.x=0;
m->bg.img.pos2.y=0;
m->bg.img.pos2.w=1920; 
m->bg.img.pos2.h=1080;

}



void initialisation_back(Game *b)
{
	initBack(b);
	
}



void afficheBack (Game b, SDL_Surface *ecran)
{

Mix_PlayMusic(b.bg.son, -1);
SDL_BlitSurface(b.bg.img.surface,&b.bg.img.pos2,ecran,&b.bg.img.pos1);
}
void afficheBackM (Game m, SDL_Surface *ecran)
{


SDL_BlitSurface(m.bg.img.surface,&m.bg.img.pos2,ecran,&m.bg.img.pos1);
}


void afficher_back(Game b, SDL_Surface *ecran)
{
	afficheBack(b,ecran);
	
	
	
}

void scrolling (Game *b,int direction , int *pas)
{
 
if (direction ==0)
{
	b->bg.img.pos1.x+=pas;          

	
	
        }
else if (direction ==1){          
	b->bg.img.pos1.x-=pas; 

	
	}



else if (direction ==2){          
        b->bg.img.pos1.y+= pas;

	 
	 }
else if (direction ==3){  
        b->bg.img.pos1.y-=pas;

         
	}
}



















