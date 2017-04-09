#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena

void ezabatuLerroBat(int lerroa){
	iprintf("\x1b[%d;0H                                ", lerroa);
}

void ezabatuPantaila(){
	int i;
	for(i = 0; i<24; i++){
		ezabatuLerroBat(i);
	}
}

void ezabatuSpriteak(){
	EzabatuTxoriGoi(3,0,0);
	EzabatuTxoriBehe(3,0,0);
	EzabatuCactus(2,0,0);
	EzabatuTrex(1,0,0);
}

void eguneratuPosizioak(){
	txoriPos = 384;
	cactusPos = 256;
}