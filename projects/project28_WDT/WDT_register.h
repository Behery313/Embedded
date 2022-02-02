/*
 * WDT_register.h
 *
 *  Created on: 2 Feb 2022
 *      Author: Yusuf
 */

#ifndef WDT_REGISTER_H_
#define WDT_REGISTER_H_

#define WDTCR			*((volatile u8*)0X41)
#define WDTCR_WDP0		0
#define WDTCR_WDP1		1
#define WDTCR_WDP2		2
#define WDTCR_WDE		3
#define WDTCR_WDTOE		4


#endif /* WDT_REGISTER_H_ */
