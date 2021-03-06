/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	HAL				**********************/
/**************		SWC:	CLCD			**********************/
/**************		Version:1.1				**********************/
/**************		Date:19/1/2022			**********************/
/*****************************************************************/
/*****************************************************************/
/*VERSION 1.1 : */
/*1)added feature write on the second line after finishing first line */
/*2)added 4 bit mode operation*/
#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

#define MAX_COLUMNS 16
#define PRE_FOUR_BIT_MODE 0
#define PRE_EIGHT_BIT_MODE 1

/*power function*/
u32 u32POWER(u32 Copy_u8Num, u8 Copy_u8pow);
#endif
