/*
 * USART_program.c
 *
 *  Created on: 2 Feb 2022
 *      Author: Yusuf
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_register.h"
#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"


void (*USART_SendingNotif)(void)=NULL;
void (*USART_ReceivingNotif)(void)=NULL;
void (*USART_TransmissionCompleteNotif)(void)=NULL;
u16 Global_u16SendingData;
u16* Global_pu16DataReceived=NULL;
void USART_VoidInit()
{
	/*Set the UCSRC*/
	UCSRC=ConcUCSRC;

	/*Set the bitrate(UBRR)*/
	UBRRL=UBRRLValue;
	UBRRH=UBRRHValue;

	/*set the character size bit in UCSRB*/
#if UCSZ2==0
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif UCSZ2==1
	SET_BIT(UCSRB,UCSRB_UCSZ2);
#else
#error "UCSZ error"
#endif

	/*double speed transmission State*/
#if DoubleTransmissionSpeed==Enabled

	SET_BIT(UCSRA,UCSRA_U2X);
	#elif DoubleTransmissionSpeed==Disabled
	CLR_BIT(UCSRA,UCSRA_U2X);
#else
#error 	"Invalid Double transmission speed state selection"
#endif
	//UBRRL=77;
	//UCSRC=0b10000110;
	//UCSRB=0b00011000;
}
u8 USART_VoidSendPolling(u16 Copy_u16Data)
{
	u8 Local_u8ErrorState=OK;
	u32 Local_u32TimeoutCounter=0;
	/*disable reciever*/
	CLR_BIT(UCSRB,UCSRB_RXEN);

	/*enable transmitter*/
	SET_BIT(UCSRB,UCSRB_TXEN);

	/*wait until the transmit buffer is empty*/
	while((GET_BIT(UCSRA,UCSRA_UDRE)==0)&&Local_u32TimeoutCounter<TimeoutCounts)
	{
		/*Increment Timeout Counter*/
		Local_u32TimeoutCounter++;
	}
	if(Local_u32TimeoutCounter==TimeoutCounts)
	{
		Local_u8ErrorState=TIMEOUT;
	}
	else
	{
		#if  DataBits==NineBits
		/*write the ninth bit before writing UDR*/
		if(GET_BIT(Copy_u16Data,8)==0)
		{
			CLR_BIT(UCSRB,UCSRB_TXB8);
		}
		else if(GET_BIT(Copy_u16Data,8)==1)
		{
			SET_BIT(UCSRB,UCSRB_TXB8);
		}
		#endif
		/*write data*/
		UDR=Copy_u16Data;
	}

	return Local_u8ErrorState;
}
u16 USART_u16RecievePolling()
{
	u16 Local_u16DataRec;
	/*disable transmitter*/
	CLR_BIT(UCSRB,UCSRB_TXEN);

	/*enable reciever*/
	SET_BIT(UCSRB,UCSRB_RXEN);


	/*wait for the unread data*/
	while((GET_BIT(UCSRA,UCSRA_RXC)==0))
	{
		/*Do nothing*/

	}


		#if  DataBits==NineBits
		/*read the ninth bit before reading UDR*/
	Local_u16DataRec=((GET_BIT(UCSRB,UCSRB_RXB8))<<8);
		#endif
		/*store the data*/
	Local_u16DataRec=UDR;

	return Local_u16DataRec;
}
u8 USART_VoidEnableINT(u8 Copy_u8INTNum)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8INTNum)
	{
		case RXInt:
			SET_BIT(UCSRB,UCSRB_RXCIE);
			break;
		case TXInt:
			SET_BIT(UCSRB,UCSRB_TXCIE);
			break;
		case DataRegEmptyInt:
			SET_BIT(UCSRB,UCSRB_UDRIE);
			break;
		default:
			Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
void USART_VoidSendINT(u16 Copy_u16Data,void (*pFuncSendISR)(void))
{
	/*disable reciever*/
	CLR_BIT(UCSRB,UCSRB_RXEN);

	/*enable transmitter*/
	SET_BIT(UCSRB,UCSRB_TXEN);

	/*initialize callback*/
	USART_SendingNotif=pFuncSendISR;

	/*Initialize Data*/
	Global_u16SendingData=Copy_u16Data;
}
u8 USART_u8RecieveINT(u16* pu16Data,void (*pFuncRecISR)(void))
{
	u8 Local_u8ErrorState=OK;
	if((pFuncRecISR==NULL)||(pu16Data==NULL))
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		/*disable transmitter*/
		CLR_BIT(UCSRB,UCSRB_TXEN);

		/*enable reciever*/
		SET_BIT(UCSRB,UCSRB_RXEN);

		/*initialize callback*/
		USART_ReceivingNotif=pFuncRecISR;

		/*Initialize Data*/
		Global_pu16DataReceived=pu16Data;
	}
	return Local_u8ErrorState;
}
u8 USART_SetTransmissionCompleteCallback(void(* Func)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Func!=NULL)
	{
		USART_TransmissionCompleteNotif=Func;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*Receive  complete interrupt*/
void __vector_13(void) __attribute__((signal));
void __vector_13()
{
	if (Global_pu16DataReceived!=NULL)
	{
		#if  DataBits==NineBits
			/*read the ninth bit before reading UDR*/
			*Global_pu16DataReceived=((GET_BIT(UCSRB,UCSRB_RXB8))<<8);
		#endif
		/*store the data*/
		*Global_pu16DataReceived=UDR;
		USART_ReceivingNotif();
	}
}

/*Transmit data register empty interrupt*/
void __vector_14(void) __attribute__((signal));
void __vector_14()
{

	#if  DataBits==NineBits
	/*write the ninth bit before writing UDR*/
	if(GET_BIT(Global_u16SendingData,8)==0)
	{
		CLR_BIT(UCSRB,UCSRB_TXB8);
	}
	else if(GET_BIT(Global_u16SendingData,8)==1)
	{
		SET_BIT(UCSRB,UCSRB_TXB8);
	}
	#endif
	/*write data*/
	UDR=Global_u16SendingData;
	/*callback*/
	USART_SendingNotif();
}
/*Transmit complete interrupt*/
void __vector_15(void) __attribute__((signal));
void __vector_15()
{
	USART_TransmissionCompleteNotif();
}
