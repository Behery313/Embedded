/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	ADC				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

//set prescale 
/*
	options :1)DivBy2
			 2)DivBy4
			 3)DivBy8
			 4)DivBy16
			 5)DivBy32
			 6)DivBy64
			 7)DivBy128
*/          
#define PRESCALER_SEL		DivBy128



//Refrence selection
/*
	options :1)AREF
			 2)AVCC
			 3)Internal :for  VREF=2.56V
*/         
#define  RefSelection		AVCC	

//Left adjustment
/*
	options :1)Left  :for 8 bit read
			 2)Right :for 10 bit read
*/
#define  Adjustment		Right


#endif
