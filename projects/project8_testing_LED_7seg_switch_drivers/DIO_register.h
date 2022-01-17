/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	DIO				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#define PORTA_reg	*((volatile u8*)0x3b) 
#define DDRA_reg 	*((volatile u8*)0x3a) 
#define PINA_reg 	*((volatile u8*)0x39) 

#define PORTB_reg 	*((volatile u8*)0x38) 
#define DDRB_reg 	*((volatile u8*)0x37) 
#define PINB_reg	*((volatile u8*)0x36) 

#define PORTC_reg	*((volatile u8*)0x35) 
#define DDRC_reg	*((volatile u8*)0x34) 
#define PINC_reg	*((volatile u8*)0x33) 

#define PORTD_reg	*((volatile u8*)0x32) 
#define DDRD_reg	*((volatile u8*)0x31) 
#define PIND_reg	*((volatile u8*)0x30) 

#endif
