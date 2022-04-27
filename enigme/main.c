#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "enigme.c"
#include <string.h>	                	
int score=120;
char scorechar[100];
int main(){

TTF_Init();

TTF_Font*police=NULL;

TTF_Font*policee=NULL;

SDL_Color red={125,0,0};
SDL_Color white={0,0,0};
police=TTF_OpenFont("Trajan Pro.ttf",20);
policee=TTF_OpenFont("Trajan Pro.ttf",15);
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
Mix_Chunk* soundbtn;
soundbtn = Mix_LoadWAV("mixkit-game-click-1114.wav");

SDL_Surface *surface_score=NULL;
SDL_Color blue={0,0,155};
SDL_Color green={0,200,0};
surface_score=TTF_RenderText_Blended(police,"score :",blue);
SDL_Rect position_score; 
position_score.x=50;
position_score.y=80;

SDL_Surface *surface_message=NULL;
surface_message=TTF_RenderText_Blended(police,"",green);
SDL_Rect position_message; 
position_message.x=350;
position_message.y=200;
sprintf(scorechar,"%d",score);
SDL_Surface *surface_total_score=NULL;
surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
SDL_Rect position_total_score;
position_total_score.x=150;
position_total_score.y=80;
enigme e;
SDL_Surface *screen=NULL;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("erreur: %s \n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(500,314,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("unable to set video mode :%s",SDL_GetError());
return 1;
}
SDL_Rect position; 
position.x=0;
position.y=0;

SDL_Surface *image=NULL;
image=IMG_Load("eren.jpg");
init_enigmes(&e);
int cont=1;
SDL_Event event;
int detect_sound=0;

int detect_reponse=0;
while(cont==1){
	if(score<=0)
	cont=0;
	SDL_BlitSurface(image,NULL,screen,&position);
	SDL_BlitSurface(surface_total_score,NULL,screen,&position_total_score);
	SDL_BlitSurface(surface_score,NULL,screen,&position_score);
	afficherenigme(e,screen);
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                cont=0;
                break;

	    case SDLK_a:
            {
		if(detect_reponse==0){
			if(e.reponse!=1){
				score-=20;
				init_enigmes(&e);
				sprintf(scorechar,"%d",score);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);	
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
			}

			else if(e.reponse==1){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);	
				detect_reponse=1;
				surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}}
										}break;





            case SDLK_b:

            {	
		if(detect_reponse==0){
			if(e.reponse!=2){
				score-=20;
				init_enigmes(&e);
				detect_reponse=0;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);
				}
				else if(e.reponse==2){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				detect_reponse=1;
				surface_message=TTF_RenderText_Blended(policee,"You Won",green);}}
		

		}
		break;
 

		case SDLK_c:
            {	
		if(detect_reponse==0){
			if(e.reponse!=3){
				score-=20;	
				detect_reponse=0;			
				init_enigmes(&e);
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong !",red);
				}
			else if(e.reponse==3){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				detect_reponse=1;surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}}}
				break;}
	

	
case SDL_MOUSEBUTTONDOWN:
        {
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:

            {
                  if(event.button.x>400 && event.button.x<450 && event.button.y>50 && event.button.y<70)
            {
		if(detect_reponse==0){
				if(e.reponse!=1){
				score-=20;
				init_enigmes(&e);
				detect_reponse=0;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);
				}
			else if(e.reponse==1){
				score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);	
				detect_reponse=1;
				surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}
		}}

		else if(event.button.x>400 && event.button.x<450 && event.button.y>100 && event.button.y<120)
            {        
       		
		if(detect_reponse==0){
			if(e.reponse!=2){
				score-=20;
				init_enigmes(&e);
				detect_reponse=0;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);
				}
				else if(e.reponse==2){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				detect_reponse=1;surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}
		
		
		}
            }

		else if(event.button.x>400 && event.button.x<450 && event.button.y>150 && event.button.y<170)
            {
       
		if(detect_reponse==0){
			if(e.reponse!=3){
				score-=20;
				init_enigmes(&e);
				detect_reponse=0;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);
					
				}
			else if(e.reponse==3){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				detect_reponse=1;surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}
		}

		
            }

		
		


		



        }

}
}

 case SDL_MOUSEMOTION:
        {
         if(event.motion.x>50 && event.motion.x<150 && event.motion.y>20 && event.motion.y<40)// postion question
            {
	if(detect_sound==0){
           	Mix_PlayChannel(-1,soundbtn,0 );
		detect_sound=1;

}
           

          }
	else if(event.motion.x>400 && event.motion.x<450 && event.motion.y>50 && event.motion.y<70)//reponse 1
            {
               if(detect_sound==0){
           	Mix_PlayChannel(-1,soundbtn,0);
		detect_sound=1;	
		e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,red);
		e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,white);
		e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,white);}
            }


	else if(event.motion.x>400 && event.motion.x<450 && event.motion.y>100 && event.motion.y<120)//reponse2
            {        
       	if(detect_sound==0){
           	Mix_PlayChannel(-1,soundbtn,0 );
		detect_sound=1;}
	e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,white);
        e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,red);			
	e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,white);
            }


	else if(event.motion.x>400 && event.motion.x<450 && event.motion.y>150 && event.motion.y<170)//rep3
            {    
       	if(detect_sound==0){
           	Mix_PlayChannel(-1,soundbtn,0 );
		detect_sound=1;}
	e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,red);
        e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,white);
	e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,white);     
            }
	else{
	detect_sound=0;
	e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,white);
        e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,white);
	e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,white);}
	   
              
	    
}
    


}

SDL_Flip(screen);
SDL_BlitSurface(surface_total_score,NULL,screen,&position_total_score);
SDL_BlitSurface(surface_score,NULL,screen,&position_score);
SDL_BlitSurface(surface_message,NULL,screen,&position_message);
SDL_Flip(screen);
SDL_Delay(10);
}
SDL_Quit();
return 0;}






