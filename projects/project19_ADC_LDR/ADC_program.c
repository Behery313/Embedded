/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	ADC				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"

u8 Global_u8ADCState=IDLE;
static u16* ADC_pu16Reading;
static void(* ADC_pvSetCallBackNotification)(void);
void ADC_VoidInit()
{
	/*refrence selection*/
	#if RefSelection==AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	#elif RefSelection==AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	#elif RefSelection==Internal
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
	#else 
	#error "Error in reference selection"
	#endif

	/* adjustment*/
	#if Adjustment==Left
	SET_BIT(ADMUX,ADMUX_ADLAR);
	#elif Adjustment==Right
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	#else
	#error"Error in left adjustment"
	#endif

	/*Prescaler (BIT MASKING)*/
	ADCSRA&=Prescaler_BIT_MASK;
	ADCSRA|=PRESCALER_SEL;

	/*Enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
u8 ADC_u8GetChannelReadingSync(u8 Copy_u8Channel , u16* Copy_pu16ADCReading)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pu16ADCReading!=NULL)
	{
		if(Global_u8ADCState==IDLE)
		{
			//make ADC state busy
			Global_u8ADCState=BUSY;

			u32 Local_u8LoopCounter=0;

			//setting channel
			ADMUX&=MUX_BIT_MASK;
			ADMUX|=Copy_u8Channel;

			//Start conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			//polling(busy waiting) until conversion is done
			while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)||(Local_u8LoopCounter<ADC_TIMEOUT))
			{
				Local_u8LoopCounter++;
			}
			if(Local_u8LoopCounter==ADC_TIMEOUT)
			{
				Local_u8ErrorState=TIMEOUT;
			}
			else
			{
				//make ADC state IDLE
				Global_u8ADCState=IDLE;

				//clear the flag manually by setting it to 1
				SET_BIT(ADCSRA,ADCSRA_ADIF);

				#if Adjustment==Left//take 8 bits
					*Copy_pu16ADCReading= ADCH;
				#elif Adjustment==Right//take 10 bits
					//*Copy_pu16ADCReading=(ADCL|(ADCH<<8)); //this is trivial way
					*Copy_pu16ADCReading=ADC;//this will take 2 bytes which include ADCL and ADCH
				#else
					#error "Error in adjustment"
				#endif
			}
		}
		else
		{
			/*make error state busy function*/
			Local_u8ErrorState=BUSY_FUNC;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
u8 ADC_u8GetChannelReadingAsync(u8 Copy_u8Channel , u16* Copy_pu16ADCReading,void(*Copy_pvADCNotification)(void))
{
	u8 Local_u8ErrorState=OK;
	if((Copy_pu16ADCReading==NULL)||(Copy_pvADCNotification==NULL))
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		if(Global_u8ADCState==IDLE)
		{
			/*set ADC state to busy*/
			Global_u8ADCState=BUSY;

			/*setting global pointers to the input pointers to be used in the ISR*/
			ADC_pu16Reading=Copy_pu16ADCReading;
			ADC_pvSetCallBackNotification=Copy_pvADCNotification;

			/*setting channel*/
			ADMUX&=MUX_BIT_MASK;
			ADMUX|=Copy_u8Channel;

			/*enable interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);

			/*Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

		}
		else
		{
			Local_u8ErrorState=BUSY_FUNC;
		}
	}
	return Local_u8ErrorState;
}
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	/*conversion done set adc state to idle*/
	Global_u8ADCState=IDLE;

	/*conversion done set the adc reading*/
	#if Adjustment==Left//take 8 bits
		*ADC_pu16Reading= ADCH;

	#elif Adjustment==Right//take 10 bits
		//*ADC_pu16Reading=(ADCL|(ADCH<<8)); //this is trivial way
		*ADC_pu16Reading=ADC;//this will take 2 bytes which include ADCL and ADCH

	#else
	#error "Error in adjustment"
	#endif

	/*callback the notification function*/
	ADC_pvSetCallBackNotification();

	/*Disable the interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}
