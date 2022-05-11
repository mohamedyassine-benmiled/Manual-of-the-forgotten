#ifndef fonction_H_INCLUDED
#define fonction_H_INCLUDED
#include "textetictac.h" 
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1300  
#define SCREEN_H 760 







struct tictactoe
{

SDL_Rect backpos  ;   
SDL_Surface *back ;  




SDL_Rect posx1  ;     
SDL_Rect posx2  ;    
SDL_Rect posx3  ;    
SDL_Rect posx4  ;   
SDL_Rect posx5  ;    
SDL_Rect posx6  ;  
SDL_Rect posx7  ;   
SDL_Rect posx8  ;    
SDL_Rect posx9  ;  
SDL_Surface *x1 ;    
SDL_Surface *x2 ;  
SDL_Surface *x3 ;  
SDL_Surface *x4 ;  
SDL_Surface *x5 ;  
SDL_Surface *x6 ;  
SDL_Surface *x7 ;  
SDL_Surface *x8 ;  
SDL_Surface *x9 ; 




SDL_Rect poso1  ;     
SDL_Rect poso2  ;    
SDL_Rect poso3  ;    
SDL_Rect poso4  ;   
SDL_Rect poso5  ;    
SDL_Rect poso6  ;  
SDL_Rect poso7  ;   
SDL_Rect poso8  ;    
SDL_Rect poso9  ;  
SDL_Surface *o1 ;    
SDL_Surface *o2 ;  
SDL_Surface *o3 ;  
SDL_Surface *o4 ;  
SDL_Surface *o5 ;  
SDL_Surface *o6 ;  
SDL_Surface *o7 ;  
SDL_Surface *o8 ;  
SDL_Surface *o9 ; 


};

typedef struct tictactoe tic ; 










void initialiser_tictac(tic *m) ;
void afficherminimap(tic m, SDL_Surface * screen);
void liberer(tic m) ;










void displayBoard(char board[]);
int verifySelection(int square ,int player,char board[],tic m, SDL_Surface * screen);
void checkForWin(char board[],char *whoWon,Text t,SDL_Surface *screen);















#endif

