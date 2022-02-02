/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	TIMER			**********************/
/**************		Version:1.2				**********************/
/**************		Date:31/1/2022			**********************/
/*****************************************************************/
/*****************************************************************/
/*V1.1: Added FAST PWM config
 *V1.2: Added Timer 1 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/*MODES*/
#define CTC_MODE						1
#define Normal_MODE						2
#define FastPWM_MODE					3
/*COM output pin behavior options*/
#define Disconnected					0
#define Toggle							16//1<<4
#define Clear	    					32//2<<4
#define Set								48//3<<4
#define COM_OutputModeBitMask			0b11001111

/*COM for fast PWM*/
#define CompClearOC0_OverflowSetOC0 	32//2<<4
#define CompSetOC0_OverflowClearOC0 	48//3<<4

/*Clock select options*/
#define OFF						0
#define NONE					1
#define DIV_8					2
#define DIV_64					3
#define DIV_256					4
#define DIV_1024				5
#define EXT_T0_FALLING			6
#define EXT_T0_RISING			7
#define CLK_SourceBitMask		0b11111000

#define IDLE					1
#define BUSY					0
#endif /* TIMER_PRIVATE_H_ */
