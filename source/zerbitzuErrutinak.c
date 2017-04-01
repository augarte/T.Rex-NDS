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
	if (SakatutakoTekla()==A){
		EGOERA=1;
		ErlojuaMartxanJarri();
		iprintf("\x1b[13;5HPasa diren segunduak=0");
		erakutsiAteaIrekita();
		ErakutsiErronboa(1, 5, 5);
		ErakutsiErronboHandia(2, 100, 100);
	}
}

void tenpEten(){
	static int tik=0;
	static int seg=0;

	if (EGOERA==1){
		tik++;
		if (tik==5)
		{
			seg ++;
			iprintf("\x1b[13;5HPasa diren segunduak=%d", seg);
			tik=0;
			/*if (seg==3){
				erakutsiAtea();
				seg=0;
				EGOERA=0;
				EzabatuErronboa(1, 5, 5);
				EzabatuErronboHandia(2, 100, 100);
			}*/		
		}
	}
}

void etenZerbErrutEzarri(){
	irqSet(IRQ_KEYS, tekEten);
	irqSet(IRQ_TIMER0, tenpEten);
}

