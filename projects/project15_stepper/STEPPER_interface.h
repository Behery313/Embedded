/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	HAL				**********************/
/**************		SWC:	STEPPER			**********************/
/**************		Version:1.00			**********************/
/**************		Date:22/1/2022			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef STEPPER_H_
#define STEPPER_H_

#define STEPPER_CW			0
#define STEPPER_CCW			1
//Functions
// direction 'CW' for clockwise or 'CCW' for counter clockwise
//STEPPER_STEP 'STEPPER_HALF_STEP' or 'STEPPER_FULL_STEP'
void STEPPER_VoidRotate(u8 STEPPER_u8RotationDirection,f32 STEPPER_u8Angle);
#endif
