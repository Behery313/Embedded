/*
 * USART_register.h
 *
 *  Created on: 2 Feb 2022
 *      Author: Yusuf
 */

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

#define UDR					*((volatile u8*) 0X2C)		/*USART I/O Data Register*/

#define UCSRA				*((volatile u8*) 0X2B)		/*USART Control and Status Register A*/
#define UCSRA_MPCM			0
#define UCSRA_U2X			1
#define UCSRA_PE			2
#define UCSRA_DOR			3
#define UCSRA_FE			4
#define UCSRA_UDRE			5
#define UCSRA_TXC			6
#define UCSRA_RXC			7

#define UCSRB				*((volatile u8*) 0X2A)		/*USART Control and Status Register B*/
#define UCSRB_TXB8			0
#define UCSRB_RXB8			1
#define UCSRB_UCSZ2			2
#define UCSRB_TXEN			3
#define UCSRB_RXEN			4
#define UCSRB_UDRIE			5
#define UCSRB_TXCIE			6
#define UCSRB_RXCIE			7

#define UCSRC				*((volatile u8*) 0X40)		/*USART Control and Status Register C*/
#define UCSRC_UCPOL			0
#define UCSRC_UCSZ0			1
#define UCRSC_UCSZ1			2
#define UCSRC_USBS			3
#define UCSRC_UPM0			4
#define UCSRC_UPM1			5
#define UCSRC_UMSEL			6
#define UCSRC_URSEL			7

#define UBRRH				*((volatile u8*) 0X40)		/*USART Baud Rate Registers*/
#define UBRRL				*((volatile u8*) 0X29)		/*USART Baud Rate Registers*/

#endif /* USART_REGISTER_H_ */
