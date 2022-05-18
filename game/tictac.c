#include <SDL/SDL.h>
#include "include/tictac.h" 
#include <SDL/SDL_image.h>
#include "include/textetictac.h" 

    int i, square;    
int vrai=0;
   char board[ 9 ], whoWon = ' ';
   int currentPlayer = 0;
void starttic(SDL_Surface *screen)
{
   tic m;
   Text t;
   int done = 0;
initialiser_tictac(&m) ;
initText(&t) ; 
SDL_Event event ;  
afficherminimap(m,screen);
	

//////////////////////////////////////

    for(i = 0; i < 9; i++) board[ i ] = ' ';

  displayBoard(board);

    while(whoWon == ' ') 
  
    {
  
	
	     
      
	
	
         displayTextplayer(t,screen) ;

         displayTextenemy(t,screen) ;
    
    
    
    
    
    
    
    
    
    

      // printf("\n%c\n", whoWon);

 
       if(currentPlayer == 0 || currentPlayer == 1) {
          printf("\nPlayer X\n");    
          printf("Enter an available square (1..9)");
    
          
          
           while (!done)
   { 
            
                             
          
SDL_PollEvent(&event); 

	switch(event.type) 
	{
case SDL_QUIT : 
done = 0 ; 
break ; 

case SDL_KEYDOWN:
	switch(event.key.keysym.sym)
	{
		
case SDLK_a:
square=1;
done = 1 ; 
		break;

case SDLK_z:
square=2;
done = 1 ; 
		break;
		
	case SDLK_e:
square=3;
done = 1 ; 
		break;   
		
	case SDLK_q:
square=4;
done = 1 ; 
		break;   	
		

case SDLK_s:
square=5;
done = 1 ; 
		break;   


case SDLK_d:
square=6;
done = 1 ; 
		break;   

		                
 case SDLK_w:
square=7;
done = 1 ; 
		break;   
		
		
case SDLK_x:
square=8;
done = 1 ; 
		break;  
		
		
case SDLK_c:
square=9;
done = 1 ; 
		break;    		
		
	              
     }
     
     
     
     
     
     
     
     
     
     
     
     
     
   
case SDL_MOUSEBUTTONUP:
{
if (event.button.button == SDL_BUTTON_LEFT)
	{  if (event.button.x > 300 && event.button.x < 483 && event.button.y > 75 && event.button.y < 253)
	   { 
	   square=1;
	   done = 1 ; 
	   }
	   
	
	if (event.button.x > 494 && event.button.x < 674 && event.button.y > 75 && event.button.y < 253)
	   { 
	   square=2;
	   done = 1 ; 
	   }  
	   
	   
	   if (event.button.x > 684 && event.button.x < 864 && event.button.y > 75 && event.button.y < 253)
	   { 
	   square=3;
	   done = 1 ; 
	   } 
	   
	   
	   if (event.button.x > 300 && event.button.x < 483 && event.button.y > 261 && event.button.y < 439)
	   { 
	   square=4;
	   done = 1 ; 
	   }
	   
	   
	   if (event.button.x > 494 && event.button.x < 674 && event.button.y > 261 && event.button.y < 439)
	   { 
	   square=5;
	   done = 1 ; 
	   }
	   
	   
	   
	   if (event.button.x > 684 && event.button.x < 864 && event.button.y > 261 && event.button.y < 439)
	   { 
	   square=6;
	   done = 1 ; 
	   }
	   
	   
	   if (event.button.x > 300 && event.button.x < 483 && event.button.y > 449 && event.button.y < 625)
	   { 
	   square=7;
	   done = 1 ; 
	   }
	   
	   
	   if (event.button.x > 494 && event.button.x < 674 && event.button.y > 449 && event.button.y < 625)
	   { 
	   square=8;
	   done = 1 ; 
	   }
	   
	   
	   
	   if (event.button.x > 684 && event.button.x < 864 && event.button.y > 449 && event.button.y < 625)
	   { 
	   square=9;
	   done = 1 ; 
	   }
   
	 }


}
break; 



	}

 	
 	
     }          
    	vrai=0;

           
          if(verifySelection(square, currentPlayer,board,m,screen) == 1) 
           {
             currentPlayer = 1;
      
           } 
           else {
             currentPlayer = 2;
           
        }
                

      						     } //if joueur

       else 
       { 
 	 
	
          printf("\nPlayer 0\n");
  /*random int between 1 and 9 */
	/*srand(time(NULL));
	 square = rand() % 9+1;*/
	
////////////////













   if((board[ 0 ] == 'O' && board[ 1 ] == 'O' && board[ 2 ] == ' ' && vrai==0)||(board[ 0 ] == 'X' && board[ 1 ] == 'X' && board[ 2 ] == ' ' && vrai==0)) {
    square = 3;
   vrai=1; }
else if((board[ 0 ] == 'O' && board[ 1 ] == ' ' && board[ 2 ] == 'O' && vrai==0)||(board[ 0 ] == 'X' && board[ 1 ] == ' ' && board[ 2 ] == 'x' && vrai==0)) {
    square = 2;
    vrai=1;}
else if((board[ 0 ] == ' ' && board[ 1 ] == 'O' && board[ 2 ] == 'O' && vrai==0)||(board[ 0 ] == ' ' && board[ 1 ] == 'X' && board[ 2 ] == 'X' && vrai==0)) {
    square = 1;
    vrai=1;}


   else if((board[ 3 ] == ' ' && board[ 4 ] == 'O' && board[ 5 ] == 'O' && vrai==0)||(board[ 3 ] == ' ' && board[ 4 ] == 'X' && board[ 5 ] == 'X' && vrai==0)) {
   square = 4;
   vrai=1;}
    else if((board[ 3 ] == 'O' && board[ 4 ] == ' ' && board[ 5 ] == 'O' && vrai==0)||(board[ 3 ] == 'X' && board[ 4 ] == ' ' && board[ 5 ] == 'X' && vrai==0)) {
   square = 5; 
   vrai=1;}   
 else if((board[ 3 ] == 'O' && board[ 4 ] == 'O' && board[ 5 ] == ' ' && vrai==0)||(board[ 3 ] == 'X' && board[ 4 ] == 'X' && board[ 5 ] == ' ' && vrai==0)) {
   square = 6;
   vrai=1; } 
   
   
   
   
      else if((board[ 6 ] == ' ' && board[ 7 ] == 'O' && board[ 8 ] == 'O' && vrai==0)||(board[ 6 ] == ' ' && board[ 7 ] == 'X' && board[ 8 ] == 'X' && vrai==0)) {
square = 7;
vrai=1; }
  else if((board[ 6 ] == 'O' && board[ 7 ] == ' ' && board[ 8 ] == 'O' && vrai==0)||(board[ 6 ] == 'X' && board[ 7 ] == ' ' && board[ 8 ] == 'X' && vrai==0)) {
square = 8;
vrai=1; } 
  else if((board[ 6 ] == 'O' && board[ 7 ] == 'O' && board[ 8 ] == ' ' && vrai==0)||(board[ 6 ] == 'X' && board[ 7 ] == 'X' && board[ 8 ] == ' ' && vrai==0)) {
square = 9; 
vrai=1; } 



      else if((board[ 0 ] == ' ' && board[ 3 ] == 'O' && board[ 6 ] == 'O' && vrai==0)||(board[ 0 ] == ' ' && board[ 3 ] == 'X' && board[ 6 ] == 'X' && vrai==0)) {
	square = 1; 
	vrai=1;} 
	else if((board[ 0 ] == 'O' && board[ 3 ] == ' ' && board[ 6 ] == 'O' && vrai==0)||(board[ 0 ] == 'X' && board[ 3 ] == ' ' && board[ 6 ] == 'X' && vrai==0)) {
	square = 4; 
	vrai=1;} 
	else if((board[ 0 ] == 'O' && board[ 3 ] == 'O' && board[ 6 ] == ' ' && vrai==0)||(board[ 0 ] == 'X' && board[ 3 ] == 'X' && board[ 6 ] == ' ' && vrai==0)) {
	square = 7; 
	vrai=1;} 
	
	

      else if((board[ 1 ] == ' ' && board[ 4 ] == 'O' && board[ 7 ] == 'O' && vrai==0)||(board[ 1 ] == ' ' && board[ 4 ] == 'X' && board[ 7 ] == 'X' && vrai==0)) {
	square = 2;
	vrai=1; } 
	 else if((board[ 1 ] == 'O' && board[ 4 ] == ' ' && board[ 7 ] == 'O' && vrai==0)||(board[ 1 ] == 'X' && board[ 4 ] == ' ' && board[ 7 ] == 'X' && vrai==0)) {
	square = 5; 
	vrai=1;} 
	else if((board[ 1 ] == 'O' && board[ 4 ] == 'O' && board[ 7 ] == ' ' && vrai==0)||(board[ 1 ] == 'X' && board[ 4 ] == 'X' && board[ 7 ] == ' ' && vrai==0)) {
	square = 8;
	vrai=1; }
	
	
	
	
     else if((board[ 2 ] == ' ' && board[ 5 ] == 'O' && board[ 8 ] == 'O' && vrai==0)||(board[ 2 ] == ' ' && board[ 5 ] == 'X' && board[ 8 ] == 'X' && vrai==0)) {
	square = 3; 
	vrai=1;}
	else if((board[ 2 ] == 'O' && board[ 5 ] == ' ' && board[ 8 ] == 'O' && vrai==0)||(board[ 2 ] == 'X' && board[ 5 ] == ' ' && board[ 8 ] == 'X' && vrai==0)) {
	square = 6; 
	vrai=1;}
    else if((board[ 2 ] == 'O' && board[ 5 ] == 'O' && board[ 8 ] == ' ' && vrai==0)||(board[ 2 ] == 'X' && board[ 5 ] == 'X' && board[ 8 ] == ' ' && vrai==0)) {
	square = 9;
	vrai=1;} 
	
	
	else if((board[ 0 ] == ' ' && board[ 4 ] == 'O' && board[ 8 ] == 'O' && vrai==0)||(board[ 0 ] == ' ' && board[ 4 ] == 'X' && board[ 8 ] == 'X' && vrai==0)) {
       square = 1;
       vrai=1;}
	else if((board[ 0 ] == 'O' && board[ 4 ] == ' ' && board[ 8 ] == 'O' && vrai==0)||(board[ 0 ] == 'X' && board[ 4 ] == ' ' && board[ 8 ] == 'X' && vrai==0)) {
       square = 5;
       vrai=1;}
	else if((board[ 0 ] == 'O' && board[ 4 ] == 'O' && board[ 8 ] == ' ' && vrai==0)||(board[ 0 ] == 'X' && board[ 4 ] == 'X' && board[ 8 ] == ' ' && vrai==0)) {
     square = 7;
     vrai=1;}

     
      else if((board[ 2 ] == ' ' && board[ 4 ] == 'O' && board[ 6 ] == 'O' && vrai==0)||(board[ 2 ] == ' ' && board[ 4 ] == 'X' && board[ 6 ] == 'X' && vrai==0)) {
  square = 3;
  vrai=1;}
 else if((board[ 2 ] == 'O' && board[ 4 ] == ' ' && board[ 6 ] == 'O' && vrai==0)||(board[ 2 ] == 'X' && board[ 4 ] == ' ' && board[ 6 ] == 'X' && vrai==0)) {
  square = 5;
  vrai=1;}
 else if((board[ 2 ] == 'O' && board[ 4 ] == 'O' && board[ 6 ] == ' ' && vrai==0)||(board[ 2 ] == 'X' && board[ 4 ] == 'X' && board[ 6 ] == ' ' && vrai==0)) {
  square = 7;
  vrai=1;}



if (vrai==0)
{
srand(time(NULL));
	 square = rand() % 9+1;
}














          if(verifySelection(square, currentPlayer,board,m,screen) == 1)  {

             currentPlayer = 2;
   
          } 
          else 
          {

             currentPlayer = 1;
          
          }

       } 
	 
      displayBoard(board);
       checkForWin(board,&whoWon, t,screen);
       
      done=0;
      if ( currentPlayer == 2)
      {  t.textColor2.r=0;
	t.textColor2.g=0;
	t.textColor2.b=255 ;
	t.textColor.r=255;
	t.textColor.g=255 ;
	t.textColor.b=255 ;
	vrai=0;}
      
      
      if ( currentPlayer == 1)
  	{t.textColor2.r=255;
	t.textColor2.g=255;
	t.textColor2.b=255 ;
	t.textColor.r=0;
	t.textColor.g=0 ;
	t.textColor.b=255 ; }
    }//end for loop

freeText(t) ;
return;
}

