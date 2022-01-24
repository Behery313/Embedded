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
#include"STEPPER_interface.h"
void main()
{
	PORT_VoidInit();
	//STEPPER_VoidRotate(STEPPER_CW,45);
while(1)
{ DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_7,DIO_u8LOW);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_6,DIO_u8HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_5,DIO_u8HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_4,DIO_u8HIGH);
	_delay_ms(100);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_7,DIO_u8HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_6,DIO_u8LOW);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_5,DIO_u8HIGH);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_4,DIO_u8HIGH);
		_delay_ms(100);
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_7,DIO_u8HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_6,DIO_u8HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_5,DIO_u8LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_4,DIO_u8HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_7,DIO_u8HIGH);
				DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_6,DIO_u8HIGH);
				DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_5,DIO_u8HIGH);
				DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_4,DIO_u8LOW);
				_delay_ms(100);
			//	_delay_ms(1000);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,0);
				_delay_ms(100);
}
}
