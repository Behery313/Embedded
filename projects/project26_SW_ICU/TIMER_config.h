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

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*options : 1) CTC_MODE
 			2)Normal_MODE
 			3)FastPWM_MODE*/
#define TIMER0_MODE		FastPWM_MODE
#define TIMER1_MODE		Normal_MODE
/*options : non PWM
   			1)Disconnected	:OC0 not used
  		    2)Toggle		:OC0 is toggled on compare match
  		    3)Clear			:OC0 is cleared on compare match
  		    4)Set			:OC0 is set on compare match

  		    FAST PWM
  		    1)Disconnected	:OC0 not used
  		    2)CompClearOC0_OverflowSetOC0: Clear OC0 on compare match event Set OC0 on overflow event
  		    3)CompSetOC0_OverflowClearOC0: Set OC0 on compare match event Clear OC0 on overflow event
  		    */
#define OC0_action	CompClearOC0_OverflowSetOC0
#define OC1A_action	Disconnected
#define OC1B_action	Disconnected
/*Clock source options:	1)OFF	:no clock source timer/counter is off
 * 						2)NONE	:no prescaling clock is same as System clock
 * 						3)DIV_8	:Prescaler =8
 * 						4)DIV_64
 * 						5)DIV_256
 * 						6)DIV_1024
 * 						7)EXT_T0_FALLING :external event is monitored each falling edge of the event is counted
 * 						8)EXT_T0_RISING  :external event is monitored each rising edge of the event is counted
 * 						*/
#define TIMER0_1ClkSource		DIV_8
#define TIMER1_1ClkSource		DIV_8

#define TIMEOUT_COUNTS			5000000
#endif /* TIMER_CONFIG_H_ */
