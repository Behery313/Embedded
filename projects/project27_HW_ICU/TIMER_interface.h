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

/*ALL FUNCTIONS VERIFIED USING 10 SECS delay :)*/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/*timer is 8 bits so Register value is 0->255
 * NOTE:use this function with FAST PWM
 * NOTE:this function doesn't stop it will continue counting
  Copy_u8RegisterValue is Compare register value in case of CTC and fast PWM
  Copy_u8RegisterValue is preload value in timer register in case of Normal mode */
void TIMER0_VoidInitAsync(u8 Copy_u8RegisterValue);//with interrupts

void TIMER0_VoidInitSync();//Must be called at least ONE TIME ONLY before wait sync
u8 TIMER0_u8WaitSync(u8 Copy_u8RegisterValue,u32 Copy_u32Counts);//without interrupts
/*return options:
1)OK				0
2)NOK				1
3)NULL_POINTER		2
4)TIMEOUT			3
5)BUSY_FUNC			4
*/
u8 TIMER0_u8SetCallBack(void (*Copy_pvNotif)(void));//used in every mode of operation

void TIMER0_SetPreload(u8 Copy_u8Preload);//used in Normal mode to set TCNT0 can't be used in any other mode

/*TIMER 1*/
void TIMER1_VoidInit(u16 Copy_u16TOP);//TOP value ignored in modes other than PWM
void TIMER1_VoidSetOCRValue(u16 Copy_u16RegisterValue);
u16 TIMER1_u16ReadTimerValue();
void TIMER1_VoidSetTimerValue(u16 Copy_u16TimerValue);

void Timer1ICU_VoidSetEdge(u8 Local_u8Edge);
#define ICU_Rising 		0
#define ICU_Falling 	1

u16 TIMER1ICU_u16GetICRValue();
#endif /* TIMER_INTERFACE_H_ */
