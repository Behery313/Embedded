/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	SPI				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_VoidMasterInit();/*initialize as master based on the prebuilt configurations*/

void SPI_VoidSlaveInit();/*initialize as slave based on the prebuilt configurations*/

u8 	 SPI_u8TransceiveAsync(u8 Copy_u8TransmittedData,u8* pu8_RecievedData,void (*pVoidCallBackFunc)(void));
/*sending data using interrupt MUST ENABLE SREG(GIE_ENABLE function)*/
/*COMMENT:this function doesn't disable the interrupt after transmission if shutdown is required call the [SPI_VoidDisableTransferCompleteINT()]*/

u8 	 SPI_u8TransceiveSync(u8 Copy_u8TransmittedData,u8* pu8_RecievedData);/*sending data using polling*/

void SPI_VoidEnableTransferCompleteINT();/*enable transfer complete interrupt*/

void SPI_VoidDisableTransferCompleteINT();/*Disable transfer complete interrupt*/

#endif
