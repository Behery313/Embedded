/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	EXTI			**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
//Prebuild functions
void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);

//postbuild functions
//options for control sense
#define EXTI_FALLING				1
#define EXTI_RISING					2
#define EXTI_ANYCHANGE				3//NOT AVAILABLE FOR INT2
#define EXTI_LOW_LEVEL				4//NOT AVAILABLE FOR INT2

//INT options
#define EXTI_INT0					1
#define EXTI_INT1					2
#define EXTI_INT2					3

u8 EXTI_u8SetControlSense(u8 Copy_u8ControlSense,u8 Copy_u8Int);
u8 EXTI_u8InterruptEnable(u8 Copy_u8Int);
u8 EXTI_u8InterruptDisable(u8 Copy_u8Int);
//Callback functions
u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void));
u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void));
u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void));
#endif
