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
u32 Counts_CTC=255*10;
u32 Counts_Normal=184*10;
u8 compregister=184;
u8 preload=229;
void main()
{
		PORT_VoidInit();
		//GIE_VoidEnable();//verified Async function
		//TIMER0_VoidInitSync();
		TIMER0_u8SetCallBack(TIMER_NOTIF);
//TIMER0_VoidInitAsync(compregister);// used to verify CTC
	//	TIMER0_VoidInitAsync(preload);//used to verify Normal mode
		TIMER0_VoidInitSync();
		while(1)
			{
			static u8 LED=0;
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,TOG_BIT(LED,0));
		//		TIMER0_u8WaitSync(preload,Counts_Normal);//verified Normal mode
			TIMER0_u8WaitSync(compregister,Counts_CTC);
			}
}
void TIMER_NOTIF()
{
	static u8 LED=0;
	static u32 counter=0;
			counter++;
			/*if(counter==Counts_CTC)
			{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,TOG_BIT(LED,0));
	counter=0;
			}*/
			if(counter==Counts_Normal)
						{
				TIMER0_SetPreload(preload);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,TOG_BIT(LED,0));
				counter=0;
						}
}
