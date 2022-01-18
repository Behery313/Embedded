/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	HAL				**********************/
/**************		SWC:	SWITCH			**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/

#ifndef SWITCH_interface_H_
#define SWITCH_interface_H_

/*****************************TYPE*******************************/
#define SW_u8Maintained 	(u8) 0
#define SW_u8Temporary		(u8) 1//debouncing used

/************************Pull type*******************************/
//either pullup or pulldown
#define SW_u8Pullup 		(u8) 1
#define SW_u8Pulldown 		(u8) 0

/***************************State*********************************/
#define SW_u8Pressed		(u8) 1
#define SW_u8NotPressed		(u8) 0

/************************input struct****************************/
typedef struct SW_t{
	u8 SW_u8Port;
	u8 SW_u8PIN;
	u8 SW_u8SelfLockingType;//maintained or temporary
	u8 SW_u8Pulltype
}SW_t;

/********************function prototypes*************************/

u8 SW_u8GetState(SW_t* pstruct_SWn,u8* pu8_SwitchState);
#endif
