/*
 * main.c
 *
 *  Created on: 26 Jan 2022
 *      Author: Yusuf
 */


/*
 * main.c
 *
 *  Created on: 17 Jan 2022
 *      Author: Yusuf
 */

#include"STD_TYPES.h"
#include"DIO_interface.h"
#include "ADC_interface.h"
#include"PORT_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>

s32 S32Map (s32 S32_X1,s32 S32_X2,s32 S32_Y2,s32 S32_Y1,s32 S32_X)
{
	return (S32_Y1+((S32_X-S32_X1)*(S32_Y2-S32_Y1)/(S32_X2-S32_X1)));
}
void main ()
{
	PORT_VoidInit();
	ADC_VoidInit();
	CLCD_VoidInit();
CLCD_VoidShowNum(S32Map(0,255,8,1,100));
	u16 LDR_OUT;
	/*while(1)
	{

		LDR_OUT=ADC_u16GetChannelReading(0);
		if(LDR_OUT>200)
		{
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
		}
		else if(LDR_OUT>160)
		{
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_1,1);
		}
		else if(LDR_OUT>120)
		{
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_1,1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_2,1);
		}
		else if(LDR_OUT>80)
		{
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_1,1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_2,1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_3,1);
		}
		else if(LDR_OUT>40)
		{
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_1,1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_2,1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_3,1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_4,1);
		}
		CLCD_VoidShowNum(ADC_u16GetChannelReading(0));
		_delay_ms(500);
		CLCD_VoidReset_Display();
		DIO_u8SetPortValue(DIO_u8PORTB,0);
		_delay_ms(500);
	}*/

}
