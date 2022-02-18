#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/fgif.h"
//#include "lzwtable.h"

#define GIF_DEFAULT_DELAY 10

uchar Fuchar(FILE* F)
{
	uchar res;
	fread(&res,1,1,F);
	return res;
}

ushort Fushort(FILE* F)
{
	ushort res;
	fread(&res,2,1,F);
	return res;
}

int Fnchain(FILE* F,int size,char* out)
{
	out[size] = '\0';
	fread(out,1,size,F);
	return 0;
}

int GIFCheckHead(FILE* F,char* version)
{
	char gif[4];
	Fnchain(F,3,gif);
	if (strcmp(gif,"GIF")!=0)
		return -1;
	Fnchain(F,3,version);
	return 0;
}

int GIFLSD(FILE* F,LSD* plsd)
{
	uchar pf;
	uchar pixelaspectratio;
	plsd->width = Fushort(F);
	plsd->height = Fushort(F);
	pf = Fuchar(F);
	plsd->GlobalColorTableFlag = (pf>>7);
	plsd->ColorResol = ((pf>>4)&7);
	plsd->SortFlag = ((pf>>3)&1);
	plsd->SizeofGlobalColorTable = (pf&7);
	plsd->BackGroundColorIndex = Fuchar(F);
	pixelaspectratio = Fuchar(F);
	plsd->AspectRatio = (pixelaspectratio+15)*1.0f/64;
	return 0;
}

int GIFPalette(FILE* F,uchar sizofglobalcolortable,Palette* ppal)
{
	int i;
	memset(ppal,0,sizeof(Palette));
	ppal->nbcol = 1<<(sizofglobalcolortable+1);
	for(i=0;i<ppal->nbcol;i++)
	{
		ppal->pix[i].r = Fuchar(F);
		ppal->pix[i].g = Fuchar(F);
		ppal->pix[i].b = Fuchar(F);
	}
	return 0;
}

int GIFanimate(FILE* F,Animate* pan)
{
	uchar BlockSize,pfield,terminator; // I'll be back.
	BlockSize = Fuchar(F); 
	if (BlockSize!=4)
		return -11;
	pfield = Fuchar(F);
	pan->transparentflag = (pfield&1);
	pan->userinputflag = ((pfield>>1)&1);
	pan->disposalmethod = ((pfield>>2)&3);
	pan->delay = Fushort(F);
	if (pan->delay == 0)
		pan->delay = GIF_DEFAULT_DELAY;
	pan->transparentcolorindex = Fuchar(F);
	terminator = Fuchar(F);
	return 0;
}

int GIFAppBlocExtention(FILE* F)
{
	uchar BlockSize,len;
	char buf[9];
	char buf2[4];
	BlockSize = Fuchar(F); 
	if (BlockSize!=11)
		return -12;
	Fnchain(F,8,buf);
	Fnchain(F,3,buf2);
	do 
	{
		char* buf3;
		len = Fuchar(F);
		if (len==0)
			break;
		buf3 = malloc((len+1)*sizeof(char));
		Fnchain(F,len,buf3);
		free(buf3);
	} while (len!=0);
	return 0;
}

int GIFCommentBloc(FILE* F)
{
	uchar len;
	do 
	{
		char* buf3;
		len = Fuchar(F);
		if (len==0)
			break;
		buf3 = malloc((len+1)*sizeof(char));
		Fnchain(F,len,buf3);
		free(buf3);
	} while (len!=0);
	return 0;
}

int GIFsubbloc(FILE* F,GIFBrut* g)
{
	uchar GCL;
	GCL = Fuchar(F);  //Graphic Control Label 
	switch(GCL)
	{
	case 0xF9:
		return GIFanimate(F,&g->an);
	case 0xFF:
		return GIFAppBlocExtention(F);
	case 0xFE:
		return GIFCommentBloc(F);
	default:
		break;
	}
	return -10;
}

