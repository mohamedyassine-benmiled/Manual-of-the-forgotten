#include "background.h"


void initBack (background *b)
{
//background
b->imgback=IMG_Load("prison.bmp");
b->posback.x=0;
b->posback.y=0;
//camera
b->camera.x=0;
b->camera.y=0;
b->camera.w=SCREEN_W; 
b->camera.h=SCREEN_H;
//musique
b->son=Mix_LoadMUS("musique.mp3"); //Chargement de la musique

}

void initBackMasque (background *b)
{
//background
b->imgback=SDL_LoadBMP("prison mask.bmp");
b->posback.x=0;
b->posback.y=0;

//camera
b->camera.x=0;
b->camera.y=0;
b->camera.w=SCREEN_W; 
b->camera.h=SCREEN_H;

}

void initBack2 (background *b)
{
//background2
b->imgback=IMG_Load("prison.bmp");
b->posback2.x=0;
b->posback2.y=0;
//camera2
b->camera2.x=0;
b->camera2.y=0;
b->camera2.w=SCREEN_W; 
b->camera2.h=SCREEN_H;
//musique
b->son=Mix_LoadMUS("musique.mp3"); //Chargement de la musique

}


void initialisation_back(background *b)
{
	initBack(b);
	initBack2(b);
}



void afficheBack (background b, SDL_Surface *ecran)
{

Mix_PlayMusic(b.son, -1);
SDL_BlitSurface(b.imgback,&b.camera,ecran,&b.posback);
}

void afficheBack2 (background b, SDL_Surface *ecran)
{

Mix_PlayMusic(b.son, -1); 
SDL_BlitSurface(b.imgback,&b.camera2,ecran,&b.posback2);
}
/*void afficher_back(background b, SDL_Surface *ecran)
{
	afficheBack(b,ecran);
	afficheBack2(b,ecran);
	
}*/

void scrolling (background *b,int direction)
{
 const int speed=5;
if (direction ==0){
	b->camera.x+= speed;          

	b->camera2.x+= speed;
	
        }
else if (direction ==1){          
	b->camera.x-=speed; 

	b->camera2.x-=speed; 
	}
else if (direction ==4){
        b->camera2.x+= speed;
	}
else if (direction ==7){            
	b->camera2.x-= speed;
	}
else if (direction ==2){  
        b->camera.y-= speed;

         b->camera2.y-= speed;
	}
else if (direction ==3){          
        b->camera.y+= speed;

	 b->camera2.y+= speed;
	 }

}



















