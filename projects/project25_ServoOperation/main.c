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
#include "ADC_interface.h"
/*move the servo with potentiometer*/
void ADC_vNotification();
s32 S32Map (s32 S32_X1,s32 S32_X2,s32 S32_Y2,s32 S32_Y1,s32 S32_X)
{
	return (S32_Y1+((S32_X-S32_X1)*(S32_Y2-S32_Y1)/(S32_X2-S32_X1)));
}
u8 ADC_reading;
void main()
{
		PORT_VoidInit();
		GIE_VoidEnable();
		ADC_VoidInit();
		TIMER1_VoidInit(3750);

		while(1)
		{

			ADC_u8GetChannelReadingAsync(0,&ADC_reading,&ADC_vNotification);
			/*for(u16 i=94;i<=469;i++)
			{
				TIMER1_VoidSetOCRValue(i);
				_delay_ms(30);
			}*/
		}

}
void ADC_vNotification()
{
	s32 map=S32Map (0,255,469,94,ADC_reading);
	TIMER1_VoidSetOCRValue(map);
}
