
#include "include/animation.h"
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

int animatehover(int x,int y,image img,image img2,SDL_Surface *screen)
{
    int hover;
                    if (hoverbutton(x,y,img))
                    {
                        hover=1;
                        show(img,screen);
                        

                    }
                    else
                    {
                        hover=0;
                        show(img2,screen);

                    }
    return hover;
}
void animateclick(int x,int y,image img,image img2,SDL_Surface *screen)
{
                    if (hoverbutton(x,y,img))
                    {
                        show(img,screen);
                    }


}