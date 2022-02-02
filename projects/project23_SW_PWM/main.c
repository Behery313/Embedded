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
void TIMER_NOTIF();
u32 Counts_CTC=5;
u32 Counts_Normal=184*10;
u8 compregister=188;
u8 preload=229;
void main()
{
		PORT_VoidInit();
		GIE_VoidEnable();//verified Async function
		//TIMER0_VoidInitSync();
		TIMER0_u8SetCallBack(TIMER_NOTIF);
TIMER0_VoidInitAsync(compregister);// used to verify CTC
	//	TIMER0_VoidInitAsync(preload);//used to verify Normal mode
		//TIMER0_VoidInitSync();
		while(1)
			{

			}
}
void TIMER_NOTIF()
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_3,1);
	static u32 counter=0;
			counter++;
			if(counter==5)
			{
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,0);
			}
			else if(counter==10)
			{
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_1,0);
			}
			else if(counter==15)
			{
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_2,0);
			}
			else if(counter==20)
			{
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_1,1);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_2,1);
				counter=0;
			}
}
