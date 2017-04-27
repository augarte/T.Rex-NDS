/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <time.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"
#include "posizioak.h"
#include "funtzioLaguntzaileak.h"

int EGOERA;

void tekEten (){
	if(EGOERA==1){
		if (SakatutakoTekla()==A){
			EGOERA=2;
		}
	}
}

void tenpEten(){
	static int salto=0;
	static int points=0;
	static int txori=0;

	if(EGOERA==1 || EGOERA==2){
		if(EGOERA==2){
			if(salto<12){
				trexPos=trexPos-8;
			}
			else{
				trexPos=trexPos+8;
			}
			ErakutsiTrex(1,12,trexPos);
			salto++;
			if(salto==24){
				EGOERA=1;
				salto=0;
			}
		}

		ErakutsiCactus(2,cactusPos,120);
		pantailatikKanpo(&cactusPos, points);

		if(points>1000){
			if(txori==1){
				ErakutsiTxoriBehe(3, txoriPos, 150);
				txori=0;
			}
			else{
				ErakutsiTxoriGoi(3, txoriPos, 150);
				txori++;
			}
			pantailatikKanpo(&txoriPos, points);
		}
		
		points ++;
		iprintf("\x1b[13;5HPuntuazioa=%d", points);

		if (((txoriPos >= -20 && txoriPos <= 57) || (cactusPos >= -19 && cactusPos <= 58)) && EGOERA != 2){
			ErlojuaGelditu();
			iprintf("\x1b[16;5HGaldu egin duzu.");
			points = 0;
			txoriPos = 384;
			cactusPos = 256;
			trexPos = 120;
			ezabatuSpriteak();
			erakutsiBukaeraFondoa();
			EGOERA = 3;
		}
	}
}

void pantailatikKanpo(int *elem, int p){
	int r, par=1;
	if (*elem<-32){
		r=rand() % 41;
		*elem=256+r;
	}
	else{
		if(p<400){
			*elem=*elem-5;
		}
		else if(p>=800){
			if(par=1){
				*elem=*elem-10;
				par=0;
			}
			else{
				*elem=*elem-15;
				par=1;
			}
		}
		else{
			*elem=*elem-(5*p/400);
		}
	}
}

void etenZerbErrutEzarri(){
	irqSet(IRQ_KEYS, tekEten);
	irqSet(IRQ_TIMER0, tenpEten);
}