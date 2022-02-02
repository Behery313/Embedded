/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	TIMER			**********************/
/**************		Version:1.2				**********************/
/**************		Date:31/1/2022			**********************/
/*****************************************************************/
/*****************************************************************/
/*V1.1: Added FAST PWM config
 *V1.2: Added Timer 1 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_register.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

void (*Timer0_Notif)(void)=NULL;
void (*ICUNotif)(void)=NULL;
u8 Global_u8State=IDLE;
void TIMER0_VoidInitSync()
{

	/*Choose mode*/
	#if TIMER0_MODE==CTC_MODE
		/*choose CTC MODE*/
		SET_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*Disable interrupt*/
		CLR_BIT(TIMSK,TIMSK_OCIE0);

	#elif TIMER0_MODE==Normal_MODE
		/*choose Normal MODE*/
		CLR_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*Disable interrupt*/
		CLR_BIT(TIMSK,TIMSK_TOIE0);

	#elif TIMER0_MODE==FastPWM_MODE

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
#if TIMER0_MODE==CTC_MODE
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
#elif TIMER0_MODE==Normal_MODE
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
#elif TIMER0_MODE==FastPWM_MODE

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
#if TIMER0_MODE==CTC_MODE
		/*choose CTC MODE*/
		SET_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*Save output compare value*/
		OCR0=Copy_u8RegisterValue;//the value given is output compare to be compared every tick with TCNT0

		/*enable interrupt*/
		SET_BIT(TIMSK,TIMSK_OCIE0);

		/*set OC0 Action*/
		TCCR0&=COM_OutputModeBitMask;
		TCCR0|=OC0_action;

		/*set Clock source option to turn on the timer*/
		TCCR0&=CLK_SourceBitMask;
		TCCR0|=TIMER0_1ClkSource;

#elif TIMER0_MODE==Normal_MODE
		/*choose Normal MODE*/
		CLR_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*save preload value*/
		TCNT0=Copy_u8RegisterValue;//the value given if preload value

		/*enable interrupt*/
		SET_BIT(TIMSK,TIMSK_TOIE0);

		/*set OC0 Action*/
		TCCR0&=COM_OutputModeBitMask;
		TCCR0|=OC0_action;

		/*set Clock source option to turn on the timer*/
		TCCR0&=CLK_SourceBitMask;
		TCCR0|=TIMER0_1ClkSource;

#elif TIMER0_MODE==FastPWM_MODE

		/*choose Fast PWM MODE*/
		SET_BIT(TCCR0,TCCR0_WGM01);
		SET_BIT(TCCR0,TCCR0_WGM00);

		/*Save output compare value*/
		OCR0=Copy_u8RegisterValue;

		/*choose OC0 behavior*/
		TCCR0&=COM_OutputModeBitMask;
		TCCR0|=OC0_action;

		/*Disable interrupt*/
		CLR_BIT(TIMSK,TIMSK_TOIE0);

		/*choose prescaler*/
		TCCR0&=CLK_SourceBitMask;
		TCCR0|=TIMER0_1ClkSource;
#else
#error "Error in mode selection"
#endif



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
#if TIMER0_MODE==Normal_MODE
	TCNT0=Copy_u8Preload;
#endif
}

void TIMER1_VoidInit(u16 Copy_u16TOP)
{
#if TIMER1_MODE==FastPWM_MODE
	/*output PWM behavior on Channel A non inverting */
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	/*Set mode to FAST PWM with TOP=ICR*/
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	CLR_BIT(TCCR1A,TCCR1A_WGM10);

	/*Set the TOP value in ICR*/
	ICR1=Copy_u16TOP;

	/*Set the prescaler*/
	TCCR1B&=CLK_SourceBitMask;
	TCCR1B|=TIMER1_1ClkSource;
#elif TIMER1_MODE==CTC_MODE
#elif TIMER1_MODE==Normal_MODE

		/*set wave form generation to normal*/
		CLR_BIT(TCCR1A,TCCR1A_WGM11);
		CLR_BIT(TCCR1B,TCCR1B_WGM12);
		CLR_BIT(TCCR1B,TCCR1B_WGM13);
		CLR_BIT(TCCR1A,TCCR1A_WGM10);

		/*choose OC1 to be disconnected*/
		CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLR_BIT(TCCR1A,TCCR1A_COM1A1);
		CLR_BIT(TCCR1A,TCCR1A_COM1B0);
		CLR_BIT(TCCR1A,TCCR1A_COM1B1);

		/*set prescaler*/
		TCCR1B&=CLK_SourceBitMask;
		TCCR1B|=TIMER1_1ClkSource;

#elif TIMER1_MODE==PhaseCorrect
#else
#error "Error in TIMER1_MODE"
#endif
}
void TIMER1_VoidSetTimerValue(u16 Copy_u16TimerValue)
{
	TCNT1=Copy_u16TimerValue;
}
u16 TIMER1_u16ReadTimerValue()
{
	return TCNT1;
}
void TIMER1_VoidSetOCRValue(u16 Copy_u16RegisterValue)
{
	/*Set the Compare match value in OCR1 of the Channel A*/
		OCR1A=Copy_u16RegisterValue;
}

void Timer1ICU_VoidICUInit(u8 Local_u8Edge)
{
	/*set the initial edge*/
	if(Local_u8Edge==ICU_Rising)
	{
		SET_BIT(TCCR1B,TCCR1B_ICNC1);
	}
	else if(Local_u8Edge==ICU_Falling)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICNC1);
	}
	/*enable ICU interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void Timer1ICU_VoidSetEdge(u8 Local_u8Edge)
{
	/*set the initial edge*/
	if(Local_u8Edge==ICU_Rising)
	{
		SET_BIT(TCCR1B,TCCR1B_ICNC1);
	}
	else if(Local_u8Edge==ICU_Falling)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICNC1);
	}
}
void Timer1ICU_VoidDisableInterrupt()
{
	/*disable ICU interrupt*/
		CLR_BIT(TIMSK,TIMSK_TICIE1);
}
void Timer1ICU_VoidEnableInterrupt()
{
	/*enable ICU interrupt*/
		SET_BIT(TIMSK,TIMSK_TICIE1);
}
u8 TIMER1ICU_u8SetCallBack(void(*ICUFUNC)(void))
{
	u8 Local_u8ErrorState=OK;
	if(ICUFUNC!=NULL)
	{
		ICUNotif=ICUFUNC;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
void __vector_6(void) __attribute__((signal));
void __vector_6()
{
	ICUNotif();
}
