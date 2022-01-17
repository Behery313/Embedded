/*
 * main.c
 *
 *  Created on: Sep 14, 2018
 *      Author: Mohamed
 */
#include "avr/delay.h"
#include "typedefs.h"

#include"DIO_Int.h"
			/*Connect your 7 Seg to PORTC as following*/
			/*Seg a: PIN C0*/
			/*Seg b: PIN C1*/
			/*Seg c: PIN C2*/
			/*Seg d: PIN C3*/
			/*Seg e: PIN C4*/
			/*Seg f: PIN C5*/
			/*Seg g: PIN C6*/
u8 Arr_DecToSeg[10] = {		               
					   /*Change this according to your 7Seg*/
					   /*if it common Cathode reverse each 0 by 1*/
					   /* gfedcba*/

		0b10100000,   /* 0 */
		0b11111001,   /* 1 */
		0b11000100,   /* 2 */
		0b11010000,   /* 3 */
		0b10011001,   /* 4 */
		0b10010010,   /*5*/
		0b10000011,   /* 6 */
		0b11111000,   /* 7 */
		0b10000000,   /* 8 */
		0b10010000   /* 9 */
					  };
void main(void)
{
	/*LED PORTD PIN5 blinking*/
	/*Set the Direction of PORTD PIN 5 as output*/
	/*Add your code here*/
	DIO_SetPinDir(PORTD, PIN_5, OUTPUT);
	while(1)
	{
		/*LED PORTD PIN5 blinking cont.*/
		/*Set PortD Pin5 to High*/
		/*Add your code here*/
		DIO_SetPinVal(PORTD, PIN_5, HIGH);
		/*Delay for 1 second*/
		_delay_ms(1000);
		/*Add your code here*/
		/*Set PortD Pin5 to High*/
		/*Delay for 1 second*/
		/*Add your code here*/
		DIO_SetPinVal(PORTD, PIN_5, LOW);
		_delay_ms(1000);


		/*If Push Pin3 in PORTA is LOW start the 7 Seg sequence*/
		/*Configure Pin3 in PORTA as input*/
		/*Add your code here*/
		DIO_SetPinDir(PORTA,PIN_2,INPUT);
		/*Configure Pin3 as internal pull-up*/
		/*Add your code here*/
		DIO_SetPinVal(PORTA,PIN_2,HIGH);
		/*Check the PORTA Pin 3 value is LOW*/
		if(DIO_GetPinVal(PORTA,PIN_2)==LOW)
		{

			/*Configure whole PORTC as output*/
			/*Add your code here*/
			DIO_SetPortDir(PORTC,0XFF);
			/*In case common Anode 7Seg configure any pin as High*/
			/*and connect it to the common 7Seg pins*/
			/*Set the Direction of PORTD PIN 7 as output*/
			/*Add your code here*/
			DIO_SetPinDir(PORTD,PIN_7,OUTPUT);
			/*Set Pin D7 as high*/
			/*Add your code here*/
			DIO_SetPinVal(PORTD,PIN_7,HIGH);
			for(u8 LoopCounter=0; LoopCounter<9;LoopCounter++)
			{
				/*Start the 7 Segements display sequence*/
				/*Set the value of PORTC pins to show the no on 7SEG*/
				/*Add your code here*/
				DIO_SetPortVal(PORTC,Arr_DecToSeg[LoopCounter]);
				/*Delay for 1 second*/
		        /*Add your code here*/
				_delay_ms(1000);
			}
		}
		else
		{

			/*Do nothing PIN 3 in PORTA is HIGH so Push not activated*/
		}
	}

}
