/*
 * main.c
 *
 *  Created on: 17 Jan 2022
 *      Author: Yusuf
 */

#include"STD_TYPES.h"
#include"DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include"PORT_interface.h"

#include <util/delay.h>
void main()
{
	PORT_VoidInit();
	GIE_VoidEnable();
	EXTI_voidInt2Init();
	while(1)
	{
		_delay_ms(2000);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,0);
	}
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
}
