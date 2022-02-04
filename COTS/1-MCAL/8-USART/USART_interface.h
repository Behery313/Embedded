/*
 * USART_interface.h
 *
 *  Created on: 2 Feb 2022
 *      Author: Yusuf
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_VoidInit();
u8 USART_VoidSendPolling(u16 Copy_u16Data);
u16 USART_u16RecievePolling();


/*INTNum*/
#define RXInt				0
#define TXInt				1
#define DataRegEmptyInt		2
u8 USART_VoidEnableINT(u8 Copy_u8INTNum);
void USART_VoidSendINT(u16 Copy_u16Data,void (*pFuncSendISR)(void));
u8 USART_u8RecieveINT(u16* pu16Data,void (*pFuncRecISR)(void));

#endif /* USART_INTERFACE_H_ */
