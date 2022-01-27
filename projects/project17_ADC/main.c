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

void main()
{
	PORT_VoidInit();
	ADC_VoidInit();
	CLCD_VoidInit();
	u16 test;
	while(1)
	{
		test=ADC_u16GetChannelReading(0);
		CLCD_VoidShowNum(test);
		_delay_ms(500);
		CLCD_VoidReset_Display();
	}
}
