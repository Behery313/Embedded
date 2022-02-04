/*
 * USART_config.h
 *
 *  Created on: 2 Feb 2022
 *      Author: Yusuf
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


/*Number of data bits used*/
/*OPTIONS:	1)FiveBits
 * 			2)SixBits
 * 			3)SevenBits
 * 			4)EightBits
 * 			5)NineBits*/
#define DataBits					EightBits

/*Number of Stop Bits used*/
/*OPTIONS:"OneStopBit" or "TwoStopBit"*/
#define StopBits					OneStopBit

/*Parity used*/
/*OPTIONS: "NoParity" or "EvenParity" or "OddParity"*/
#define Parity						NoParity

/*Synchronization used*/
/*OPTIONS:"ASYNC" or "SYNC"*/
#define SynchronizationMode			ASYNC

/*Double USART Transmission Speed*/
/*OPTIONS:"Disabled" or "Enabled"*/
#define DoubleTransmissionSpeed		Disabled

/*System frequency*/
#define SystemFrequency				12000000

/*Required BaudRate*/
#define BaudRate					9600

/*Clock polarity*/
/*OPTIONS:	1)RisingEdgeTransmitFallingEdgeRecieve
 * 			2)FallingEdgeTransmitRisingEdgeRecieve*/
#define ClockPolarity				RisingEdgeTransmitFallingEdgeRecieve

/*Interrupt selection*/
#define RXCompleteInterrupt			Disabled
#define TXCompleteInterrupt			Disabled
#define DataRegisterEmptyInterrupt	Disabled

#define TimeoutCounts				5000000
#endif /* USART_CONFIG_H_ */
