extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

extern void memoriaErreserbatu();

/* Pixel bakoitzak har ditzakeen 256 balioetako bakoitzari kolore bat esleitu pantaila nagusian. 0 balioa gardena da 
   eta definitu gabeko balioak beltzak. */

extern void PaletaNagusiaEzarri();

/* Pixel bakoitzak har ditzakeen 256 balioetako bakoitzari kolore bat esleitu bigarren pantailan. 0 balioa 
   gardena da eta definitu gabeko balioak beltzak. */

extern void BigarrenPaletaEzarri();

/* Irudikatutako Spriteak memorian kargatzen ditu.*/

extern void SpriteakMemorianGorde();

/* Funtzio honek erronbo bat irudikatuko dut pantailako x-y posizioan. Pantailan ateratzea nahi den erronbo 
   bakoitzari indize desberdin bat esleitu behar zaio, 0 eta 126 balioen arteko indizea izan daiteke. */

extern void ErakutsiKarratua(int indizea, int x, int y);
extern void EzabatuaKarratua(int indizea, int x, int y);

extern void ErakutsiTrex(int indizea, int x, int y);
extern void EzabatuTrex(int indizea, int x, int y);


extern void ErakutsiErronboa(int indizea, int x, int y);
/*Funtzio honek erronbo baten indizea pasata pantailatik ezabatzen du*/
extern void EzabatuErronboa(int indizea, int x, int y);

extern void ErakutsiErronboHandia(int indizea, int x, int y);
extern void EzabatuErronboHandia(int indizea, int x, int y);


