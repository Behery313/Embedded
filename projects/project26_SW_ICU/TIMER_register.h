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

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/******************************************************************TIMER 0*********************************************************************/

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

/******************************************************************TIMER 1*********************************************************************/
#define TCCR1A			*((volatile u8*)0x4f)
#define TCCR1A_WGM10	0
#define TCCR1A_WGM11	1
#define TCCR1A_FOC1B	2
#define TCCR1A_FOC1A	3
#define TCCR1A_COM1B0	4
#define TCCR1A_COM1B1	5
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1A1	7

#define TCCR1B			*((volatile u8*)0x4e)
#define TCCR1B_CS10		0
#define TCCR1B_CS11		1
#define TCCR1B_CS12		2
#define TCCR1B_WGM12	3
#define TCCR1B_WGM13	4
#define TCCR1B_ICES1	6
#define TCCR1B_ICNC1	7

#define TCNT1			*((volatile u16*)0x4C)
#define TCNT1L			*((volatile u8*)0x4C)
#define TCNT1H			*((volatile u8*)0x4D)

#define OCR1A			*((volatile u16*)0x4a)
#define OCR1AL			*((volatile u8*)0x4a)
#define OCR1AH			*((volatile u8*)0x4b)

#define OCR1BL			*((volatile u8*)0x48)
#define OCR1BH			*((volatile u8*)0x49)
#define OCR1B			*((volatile u16*)0x48)

#define ICR1H			*((volatile u8*)0x47)
#define ICR1L			*((volatile u8*)0x46)
#define ICR1			*((volatile u16*)0x46)

#define TIMSK_TOIE1		2		/*overflow interrupt enable*/
#define TIMSK_OCIE1B	3		/*output compare B match interrupt enable*/
#define TIMSK_OCIE1A	4		/*output compare A match interrupt enable*/
#define TIMSK_TICIE1	5		/*input capture interrupt enable*/

#define TIFR_TOV1		2		/*overflow flag*/
#define TIFR_OCF1B		3		/*output compare B match flag*/
#define TIFR_OCF1A		4		/*output compare A match flag*/
#define TIFR_ICF1		5 		/*input capture flag*/

#endif /* TIMER_REGISTER_H_ */
