#include "include/animation.h"

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


