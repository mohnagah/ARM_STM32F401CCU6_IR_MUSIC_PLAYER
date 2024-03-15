/*
 * STP_LED_MATRIX.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Mohammed Nagah Amr
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "GPTIM_interface.h"
#include "STP_interface.h"
#include "SYSTICK_interface.h"


void print_welcome(void)
{
	//(00, 41, 41, 49, 49, 49, 7F, 00)
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD41);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB41);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF749);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF49);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF49);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF7F);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);
	/////////////////////////////////////////////////////////////////
	//(00, A0, A0, A4, A4, A4, BF, 00)
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDA0);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFBA0);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF7A4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEFA4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDFA4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFBF);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////////
	//(00, D0, 50, 52, D2, 52, DF, 00)
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDD0);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB50);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF752);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEFD2);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF52);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFDF);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	//////////////////////////////////////////////
	//(00, E8, 28, 29, E9, 29, EF, 00)
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDE8);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB28);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF729);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEFE9);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF29);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFEF);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	/////////////////////////////////////////////
	//(00, 74, 14, 14, 74, 14, 77, 00)
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD74);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB14);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF714);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF74);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF14);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF77);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	//(00, BA, 8A, 8A, BA, 8A, BB, 00)
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDBA);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB8A);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF78A);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEFBA);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF8A);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFBB);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	//(00, 5D, 45, 45, 5D, 45, DD, 00)
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD5D);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB45);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF745);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF5D);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF45);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFDD);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);


	////////////////////////////////////////////
	//(00, 2E, 22, 22, 2E, 22, EE, 00)
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD2E);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB22);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF722);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF2E);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF22);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFEE);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);


	////////////////////////////////////////////
	//(00, 17, 11, 11, 17, 11, 77, 00)
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD17);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF711);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF17);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF77);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	//(00, 0B, 88, 88, 8B, 88, 3B, 00)
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD0B);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB88);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF788);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF88);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF8B);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF88);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F3B);
	MSYSYTICK_voidDelayUs(150000);




	/////////////////////////////////////////////////////////////////

	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD3C);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB02);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF701);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF01);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF02);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF3C);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD1E);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB01);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF780);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF80);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF01);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF1E);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	//////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD0F);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB80);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF720);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF20);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF80);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF0F);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	/////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD87);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB20);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF720);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF20);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF20);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF87);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDC3);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB20);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF710);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF10);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF20);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFC3);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDE1);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB10);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF708);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF08);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF10);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFE1);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);


	////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDF0);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB08);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF704);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF04);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF08);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFF0);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD78);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB04);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF702);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF02);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF04);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF78);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	///////////O  /////////////////////////////////

	/////////////////////////////////////////////////////////////////

	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD0E);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF711);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF0E);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD07);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB88);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF788);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF88);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF88);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF07);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	//////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD83);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x44);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF744);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF44);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF44);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF83);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	/////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDC1);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB22);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF722);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF22);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF22);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFC1);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDE0);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF711);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFE0);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD70);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB88);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF788);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x88);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF88);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF70);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);


	////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD38);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB44);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF744);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF44);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF44);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF38);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD1C);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB22);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF722);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF22);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF22);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF1C);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);
	S2P_vSendData(0xFE00);

	/////////////////////////////////////////////////////////////////

	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD0E);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF711);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF11);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF0E);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);
	//////////////////////////////// M //////////////////////////////////
	S2P_vSendData(0xFE02);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFE);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB92);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF792);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF92);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF92);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF92);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);
	/////////////////////////////////////////////////////////////////

	S2P_vSendData(0xFE01);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFD7F);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB49);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF749);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF49);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF49);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF49);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////////
	S2P_vSendData(0xFE80);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDBF);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFBA4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF7A4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEFA4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDFA4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFA4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	//////////////////////////////////////////////
	S2P_vSendData(0xFE20);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDDF);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB52);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF752);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF52);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF52);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF52);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	/////////////////////////////////////////////
	S2P_vSendData(0xFE20);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDEF);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB29);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF729);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF29);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF29);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF29);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	S2P_vSendData(0xFE10);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDF7);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB94);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF794);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF94);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF94);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF94);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	S2P_vSendData(0xFE08);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDFB);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB4A);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF74A);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF4A);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF4A);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF4A);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	S2P_vSendData(0xFE04);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDFD);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB25);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF725);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF25);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF25);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF25);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);

	////////////////////////////////////////////
	S2P_vSendData(0xFE02);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDFE);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFB92);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF792);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF92);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF92);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF92);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(150000);
	MSYSYTICK_voidCtrlIntState(SYSTICKEnable);

}
