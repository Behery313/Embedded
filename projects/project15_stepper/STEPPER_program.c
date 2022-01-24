/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	HAL				**********************/
/**************		SWC:	STEPPER			**********************/
/**************		Version:1.00			**********************/
/**************		Date:22/1/2022			**********************/
/*****************************************************************/
/*****************************************************************/
#include"STD_TYPES.h"
#include "STEPPER_config.h"
#include "DIO_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_private.h"
#include"STEPPER_interface.h"
#include<util/delay.h>
//StrideAngle=5.625/64=0.0879 this is minimum step using halfstep 

//using full step ->step=2*0.0879=0.175degree =>number of steps taken for complete rotation =360/0.175=2048

//Frequency =100Hz :means stepper can do 100 steps per second meaning each step takes 1/100 second =10msec by trying we figured the max can be step each 2 msec instead of 10msec

//speed variation ratio 1/64  meaning we have 2 gears in the stepper smallone that we drive and big one that the small one drives if 
//small gear takes  0.175*64 to make full step in the large gear which is equivalent to 0.175degree in the large gear 

static u8 STEPPER_u8CoilIndex=0;
void STEPPER_VoidRotate(u8 STEPPER_u8RotationDirection,f32 STEPPER_u8Angle)
{
	u16 Local_u16StepperSteps=STEPPER_u8Angle/STEPPER_STEP;
	if(STEPPER_u8RotationDirection==STEPPER_CW)
	{
		for(u16 Local_u16Iterator=1;Local_u16Iterator<=Local_u16StepperSteps;Local_u16Iterator++)
		{	if(STEPPER_u8CoilIndex==0)
			{
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_u8LOW);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_u8HIGH);
				STEPPER_u8CoilIndex=1;
				_delay_ms(2);
			}
			else if(STEPPER_u8CoilIndex==1)
			{
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_PIN,DIO_u8LOW);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_u8HIGH);
				STEPPER_u8CoilIndex=2;
				_delay_ms(2);
			}
			else if(STEPPER_u8CoilIndex==2)
			{
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_u8LOW);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_u8HIGH);
				STEPPER_u8CoilIndex=3;
				_delay_ms(2);
			}
			else if(STEPPER_u8CoilIndex==3)
			{
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_u8LOW);
				STEPPER_u8CoilIndex=0;
				_delay_ms(2);
			}
		}
	}
	/*COUNTER CLOCKWISE*/
	else if (STEPPER_u8RotationDirection==STEPPER_CCW)
	{
		for(u16 Local_u16Iterator=1;Local_u16Iterator<=Local_u16StepperSteps;Local_u16Iterator++)
		{
			if(STEPPER_u8CoilIndex==0)
			{
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_u8LOW);
				STEPPER_u8CoilIndex=1;
				_delay_ms(2);
			}
			else if(STEPPER_u8CoilIndex==1)
			{
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_u8LOW);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_u8HIGH);
				STEPPER_u8CoilIndex=2;
				_delay_ms(2);
			}
			else if(STEPPER_u8CoilIndex==2)
			{
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_PIN,DIO_u8LOW);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_u8HIGH);
				STEPPER_u8CoilIndex=3;
				_delay_ms(2);
			}
			else if(STEPPER_u8CoilIndex==3)
			{
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_u8LOW);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_u8HIGH);
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_u8HIGH);
				STEPPER_u8CoilIndex=0;
				_delay_ms(2);
			}
		}
	}
}
