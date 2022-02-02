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

#include "WDTC_interface.h"

void main()
{
	PORT_VoidInit();
	DIO_u8SetPinValue(DIO_u8PORTB,0,1);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_u8PORTB,0,0);
	/*sleep for 1 sec*/
	WDT_VoidSleep(Sleep_1s);
	WDT_VoidDisable();
	while(1);
}
