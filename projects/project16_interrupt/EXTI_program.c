/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	EXTI			**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/

#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_register.h"


void EXTI_voidInt0Init(void)
{
	// enabling INT0
	SET_BIT(GICR,GICR_INT_0_BIT);
	
	//setting sensor control
	#if INT0_SensorControl==EXTI_FALLING
	SET_BIT(MCUCR,MCUCR_ISC01_BIT);
	CLR_BIT(MCUCR,MCUCR_ISC00_BIT);
	
	#elif INT0_SensorControl==EXTI_RISING
	SET_BIT(MCUCR,MCUCR_ISC01_BIT);
	SET_BIT(MCUCR,MCUCR_ISC00_BIT);	

	#elif INT0_SensorControl==EXTI_CHANGE
	CLR_BIT(MCUCR,MCUCR_ISC01_BIT);
	SET_BIT(MCUCR,MCUCR_ISC00_BIT);

	#elif INT0_SensorControl==EXTI_LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC01_BIT);
	CLR_BIT(MCUCR,MCUCR_ISC00_BIT);
	
	#endif
	
}
void EXTI_voidInt1Init(void)
{
		// enabling INT0
	SET_BIT(GICR,GICR_INT_1_BIT);
	
	//setting sensor control
	#if INT0_SensorControl==EXTI_FALLING
	SET_BIT(MCUCR,MCUCR_ISC11_BIT);
	CLR_BIT(MCUCR,MCUCR_ISC10_BIT);
	
	#elif INT0_SensorControl==EXTI_RISING
	SET_BIT(MCUCR,MCUCR_ISC11_BIT);
	SET_BIT(MCUCR,MCUCR_ISC10_BIT);	
	
	#elif INT0_SensorControl==EXTI_CHANGE
	CLR_BIT(MCUCR,MCUCR_ISC11_BIT);
	SET_BIT(MCUCR,MCUCR_ISC10_BIT);
	
	#elif INT0_SensorControl==EXTI_LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC11_BIT);
	CLR_BIT(MCUCR,MCUCR_ISC10_BIT);
	
	#endif
}
void EXTI_voidInt2Init(void)
{
	// enabling INT0
	SET_BIT(GICR,GICR_INT_2_BIT);
	
	//setting sensor control
	#if INT0_SensorControl==EXTI_FALLING
	CLR_BIT(MCUCSR,MCUCSR_ISC2_BIT);
	
	#elif INT0_SensorControl==EXTI_RISING
	SET_BIT(MCUCSR,MCUCSR_ISC2_BIT);
	
	#endif
}
