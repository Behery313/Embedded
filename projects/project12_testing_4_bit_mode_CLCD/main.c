/*
 * main.c
 *
 *  Created on: 17 Jan 2022
 *      Author: Yusuf
 */

#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"CLCD_interface.h"
#include"PORT_interface.h"
#include<util/delay.h>
#include"KPD_interface.h"
void main()
{
	PORT_VoidInit();
	u8 pattern1[]={0,0b1,0b1,0b1,0b11111,0,0b01010,0};
	u8 Local_u8Key;

	CLCD_VoidInit();
	CLCD_VoidWriteSpecialChar(pattern1,0,0,0);
	//while(1){CLCD_VoidWriteSpecialChar(pattern1,0,14)}
	while(1){
/*use do while to avoid making any action until any key is pressed (busy waiting)*/
		do
		{
			Local_u8Key=KPD_u8GetPressedKey();

		}while(Local_u8Key==0xff);

		CLCD_VoidShowNum(Local_u8Key);
	}
}
