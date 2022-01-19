/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	HAL				**********************/
/**************		SWC:	KPD				**********************/
/**************		Version:1.00			**********************/
/**************		Date:18/1/2022			**********************/
/*****************************************************************/
/*****************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_PORT 				DIO_u8PORTA
#define KPD_ROW_1				DIO_u8PIN_0
#define KPD_ROW_2				DIO_u8PIN_1
#define KPD_ROW_3				DIO_u8PIN_2
#define KPD_ROW_4				DIO_u8PIN_3

#define KPD_COL_1				DIO_u8PIN_4
#define KPD_COL_2				DIO_u8PIN_5
#define KPD_COL_3				DIO_u8PIN_6
#define KPD_COL_4				DIO_u8PIN_7

#define KPD_KEY_ARR_VALUES		{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define KPD_NO_PRESSED_KEY		0xff
#endif
