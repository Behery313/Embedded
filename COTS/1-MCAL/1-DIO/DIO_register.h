/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	DIO				**********************/
/**************		Version:1.1				**********************/
/*****************************************************************/
/*****************************************************************/
/*V1.1: removed DDR address*/
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#define PORTA_reg	*((volatile u8*)0x3b)  
#define PINA_reg 	*((volatile u8*)0x39) 

#define PORTB_reg 	*((volatile u8*)0x38) 
#define PINB_reg	*((volatile u8*)0x36) 

#define PORTC_reg	*((volatile u8*)0x35) 
#define PINC_reg	*((volatile u8*)0x33) 

#define PORTD_reg	*((volatile u8*)0x32) 
#define PIND_reg	*((volatile u8*)0x30) 

#endif