void initialiser_tictac(tic *m) 
{
	
m->back = IMG_Load("tictaktoe.jpg") ;
	m->backpos.x=0 ; 
	m->backpos.y=0 ; 


m->x1 = IMG_Load("graphics/720/tictactoe/x.png") ;
	m->posx1.x=0 ; 
	m->posx1.y=0 ; 
m->o1 = IMG_Load("graphics/720/tictactoe/o.png") ;
	m->poso1.x=0 ; 
	m->poso1.y=0 ; 	
m->x2 = IMG_Load("graphics/720/tictactoe/x.png") ;
	m->posx2.x=194 ; 
	m->posx2.y=0 ; 
m->o2 = IMG_Load("graphics/720/tictactoe/o.png") ;
	m->poso2.x=194 ; 
	m->poso2.y=0 ;
m->x3 = IMG_Load("graphics/720/tictactoe/x.png") ;
	m->posx3.x=388 ; 
	m->posx3.y=0 ; 
m->o3 = IMG_Load("graphics/720/tictactoe/o.png") ;
	m->poso3.x=388 ; 
	m->poso3.y=0 ;  
m->x4 = IMG_Load("graphics/720/tictactoe/x.png") ;
	m->posx4.x=0 ; 
	m->posx4.y=183 ; 
m->o4 = IMG_Load("graphics/720/tictactoe/o.png") ;
	m->poso4.x=0 ; 
	m->poso4.y=183 ; 	
m->x5 = IMG_Load("graphics/720/tictactoe/x.png") ;
	m->posx5.x=194; 
	m->posx5.y=183 ; 
m->o5 = IMG_Load("graphics/720/tictactoe/o.png") ;
	m->poso5.x=194 ; 
	m->poso5.y=183 ; 
m->x6 = IMG_Load("graphics/720/tictactoe/x.png") ;
	m->posx6.x=388; 
	m->posx6.y=183 ; 
m->o6 = IMG_Load("graphics/720/tictactoe/o.png") ;
	m->poso6.x=388 ; 
	m->poso6.y=183 ; 	
m->x7 = IMG_Load("graphics/720/tictactoe/x.png") ;
	m->posx7.x=0 ; 
	m->posx7.y=366 ; 
m->o7 = IMG_Load("graphics/720/tictactoe/o.png") ;
	m->poso7.x=0 ; 
	m->poso7.y=366 ; 
m->x8 = IMG_Load("graphics/720/tictactoe/x.png") ;
	m->posx8.x=194 ; 
	m->posx8.y=366 ; 
m->o8 = IMG_Load("graphics/720/tictactoe/o.png") ;
	m->poso8.x=194 ; 
	m->poso8.y=366 ; 
m->x9 = IMG_Load("graphics/720/tictactoe/x.png") ;
	m->posx9.x=388 ; 
	m->posx9.y=366 ; 	
m->o9 = IMG_Load("graphics/720/tictactoe/o.png") ;
	m->poso9.x=388; 
	m->poso9.y=366 ; 		
	
	
}






