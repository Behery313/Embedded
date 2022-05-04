/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	SPI				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#define DATA_ORDER			MSBtoLSB	/*which bits are transmitted first */
/*OPTIONS:	1)MSBtoLSB
  			2)LSBtoMSB*/

#define CLK_POLARITY		LeadRise	/*polarity of the clock which defines whether the leading edge is rising or falling edges */
/*OPTIONS:	1)LeadRise
  			2)LeadFall*/

#define CLK_PHASE			LeadSample	/*Determine the action done on the data with the leading and trailing edge whether to sample or setup*/
/*OPTIONS:	1)LeadSample
  			2)LeadSetup*/

#define PRESCALER			DIV_4 		/*Clock rate choice */
/*OPTIONS :	1)DIV_4
 * 			2)DIV_16
 * 			3)DIV_64
 * 			4)DIV_128
 * 			5)DIV_2
 * 			6)DIV_8
 * 			7)DIV_32
 * 			8)DIV_64
 * */
#define TIMEOUT_COUNTS		5000000

#endif
