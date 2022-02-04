/*
 * USART_private.h
 *
 *  Created on: 2 Feb 2022
 *      Author: Yusuf
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define FiveBits	1
#define SixBits		2
#define SevenBits	3
#define EightBits	4
#define NineBits	5

#define OneStopBit	1
#define TwoStopBit	2

#define NoParity	1
#define EvenParity	2
#define OddParity	3

#define SYNC		1
#define ASYNC		2

#define Disabled	1
#define Enabled		2

#define TRANSMITTER	1
#define RECIEVER	2
/*check if double transmission speed is enabled in Synchronous mode*/
#if (DoubleTransmissionSpeed==Enabled) && (SynchronizationMode==SYNC)
#error"Double transmission speed incompatible with Sync mode"
#endif
/************************Define and concatenate UCSRC register******************************/
/* Concatenate MACRO*/
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)				CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0

/*Defining Databits in register*/
#if DataBits==FiveBits

#define UCSZ0		0
#define UCSZ1		0
#define UCSZ2		0

#elif DataBits==SixBits

#define UCSZ0		1
#define UCSZ1		0
#define UCSZ2		0

#elif DataBits==SevenBitsBits

#define UCSZ0		0
#define UCSZ1		1
#define UCSZ2		0

#elif DataBits==EightBits

#define UCSZ0		1
#define UCSZ1		1
#define UCSZ2		0

#elif DataBits==NineBits

#define UCSZ0		1
#define UCSZ1		1
#define UCSZ2		1

#else
#error "Invalid Data bits"
#endif

/*Define synchronization bit*/
#if SynchronizationMode==SYNC
#define UMSEL		1

#elif SynchronizationMode==ASYNC
#define UMSEL		0

#else
#error "Invalid synchronization mode"
#endif

/*Define Parity bits*/
#if Parity==NoParity
#define UPM0	0
#define UPM1	0
#elif Parity==EvenParity
#define UPM0	0
#define UPM1	1
#elif Parity==OddParity
#define UPM0	1
#define UPM1	1
#else
#error "Invalid parity selection"
#endif

/*Define StopBits*/
#if StopBits==OneStopBit
#define USBS	0

#elif StopBits==TwoStopBit
#define USBS	1

#else
#error "Invalid Stop Bits selection"
#endif

/*Define Clock Polarity for synchronous mode*/
#if SynchronizationMode==ASYNC
#define UCPOL	0
#elif SynchronizationMode==SYNC
#if ClockPolarity==RisingEdgeTransmitFallingEdgeRecieve
#define UCPOL 	0
#elif ClockPolarity==FallingEdgeTransmitRisingEdgeRecieve
#define UCPOL	1
#else
#error "Invalid Clock Polarity selection"
#endif
#else
#error "Invalid synchronization selection"
#endif


/*Calculating the UBRR*/
#if SynchronizationMode==ASYNC
	#if DoubleTransmissionSpeed==Enabled
		/*if double transmission enabled in ASYNC*/
		#define GET_UBRR(Freq,Baud)		(Freq/(8*Baud))-1

	#elif DoubleTransmissionSpeed==Disabled
		/*if double transmission disabled in ASYNC*/
		#define GET_UBRR(Freq,Baud)		(u32)((u32)Freq/(16UL*(u32)Baud))-1UL
	#else
		#error"Invalid Double transmission speed"
	#endif
#elif SynchronizationMode==SYNC
	#define GET_UBRR(Freq,Baud)		(Freq/(2*Baud))-1
#else
	#error "Invalid Synchronization mode"
#endif


/*Define Concatenation of UCSRC*/
#define ConcUCSRC		CONC(1,UMSEL,UPM1,UPM0,USBS,UCSZ1,UCSZ0,UCPOL)

/*Calculate the required UBBR*/
#define UBRR			GET_UBRR(SystemFrequency,BaudRate)

/*storing 8 LSBs in the UBBRL*/
#define UBRRLValue		(u8)UBRR

/*storing 4 MSBs in the UBBRH*/
#define UBRR_MSBs		(u8)(UBRR>>8)

/*Define UBRRHValue while clearing the 8th bit (URSEL) */
#define UBRRHValue		((u8)(~(1<<7))&(u8)UBRR_MSBs)
#endif /* USART_PRIVATE_H_ */
