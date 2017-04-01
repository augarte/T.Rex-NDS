/*-------------------------------------
definizioak.h
-------------------------------------*/

#include <nds.h>		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia

#define IME		(*(vuint32*)0x04000208) //Interrupt Master Enable -- Eten guztiak baimendu-galarazi
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable -- Etenak banaka baimendu-galarazi
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag -- Eten eskaeren erregistroa

// Etenen tratamendurako funtzioak
#define EtenakBaimendu() IME=1 //Eten guztiak baimendu
#define EtenakGalarazi() IME=0 //Eten guztiak galarazi

//teklatuaren erregistroak
#define TEKLAK_DAT	(*(vu16*)0x4000130) //teklatuaren datu erregistroa
#define TEKLAK_KNT	(*(vu16*)0x4000132) //teklatuaren kontrol erregistroa

//denboragailuaren (Timer0) erregistroak
#define DENB0_KNT   (*(vuint16*)0x04000102) //kontrol erregistroa
#define DENB0_DAT    (*(vuint16*)0x04000100) //datu-erregistroa



//ukimen-pantailaren erregistroak
touchPosition PANT_DAT;

// Teklei izena eman diegu zenbakiak nahasgarriak izan daitezkeelako

#define A				0 
#define B				1
#define SELECT			2 
#define START			3
#define ESKUBI			4 
#define EZKER			5
#define GORA			6 
#define BEHERA			7
#define R				8 
#define L				9

extern int EGOERA;
