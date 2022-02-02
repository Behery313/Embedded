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
#include <util/delay.h>
/*ADC state*/

u8 Global_u8ADCState=IDLE;							/*Global variable indicating the state of the ADC*/
/*to be used in getting reading in the ISR*/
static u16* ADC_pu16Reading;						/*Global pointer to carry the reading of the ADC*/

/*to be used in input struct*/
static u8 	Global_u8ADCChainSize;					/*Global variable to carry size of the chain*/
static u16* Global_pu16ADCChainResultArr=NULL;		/*Global pointer to carry array of results*/
static u8*	Global_pu8ADCChannelArr=NULL;			/*Global pointer to carry array of channels used*/

static u8   Global_u8ChainConversionIndex=0;		/*Global index to indicate which channel new channel to use */

/*to be used in setting the callback function*/
static void(* ADC_pvSetCallBackNotification)(void)=NULL;

static u8 ADC_u8ISRSource=0;
void ADC_VoidInit()
{
	/*reference selection*/
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

	/*Autotrigger set option*/
	#if Autotrigger==ENABLED
		SET_BIT(ADCSRA,ADCSRA_ADATE);
		SFIOR&=Autotrigger_BIT_MASK;
		SFIOR|=AutotriggerSource;
	#elif Autotrigger==DISABLED
		CLR_BIT(ADCSRA,ADCSRA_ADATE);
	#else
		#error "Error in Autotrigger option"
	#endif
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
			while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)&&(Local_u8LoopCounter<ADC_TIMEOUT))
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

			/*edit ADC ISR source*/
			ADC_u8ISRSource=SingleChannelAsync;

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

u8 ADC_u16AccessADCRegisters(u16* pu16_ADCReading)
{
	u8 Local_u8ErrorState=OK;
	if(pu16_ADCReading==NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		#if Adjustment==Left//take 8 bits
			*pu16_ADCReading= ADCH;
		#elif Adjustment==Right//take 10 bits
			//*ADC_pu16Reading=(ADCL|(ADCH<<8)); //this is trivial way
			*pu16_ADCReading=ADC;//this will take 2 bytes which include ADCL and ADCH
		#else
		#error "Error in adjustment"
		#endif
	}
	return Local_u8ErrorState;
}

u8 ADC_u8StartChainAsync(Chain_t *Copy_Chain)
{
	u8 Local_u8ErrorState=OK;

	/*check null pointer*/
	if(Copy_Chain==NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		/*edit ADC ISR source*/
		ADC_u8ISRSource=ChainChannelAsync;

		/*Check on state of ADC*/
		if (Global_u8ADCState==BUSY)
		{
			Local_u8ErrorState=BUSY;
		}
		/*in case of idle*/
		else
		{
			/*Make ADC BUSY*/
			Global_u8ADCState=BUSY;

			/*copy the struct elements to the global variables*/

			/*initialize global ADC channel Array*/
			Global_pu8ADCChannelArr=		  Copy_Chain->Channels;

			/*initialize global ADC chain size*/
			Global_u8ADCChainSize=		  Copy_Chain->Size;

			/*initialize global ADC result array*/
			Global_pu16ADCChainResultArr=  Copy_Chain->Results;

			/*initialize callback function*/
			ADC_pvSetCallBackNotification=Copy_Chain->NotificationFunc;

			/*initialize Current conversion index to 0*/
			Global_u8ChainConversionIndex=0;

			/*set required channel*/
			/*clearing the channel selection bits*/
			ADMUX&=MUX_BIT_MASK;

			/*set required channel (first channel)*/
			ADMUX|=Global_pu8ADCChannelArr[Global_u8ChainConversionIndex];

			/*enable conversion complete interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);

			/*Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

		}
	}
	return Local_u8ErrorState;
}
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	if(ADC_u8ISRSource==SingleChannelAsync)
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
	/*ChainAsync*/
	else if(ADC_u8ISRSource==ChainChannelAsync)
	{
		/*store the data*/
#if Adjustment==Left//take 8 bits
		Global_pu16ADCChainResultArr[Global_u8ChainConversionIndex]=ADCH;

#elif Adjustment==Right//take 10 bits
		Global_pu16ADCChainResultArr[Global_u8ChainConversionIndex]=ADC;

#else
#error "Error in adjustment"
#endif

		/*increment index*/
		Global_u8ChainConversionIndex++;

		/*check if we finished the conversion of all required channels*/
		/*in case of finishing all channels*/
		if(Global_u8ChainConversionIndex==Global_u8ADCChainSize)
		{
			/*Reset ADC state*/
			Global_u8ADCState=IDLE;

			/*Call notification function*/
			ADC_pvSetCallBackNotification();

			/*Disable conversion complete interrupt*/
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		/*in case of remaining channels*/
		else if(Global_u8ChainConversionIndex<Global_u8ADCChainSize)
		{
			/*set next channel*/
			/*clearing the channel selection bits*/
			ADMUX&=MUX_BIT_MASK;

			/*set required channel (first channel)*/
			ADMUX|=Global_pu8ADCChannelArr[Global_u8ChainConversionIndex];

			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
	}
}
