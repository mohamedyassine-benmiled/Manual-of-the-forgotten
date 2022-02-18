typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;

typedef struct
{
	ushort width;
	ushort height;
	uint GlobalColorTableFlag:1;
	uint ColorResol:3;
	uint SortFlag:1;
	uint SizeofGlobalColorTable:3;
	uchar BackGroundColorIndex;
	float AspectRatio;
} LSD;   // hhaaaa !! C'est de la bonne !!

typedef struct
{
	uchar r,g,b;
} DataRGB;

typedef struct
{
	DataRGB pix[256];
	int nbcol;
} Palette;

typedef struct 
{
	ushort delay;  // 1/100e
	uchar transparentcolorindex;
	uint disposalmethod:2;
	uint userinputflag:1;
	uint transparentflag:1;
} Animate;

typedef struct
{
	ushort left,top,width,height;
	uint i:1; // I=0 - Image formatted in Sequential order  ;  I=1 - Image formatted in Interlaced order
	uint sortflag:1;
	// localpalette
	uint m:1; // M=0 - Use global color map, ignore 'pixel' ;  M=1 - Local color map follows, use 'pixel'
	uint localcolortab:3; // bpp pour calculer Palette.
	Palette localpal;
// inherit subbloc
	Animate an;
// datas
	uchar* pix;
} Frame;

typedef struct
{
	LSD lsd;
	Palette globalpal;
	Animate an;
	int lasterror;
// frames
	Frame** tfr;
	int nb;
	int rsv;
} GIFBrut;

GIFBrut* LoadGif(const char* ingif);
int ReleaseGif(GIFBrut*);

