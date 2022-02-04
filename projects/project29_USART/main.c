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
#include "USART_interface.h"


void main()
{
	PORT_VoidInit();
	u8 Data;
	/*initialize*/
	USART_VoidInit();

	while(1)
	{
		Data=USART_u16RecievePolling();
		if(Data=='1')
			{
				DIO_u8SetPinValue(DIO_u8PORTB,0,1);
				USART_VoidSendPolling('o');
			}
		else if(Data=='2')
			{
				DIO_u8SetPinValue(DIO_u8PORTB,0,0);
				USART_VoidSendPolling('t');
			}

	}
}
