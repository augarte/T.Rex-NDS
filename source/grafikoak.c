/*---------------------------------------------------------------------------------
Hemen bideo sistemaren definizioa baino ez dugu egiten, beste EZER EZ DA IKUTU BEHAR

Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia
#include "grafikoak.h"
#include "spriteak.h"


void hasieratuBideoa() {
    /*  Bi pantailatan irudiak erakutsi ahal izateko memoria mapeatu. */

    vramSetMainBanks(VRAM_A_MAIN_BG_0x06000000,
                     VRAM_B_MAIN_BG_0x06020000,
                     VRAM_C_SUB_BG_0x06200000,
                     VRAM_E_LCD);

    vramSetBankE(VRAM_E_MAIN_SPRITE);
    vramSetBankD(VRAM_D_SUB_SPRITE);

    /*  Pantaila nagusirako bideo modua ezarri */
    videoSetMode(MODE_5_2D | // 5. bideo modua ezarri
                 DISPLAY_BG2_ACTIVE | // 2. fondoa aktibatu
                 DISPLAY_BG3_ACTIVE); // 3. fondoa aktibatu

    /*  2. mailako pantaila bideo modua ezarri */
    videoSetModeSub(MODE_5_2D | // 5. bideo modua ezarri
                    DISPLAY_BG3_ACTIVE); // 3. fondoa aktibatu
}


/* ---- ZATI HAU EZ DA ALDATU BEHAR ---- */
/* ----  FONDOEN KONFIGURAZIOA DA   ---- */
/* ----     HEMENDIK HASITA         ---- */

/* Fondo sistema konfiguratzeko prozedura */
void hasieratuFondoak() {
    /*  Pantaila nagusiko 3 fondoaren afinitatea ezarri 16 biteko koloretarako. */
    REG_BG3CNT = BG_BMP16_256x256 |
                 BG_BMP_BASE(0) | // Memoriako hasierako helbidea
                 BG_PRIORITY(3); // Lehentasun baxua

    /*  Pantaila nagusiko 3 fondoaren transformazio matrizeari identitate matrizea esleitu. */
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

/*******************************************************************************************/
    /*  Pantaila nagusiko 3 fondoaren egoera definitu. */
    /*  Grafikoa beste posizio batean jarri nahi izanez gero hau aldatu beharko da. */
    REG_BG3X = 0;
    REG_BG3Y = 0;
/*******************************************************************************************/

    /*  Pantaila nagusiko 3 fondoaren afinitatea ezarri 16 biteko koloretarako. */
    REG_BG2CNT = BG_BMP16_128x128 |
                 BG_BMP_BASE(8) | // Memoriako hasierako helbidea
                 BG_PRIORITY(2);  // Lehentasun baxua

    /*  Pantaila nagusiko 3 fondoaren transformazio matrizeari identitate matrizea esleitu. */
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;

/*******************************************************************************************/
    /*  Pantaila nagusiko 3 fondoaren egoera definitu. */
    /*  Grafikoa beste posizio batean jarri nahi izanez gero hau aldatu beharko da. */
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;
/*******************************************************************************************/

    /*  Bigarren mailako pantailako 3 fondoaren afinitatea ezarri 16 biteko koloretarako. */
    REG_BG3CNT_SUB = BG_BMP16_256x256 |
                     BG_BMP_BASE(0) | // Memoriako hasierako helbidea
                     BG_PRIORITY(3); // Lehentasun baxua

    /*  Bigarren mailako pantailako 3 fondoaren transformazio matrizeari identitate matrizea esleitu. */
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;

/*******************************************************************************************/
    /*  Bigarren mailako pantailako 3 fondoaren egoera definitu. */
    /*  Grafikoa beste posizio batean jarri nahi izanez gero hau aldatu beharko da. */
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;
/*******************************************************************************************/
}

/* ----       HONAINO       ---- */

void GrafikoakHasieratu(){
	powerOn(POWER_ALL_2D);
    lcdMainOnBottom();
    hasieratuBideoa();
    //hasieratuFondoak();
	consoleDemoInit(); //Goiko pantaila testua erakusteko eta beheko irudiak erakusteko erabiliko da.
}


//************************************************
//Spriteak
//************************************************

/* Spritentzako memoria hasieratu.*/
void initSpriteMem() {

	oamInit(&oamMain, SpriteMapping_1D_32, false);
	oamInit(&oamSub, SpriteMapping_1D_32, false);
}



void HasieratuGrafikoakSpriteak(){
	GrafikoakHasieratu();
	hasieratuFondoak();
	initSpriteMem();
	memoriaErreserbatu();
	PaletaNagusiaEzarri();
	SpriteakMemorianGorde();
}
