/*
 * main.c
 *
 *  Created on: 27 Jan 2022
 *      Author: Yusuf
 */

#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include <util/delay.h>
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "CLCD_interface.h"
/*move the servo with potentiometer*/
void HW_ICU();
static u16 PeriodTicks=0;
static u16 ONTicks=0;
s32 S32Map (s32 S32_X1,s32 S32_X2,s32 S32_Y2,s32 S32_Y1,s32 S32_X)
{
	return (S32_Y1+((S32_X-S32_X1)*(S32_Y2-S32_Y1)/(S32_X2-S32_X1)));
}
void main()
{
		u8 Local_u8OCR0Value=64;
		PORT_VoidInit();
		CLCD_VoidInit();

		/*set ICU callback function*/
		TIMER1ICU_u8SetCallBack(&HW_ICU);
		/*initialize ICU*/
		Timer1ICU_VoidICUInit(ICU_Rising);
		/*initialize timer1*/
		TIMER1_VoidInit(0);

		/*start PWM with OCR value*/
		TIMER0_VoidInitAsync(Local_u8OCR0Value);
		GIE_VoidEnable();
		while(1)
		{
			//while(PeriodTicks==0&&ONTicks==0);

			CLCD_VoidGoToXY(0,0);
			CLCD_VoidShowNum(PeriodTicks);
			CLCD_VoidSendString("//");
			CLCD_VoidShowNum(ONTicks);
		}

}
void HW_ICU()
{
	static u8 Local_u8Counter=0;
	static u16 ISRValue1;
	static u16 ISRValue2;
	static u16 ISRValue3;
	Local_u8Counter++;
	if(Local_u8Counter==1)
	{
		/*read value from ICU*/
		ISRValue1=TIMER1ICU_u16GetICRValue();
	}
	else if(Local_u8Counter==2)
	{
		/*read value from ICU*/
		ISRValue2=TIMER1ICU_u16GetICRValue();

		/*get period ticks*/
		PeriodTicks=ISRValue2-ISRValue1;

		/*change the control sense to falling*/
		Timer1ICU_VoidSetEdge(ICU_Falling);

	}
	else if(Local_u8Counter==3)
	{
		/*read value from ICU*/
		ISRValue3=TIMER1ICU_u16GetICRValue();

		/*calculate on ticks*/
		ONTicks=ISRValue3-ISRValue2;

		/*Shut down the interrupt*/
		Timer1ICU_VoidDisableInterrupt();

		/*Reset the Local counter for future calculation of period and on time ticks*/
	//	Local_u8Counter=0;

	}
}
