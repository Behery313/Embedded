/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	SPI				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define MSBtoLSB		1
#define LSBtoMSB		2

#define LeadRise		1
#define LeadFall		2

#define LeadSample		1
#define LeadSetup		2

#define CLK_MASK		0b11111100
#define	DIV_4			0
#define DIV_16			1
#define DIV_64			2
#define DIV_128			3
#define DIV_2			4
#define DIV_8			5
#define DIV_32			6
//#define DIV_64			7

#endif
