/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	TIMER			**********************/
/**************		Version:1.1				**********************/
/**************		Date:29/1/2022			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0			*((volatile u8*)0x53)		/*Timer /counter control register*/
#define TCCR0_CS00		0							/*Clock Select Bit used to select prescaler or turn off the timer or to select external event source instead of clock*/
#define TCCR0_CS01		1							/*Clock Select Bit used to select prescaler or turn off the timer or to select external event source instead of clock*/
#define TCCR0_CS02		2							/*Clock Select Bit used to select prescaler or turn off the timer or to select external event source instead of clock*/
#define TCCR0_WGM01		3							/*Waveform Generation Mode01 used to choose mode of the timer /counter*/
#define TCCR0_COM00		4							/*Compare Match Output Mode00 used to control output compare pin(OC0) behavior in case of compare match */
#define TCCR0_COM01		5							/*Compare Match Output Mode01 used to control output compare pin(OC0) behavior in case of compare match */
#define TCCR0_WGM00		6							/*Waveform Generation Mode00 used to choose mode of the timer /counter*/
#define TCCR0_FOC0		7							/*Force Output Compare used to trigger Compare match event when set to 1 for testing purposes*/

#define TCNT0			*((volatile u8*)0x52)		/*Counter Register TCNT0 used to give access to counter or timer counts */

#define OCR0			*((volatile u8*)0x5c)		/*Output compare register is used to continously compare TCNT0 with OCR0 until a match occurs*/

#define TIMSK			*((volatile u8*)0x59)		/*Timer/Counter Interrupt Mask Register used to access interrupts*/
#define TIMSK_TOIE0		0							/*Timer/Counter0 Overflow Interrupt Enable*/
#define TIMSK_OCIE0		1							/*Timer/Counter0 Output Compare Match Interrupt Enable*/

#define TIFR			*((volatile u8*)0x58)		/*Timer/Counter Interrupt Flag Register used to access flags of the compare match or overflow*/
#define TIFR_TOV0		0							/*Timer/Counter0 Overflow Flag*/
#define TIFR_OCF0		1							/*Output Compare Flag*/

#define SFIOR			*((volatile u8*)0x50)		/*Special Function IO Register*/
#define SFIOR_PSR10		0							/*Prescaler Reset Timer/Counter1 and Timer/Counter0 used to reset prescaler of both timers as they have same prescaler write to 1 to reset then it will be auto cleared after prescaler reset*/

#endif /* TIMER_REGISTER_H_ */
