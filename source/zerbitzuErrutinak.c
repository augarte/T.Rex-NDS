/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"

int EGOERA;

void tekEten (){
	if(EGOERA==1){
		if (SakatutakoTekla()==A){
			EGOERA=2;
			//ErakutsiTrex(1,5,5);
			ErakutsiKarratua(1,5,100);
		}
	}
}

void tenpEten(){
	static int tik=0;
	static int seg=0;

	if (EGOERA==1){
		tik++;
		if (tik==5){
			seg ++;
			iprintf("\x1b[13;5HPasa diren segunduak=%d", seg);
			tik=0;
		}
	}
}

void etenZerbErrutEzarri(){
	irqSet(IRQ_KEYS, tekEten);
	irqSet(IRQ_TIMER0, tenpEten);
}

