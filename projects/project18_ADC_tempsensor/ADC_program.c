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
u16 ADC_u16GetChannelReading(u8 Copy_u8Channel)
{

		//setting channel
		ADMUX&=MUX_BIT_MASK;
		ADMUX|=Copy_u8Channel;

		//Start conversion
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		//polling(busy waiting) until conversion is done
		while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0)
		{
			//do nothing
		}
		//clear the flag manually by setting it to 1
		SET_BIT(ADCSRA,ADCSRA_ADIF);

		#if Adjustment==Left//take 8 bits
			return ADCH;
		#elif Adjustment==Right//take 10 bits
				return (ADCL|(ADCH<<8)); //this is trivial way
			//return ADC;//this will take 2 bytes which include ADCL and ADCH
		#else
			#error "Error in adjustment"
		 #endif

}
