/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	HAL				**********************/
/**************		SWC:	CLCD			**********************/
/**************		Version:1.00			**********************/
/**************		Date:17/1/2022			**********************/
/*****************************************************************/
/*****************************************************************/

#ifndef CLCD_config_H_
#define CLCD_config_H_
/*************************WORKING MODE**************************/
/*choose working mode either "PRE_EIGHT_BIT_MODE" or "PRE_FOUR_BIT_MODE"*/
#define CLCD_WORKING_MODE				PRE_FOUR_BIT_MODE

/************************DATA PORT******************************/
#define CLCD_8_BIT_DATA_PORT			DIO_u8PORTD

/*4 bit data inputs are ignored if 4 bit mode isn't used*/
#define CLCD_4_BIT_DATA_PORT			DIO_u8PORTD

#define CLCD_4_BIT_DATA_PIN_0			DIO_u8PIN_4
#define CLCD_4_BIT_DATA_PIN_1			DIO_u8PIN_5
#define CLCD_4_BIT_DATA_PIN_2			DIO_u8PIN_6
#define CLCD_4_BIT_DATA_PIN_3			DIO_u8PIN_7

/************************Control PINS***************************/
#define CLCD_CTRL_PORT 		DIO_u8PORTC
#define CLCD_RS_PIN			DIO_u8PIN_0
#define CLCD_RW_PIN			DIO_u8PIN_1
#define CLCD_E_PIN			DIO_u8PIN_2

#endif
