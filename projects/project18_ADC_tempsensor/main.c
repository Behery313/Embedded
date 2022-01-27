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
#include "TmpSensor_interface.h"

void main ()
{
	PORT_VoidInit();
	ADC_VoidInit();
	CLCD_VoidInit();
	u16 Digital;
	u16 MilliVolt;
	u8 Temp;
	while(1)
	{
		Digital=ADC_u16GetChannelReading(0);
		MilliVolt=(u16)(((u32)Digital*5000UL)/256UL);
		//TEMP_u16GetReading();
		CLCD_VoidShowNum(MilliVolt/10);

		_delay_ms(500);
		CLCD_VoidReset_Display();
	}

}
