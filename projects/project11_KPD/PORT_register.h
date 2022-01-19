/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	PORT			**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

#define DDRA_reg 	*((volatile u8*)0x3a) 
#define DDRB_reg 	*((volatile u8*)0x37) 
#define DDRC_reg	*((volatile u8*)0x34) 
#define DDRD_reg	*((volatile u8*)0x31) 

#define PORTA_reg	*((volatile u8*)0x3b) 
#define PORTB_reg 	*((volatile u8*)0x38) 
#define PORTC_reg	*((volatile u8*)0x35) 
#define PORTD_reg	*((volatile u8*)0x32) 
#endif