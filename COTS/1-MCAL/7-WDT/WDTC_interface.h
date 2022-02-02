/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	TIMER			**********************/
/**************		Version:1.00			**********************/
/**************		Date:2/2/2022			**********************/
/*****************************************************************/
/*****************************************************************/


#ifndef WDTC_INTERFACE_H_
#define WDTC_INTERFACE_H_

#define Sleep_16p3ms		0
#define Sleep_32p5ms		1
#define Sleep_65ms			2
#define Sleep_0p13s			3
#define Sleep_0p26s			4
#define Sleep_0p52s			5
#define Sleep_1s			6
#define Sleep_2p1s			7
void WDT_VoidSleep(u8 Copy_u8TimeoutIndex);	/*Copy_u8TimeoutIndex=0->7*/
void WDT_VoidDisable();						/*Disable the WDT*/

#endif /* WDTC_INTERFACE_H_ */
