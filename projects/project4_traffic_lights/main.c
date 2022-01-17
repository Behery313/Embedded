/*
 * main.c
 *
 *  Created on: 14 Jan 2022
 *      Author: Yusuf
 */
#include<avr/io.h>
#include<util/delay.h>
typedef unsigned char u8;
void countdown(u8 start)
{
	u8 num_7_seg[]={0b10100000,0b11111001,0b11000100,0b11010000,0b10011001,0b10010010,0b10000011,0b11111000,0b10000000,0b10011000};
	for(u8 i=start;i>0;i--)
	{
	//	base=start/10;
		PORTC=num_7_seg[i/10];
		PORTA=num_7_seg[i%10];
		_delay_ms(1000);
	}
}
void main()
{
	DDRA=0xff;
	DDRD=0xff;
	DDRC=0xff;
	//u8 num_7_seg[]={0b10100000,0b11111001,0b11000100,0b11010000,0b10011001,0b10010010,0b10000011,0b11111000,0b10000000,0b10011000};
	while(1)
	{
		//turn red on and wait for 15 seconds
		PORTD=0b100;
		countdown(10);
		//
		PORTD=0b010;
		countdown(10);
		PORTD=0b001;
		countdown(15);
	}
}
