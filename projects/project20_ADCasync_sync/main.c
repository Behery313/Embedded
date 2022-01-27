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
#include"GIE_interface.h"

void ADC_vNotification();
u16 ADC_reading;
void main()
{
	PORT_VoidInit();
	ADC_VoidInit();
	CLCD_VoidInit();
	GIE_VoidEnable();
	while(1)
	{
		ADC_u8GetChannelReadingSync(0,&ADC_reading);
		CLCD_VoidShowNum(ADC_reading);
		_delay_ms(100);
		CLCD_VoidReset_Display();
		_delay_ms(100);
		//DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
	}

}
void ADC_vNotification()
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
	CLCD_VoidShowNum(ADC_reading);
}