void afficherminimap(tic m, SDL_Surface * screen)
{
	SDL_BlitSurface(m.back,NULL,screen,&m.backpos) ;

  SDL_Flip(screen);	
	
}



void liberer(tic m) 
{	
	SDL_FreeSurface(m.back) ; 
	SDL_FreeSurface(m.x1) ; 
	SDL_FreeSurface(m.x2) ; 
	SDL_FreeSurface(m.x3) ; 
	SDL_FreeSurface(m.x4) ; 
	
	
} 





void displayBoard(char board[]) {

    /* system("cls");*/
     printf("\t|\t|\n");
     printf("%c\t|%c\t|%c\n", board[0], board[1], board[2]);
     printf("--------|-------|--------\n");
     printf("\t|\t|\n");
     printf("%c\t|%c\t|%c\n", board[3], board[4], board[5]);
     printf("--------|-------|--------\n");
     printf("%c\t|%c\t|%c\n", board[6], board[7], board[8]);
     printf("\t|\t|\n");
}
















int verifySelection(int square, int player,char board[],tic m, SDL_Surface * screen) {

     if((player == 0 || player == 1) && board[square-1] == ' ') {

         board[ square - 1 ] = 'X';





if ( board[ 1 - 1 ]=='X')
SDL_BlitSurface(m.x1,NULL,screen,&m.posx1) ;
if (board[ 2 - 1 ]=='X')
SDL_BlitSurface(m.x2,NULL,screen,&m.posx2) ;
if (board[ 3 - 1 ]=='X')
SDL_BlitSurface(m.x3,NULL,screen,&m.posx3) ;
if (board[ 4 - 1 ]=='X')
SDL_BlitSurface(m.x4,NULL,screen,&m.posx4) ;
if (board[ 5 - 1 ]=='X')
SDL_BlitSurface(m.x5,NULL,screen,&m.posx5) ;
if (board[ 6 - 1 ]=='X')
SDL_BlitSurface(m.x6,NULL,screen,&m.posx6) ;
if (board[ 7 - 1 ]=='X')
SDL_BlitSurface(m.x7,NULL,screen,&m.posx7) ;
if (board[ 8 - 1 ]=='X')
SDL_BlitSurface(m.x8,NULL,screen,&m.posx8) ;
if (board[ 9 - 1 ]=='X')
SDL_BlitSurface(m.x9,NULL,screen,&m.posx9) ;
SDL_Flip(screen);




         return 0;
     }

     else if(board[square-1] == ' ' && player == 2) {

          board[square-1] = 'O';





if ( board[ 1 - 1 ]=='O')
SDL_BlitSurface(m.o1,NULL,screen,&m.poso1) ;
if (board[ 2 - 1 ]=='O')
SDL_BlitSurface(m.o2,NULL,screen,&m.poso2) ;
if (board[ 3 - 1 ]=='O')
SDL_BlitSurface(m.o3,NULL,screen,&m.poso3) ;
if (board[ 4 - 1 ]=='O')
SDL_BlitSurface(m.o4,NULL,screen,&m.poso4) ;
if (board[ 5 - 1 ]=='O')
SDL_BlitSurface(m.o5,NULL,screen,&m.poso5) ;
if (board[ 6 - 1 ]=='O')
SDL_BlitSurface(m.o6,NULL,screen,&m.poso6) ;
if (board[ 7 - 1 ]=='O')
SDL_BlitSurface(m.o7,NULL,screen,&m.poso7) ;
if (board[ 8 - 1 ]=='O')
SDL_BlitSurface(m.o8,NULL,screen,&m.poso8) ;
if (board[ 9 - 1 ]=='O')
SDL_BlitSurface(m.o9,NULL,screen,&m.poso9) ;
SDL_Flip(screen);











          return 0;

     } else 

       return 1;  
     
}















