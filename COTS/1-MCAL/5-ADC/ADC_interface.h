/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	ADC				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/*MUX channels*/
//Single ended
#define SE_ADC0 				0
#define SE_ADC1 				1
#define SE_ADC2 				2
#define SE_ADC3 				3
#define SE_ADC4 				4
#define SE_ADC5 				5
#define SE_ADC6					6
#define SE_ADC7 				7
#define SE_VBG					30//input is 1.22V from Microcontroller
#define SE_GND					31
//Differential
#define PosADC0_NegADC0_10x		8
#define PosADC1_NegADC0_10x		9
#define PosADC0_NegADC0_200x	10
#define PosADC1_NegADC0_200x	11
#define PosADC2_NegADC2_10x		12
#define PosADC3_NegADC2_10x		13
#define PosADC2_NegADC2_200x	14
#define PosADC3_NegADC2_200x	15
#define PosADC0_NegADC1_1x		16
#define PosADC1_NegADC1_1x		17
#define PosADC2_NegADC1_1x		18
#define PosADC3_NegADC1_1x		19
#define PosADC4_NegADC1_1x		20
#define PosADC5_NegADC1_1x		21
#define PosADC6_NegADC1_1x		22
#define PosADC7_NegADC1_1x		23
#define PosADC0_NegADC2_1x		24
#define PosADC1_NegADC2_1x		25
#define PosADC2_NegADC2_1x		26
#define PosADC3_NegADC2_1x		27
#define PosADC4_NegADC2_1x		28
#define PosADC5_NegADC2_1x		29

/*Function prototypes*/
void ADC_VoidInit();
/*return options:
1)OK				0
2)NOK				1
3)NULL_POINTER		2
4)TIMEOUT			3
5)BUSY_FUNC			4
*/
u8 ADC_u8GetChannelReadingSync(u8 Copy_u8Channel , u16* Copy_pu16ADCReading);
u8 ADC_u8GetChannelReadingAsync(u8 Copy_u8Channel , u16* Copy_pu16ADCReading,void(*Copy_pvADCNotification)(void));

/*options:
1)ADC_TenBitMode
2)ADC_EightBitMode
*/
//TO BE CALLED ONLY AFTER CALLING one of the GetChannelReading functions first
u8 ADC_u16AccessADCRegisters(u16* pu16_ADCReading);//this function returns contents of ADCH and ADCL according to input mode for use in autotrigger mode
#endif
