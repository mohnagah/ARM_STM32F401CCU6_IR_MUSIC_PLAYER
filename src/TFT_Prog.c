/*
 * TFT_Prog.c
 *
 *  Created on: Jun 8, 2023
 *      Author:  Mohammed Nagah Amr
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"

#include"GPIO_interface.h"
#include"SPI_interface.h"
#include"SYSTICK_interface.h"

#include"TFT_Private.h"
#include"TFT_Config.h"
#include"TFT_Interface.h"



static void  TFT_voidWriteCmnd(u8 	Copy_u8Command)
{
	// Pull TFT_A0 To ground
	MGPIO_vWritePin(PORT_B,PIN_0,GPIO_LOW);

	//Send Value of Command
	(void) SPI1_u16Transceive(Copy_u8Command);
}
static void  TFT_voidWriteData(u8 	Copy_u8Data)
{
	// Pull TFT_A0 To vcc
	MGPIO_vWritePin(PORT_B,PIN_0,GPIO_HIGH);
	//Send Value of Data
	(void) SPI1_u16Transceive(Copy_u8Data);
}

void TFT_voidvInit(void)
{


	/**Reset Pulse **/
	MGPIO_vWritePin(PORT_B,PIN_1,GPIO_HIGH);
	//200 Tick -> 100 Us
	MSYSYTICK_voidDelayUs(100);

	MGPIO_vWritePin(PORT_B,PIN_1,GPIO_LOW);
	//2 Tick -> 1 Us
	MSYSYTICK_voidDelayUs(1);

	MGPIO_vWritePin(PORT_B,PIN_1,GPIO_HIGH);
	//200 Tick -> 100 Us
	MSYSYTICK_voidDelayUs(100);

	MGPIO_vWritePin(PORT_B,PIN_1,GPIO_LOW);

	//200 Tick -> 100 Us
	MSYSYTICK_voidDelayUs(100);

	MGPIO_vWritePin(PORT_B,PIN_1,GPIO_HIGH);

	//240000 Tick -> 120 Ms
	MSYSYTICK_voidDelayUs(120000);


	/**Send sleep out command ID =0x11**/
	TFT_voidWriteCmnd(0x11);
	/***delay 150 ms***/
	MSYSYTICK_voidDelayUs(150000);
	/*Choose Color Coding Std. => RGB656 ID=0x3A , Paramater => 0x05*/
	TFT_voidWriteCmnd(0x3A); // Command ID
	TFT_voidWriteData(0x05); // Command Data // RGB565



	/*Display ON Cmnd => ID=0x29*/
	TFT_voidWriteCmnd(0X29);


}


void TFT_voidDisplay(const u16  * Copy_ptrImage)
{
	u16 Local_u16Counter;

	/*Set X address */
	TFT_voidWriteCmnd(0x2A);// set x address command Id

	TFT_voidWriteData(0);// set x address command parameters [start_address]
	TFT_voidWriteData(0);//[2bytes][00 00]

	TFT_voidWriteData(0);// set x address command parameters [end_address]
	TFT_voidWriteData(127);	// [2bytes][00 127]


	/*Set Y address */
	TFT_voidWriteCmnd(0x2B);// set y address command Id

	TFT_voidWriteData(0);
	TFT_voidWriteData(0);

	TFT_voidWriteData(0);
	TFT_voidWriteData(159);


	//RAM Write Command
	TFT_voidWriteCmnd(0x2C);


	//Display
for(Local_u16Counter=0;Local_u16Counter<TFT_Arr_Size;Local_u16Counter++)
{
	//[11001101 - 11011011]
    // 1- send MSByte// 11001101 >> 8
	TFT_voidWriteData(~(Copy_ptrImage[Local_u16Counter]>>8));
	// 2- send LSByte
	TFT_voidWriteData(~(Copy_ptrImage[Local_u16Counter]&0x00FF));

}

}

void TFT_voidDisplay_Proutus(const u16  * Copy_ptrImage)
{
	u16 Local_u16Counter;

	/*Set X address */
	TFT_voidWriteCmnd(0x2A);// set x address command Id

	TFT_voidWriteData(0);// set x address command parameters [start_address]
	TFT_voidWriteData(0);//[2bytes][00 00]

	TFT_voidWriteData(0);// set x address command parameters [end_address]
	TFT_voidWriteData(127);	// [2bytes][00 127]


	/*Set Y address */
	TFT_voidWriteCmnd(0x2B);// set y address command Id

	TFT_voidWriteData(0);
	TFT_voidWriteData(0);

	TFT_voidWriteData(0);
	TFT_voidWriteData(159);


	//RAM Write Command
	TFT_voidWriteCmnd(0x2C);


	//Display
for(Local_u16Counter=0;Local_u16Counter<TFT_Arr_Size;Local_u16Counter++)
{
	//[11001101 - 11011011]
    // 1- send MSByte// 11001101 >> 8
	TFT_voidWriteData(Copy_ptrImage[Local_u16Counter]>>8);
	// 2- send LSByte
	TFT_voidWriteData(Copy_ptrImage[Local_u16Counter]&0x00FF);

}

}



