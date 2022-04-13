void updateminimap(Game *g ){
g->minimap.img.pos2.w=g->bg.img.pos2.w*MINIMAP/100;
g->minimap.img.pos2.h=g->bg.img.pos2.h*MINIMAP/100;
g->minimap.img.pos2.x=g->bg.img.pos2.x*MINIMAP/100;
g->minimap.img.pos2.y=g->bg.img.pos2.y*MINIMAP/100; //position background
g->minimap.player[0].position.x=g->player[0].position.x*20/100+g->minimap.img.pos1.x;
g->minimap.player[0].position.y=g->player[0].position.y*20/100+g->minimap.img.pos1.x;











}


void initminimap(minimap *assets)
{
    

     //Background
        assets->img.surface=IMG_Load("graphics/720/Level/Level1_0.png");
        assets->img.pos1.x=500;
        assets->img.pos1.y=500;

	 
	 	

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































