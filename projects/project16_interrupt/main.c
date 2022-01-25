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
//ISR Prototypes
void ISR_voidInt0(void);
void ISR_voidInt1(void);
void ISR_voidInt2(void);
void main()
{
	PORT_VoidInit();
	GIE_VoidEnable();
	//EXTI_voidInt0Init();
	//EXTI_voidInt1Init();
	//EXTI_voidInt2Init();
	EXTI_u8InterruptEnable(EXTI_INT0);
	EXTI_u8InterruptEnable(EXTI_INT1);
	EXTI_u8InterruptEnable(EXTI_INT2);
	EXTI_u8SetControlSense(EXTI_FALLING,EXTI_INT0);
	EXTI_u8SetControlSense(EXTI_FALLING,EXTI_INT1);
	EXTI_u8SetControlSense(EXTI_FALLING,EXTI_INT2);
	EXTI_u8Int0SetCallBack(&ISR_voidInt0);//"&" for misra rules
	EXTI_u8Int1SetCallBack(&ISR_voidInt1);//"&" for misra rules
	EXTI_u8Int2SetCallBack(&ISR_voidInt2);//"&" for misra rules

	while(1)
	{
		//_delay_ms(2000);
		//DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,0);
	}
}
void ISR_voidInt0(void)
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
}
void ISR_voidInt1(void)
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_1,1);
}
void ISR_voidInt2(void)
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_3,1);
}
