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
			ErakutsiTrex(1,12,150);
		}
	}
}

void tenpEten(){
	static int salto=0;
	static int tik=0;
	static int seg=0;

	if(EGOERA==1 || EGOERA==2){
		if(EGOERA==2){
			salto++;
			if(salto==10){
				EGOERA=1;
				salto=0;
				ErakutsiTrex(1,12,120);
			}
		}
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