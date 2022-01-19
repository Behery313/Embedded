/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	DIO				**********************/
/**************		Version:1.1				**********************/
/*****************************************************************/
/*****************************************************************/

/*V1.1: removed definitions of output and input , removed functions setpindirection and set port direction as directions are controlled in the PORT file*/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/****************************PORTS*****************************************/
#define DIO_u8PORTA		(u8) 0
#define DIO_u8PORTB		(u8) 1
#define DIO_u8PORTC		(u8) 2
#define DIO_u8PORTD		(u8) 3
/****************************PINS*****************************************/
#define DIO_u8PIN_0		(u8) 0
#define DIO_u8PIN_1		(u8) 1
#define DIO_u8PIN_2 	(u8) 2
#define DIO_u8PIN_3   	(u8) 3
#define DIO_u8PIN_4   	(u8) 4
#define DIO_u8PIN_5  	(u8) 5
#define DIO_u8PIN_6  	(u8) 6
#define DIO_u8PIN_7  	(u8) 7
/****************************EXTRAS****************************************/
#define DIO_u8HIGH		(u8) 1
#define DIO_u8LOW		(u8) 0
/*********************Function Prototypes*********************************/
u8 DIO_u8SetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin,u8 Copy_u8Value);//set value for specific pin

u8 DIO_u8SetPortValue(u8 Copy_u8Port ,u8 Copy_u8Value);//set value for entire port(NOTE:value can  be 0b101010)

u8 DIO_u8GetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin,u8* Copy_pu8Value);//get value for specific pin
/*not tested*/
u8 DIO_u8GetPortValue(u8 Copy_u8Port ,u8* Copy_pu8Value);//get value of entire port
#endif
