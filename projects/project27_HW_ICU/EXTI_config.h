/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	EXTI			**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
//'EXTI_RISING' 'EXTI_FALLING' 'EXTI_LOW_LEVEL' 'EXTI_ANYCHANGE'
#define INT0_SensorControl		EXTI_RISING
#define INT1_SensorControl		EXTI_FALLING
#define INT2_SensorControl		EXTI_FALLING//either falling or rising only
 
#define INT0_STATE				ENABLED
#define INT1_STATE				ENABLED
#define INT2_STATE				ENABLED

#endif
