/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	TIMER			**********************/
/**************		Version:1.00			**********************/
/**************		Date:2/2/2022			**********************/
/*****************************************************************/
/*****************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDTC_interface.h"
#include "WDT_register.h"


void WDT_VoidSleep(u8 Copy_u8SleepTime)
{
	/*set WDE bit*/
	SET_BIT(WDTCR,WDTCR_WDE);
	/*CLEAR Sleep time selection bits*/
	WDTCR&=0b11111000;
	/*Set the required interval*/
	WDTCR|=Copy_u8SleepTime;
}
void WDT_VoidDisable()
{
	/*Set WDE and WDTOE in the same operation*/
	WDTCR=0b00011000;

	/*Clear WDE in 4 clock cycles */
	WDTCR=0;
}
