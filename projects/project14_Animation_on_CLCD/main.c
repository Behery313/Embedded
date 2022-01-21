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
	u8 pattern0_standing[]={0b01110,0b11111,0b01110,0b00100,0b11111,0b00100,0b01010,0b01010};
	u8 pattern1_dancing1[]={0b01110,0b11111,0b01110,0b10101,0b01110,0b00100,0b01010,0b10001};//use with standing
	u8 pattern2_gun[]={0b11111,0b11111,0b11111,0b11000,0b11000,0b00000,0b00000,0b00000};
	u8 pattern3_bullet[]={0b00100,0b01110,0b00100,0,0,0,0,0};
	u8 pattern4_dead[]={0,0,0,0b00100,0b11111,0b00100,0b01010,0b01010};
	u8 pattern5_running[]={0b01110,0b11111,0b01110,0b00100,0b11111,0b00100,0b11111,0};//use with dancing1

	u8 pattern6_football1[]={0b01110,0b11111,0b01110,0b10101,0b01110,0b00100,0b11010,0b10010};
	u8 pattern7_football2[]={0b01110,0b11111,0b01110,0b10101,0b01110,0b10100,0b01010,0b10010};

	CLCD_VoidInit();
/*	CLCD_VoidWriteSpecialChar(pattern0_standing,0,0,0);
	CLCD_VoidWriteSpecialChar(pattern1_dancing1,1,0,1);
	CLCD_VoidWriteSpecialChar(pattern2_gun,2,0,2);
	CLCD_VoidWriteSpecialChar(pattern3_bullet,3,0,3);
	CLCD_VoidWriteSpecialChar(pattern4_dead,4,0,4);
	CLCD_VoidWriteSpecialChar(pattern5_running,5,0,5);
	CLCD_VoidWriteSpecialChar(pattern6_football1,6,0,6);
	CLCD_VoidWriteSpecialChar(pattern7_football2,7,0,7);*/


	CLCD_VoidSendString("Hello! You yes  you");
	//CLCD_VoidReset_Display();
	CLCD_VoidWriteSpecialChar(pattern0_standing,0,1,15);
	_delay_ms(5000);
	CLCD_VoidReset_Display();
	/*CLCD_VoidWriteSpecialChar(pattern0_standing,0,1,15);
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("You may be wondering");
	CLCD_VoidSendString("who am I");
	_delay_ms(5000);
	CLCD_VoidReset_Display();
		CLCD_VoidWriteSpecialChar(pattern0_standing,0,1,15);
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("and how I got to your LCD");
	_delay_ms(5000);
	CLCD_VoidReset_Display();
	CLCD_VoidWriteSpecialChar(pattern0_standing,0,1,15);
	CLCD_VoidGoToXY(0,0);*/
	CLCD_VoidSendString("I am Mr P I can do many things");

	//CLCD_VoidReset_Display();
	CLCD_VoidWriteSpecialChar(pattern0_standing,0,1,15);
	_delay_ms(5000);
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidReset_Display();
	CLCD_VoidSendString("I can run");
	_delay_ms(5000);
	//running
	for(u8 i=0;i<16;i+=2)
	{
		CLCD_VoidWriteSpecialChar(pattern1_dancing1,1,1,i);
		_delay_ms(300);
		CLCD_VoidReset_Display();
		CLCD_VoidWriteSpecialChar(pattern5_running,2,1,i+1);
		_delay_ms(300);
		CLCD_VoidReset_Display();
	}

	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("I can dance");

	_delay_ms(1000);
	CLCD_VoidReset_Display();
//	CLCD_VoidSendString("Look at them      MOVES!");
//	CLCD_VoidWriteSpecialChar(pattern0_standing,0,1,15);

//	_delay_ms(5000);
	CLCD_VoidReset_Display();
	for(u8 i=0;i<8;i++)
		{
			CLCD_VoidWriteSpecialChar(pattern1_dancing1,1,1,15);
			_delay_ms(500);
			CLCD_VoidReset_Display();
			CLCD_VoidWriteSpecialChar(pattern0_standing,0,1,15);
			_delay_ms(500);
			CLCD_VoidReset_Display();
		}
	//playing football

	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("and certainly   unlike you");
	_delay_ms(5000);
	CLCD_VoidReset_Display();
	CLCD_VoidGoToXY(0,0);
		CLCD_VoidSendString("I can play      football");
		_delay_ms(5000);
		CLCD_VoidReset_Display();
	for(u8 i=0;i<8;i++)
			{
				CLCD_VoidWriteSpecialChar(pattern6_football1,3,1,15);
				_delay_ms(500);
				CLCD_VoidReset_Display();
				CLCD_VoidWriteSpecialChar(pattern7_football2,4,1,15);
				_delay_ms(500);
				CLCD_VoidReset_Display();
			}


	CLCD_VoidSendString("I would like to tell you a fact");
	_delay_ms(5000);
	CLCD_VoidReset_Display();

	CLCD_VoidSendString("like the ending of AOT");
	_delay_ms(5000);
	CLCD_VoidReset_Display();

	CLCD_VoidSendString("let me tell you");
	_delay_ms(5000);
	CLCD_VoidReset_Display();

	CLCD_VoidSendString("Wait what are   you doing!");
	_delay_ms(5000);
	CLCD_VoidReset_Display();



	CLCD_VoidWriteSpecialChar(pattern0_standing,0,1,15);
	CLCD_VoidWriteSpecialChar(pattern2_gun,5,1,0);

	//CLCD_VoidReset_Display();
	for(u8 i=1;i<15;i++)
	{
		//CLCD_VoidWriteSpecialChar(pattern2_gun,5,1,0);

		CLCD_VoidWriteSpecialChar(pattern3_bullet,6,1,i);
		_delay_ms(300);
		CLCD_VoidGoToXY(1,i);
		CLCD_VoidSendString(" ");
		//CLCD_VoidReset_Display();

		//CLCD_VoidWriteSpecialChar(pattern0_standing,0,1,15);
	}


	CLCD_VoidWriteSpecialChar(pattern4_dead,7,1,15);
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("MY HEAD");
	_delay_ms(5000);
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("HOW AM I TALKING");
	_delay_ms(5000);
	CLCD_VoidGoToXY(0,0);
	CLCD_VoidSendString("CODE ME A HEAD  ");

}
