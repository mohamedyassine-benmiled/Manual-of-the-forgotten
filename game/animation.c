#include "include/animation.h"
#include"include/enemy.h"

//Check if mouse on top of button
int hoverbutton(int x,int y, image img )
{

        int inside = true;

        if( x < img.pos2.x )
        {
            inside = false;
        }
        else if( x > img.pos2.x + img.pos2.w )
        {
            inside = false;
        }

        else if( y < img.pos2.y )
        {
            inside = false;
        }
        else if( y > img.pos2.y + img.pos2.h )
        {
            inside = false;
        }
        return inside ;
}
//Show image if mouse is ont top of button
int animatehover(int x,int y,image img,image img2,SDL_Surface *screen)
{
    int runsound;
                    if (hoverbutton(x,y,img))
                    {
                        runsound=1;
                        show(img,screen);
                    }
                    else
                    {
                        runsound=0;
                        show(img2,screen);

                    }


    return runsound;
}
void Remplissage_animation (mouvement *mvt)
{
 mvt-> mvt_av [0]=IMG_Load("walk1.png");
 mvt-> mvt_av [1]=IMG_Load("walk2.png");
 mvt-> mvt_av [2]=IMG_Load("walk3.png");
 mvt-> mvt_av [3]=IMG_Load("walk4.png");
 mvt-> mvt_av [4]=IMG_Load("walk5.png");
 mvt-> mvt_av [5]=IMG_Load("walk6.png");
 mvt-> mvt_av [6]=IMG_Load("walk7.png");

 mvt-> mvt_back [0]=IMG_Load("walk8.png");
 mvt-> mvt_back [1]=IMG_Load("walk9.png");
 mvt-> mvt_back [2]=IMG_Load("walk10.png");
 mvt-> mvt_back [3]=IMG_Load("walk11.png");
 mvt-> mvt_back [4]=IMG_Load("walk12.png");
 mvt-> mvt_back [5]=IMG_Load("walk13.png");
 mvt-> mvt_back [6]=IMG_Load("walk14.png");
}

