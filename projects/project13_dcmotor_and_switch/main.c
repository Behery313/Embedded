/*
 * main.c
 *
 *  Created on: 17 Jan 2022
 *      Author: Yusuf
 */

#include"STD_TYPES.h"
#include"DIO_interface.h"

#include"PORT_interface.h"
#include<util/delay.h>
void main()
{
	PORT_VoidInit();
	while(1)
	{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,0);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_2,1);
	_delay_ms(5000);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_2,0);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
	_delay_ms(5000);
	}

}
