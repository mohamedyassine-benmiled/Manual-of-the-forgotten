#include <assert.h>
#include "include/fgifsdl.h"
#include "include/fgif.h"

void SDL_PutPixel32(SDL_Surface *surface, int x, int y, unsigned long pixel)
{
    unsigned char *p = (unsigned char *)surface->pixels + y * surface->pitch + x * 4;
    *(unsigned long*)p = pixel;
}

unsigned long SDLGifGetPixelFromIndex(int ind,Palette* pal)
{
	return pal->pix[ind].r * 0x10000 + pal->pix[ind].g * 0x100 + pal->pix[ind].b;
}

int SDLProcessDisposal(Frame* fr,Palette* pal,SDL_Surface* srf,unsigned char backgroundcolorindex)
{ // http://www.webreference.com/content/studio/disposal.html
	SDL_Rect clipzone;
	clipzone.x = fr->left;
	clipzone.y = fr->top;
	clipzone.w = fr->width;
	clipzone.h = fr->height;
	switch (fr->an.disposalmethod)
	{
	case 1: // Do not dispose
		while(0);
		//SDL_FillRect(srf,&clipzone,0xFF000000);
		break;
	case 2: // Restore to background color
		SDL_FillRect(srf,&clipzone,0xFF000000); // ou NULL ? 
		break;
	case 0: // No disposal specified
	case 3: // Restore to previous
	default:
		assert(0);
		break;
	}
	return 0;
}

SDL_Surface* SDLLoadGif_OneSurf(Frame* fr,Palette* pal,SDL_Surface* prec,unsigned char backgroundcolorindex)
{
	int i,j,cpt;
	unsigned long pixel;
	SDL_Surface* srf = SDL_CreateRGBSurface(0,prec->w,prec->h,32,0,0,0,0);
	SDL_FillRect(srf,NULL,0xFF000000);
	SDL_BlitSurface(prec,NULL,srf,NULL);
	SDLProcessDisposal(fr,pal,srf,backgroundcolorindex);
	if (SDL_MUSTLOCK(srf))
		SDL_LockSurface(srf);
	for(cpt=0,j=0;j<fr->height;j++)
		for(i=0;i<fr->width;i++,cpt++)
		{
			if (!fr->an.transparentflag || fr->an.transparentcolorindex!=fr->pix[cpt])
			{
				pixel = SDLGifGetPixelFromIndex(fr->pix[cpt],pal);
				SDL_PutPixel32(srf,i+fr->left,j+fr->top,pixel);
			}
		}
	if (SDL_MUSTLOCK(srf))
		SDL_UnlockSurface(srf);
	SDL_SetColorKey(srf,SDL_SRCCOLORKEY ,0xFF000000);
	return srf;
}

SDL_Gif* SDLLoadGif(const char* fic)
{
	int i;
	GIFBrut* g;
	SDL_Gif* out;
	SDL_Surface* prec;
	SDL_Surface* keepprec;
	g = LoadGif(fic);
	if (g->lasterror!=0)
	{
		ReleaseGif(g);
		return NULL;
	}
	prec = SDL_CreateRGBSurface(0,g->lsd.width,g->lsd.height,32,0,0,0,0);
	SDL_FillRect(prec,NULL,0xFF000000);
	keepprec = prec;
	out = malloc(sizeof(SDL_Gif));
	out->nbframes = g->nb;
	out->tab = malloc(g->nb*sizeof(SDL_Surface*));
	out->timers = malloc((g->nb+1)*sizeof(int));
	out->timers[0] = 0;
	for(i=0;i<g->nb;i++)
	{
		out->timers[i+1] = out->timers[i] + g->tfr[i]->an.delay;
		if (g->tfr[i]->m==0)
			out->tab[i] = SDLLoadGif_OneSurf(g->tfr[i],&g->globalpal,prec,g->lsd.BackGroundColorIndex);
		else
			out->tab[i] = SDLLoadGif_OneSurf(g->tfr[i],&g->tfr[i]->localpal,prec,g->lsd.BackGroundColorIndex);
		prec = out->tab[i];
	}
	if (out->timers[g->nb]==0)
		out->timers[g->nb] = 1;  // au moins 1 frame d'anim, meme si pas d'anims.
	SDL_FreeSurface(keepprec);
	ReleaseGif(g);
	return out;
}

int SDLFreeGif(SDL_Gif* g)
{
	if (g)
	{
		if (g->tab)
		{
			int i;
			for(i=0;i<g->nbframes;i++)
				SDL_FreeSurface(g->tab[i]);
			free(g->tab);
			free(g->timers);
		}
		free(g);
	}
	return 0;
}

SDL_Surface* SDLGifAutoFrame(SDL_Gif* g)
{
	int timer,i;
	timer = SDL_GetTicks()/10;
	timer = timer%(g->timers[g->nbframes]);
	for(i=1;i<=g->nbframes;i++)
		if (timer<g->timers[i])
			return g->tab[i-1];
	assert(0);
	return NULL;
}
