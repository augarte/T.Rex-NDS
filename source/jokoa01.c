/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia

//Geuk garatutako fitxategiak
	
#include "definizioak.h"
#include "periferikoak.h"
#include "zerbitzuErrutinak.h"
#include "fondoak.h"
#include "funtzioLaguntzaileak.h"


void jokoa01(){	
	//***************************************************************************************//
	// Etenak baimendu behar dira.
	// Teklatua konfiguratu behar da.	
	// Tenporizadorea konfiguratu behar da.
	// Teklatuaren etenak baimendu behar dira.
	// Tenporizadorearen etenak baimendu behar dira.
	// Etenen zerbitzu errutinak ezarri behar dira.
	//***************************************************************************************//

	EGOERA=0;
	erakutsiHasieraFondoa();
	iniziatu();
	int tekla=-1;
	
	iprintf("\x1b[10;5HSakatu START jokatzeko");	//Honek, 10 lerroan eta 5 zutabean hasiko da idazten.					

	while(EGOERA != 4){	
		if(EGOERA == 0){
			if(TeklaDetektatu()){
				tekla =  SakatutakoTekla(); 
				if(tekla==3){
					ezabatuLerroBat(10);
					ezabatuLerroBat(13);
					ezabatuLerroBat(16);
					EGOERA = 1;
					erakutsiPartidaFondoa();
					ErlojuaMartxanJarri();	
					ErakutsiTrex(1,12,120);
				}
			}
		}
		else if(EGOERA == 3){
			touchRead(&PANT_DAT);
			int px = PANT_DAT.px;
			int py = PANT_DAT.py;
			if((px > 94 && px < 162) && (py > 66 && py < 126)){
				EGOERA=0;
				erakutsiHasieraFondoa();
				ezabatuLerroBat(13);
				ezabatuLerroBat(16);
				iprintf("\x1b[10;5HSakatu START jokatzeko");
			}
		}	
	}
	ErlojuaGelditu();
	ezabatuPantaila();
	iprintf("\x1b[16;5HJokoa bukatu egin da.");
}

void iniziatu(){
	IME = 1;
	konfiguratuTeklatua(0x00004005);
	konfiguratuTenporizadorea(30583, 0x00000041);
	TekEtenBaimendu();
	DenbEtenBaimendu();
	etenZerbErrutEzarri();
}
