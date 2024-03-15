/*
 * main.c
 *
 *  Created on: Mar 9, 2024
 *      Author: Mohammed Nagah Amr
 */

/******LIBs******/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******MCAL******/
#include "MRCC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
#include "GPTIM_interface.h"

/******HAL******/
#include "TFT_Interface.h"
#include "DAC_interface.h"
#include "STP_interface.h"

/*****IMGs******/
#include "satalna.h"
#include "koloby3dy.h"
#include "white.h"

/*****SONGs*****/
#include "satalana.h"
#include "koloby3ady.h"

/********Welcome Message******/
#include "STP_LED_MATRIX.h"

/*****IR Variables*****/
volatile u8   Local_u8StartFlag       = 0;
volatile u32  Local_u32FrameData[50]  = {0};
volatile u8   Local_u8EdgeCounter     = 0;
volatile u8   Localu8Data            = 0;

/****FLAGs****/
u8 Update_u8Flag=0;// To break the loop of DAC and STP with LED_MATRIX
u8 Global_u8Flag=0;// For while(1) in the main

void STP_LEDMAT_PLAY(u8 * Flag)
{
	if(*Flag == 1)
	{
		print_welcome();
	}
}

void STP_LEDMAT_OPTION1(u8 * Flag)
{
	while(1)
	{
		if(*Flag == 1)
		{
			S2P_vSendData(0xFEF8);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xFD24);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xFB22);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xF722);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xEF24);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xDFF8);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xBF00);
			TIM3_voidSetBusyWait(20000);
		}
		else
		{
			break;
		}
	}
}

void STP_LEDMAT_OPTION2(u8 * Flag)
{
	while(1)
	{
		if(*Flag == 1)
		{
			S2P_vSendData(0xFEFE);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xFD92);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xFB92);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xF792);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xEF7C);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xDF00);
			TIM3_voidSetBusyWait(20000);
			S2P_vSendData(0xBF00);
			TIM3_voidSetBusyWait(20000);
		}
		else
		{
			break;
		}
	}
}


void voidPlay(void)
{
	switch (Localu8Data)
	{
	case 3:
		Global_u8Flag = 1;
		break;
	case 15:
		Global_u8Flag = 2;
		break ;
	case 19:
		Global_u8Flag = 3;
		break ;
	case 17:
		Global_u8Flag = 4;
		break ;
	}
}

void voidTakeAction(void)
{
	u8 i;
	Localu8Data = 0;

	if ( (Local_u32FrameData[0] >= 10000) && (Local_u32FrameData[0] <= 15000) )
	{
		for (i=0;i<8;i++)
		{
			if (  (Local_u32FrameData[17+i] >= 2000) && (Local_u32FrameData[17+i] <=2300) )
			{
				SET_BIT(Localu8Data,i);
			}

			else
			{
				CLR_BIT(Localu8Data,i);
			}
		}

		voidPlay();
	}

	else
	{
		/*	 Invalid Frame */
	}

	Local_u8StartFlag     = 0;
	Local_u32FrameData[0] = 0;
	Local_u8EdgeCounter   = 0;
}

void voidGetFrame(void)
{
	Update_u8Flag=0;
	if (Local_u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetInterval_single(100000,voidTakeAction);
		Local_u8StartFlag = 1;
	}

	else
	{
		Local_u32FrameData[Local_u8EdgeCounter] = ( MSTK_u32GetElapsedTime() / 2 );
		MSTK_voidSetInterval_single(100000,voidTakeAction);
		Local_u8EdgeCounter++;
	}
	if(Local_u8EdgeCounter == 50)
	{
		asm("NOP");
	}

}


