/*
 * TmpSensor_config.h
 *
 *  Created on: 26 Jan 2022
 *      Author: Yusuf
 */

#ifndef TMPSENSOR_CONFIG_H_
#define TMPSENSOR_CONFIG_H_

//options
/*MUX channels*/
/*//Single ended
1)SE_ADC0
2)SE_ADC1
3)SE_ADC2
4)SE_ADC3
5)SE_ADC4
6)SE_ADC5
7)SE_ADC6
8)SE_ADC7
9)SE_VBG					//input is 1.22V from Microcontroller
10)SE_GND
//Differential
11)PosADC0_NegADC0_10x
12)PosADC1_NegADC0_10x
13)PosADC0_NegADC0_200x
14)PosADC1_NegADC0_200x
15)PosADC2_NegADC2_10x
16)PosADC3_NegADC2_10x
17)PosADC2_NegADC2_200x
18)PosADC3_NegADC2_200x
19)PosADC0_NegADC1_1x
20)PosADC1_NegADC1_1x
21)PosADC2_NegADC1_1x
22)PosADC3_NegADC1_1x
23)PosADC4_NegADC1_1x
24)PosADC5_NegADC1_1x
25)PosADC6_NegADC1_1x
26)PosADC7_NegADC1_1x
27)PosADC0_NegADC2_1x
28)PosADC1_NegADC2_1x
29)PosADC2_NegADC2_1x
30)PosADC3_NegADC2_1x
31)PosADC4_NegADC2_1x
32)PosADC5_NegADC2_1x
*/
#define TempSensor_Channel SE_ADC0
//options:1)TEN_BITS
//		  2)EIGHT_BITS
#define BITS				EIGHT_BITS
#endif /* TMPSENSOR_CONFIG_H_ */