/*

typedef struct 
{
LZWtable entry;
int basiscodesize;
int codesize;
int nbcol;
uchar* input;
int blocsize;
} LZWDico;

int GetBit(uchar* buf,int *bcurs)
{
	int res = (((buf[(*bcurs)/8])>>((*bcurs)%8))&1);
	(*bcurs)++;
	return res;
}

int GetData(uchar* buf,int* bcurs,int codesize)
{
	int i;
	int res = 0;
	for(i=0;i<codesize;i++)
	{
		int bit = GetBit(buf,bcurs);
		bit<<=i;
		res|=bit;
	}
	return res;
}

int GIF_UpdateCodeSizeIfNeeded(int nbtable,int* codesize)
{
	int max = 1<<(*codesize);
	if (nbtable==max)
	{
		(*codesize)++;
		if (*codesize>12)
			*codesize = 12;  // force. Et normalement, le suivant est un reset table.
	}
	return 0;
}

int GIFLZWPushOutput(char* outbuf,char val,int* curs,int max)
{
	if (*curs<max)
		outbuf[(*curs)++] = val;
	//printf("%d\t",val);
	return 0;
}

int GIFLZW(char* outbuf,LZWDico* d,int max)
{
	int bcurs,cpt,outcurs,data,i;
	LZWtable* table;
	LZWchaine* entree;
	LZWchaine* w;
	w = entree = NULL;
	table = &d->entry;
	for(bcurs=0,cpt=0,outcurs=0;;cpt++)
	{
		data = GetData(d->input,&bcurs,d->codesize);
		assert(bcurs<=d->blocsize*8);
		//printf("%d\t",data);
		if (data==d->nbcol)
		{
			LZW_FreeTable(table);
			LZW_InitTable(table,d->nbcol);
			d->codesize = d->basiscodesize;
			w = LZW_FreeChaine(w);
			continue;
		}
		if (data==d->nbcol+1 || outcurs>=max)
			break;  // eof
		if (w==NULL) // premiere reelle valeur.
		{
			w = LZW_MakeChain1stElem(data);
			GIFLZWPushOutput(outbuf,data,&outcurs,max);
			continue;
		}
		entree = LZW_FreeChaine(entree);
		if (data<d->entry.nb)
			entree = LZW_RecopyChain(table->t[data]);
		else
		{
			entree = LZW_RecopyChain(w);
			LZW_PushChainElem(entree,w->t[0]);
		}
		for(i=0;i<entree->nb;i++)
			GIFLZWPushOutput(outbuf,entree->t[i],&outcurs,max);
		LZW_PushChainElem(w,entree->t[0]);
		LZW_PushTableElem(table,w);
		w = NULL;
		GIF_UpdateCodeSizeIfNeeded(table->nb,&d->codesize);
		w = LZW_RecopyChain(entree);
	}
	entree = LZW_FreeChaine(entree);
	w =LZW_FreeChaine(w);
	return outcurs;
}

int GIFLZWblocs(FILE* F,Frame* fr,int nbcol)
{
	LZWDico dico;
	long keepFcurs;
	unsigned char localblocsize;
	int writtenoctets;
	char cache[256];
	memset(&dico,0,sizeof(LZWDico));
	dico.codesize = Fuchar(F)+1;
	dico.basiscodesize = dico.codesize;
	dico.nbcol = (1<<(dico.codesize-1));   // pas nbcol (24.gif)
	dico.blocsize = 0;
// count all block : 1e passe
	keepFcurs = ftell(F);
	do 
	{
		localblocsize = Fuchar(F);
		fread(cache,1,localblocsize,F);
		dico.blocsize+=localblocsize;
	} while (localblocsize!=0);
	fseek(F,keepFcurs,SEEK_SET);
// read blocs : 2e passe
	dico.input = calloc(dico.blocsize+2,sizeof(uchar));  // +2 car assume reste = 0 et max 12 bits
	dico.blocsize = 0;
	do 
	{
		localblocsize = Fuchar(F);
		fread(dico.input+dico.blocsize,1,localblocsize,F);
		dico.blocsize+=localblocsize;
	} while (localblocsize!=0);
	dico.blocsize+=2;  // +2 car assume reste = 0 et max 12 bits
	writtenoctets = GIFLZW(fr->pix,&dico,fr->width*fr->height);
	LZW_FreeTable(&dico.entry);
	free(dico.input);
	return 0;
}
*/

typedef struct
{
	short prev;
	uchar data;
} LZWDico2_entry;

typedef struct
{
	LZWDico2_entry e[4096];
	short entrysize;
	char basiscodesize;
	char codesize;
	short nbcol;
} LZWDico2;

typedef struct
{
	char buf[256];
	FILE* F;
	short sizebuf,curs;
	uchar lastsize;
} BinFlux;


