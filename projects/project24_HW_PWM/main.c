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

void main()
{
		PORT_VoidInit();
		/*for duty cycle 25% use OC register value=64*/

		while(1)
		{
			TIMER0_VoidInitAsync(0);
			_delay_ms(1000);
			TIMER0_VoidInitAsync(255);
			_delay_ms(1000);
		}
		/*while(1)
		{
			for(u8 i=0;i<255;i++)
			{
				TIMER0_VoidInitAsync(i);// used to verify FAST PWM
				_delay_ms(10);
			}
			DIO_u8SetPinValue(DIO_u8PORTB,0,1);
			for(u8 i=0;i<255;i++)
			{
				TIMER0_VoidInitAsync(255-i);// used to verify FAST PWM
				_delay_ms(10);
			}
		}*/
}
