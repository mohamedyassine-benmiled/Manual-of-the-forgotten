void updateminimap(Game *g ){









    
}


void initminimap(minimap *assets)
{
    

     //Background
        assets->img.surface=IMG_Load("graphics/720/Level/Level1_0.png");
        
	 
	 	

}



void scrolling (Game *g)
{
 
if (g->player[0].input.right)
{
	g->bg.img.pos2.x+=SPEED;          

	
	
        }
else if(g->player[0].input.left) {          
	g->bg.img.pos2.x-=SPEED; 

	
	}
    }































