/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	ADC				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

//Prescaler
#define DivBy2				1
#define DivBy4              2
#define DivBy8              3
#define DivBy16             4
#define DivBy32             5
#define DivBy64             6
#define DivBy128            7

//Refrence selection
#define AREF				1
#define AVCC				2
#define Internal			3

//Left adjustment
#define Left				1
#define Right				2

//Bit masks
#define Prescaler_BIT_MASK	0b11111000
#define MUX_BIT_MASK		0b11100000

#endif
