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
void EXTI_SWICU();
static u16 PeriodTicks=0;
static u16 ONTicks=0;
s32 S32Map (s32 S32_X1,s32 S32_X2,s32 S32_Y2,s32 S32_Y1,s32 S32_X)
{
	return (S32_Y1+((S32_X-S32_X1)*(S32_Y2-S32_Y1)/(S32_X2-S32_X1)));
}
u8 ADC_reading;
void main()
{
		u8 Local_u8OCR0Value=64;
		PORT_VoidInit();
		CLCD_VoidInit();


		/*initialize timer1*/
			TIMER1_VoidInit(0);

		/*set the callback function*/
		EXTI_u8Int0SetCallBack(&EXTI_SWICU);

		/*enable external interrupt*/
		EXTI_u8SetControlSense(EXTI_RISING,EXTI_INT0);


		EXTI_u8InterruptEnable(EXTI_INT0);
		/*start PWM with OCR value*/
				TIMER0_VoidInitAsync(Local_u8OCR0Value);
		GIE_VoidEnable();
		while(1)
		{
			CLCD_VoidGoToXY(0,0);
			CLCD_VoidShowNum(PeriodTicks);
			CLCD_VoidSendString("//");
			CLCD_VoidShowNum(ONTicks);
		}

}
void EXTI_SWICU()
{
	static u8 Local_u8Counter=0;
	Local_u8Counter++;
	if(Local_u8Counter==1)
	{
		/*reset timer ticks*/
		TIMER1_VoidSetTimerValue(0);

	}
	else if(Local_u8Counter==2)
	{


		/*get period ticks*/
		PeriodTicks=TIMER1_u16ReadTimerValue();

		/*change the control sense to falling*/
		EXTI_u8SetControlSense(EXTI_FALLING,EXTI_INT0);


	}
	else if(Local_u8Counter==3)
	{
		/*calculate on ticks*/
		ONTicks=TIMER1_u16ReadTimerValue();
		ONTicks-=PeriodTicks;
		/*Shut down the interrupt*/
		EXTI_u8InterruptDisable(EXTI_INT0);

		/*Reset the Local counter for future calculation of period and on time ticks*/
	//	Local_u8Counter=0;

	}
}
