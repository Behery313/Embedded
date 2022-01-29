/*
 * main.c
 *
 *  Created on: 27 Jan 2022
 *      Author: Yusuf
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include <util/delay.h>
void main()
{
		PORT_VoidInit();
		while(1)
			{
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
			_delay_us(1);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,0);
			_delay_us(1);
			}
}
