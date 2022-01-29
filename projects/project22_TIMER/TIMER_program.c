/*
 * TIMER_program.c
 *
 *  Created on: 28 Jan 2022
 *      Author: Yusuf
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_register.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

void (*Timer0_Notif)(void)=NULL;

u8 Global_u8State=IDLE;
void TIMER0_VoidInitSync()
{

	/*Choose mode*/
	#if MODE==CTC_MODE
		/*choose CTC MODE*/
		SET_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*Disable interrupt*/
		CLR_BIT(TIMSK,TIMSK_OCIE0);

	#elif MODE==Normal_MODE
		/*choose Normal MODE*/
		CLR_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*Disable interrupt*/
		CLR_BIT(TIMSK,TIMSK_TOIE0);

	#else
	#error "Error in mode selection"
	#endif

		/*set OC0 Action*/
		TCCR0&=COM_OutputModeBitMask;
		TCCR0|=OC0_action;
}


u8 TIMER0_u8WaitSync(u8 Copy_u8RegisterValue,u32 Copy_u32Counts)
{
	u8 Local_u8ErrorState=OK;
	if (Global_u8State==BUSY)
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	else
	{
		/*set state to BUSY to avoid calling the function by interrupts while working in it*/
		Global_u8State=BUSY;

		/*busy waiting (polling) until timer finishes*/
#if MODE==CTC_MODE
		u32 TimeoutCounter=0;
		u32 Local_u32Counter=0;

		/*Save output compare value*/
		OCR0=Copy_u8RegisterValue;//the value given is output compare to be compared every tick with TCNT0

		/*set Clock source option to turn on the timer*/
		TCCR0&=CLK_SourceBitMask;
		TCCR0|=TIMER0_1ClkSource;
		do
		{
			Local_u32Counter++;
			while((GET_BIT(TIFR,TIFR_OCF0)==0)&&(TimeoutCounter<TIMEOUT_COUNTS))
			{
				TimeoutCounter++;
			}
			/*check for timeout*/
			if(TimeoutCounter==TIMEOUT_COUNTS)
			{
				Local_u8ErrorState=TIMEOUT;
			}
			else
			{
				/*clear the flag manually*/
				SET_BIT(TIFR,TIFR_OCF0);
			}
		}while(Local_u32Counter<Copy_u32Counts);//exit the do while after waiting for the timer to finish
#elif MODE==Normal_MODE
		u32 TimeoutCounter=0;
		u32 Local_u32Counter=0;

		/*save preload value*/
		TCNT0=Copy_u8RegisterValue;//the value given if preload value

		/*set Clock source option to turn on the timer*/
		TCCR0&=CLK_SourceBitMask;
		TCCR0|=TIMER0_1ClkSource;
		do
		{
			Local_u32Counter++;
			while((GET_BIT(TIFR,TIFR_TOV0)==0)&&(TimeoutCounter<TIMEOUT_COUNTS))
			{
				TimeoutCounter++;
			}
			/*check for timeout*/
			if(TimeoutCounter==TIMEOUT_COUNTS)
			{
				Local_u8ErrorState=TIMEOUT;
			}
			else
			{
				/*clear the flag manually*/
				SET_BIT(TIFR,TIFR_TOV0);
			}
		}while(Local_u32Counter<Copy_u32Counts);//exit the do while after waiting for the timer to finish
#else
#error "Error in mode selection"
#endif

		/*turn timer off*/
		TCCR0&=CLK_SourceBitMask;
		TCCR0|=OFF;

		/*reset state to be called again*/
		Global_u8State=IDLE;
		return Local_u8ErrorState;
	}
}
/***************************************************************/
void TIMER0_VoidInitAsync(u8 Copy_u8RegisterValue)
{

		/*Choose mode*/
#if MODE==CTC_MODE
		/*choose CTC MODE*/
		SET_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*Save output compare value*/
		OCR0=Copy_u8RegisterValue;//the value given is output compare to be compared every tick with TCNT0

		/*enable interrupt*/
		SET_BIT(TIMSK,TIMSK_OCIE0);

#elif MODE==Normal_MODE
		/*choose Normal MODE*/
		CLR_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*save preload value*/
		TCNT0=Copy_u8RegisterValue;//the value given if preload value

		/*enable interrupt*/
		SET_BIT(TIMSK,TIMSK_TOIE0);

#else
#error "Error in mode selection"
#endif

		/*set OC0 Action*/
		TCCR0&=COM_OutputModeBitMask;
		TCCR0|=OC0_action;

		/*set Clock source option to turn on the timer*/
		TCCR0&=CLK_SourceBitMask;
		TCCR0|=TIMER0_1ClkSource;


}

u8 TIMER0_u8SetCallBack(void (*Copy_pvNotif)(void))//used in every mode of operation
{

	u8 Local_u8ErrorState=OK;
	if(Copy_pvNotif!=NULL)
	{
		Timer0_Notif=Copy_pvNotif;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
void __vector_10(void) __attribute__((signal));//compare match interrupt
void __vector_10()
{

	if(Timer0_Notif!=NULL)
	{
		Timer0_Notif();
	}
}
void __vector_11(void) __attribute__((signal));//overflow interrupt
void __vector_11()
{
	if(Timer0_Notif!=NULL)
	{
		Timer0_Notif();
	}
}
void TIMER0_SetPreload(u8 Copy_u8Preload)
{
#if MODE==Normal_MODE
	TCNT0=Copy_u8Preload;
#endif
}
