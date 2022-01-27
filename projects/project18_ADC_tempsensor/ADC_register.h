/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	ADC				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX  					*((volatile u8*)0x27)			//Multiplexer Selection register
#define ADMUX_REFS1				7								//Refrence selection bit1
#define ADMUX_REFS0				6                               //Refrence selection bit0
#define ADMUX_ADLAR				5                               //Left Adjust result

#define ADCSRA  				*((volatile u8*)0x26)           //ADC control status register
#define ADCSRA_ADEN				7                               //ADC Enable
#define ADCSRA_ADSC				6                               //ADC start conversion
#define ADCSRA_ADATE			5                               //ADC auto trigger enable
#define ADCSRA_ADIF				4                               //ADC interrupt flag
#define ADCSRA_ADIE				3                               //ADC interrupt enable
#define ADCSRA_ADPS2			2                               //prescalar 2
#define ADCSRA_ADPS1			1                               //prescalar 1
#define ADCSRA_ADPS0			0                               //prescalar 0

#define ADCH					*((volatile u8*)0x25)           //ADC high register
#define ADCL					*((volatile u8*)0x24)           //ADC low register
#define ADC						*((volatile u16*)0x24)			//ADC used to return 10 bits directly from ADCH and ADCL

#endif