void checkForWin(char board[],char *whoWon,Text t,SDL_Surface *screen) {

     int i, 
         contor = 0;
 
     if(board[ 0 ] == 'X' && board[ 1 ] == 'X' && board[ 2 ] == 'X') {

        *whoWon = 'X';

     } else if(board[ 3 ] == 'X' && board[ 4 ] == 'X' && board[ 5 ] == 'X') {

        *whoWon = 'X';

     } else if(board[ 6 ] == 'X' && board[ 7 ] == 'X' && board[ 8 ] == 'X') {

        *whoWon = 'X';

     } else if(board[ 0 ] == 'X' && board[ 3 ] == 'X' && board[ 6 ] == 'X') {

        *whoWon = 'X';

     } else if(board[ 1 ] == 'X' && board[ 4 ] == 'X' && board[ 7 ] == 'X') {

        *whoWon = 'X';

     } else if(board[ 2 ] == 'X' && board[ 5 ] == 'X' && board[ 8 ] == 'X') {

        *whoWon = 'X';

     } else 

     if(board[ 0 ] == 'O' && board[ 1 ] == 'O' && board[ 2 ] == 'O') {

        *whoWon = 'O';

     } else if(board[ 3 ] == 'O' && board[ 4 ] == 'O' && board[ 5 ] == 'O') {

        *whoWon = 'O';

     } else if(board[ 6 ] == 'O' && board[ 7 ] == 'O' && board[ 8 ] == 'O') {

        *whoWon = 'O';

     } else if(board[ 0 ] == 'O' && board[ 3 ] == 'O' && board[ 6 ] == 'O') {

        *whoWon = 'O';

     } else if(board[ 1 ] == 'O' && board[ 4 ] == 'O' && board[ 7 ] == 'O') {

        *whoWon = 'O';

     } else if(board[ 2 ] == 'O' && board[ 5 ] == 'O' && board[ 8 ] == 'O') {

        *whoWon = 'O';

    }     

     //for diagonals
     if(board[ 0 ] == 'X' && board[ 4 ] == 'X' && board[ 8 ] == 'X') {

        *whoWon = 'X';

     } else if(board[ 2 ] == 'X' && board[ 4 ] == 'X' && board[ 6 ] == 'X') {

        *whoWon = 'X';
     }


     if(board[ 0 ] == 'O' && board[ 4 ] == 'O' && board[ 8 ] == 'O') {

        *whoWon = 'O';

     } else if(board[ 2 ] == 'O' && board[ 4 ] == 'O' && board[ 6 ] == 'O') {

        *whoWon = 'O';
     }


     if(*whoWon == 'X') {

        printf("\nX WON\n");
         displayTextwin( t,screen) ;
         SDL_Flip(screen);
        return; 
     }


     if(*whoWon == 'O') {

        printf("\nO WON\n");
        displayTextenemywin(t,screen) ;
        SDL_Flip(screen);
        return; 
     }


     for(i = 0; i < 9; i++) 
         if(board[i] != ' ') 
             contor++;
          
 
     if(contor == 9) {

        *whoWon = 'C';
        printf("\nCAT GAME\n");
         displayTextrounddraw( t,screen) ;
         SDL_Flip(screen);
        return;
     } 

}








