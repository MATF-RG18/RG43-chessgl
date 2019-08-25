#ifndef TEXTURE_HANDLER
#define TEXTURE_HANDLER

/* strukture zaglvalja tex fajlova */

typedef struct {
  unsigned short type;
  unsigned int size;
  unsigned short reserved1;
  unsigned short reserved2;
  unsigned int offsetbits;
} BITMAPFILEHEADER;

typedef struct {
  unsigned int size;
  unsigned int width;
  unsigned int height;
  unsigned short planes;
  unsigned short bitcount;
  unsigned int compression;
  unsigned int sizeimage;
  int xpelspermeter;
  int ypelspermeter;
  unsigned int colorsused;
  unsigned int colorsimportant;
} BITMAPINFOHEADER;

/* Struktura za smestanje podataka o slici. */
typedef struct Image {
    
    /* Dimenzije slike. */  
    int width, height; 
    /* Niz u kojem se cuvaju podaci za sve piksele u obliku (R, G, B). */
    char *pixels; 

} Image;

class TextureHandler{


public:

    TextureHandler();

    Image *image;

    /* Funkcija koja inicijalizuje strukturu i vraca pokazivac na nju. */
    void image_init(int width, int height);

    /* Funkcija koja oslobadja prostor u kojem su se cuvali podaci o slici. */
    void image_done();

    /* Ucitavanje podataka o slici iz fajla u strukturu Image. */
    void image_read(char *filename);
};

#endif