void main(void)
{
	/****RCC Initialize****/
	MRCC_vInt();
	MRCC_vEnable(RCC_AHB1,AHB1_GPIOA);
	MRCC_vEnable(RCC_AHB1,AHB1_GPIOB);
	MRCC_vEnable(RCC_APB2, APB2_SYSCFG);
	MRCC_vEnable(RCC_APB1,APB1_TIM2);
	MRCC_vEnable(RCC_APB1,APB1_TIM3);
	MRCC_vEnable(RCC_APB1,APB1_TIM4);
	MRCC_vEnable(RCC_APB2,APB2_SPI1);

	/****I/O Pins Initialization****/
	MGPIO_vSetMode(PORT_A,PIN_1,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_A,PIN_2,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_A,PIN_3,MODE_OUTPUT);
	MGPIO_vSetOutputMode(PORT_A,PIN_1,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_A,PIN_2,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_A,PIN_3,OUTPUT_PUSHPULL,SPEED_LOW);

	/****IR Input PIN******/
	MGPIO_vSetMode(PORT_A,0,MODE_INPUT);
	MGPIO_vSetInputMode(PORT_A,0,INPUT_PULLUP);


	/****TFT A0&RST PINS****/
	MGPIO_vSetMode(PORT_B,PIN_0,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_1,MODE_OUTPUT);
	MGPIO_vSetOutputMode(PORT_B,PIN_0,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_B,PIN_1,OUTPUT_PUSHPULL,SPEED_LOW);

	/*****TFT SPI PINS******/
	MGPIO_vSetMode(PORT_A,PIN_4,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_5,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_6,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_7,MODE_ALTERNATIVE);
	MGPIO_vSetAlternativeMode(PORT_A,PIN_4,ALTR_SPI);
	MGPIO_vSetAlternativeMode(PORT_A,PIN_5,ALTR_SPI);
	MGPIO_vSetAlternativeMode(PORT_A,PIN_6,ALTR_SPI);
	MGPIO_vSetAlternativeMode(PORT_A,PIN_7,ALTR_SPI);

	/* EXTI Initializtion */
	MEXTI_voidInerruptSetPort(EXTI_LineZero ,EXTI_PortA);
	MEXTI0_voidCallBack(voidGetFrame);
	MEXTI_voidInterruptEnableDisable(EXTI_LineZero,EXTI_Enable) ;
	MEXTI_voidInterruptTrigger(EXTI_LineZero,EXTI_Falling) ;


	/* Enable EXTI0 from NVIC */
	NVIC_vEnable(6);

	/* SysTick Init */
	MSYSYTICK_voidInit();

	/*TIMER2 Init*/
	TIM2_voidInit();

	/*TIMER3 Init*/
	TIM3_voidInit();

	/*TIMER4 Init*/
	TIM4_voidInit();

	/*SPI Init*/
	SPI1_voidInit();

	/*TFT Init*/
	TFT_voidvInit();

	/*S2P Init*/
	S2P_vInit();

	/*DAC Init*/
	HR2RDAC_vInit();

	/* Enable Systick Interrupt */
	MSYSYTICK_voidCtrlIntState(SYSTICKEnable);

	while(1)
	{
		switch (Global_u8Flag)
		{
		case 1:
			MGPIO_vWritePin(PORT_A,PIN_1,GPIO_LOW);
			MGPIO_vWritePin(PORT_A,PIN_2,GPIO_LOW);
			MGPIO_vWritePin(PORT_A,PIN_3,GPIO_LOW);
			TFT_voidDisplay(white);
			Update_u8Flag=1;
			STP_LEDMAT_PLAY(&Update_u8Flag);
			//Global_u8Flag = 0;
			MSYSYTICK_voidCtrlIntState(SYSTICKEnable);
			break;
		case 2:
			MGPIO_vWritePin(PORT_A,PIN_1,GPIO_HIGH);
			MGPIO_vWritePin(PORT_A,PIN_2,GPIO_LOW);
			MGPIO_vWritePin(PORT_A,PIN_3,GPIO_LOW);
			TFT_voidDisplay(satalna);
			Update_u8Flag=1;
			STP_LEDMAT_OPTION1(&Update_u8Flag);
			HR2RDAC_vSetData(satalana_raw,39780,&Update_u8Flag);
			//Global_u8Flag = 0;
			MSYSYTICK_voidCtrlIntState(SYSTICKEnable);
			break ;
		case 3:
			MGPIO_vWritePin(PORT_A,PIN_1,GPIO_LOW);
			MGPIO_vWritePin(PORT_A,PIN_2,GPIO_HIGH);
			MGPIO_vWritePin(PORT_A,PIN_3,GPIO_LOW);
			TFT_voidDisplay(koloby3dy);
			Update_u8Flag=1;
			STP_LEDMAT_OPTION2(&Update_u8Flag);
			HR2RDAC_vSetData(koloby3ady_raw,54706,&Update_u8Flag);
			//Global_u8Flag = 0;
			MSYSYTICK_voidCtrlIntState(SYSTICKEnable);
			break ;
		case 4:
			MGPIO_vWritePin(PORT_A,PIN_1,GPIO_LOW);
			MGPIO_vWritePin(PORT_A,PIN_2,GPIO_LOW);
			MGPIO_vWritePin(PORT_A,PIN_3,GPIO_HIGH);
			TFT_voidDisplay(koloby3dy);
			Update_u8Flag=1;
			STP_LEDMAT_OPTION2(&Update_u8Flag);
			HR2RDAC_vSetData(koloby3ady_raw,54706,&Update_u8Flag);
			//Global_u8Flag = 0;
			MSYSYTICK_voidCtrlIntState(SYSTICKEnable);
			break ;
		default:
			asm("NOP");
			break;
		}
	}

}
