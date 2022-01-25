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

//Global pointers for callback functions
void (* EXTI_pvInt0Func)(void)=NULL;
void (* EXTI_pvInt1Func)(void)=NULL;
void (* EXTI_pvInt2Func)(void)=NULL;

void EXTI_voidInt0Init(void)
{
	// Setting state for INT0
	#if INT0_STATE==ENABLED
	SET_BIT(GICR,GICR_INT_0_BIT);
	#elif INT0_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT_0_BIT);
	#else
	#error "Error in INT0 State"
	#endif

	//setting sensor control
	#if INT0_SensorControl==EXTI_FALLING
	SET_BIT(MCUCR,MCUCR_ISC01_BIT);
	CLR_BIT(MCUCR,MCUCR_ISC00_BIT);
	
	#elif INT0_SensorControl==EXTI_RISING
	SET_BIT(MCUCR,MCUCR_ISC01_BIT);
	SET_BIT(MCUCR,MCUCR_ISC00_BIT);	
	
	#elif INT0_SensorControl==EXTI_ANYCHANGE
	CLR_BIT(MCUCR,MCUCR_ISC01_BIT);
	SET_BIT(MCUCR,MCUCR_ISC00_BIT);
	
	#elif INT0_SensorControl==EXTI_LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC01_BIT);
	CLR_BIT(MCUCR,MCUCR_ISC00_BIT);
	
	#else
		#error "Error in sense control"
	
	#endif
	
}
void EXTI_voidInt1Init(void)
{
		// Setting INT1 State
	#if INT1_STATE==ENABLED
	SET_BIT(GICR,GICR_INT_1_BIT);
	#elif INT1_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT_1_BIT);
	#else
	#error "Error in INT1 State"
	#endif

	//setting sensor control
	#if INT1_SensorControl==EXTI_FALLING
	SET_BIT(MCUCR,MCUCR_ISC11_BIT);
	CLR_BIT(MCUCR,MCUCR_ISC10_BIT);
	
	#elif INT1_SensorControl==EXTI_RISING
	SET_BIT(MCUCR,MCUCR_ISC11_BIT);
	SET_BIT(MCUCR,MCUCR_ISC10_BIT);	
	
	#elif INT1_SensorControl==EXTI_ANYCHANGE
	CLR_BIT(MCUCR,MCUCR_ISC11_BIT);
	SET_BIT(MCUCR,MCUCR_ISC10_BIT);
	
	#elif INT1_SensorControl==EXTI_LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC11_BIT);
	CLR_BIT(MCUCR,MCUCR_ISC10_BIT);
	
	#endif
}
void EXTI_voidInt2Init(void)
{
	// Setting state of INT2
	#if INT2_STATE==ENABLED
	SET_BIT(GICR,GICR_INT_2_BIT);
	#elif INT2_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT_2_BIT);
	#else
	#error "Error in INT2 State"
	#endif
	
	//setting sensor control
	#if INT2_SensorControl==EXTI_FALLING
	CLR_BIT(MCUCSR,MCUCSR_ISC2_BIT);
	
	#elif INT2_SensorControl==EXTI_RISING
	SET_BIT(MCUCSR,MCUCSR_ISC2_BIT);
	
	#endif
}
/*POSTBUILD functions*/

u8 EXTI_u8SetControlSense(u8 Copy_u8ControlSense,u8 Copy_u8Int)
{
	u8 Local_u8ErrorState=OK;


		switch(Copy_u8ControlSense)
		{
		//rising
		case EXTI_RISING:
			switch(Copy_u8Int)
			{
			case EXTI_INT0:
				SET_BIT(MCUCR,MCUCR_ISC01_BIT);
				SET_BIT(MCUCR,MCUCR_ISC00_BIT);
				break;
			case EXTI_INT1:
				SET_BIT(MCUCR,MCUCR_ISC11_BIT);
				SET_BIT(MCUCR,MCUCR_ISC10_BIT);
				break;
			case EXTI_INT2:
				SET_BIT(MCUCSR,MCUCSR_ISC2_BIT);
				break;
			default :
				Local_u8ErrorState=NOK;
			}
			break;

			//falling
		case EXTI_FALLING:
			switch(Copy_u8Int)
			{
			case EXTI_INT0:
				SET_BIT(MCUCR,MCUCR_ISC01_BIT);
				CLR_BIT(MCUCR,MCUCR_ISC00_BIT);
				break;
			case EXTI_INT1:
				SET_BIT(MCUCR,MCUCR_ISC11_BIT);
				CLR_BIT(MCUCR,MCUCR_ISC10_BIT);
				break;
			case EXTI_INT2:
				CLR_BIT(MCUCSR,MCUCSR_ISC2_BIT);
				break;
			default:
				Local_u8ErrorState=NOK;
			}
			break;

			//any change
		case EXTI_ANYCHANGE:
			if(Copy_u8Int==EXTI_INT0)
			{
				CLR_BIT(MCUCR,MCUCR_ISC01_BIT);
				SET_BIT(MCUCR,MCUCR_ISC00_BIT);
			}
			else if(Copy_u8Int==EXTI_INT1)
			{
				CLR_BIT(MCUCR,MCUCR_ISC11_BIT);
				SET_BIT(MCUCR,MCUCR_ISC10_BIT);
			}
			else
			{
				Local_u8ErrorState=NOK;
			}
			break;

			//low level
		case EXTI_LOW_LEVEL:
			if(Copy_u8Int==EXTI_INT0)
			{
				CLR_BIT(MCUCR,MCUCR_ISC01_BIT);
				CLR_BIT(MCUCR,MCUCR_ISC00_BIT);
			}
			else if(Copy_u8Int==EXTI_INT1)
			{
				CLR_BIT(MCUCR,MCUCR_ISC11_BIT);
				CLR_BIT(MCUCR,MCUCR_ISC10_BIT);
			}
			else
			{
				Local_u8ErrorState=NOK;
			}
			break;

			//error in control sense
		default:
			Local_u8ErrorState=NOK;
		}

	return Local_u8ErrorState;
}
u8 EXTI_u8InterruptEnable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState=OK;
	switch (Copy_u8Int)
	{
	case EXTI_INT0:
		SET_BIT(GICR,GICR_INT_0_BIT);
		break;
	case EXTI_INT1:
		SET_BIT(GICR,GICR_INT_1_BIT);
		break;
	case EXTI_INT2:
		SET_BIT(GICR,GICR_INT_2_BIT);
		break;
	default:
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8InterruptDisable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState=OK;
	switch (Copy_u8Int)
		{
		case EXTI_INT0:
			CLR_BIT(GICR,GICR_INT_0_BIT);
			break;
		case EXTI_INT1:
			CLR_BIT(GICR,GICR_INT_1_BIT);
			break;
		case EXTI_INT2:
			CLR_BIT(GICR,GICR_INT_2_BIT);
			break;
		default:
			Local_u8ErrorState=NOK;
		}
	return Local_u8ErrorState;
}

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState=OK;
	if (Copy_pvInt0Func==NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		EXTI_pvInt0Func=Copy_pvInt0Func;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState=OK;
	if (Copy_pvInt1Func==NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		EXTI_pvInt1Func=Copy_pvInt1Func;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState=OK;
	if (Copy_pvInt2Func==NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		EXTI_pvInt2Func=Copy_pvInt2Func;
	}
	return Local_u8ErrorState;
}

/*ISR*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXTI_pvInt0Func();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	EXTI_pvInt1Func();
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	EXTI_pvInt2Func();
}