int GetBit2(BinFlux* pbin)
{
	short res;
	if (pbin->curs>=pbin->sizebuf)
	{
		pbin->sizebuf = Fuchar(pbin->F);
		pbin->lastsize = pbin->sizebuf;
		if (pbin->sizebuf==0)
		{
			memset(pbin->buf,0,256);
			pbin->sizebuf = 8*256;  // assume que des 0 a la fin.
		}
		else
		{
			fread(pbin->buf,pbin->sizebuf,1,pbin->F);
			pbin->sizebuf = 8*pbin->sizebuf;
		}
		pbin->curs = 0;
	}
	res = (((pbin->buf[(pbin->curs)/8])>>((pbin->curs)%8))&1);
	pbin->curs++;
	return res;
}

short GetData2(BinFlux* pbin,char codesize)
{
	char i;
	short res = 0;
	for(i=0;i<codesize;i++)
	{
		short bit = GetBit2(pbin);
		bit<<=i;
		res|=bit;
	}
	return res;
}

int GIFLZWInitDicoBin(LZWDico2* pdico,BinFlux* pbin,FILE* F)
{
	memset(pdico,0,sizeof(LZWDico2));
	memset(pbin,0,sizeof(BinFlux));
	pbin->F = F;
	pdico->codesize = Fuchar(F)+1;
	pdico->basiscodesize = pdico->codesize;
	pdico->nbcol = (1<<(pdico->codesize-1));   // pas nbcol (24.gif)
	pdico->entrysize = 0;
	return 0;
}

int LZWDico2_Reinit(LZWDico2* pdico)
{
	short i;
	pdico->codesize = pdico->basiscodesize;
	pdico->entrysize = pdico->nbcol +2;
	for(i=0;i<pdico->nbcol;i++)
	{
		pdico->e[i].prev = -1;
		pdico->e[i].data = (uchar)i;
	}
	return 0;
}

uchar LZWGetFirst(LZWDico2* pdico,LZWDico2_entry w)
{
	short ind = w.prev;
	if (ind==-1)
		return w.data;
	while(pdico->e[ind].prev!=-1)
		ind = pdico->e[ind].prev;
	return pdico->e[ind].data;
}

int GIFLZWoutput1(uchar val,uchar* out,int* outcurs,int nbpix)
{
	if (*outcurs==nbpix)
		return -1; // overflow : ignore.
	out[(*outcurs)++] = val;
	//printf("%d\t",val);
	return 0;
}

int GIFLZWoutputR(LZWDico2* pdico,short ind,uchar* out,int* outcurs,int nbpix)
{
	if (ind==-1)
		return 0;
	GIFLZWoutputR(pdico,pdico->e[ind].prev,out,outcurs,nbpix);
	GIFLZWoutput1(pdico->e[ind].data,out,outcurs,nbpix);
	return 0;
}

int GIFLZWoutput(LZWDico2* pdico,LZWDico2_entry w,uchar* out,int* outcurs,int nbpix)
{
	GIFLZWoutputR(pdico,w.prev,out,outcurs,nbpix);
	GIFLZWoutput1(w.data,out,outcurs,nbpix);
	return 0;
}

int GIF_UpdateCodeSizeIfNeeded2(LZWDico2* pdico)
{
	int max = 1<<(pdico->codesize);
	if (pdico->entrysize==max)
	{
		pdico->codesize++;
		if (pdico->codesize>12)
			pdico->codesize = 12;  // force. Et normalement, le suivant est un reset table.
	}
	return 0;
}

int GIFLZWblocs2(FILE* F,uchar* out,int nbcol,int nbpix)
{
	int bcurs,cpt,outcurs;
	short data;
	LZWDico2 dico;
	BinFlux bin;
	short lastwrank;
	LZWDico2_entry w;
	GIFLZWInitDicoBin(&dico,&bin,F);
	for(bcurs=0,cpt=0,outcurs=0,lastwrank=0;outcurs<nbpix;cpt++)
	{
		data = GetData2(&bin,dico.codesize);
		if (data==dico.nbcol)
		{
			LZWDico2_Reinit(&dico);
			data = GetData2(&bin,dico.codesize);
			w = dico.e[data];
			lastwrank = data;
			GIFLZWoutput1(data,out,&outcurs,nbpix);
			continue;
		}
		if (data == dico.nbcol+1)
			break;  // eof
		if (data<dico.entrysize)
		{
			uchar t0 = LZWGetFirst(&dico,dico.e[data]);
			GIFLZWoutput(&dico,dico.e[data],out,&outcurs,nbpix);
			dico.e[dico.entrysize].prev = lastwrank;
			dico.e[dico.entrysize].data = t0;
			lastwrank = data;
			w = dico.e[data];
			dico.entrysize++;
		}
		else
		{
			uchar w0 = LZWGetFirst(&dico,w);
			GIFLZWoutput(&dico,w,out,&outcurs,nbpix);
			GIFLZWoutput1(w0,out,&outcurs,nbpix);
			dico.e[dico.entrysize].prev = lastwrank;
			dico.e[dico.entrysize].data = w0;
			lastwrank = dico.entrysize;
			w = dico.e[dico.entrysize];		
			dico.entrysize++;
		}
		GIF_UpdateCodeSizeIfNeeded2(&dico);
	}
	if (bin.lastsize!=0)
		Fuchar(F);  // 00 
	return 0;
}

