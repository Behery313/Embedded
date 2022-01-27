/*
 * TmpSensor_program.c
 *
 *  Created on: 26 Jan 2022
 *      Author: Yusuf
 */


#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "TmpSensor_interface.h"
#include "TmpSensor_config.h"
#include "TmpSensor_private.h"
u16 TEMP_u8GetReading(void)
{
	u16 Local_u16DigitalValue=ADC_u16GetChannelReading(TempSensor_Channel);
	return (((Local_u16DigitalValue*AREFmv)/EIGHT_BITS )/10);
}
