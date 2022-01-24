/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	EXTI			**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


#define MCUCSR				*((volatile u8*) 0x54)
#define MCUCSR_ISC2_BIT		6


#define MCUCR				*((volatile u8*) 0x55)
#define MCUCR_ISC00_BIT		0
#define MCUCR_ISC01_BIT		1
#define MCUCR_ISC10_BIT		2
#define MCUCR_ISC11_BIT		3


#define GICR				*((volatile u8*) 0x5b)
#define GICR_INT_0_BIT		6
#define GICR_INT_1_BIT		7
#define GICR_INT_2_BIT		5

#define GIFR				*((volatile u8*) 0x5a)
#define GIFR_INTF_0_BIT		6
#define GIFR_INTF_1_BIT		7
#define GIFR_INTF_2_BIT		5

#endif