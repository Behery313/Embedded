/*
 * TIMER_interface.h
 *
 *  Created on: 28 Jan 2022
 *      Author: Yusuf
 */

/*ALL FUNCTIONS VERIFIED USING 10 SECS delay :)*/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/*timer is 8 bits so Register value is 0->255
  Copy_u8RegisterValue is Compare register value in case of CTC
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
#endif /* TIMER_INTERFACE_H_ */