int GIFFrame(FILE* F,Frame* fr,int nbcol)
{
	uchar mask;
	fr->left = Fushort(F);
	fr->top = Fushort(F);
	fr->width = Fushort(F);
	fr->height = Fushort(F);
	mask = Fuchar(F);
	fr->m = (mask>>7);
	fr->i = ((mask>>6)&1);
	fr->sortflag = ((mask>>5)&1);
	fr->localcolortab = (mask&7);
	fr->localpal.nbcol = 0;
	if (fr->m)
	{
		GIFPalette(F,fr->localcolortab,&fr->localpal);
		nbcol = fr->localpal.nbcol;
	}
	fr->pix = malloc((fr->width)*(fr->height)*sizeof(char));
	//GIFLZWblocs(F,fr,nbcol);	
	GIFLZWblocs2(F,fr->pix,nbcol,(fr->width)*(fr->height));
	return 0;
}

GIFBrut* GIFerror(GIFBrut* out,int errcode)
{
	assert(0);
	out->lasterror = errcode;
	return out;
}

int PushFrame(GIFBrut* out,Frame* fr)
{
	if (out->tfr==NULL)
	{
		out->tfr = calloc(1,sizeof(Frame*));
		out->nb = 0;
		out->rsv = 1;
	}
	if (out->nb==out->rsv)
	{
		out->rsv*=2;
		out->tfr = realloc(out->tfr,out->rsv*sizeof(Frame*));
		memset(out->tfr + out->nb,0,out->rsv-out->nb);
	}
	out->tfr[out->nb++] = fr;
	return 0;
}

GIFBrut* LoadGif(const char* ingif)
{//http://www.u229.no/stuff/GIFFormat/#logical_screen_descriptor
//ftp://ftp.ncsa.uiuc.edu/misc/file.formats/graphics.formats/gif89a.doc
//http://www.martinreddy.net/gfx/2d/GIF-comp.txt
	char version[4];
	uchar descriptor;
	GIFBrut* out;
	int err;
	FILE* F;
	out = calloc(1,sizeof(GIFBrut));
	F = fopen(ingif,"rb");
	if (!F)
		return GIFerror(out,-1);
	if (GIFCheckHead(F,version)!=0)
		return GIFerror(out,-2);
	if (GIFLSD(F,&out->lsd)!=0)
		return GIFerror(out,-3);
	if (out->lsd.GlobalColorTableFlag)
		GIFPalette(F,out->lsd.SizeofGlobalColorTable,&out->globalpal);  // sinon, palette locale.
	descriptor = 0;
	do
	{
		descriptor = Fuchar(F);
		//printf("%x\t",descriptor);
		switch(descriptor)
		{
		case 0x21:
			if (err=GIFsubbloc(F,out)!=0)
				GIFerror(out,err);
			break;
		case 0x2C:
			{
				Frame* fr = malloc(sizeof(Frame));
				if (GIFFrame(F,fr,out->globalpal.nbcol)!=0)
					GIFerror(out,-7);
				fr->an = out->an;
				PushFrame(out,fr);
				//return out; // SHUNT 1 frame
			}
			break;
		case 0x3B: // final terminator.
			break;
		default:
				GIFerror(out,-8);
			break;
		}
	}
	while(descriptor!=0x3B);
	fclose(F);
	return out;
}

int ReleaseGif(GIFBrut* g)
{
	if (g)
	{
		if (g->tfr)
		{
			int i;
			for(i=0;i<g->nb;i++)
			{
				free(g->tfr[i]->pix);
				free(g->tfr[i]);
			}
			free(g->tfr);
		}
		free(g);
	}
	return 0;
}

