/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"
#include "funtzioLaguntzaileak.h"
#include "posizioak.h"

int EGOERA;

void tekEten (){
	if(EGOERA==1){
		if (SakatutakoTekla()==A){
			EGOERA=2;
			ErakutsiTrex(1,12,40);
		}
	}
}

void tenpEten(){
	static int salto=0;
	static int points=0;
	static int txori=0;

	if(EGOERA==1 || EGOERA==2){
		if(EGOERA==2){
			salto++;
			if(salto==8){
				EGOERA=1;
				salto=0;
				ErakutsiTrex(1,12,120);
			}
		}
		if(txori==1){
			ErakutsiTxoriBehe(3, txoriPos, 150);
			txori=0;
		}
		else{
			ErakutsiTxoriGoi(3, txoriPos, 150);
			txori++;
		}
		ErakutsiCactus(2,cactusPos,120);
		pantailatikKanpo(&txoriPos);
		pantailatikKanpo(&cactusPos);
		points ++;
		iprintf("\x1b[13;5HPuntuazioa=%d", points);

		if (((txoriPos >= -20 && txoriPos <= 57) || (cactusPos >= -20 && cactusPos <= 57)) && EGOERA != 2){
			ErlojuaGelditu();
			iprintf("\x1b[16;5HGaldu egin duzu.");
			eguneratuPosizioak();
			ezabatuSpriteak();
			erakutsiBukaeraFondoa();
			EGOERA = 3;
		}
	}
}

void pantailatikKanpo(int *elem){
	if (*elem<-32){
		*elem=256;
	}
	else{
		*elem=*elem-15;
	}
}

void etenZerbErrutEzarri(){
	irqSet(IRQ_KEYS, tekEten);
	irqSet(IRQ_TIMER0, tenpEten);
}