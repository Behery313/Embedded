/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	SPI				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_register.h"

#include "SPI_config.h"
#include "SPI_private.h"

/*SPI State*/
u8 Global_u8SPIState=IDLE;

/*Callback function*/
void (*SPI_CallbackFunc)(void)=NULL;

/*Pointer to received data*/
u8 * Global_pu8DataRec=NULL;

void SPI_VoidMasterInit()
{

	/*master select*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*data order*/
	#if   DATA_ORDER==MSBtoLSB
		CLR_BIT(SPCR,SPCR_DORD);
	#elif DATA_ORDER==LSBtoMSB
		SET_BIT(SPCR,SPCR_DORD);
	#else
		#error "Invalid DATA ORDER selection"
	#endif

	/*clock polarity*/
	#if CLK_POLARITY==LeadRise
		CLR_BIT(SPCR,SPCR_CPOL);
	#elif CLK_POLARITY==LeadFall
		SET_BIT(SPCR,SPCR_CPOL);
	#else
		#error "Invalid Clock polarity selection"
	#endif

	/*clock phase*/
	#if CLK_PHASE==LeadSample
		CLR_BIT(SPCR,SPCR_CPHA);
	#elif CLK_PHASE==LeadSetup
		SET_BIT(SPCR,SPCR_CPHA);
	#else
		#error "Invalid Clock phase selection"
	#endif

	/*choose prescaler*/
	/*clear the prescaler bits*/
	SPCR&=CLK_MASK;

	/*set the required prescaler*/
	#if (PRESCALER<DIV_4)&&(PRESCALER>DIV_64)
		#error "Invalid prescaler selection"
	#endif
	if (PRESCALER<DIV_2)
	SPCR|=PRESCALER;

	else
	{
		SPCR|=PRESCALER-0b100;
		/*set the SPI2X*/
		SET_BIT(SPSR,SPSR_SPI2X);
	}
	/*enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_VoidSlaveInit()
{
	/*Slave select*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*data order*/
	#if   DATA_ORDER==MSBtoLSB
		CLR_BIT(SPCR,SPCR_DORD);
	#elif DATA_ORDER==LSBtoMSB
		SET_BIT(SPCR,SPCR_DORD);
	#else
		#error "Invalid DATA ORDER selection"
	#endif

	/*clock polarity*/
	#if CLK_POLARITY==LeadRise
		CLR_BIT(SPCR,SPCR_CPOL);
	#elif CLK_POLARITY==LeadFall
		SET_BIT(SPCR,SPCR_CPOL);
	#else
		#error "Invalid Clock polarity selection"
	#endif

	/*clock phase*/
	#if CLK_PHASE==LeadSample
		CLR_BIT(SPCR,SPCR_CPHA);
	#elif CLK_PHASE==LeadSetup
		SET_BIT(SPCR,SPCR_CPHA);
	#else
		#error "Invalid Clock phase selection"
	#endif

	/*choose prescaler*/
	/*clear the prescaler bits*/
	SPCR&=CLK_MASK;

	/*set the required prescaler*/
	#if (PRESCALER<DIV_4)&&(PRESCALER>DIV_64)
		#error "Invalid prescaler selection"
	#endif
	if (PRESCALER<DIV_2)
	SPCR|=PRESCALER;

	else
	{
		SPCR|=PRESCALER-0b100;
		/*set the SPI2X*/
		SET_BIT(SPSR,SPSR_SPI2X);
	}
	/*enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);
}

u8 	 SPI_u8TransceiveSync(u8 Copy_u8TransmittedData,u8* pu8_RecievedData)
{
	u8 Local_u8ErrorState=OK;
	if(Global_u8SPIState==BUSY)
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	else
	{
		u32 Local_u32TimeoutCounter=0;
		/*disable inerrupt*/
		CLR_BIT(SPCR,SPCR_SPIE);

		/*write to SPDR*/
		SPDR=Copy_u8TransmittedData;

		/*busy waiting until flag is set (transmission complete)*/
		while((GET_BIT(SPSR,SPSR_SPIF)==0)&&(Local_u32TimeoutCounter<TIMEOUT_COUNTS))
		{
			/*increment time out counter*/
			Local_u32TimeoutCounter++;
		}
		/*check for timeout*/
		if(Local_u32TimeoutCounter==TIMEOUT_COUNTS)
		{
			Local_u8ErrorState=TIMEOUT;
		}
		else
		{
			/*read the SPDR register even in case of transmitting to clear the SPIF flag*/
			*pu8_RecievedData=SPDR;
		}
		/*reset state of SPI to IDLE*/
		Global_u8SPIState=IDLE;
	}
	return Local_u8ErrorState;
}
u8 	 SPI_u8TransceiveAsync(u8 Copy_u8TransmittedData,u8* pu8_RecievedData,void (*pVoidCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Global_u8SPIState==BUSY)
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	else
	{
		/*check on null pointer*/
		if ((pu8_RecievedData==NULL)||(pVoidCallBackFunc==NULL))
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			/*Make SPI state BUSY*/
			Global_u8SPIState=BUSY;

			/*copy pointers to the global pointers to be used in the ISR*/
			Global_pu8DataRec=pu8_RecievedData;
			SPI_CallbackFunc=pVoidCallBackFunc;

			/*enable interrupt*/
			SET_BIT(SPCR,SPCR_SPIE);

			/*write data to SPDR*/
			SPDR=Copy_u8TransmittedData;
		}

	}
	return Local_u8ErrorState;
}

void SPI_VoidDisableTransferCompleteINT()
{
	CLR_BIT(SPCR,SPCR_SPIE);
}
void SPI_VoidEnableTransferCompleteINT()
{
	SET_BIT(SPCR,SPCR_SPIE);
}
/*ISR for SPI transfer complete*/
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{

	/*Change SPI state to IDLE*/
	Global_u8SPIState=IDLE;

	/*read received data*/
	*Global_pu8DataRec=SPDR;

	/*call the callback function*/
	SPI_CallbackFunc();

}
