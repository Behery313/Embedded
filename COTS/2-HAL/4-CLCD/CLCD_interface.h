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
#ifndef CLCD_interface_H_
#define CLCD_interface_H_

/*******************Function Prototypes*****************************/
void CLCD_VoidSendCommand(u8 Copy_u8Command);
void CLCD_VoidSendData(u8 Copy_u8Data);
void CLCD_VoidInit(void);
void CLCD_VoidSendString(const char * CLCD_pcString);//char not u8 used as when u8 is used the character sent is not in ASCII WE MUST USE CHAR
void CLCD_VoidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_VoidWriteSpecialChar(const u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);//block number:number of special characters 0->7
void CLCD_VoidShowNum(u32 Copy_u32Num);
void CLCD_VoidReset_Display(void);
#endif
