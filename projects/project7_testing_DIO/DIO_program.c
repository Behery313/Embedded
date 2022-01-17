/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	DIO				**********************/
/**************		Version:1.10			**********************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
/**************************************************************************/
/***************setting direction of PIN***********************************/
/**************************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8Port ,u8 Copy_u8Pin,u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState=0;//error state initially set to zero
	if (Copy_u8Pin<=DIO_u8PIN_7)
	{
		if(Copy_u8Direction==DIO_u8INPUT)//if direction is input clear bits
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA:
				CLR_BIT(DDRA_reg,Copy_u8Pin);
				break;
					
				case DIO_u8PORTB:
				CLR_BIT(DDRB_reg,Copy_u8Pin);
				break;
					
				case DIO_u8PORTC:
				CLR_BIT(DDRC_reg,Copy_u8Pin);
				break;
					
				case DIO_u8PORTD:
				CLR_BIT(DDRD_reg,Copy_u8Pin);
				break;
					
				default:
				Local_u8ErrorState=1;
				break;
			}
		}
		else if(Copy_u8Direction==DIO_u8OUTPUT)//if direction is output set bits to one
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA:
				SET_BIT(DDRA_reg,Copy_u8Pin);
				break;
				
				case DIO_u8PORTB:
				SET_BIT(DDRB_reg,Copy_u8Pin);
				break;
				
				case DIO_u8PORTC:
				SET_BIT(DDRC_reg,Copy_u8Pin);
				break;
				
				case DIO_u8PORTD:
				SET_BIT(DDRD_reg,Copy_u8Pin);
				break;
				
				default:
				Local_u8ErrorState=1;
				break;
				
			}
		}
		else//direction is neither input nor output return 0
		{
			Local_u8ErrorState=1;//error state set to 1
		}
	}
	else
	{
		Local_u8ErrorState=1;//error state set to 1
	}
	return Local_u8ErrorState;
}

/***************************************************************************/
/***************setting direction of PORT***********************************/
/***************************************************************************/

u8 DIO_u8SetPortDirection(u8 Copy_u8Port ,u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState=0;//error state initially zero
	if(Copy_u8Direction==DIO_u8INPUT)
	{
		switch (Copy_u8Port)
		{	
			case DIO_u8PORTA:
			DDRA_reg=0;
			break;
			
			case DIO_u8PORTB:
			DDRB_reg=0;
			break;
			
			case DIO_u8PORTC:
			DDRC_reg=0;
			break;
			
			case DIO_u8PORTD:
			DDRD_reg=0;
			break;
			
			default:
			Local_u8ErrorState=1;
			break;
		}
	}	
	else if(Copy_u8Direction==DIO_u8OUTPUT)
	{
		switch (Copy_u8Port)
		{	
			case DIO_u8PORTA:
			DDRA_reg=0xff;
			break;
			
			case DIO_u8PORTB:
			DDRB_reg=0xff;
			break;
			
			case DIO_u8PORTC:
			DDRC_reg=0xff;
			break;
			
			case DIO_u8PORTD:
			DDRD_reg=0xff;
			break;
			
			default:
			Local_u8ErrorState=1;
			break;
		}
	}
	else 		//incorrect direction
	{
		Local_u8ErrorState=1;	 //error incorrect input
	}	
	return Local_u8ErrorState;
}

/******************************************************************************/
/***********************Setting pin value**************************************/
/******************************************************************************/

u8 DIO_u8SetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=0;//error state initially zero
	if(Copy_u8Pin<=DIO_u8PIN_7)
	{
		if (Copy_u8Value)//if value is 1 SET the required PIN
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA:
				SET_BIT(PORTA_reg,Copy_u8Pin);
				break;
				
				case DIO_u8PORTB:
				SET_BIT(PORTB_reg,Copy_u8Pin);
				break;
				
				case DIO_u8PORTC:
				SET_BIT(PORTC_reg,Copy_u8Pin);
				break;
				
				case DIO_u8PORTD:
				SET_BIT(PORTD_reg,Copy_u8Pin);
				break;
			
				default:
				Local_u8ErrorState=1;
				break;
			}
		}
		else//value is 0 so we clear the bits
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA:
				CLR_BIT(PORTA_reg,Copy_u8Pin);
				break;
				
				case DIO_u8PORTB:
				CLR_BIT(PORTB_reg,Copy_u8Pin);
				break;
				
				case DIO_u8PORTC:
				CLR_BIT(PORTC_reg,Copy_u8Pin);
				break;
				
				case DIO_u8PORTD:
				CLR_BIT(PORTD_reg,Copy_u8Pin);
				break;
				
				default:
				Local_u8ErrorState=1;
				break;
			}
		}
	}
	else //incorrect input
	{
		Local_u8ErrorState=1;
	}	
	return Local_u8ErrorState;
}
/******************************************************************************/
/***********************Setting port value*************************************/
/******************************************************************************/

u8 DIO_u8SetPortValue(u8 Copy_u8Port ,u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=0;//error state initially zero
		switch(Copy_u8Port)
		{
			case DIO_u8PORTA:
			PORTA_reg=Copy_u8Value;
			break;
			
			case DIO_u8PORTB:
			PORTB_reg=Copy_u8Value;
			break;
			
			case DIO_u8PORTC:
			PORTC_reg=Copy_u8Value;
			break;
			
			case DIO_u8PORTD:
			PORTD_reg=Copy_u8Value;
			break;
			
			default:
			Local_u8ErrorState=1;
			break;
		}
	return Local_u8ErrorState;//incorrect input
}

/******************************************************************************/
/***********************Getting PIN value**************************************/
/******************************************************************************/

u8 DIO_u8GetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin,u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState=0;//error state initially zero
	if((Copy_pu8Value!=NULL)&&Copy_u8Pin<=DIO_u8PIN_7)//check if ptr not null and correct input pin
	{
		switch(Copy_u8Port)
		{
			case DIO_u8PORTA:
			*Copy_pu8Value=GET_BIT(PINA_reg,Copy_u8Pin);
			break;
			
			case DIO_u8PORTB:
			*Copy_pu8Value=GET_BIT(PINB_reg,Copy_u8Pin);
			break;
			
			case DIO_u8PORTC:
			*Copy_pu8Value=GET_BIT(PINC_reg,Copy_u8Pin);
			break;
			
			case DIO_u8PORTD:
			*Copy_pu8Value=GET_BIT(PIND_reg,Copy_u8Pin);
			break;
			
			default:
			Local_u8ErrorState=1;
			break;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}