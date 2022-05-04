/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	SPI				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define 	SPCR				*((volatile u8*)0X2D)/*SPI control register*/
#define 	SPCR_SPR0			0	/*Clock rate select0*/
#define 	SPCR_SPR1           1	/*Clock rate select1*/
#define 	SPCR_CPHA           2	/*Clock phase determine action on data at leading and trailing edges*/
#define 	SPCR_CPOL           3	/*Clock polarity determine the leading and trailing edges whether rising or falling*/
#define 	SPCR_MSTR           4	/*Determines either master or slave role this bit is cleared if the slave select is cleared*/
#define 	SPCR_DORD           5	/*Determines the order of the data transmitted either we transmit MSB or LSB first*/
#define 	SPCR_SPE            6	/*SPI enable */
#define 	SPCR_SPIE           7	/*SPI interrupt enable*/


#define 	SPSR				*((volatile u8*)0X2E)/*SPI status register*/
#define 	SPSR_SPI2X			0		
#define 	SPSR_WCOL			6
#define		SPSR_SPIF			7

#define 	SPDR				*((volatile u8*)0X2F)


#endif
