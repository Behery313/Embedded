#include "BIT_MATH.h"
#include "typedefs.h"

#include "DIO_Reg.h"
#include "DIO_Int.h"

/*****************Interfaces*******************/
/****************DIO_SetPinDir*****************/
/*Set Pin Direction*/
void DIO_SetPinDir(u8 Port_ID, u8 Pin_no, u8 Pin_Dir)
{
	/*Check the Port ID and Pin value are valid*/
	if((Port_ID <= PORTD)&&(Pin_no <= PIN_7))
	{
		/*The ID is valid check the Pin Direction*/
		if(Pin_Dir == INPUT)
		{
			/*Configure Pin as Input*/
			switch(Port_ID)
			{
			case PORTA:

				/*Configure the required Pin in PORTA*/
				/* as input in PORTA*/
				/*Add your code here*/
				CLR_BIT(DDRA_REG,Pin_no);
				break;
			case PORTB:
				/*Configure the required Pin in PORTA*/
				/* as input in PORTB*/
				/*Add your code here*/
				CLR_BIT(DDRB_REG,Pin_no);
				break;
			case PORTC:
				/*Configure the required Pin in PORTA*/
				/* as input in PORTC*/
				/*Add your code here*/
				CLR_BIT(DDRC_REG,Pin_no);
				break;
			case PORTD:
				/*Configure the required Pin in PORTA*/
				/* as input in PORTD*/
				/*Add your code here*/
				CLR_BIT(DDRD_REG,Pin_no);
				break;
			}

		}
		else if(Pin_Dir == OUTPUT)
		{
			/*Configure Pin as Output*/
			/*Configure Pin as Input*/
			switch(Port_ID)
			{
			case PORTA:
				/*Configure the required Pin in PORTA*/
				/* as output in PORTA*/
				/*Add your code here*/
				SET_BIT(DDRA_REG,Pin_no);
				break;
			case PORTB:
				/*Configure the required Pin in PORTA*/
				/* as output in PORTB*/
				/*Add your code here*/
				SET_BIT(DDRB_REG,Pin_no);
				break;
			case PORTC:
				/*Configure the required Pin in PORTA*/
				/* as output in PORTC*/
				/*Add your code here*/
				SET_BIT(DDRC_REG,Pin_no);
				break;
			case PORTD:
				/*Configure the required Pin in PORTA*/
				/* as output in PORTD*/
				/*Add your code here*/
				SET_BIT(DDRD_REG,Pin_no);
				break;
			}
		}
		else
		{
			/*Do nothing wrong Direction*/
		}
	}
	else
	{
		/*Do nothing Wrong Port ID or Pin no*/
	}
}
/*************End of DIO_SetPinDir**************/

/****************DIO_SetPinVal******************/
/*Set Pin Value*/
void DIO_SetPinVal(u8 Port_ID, u8 Pin_no, u8 Pin_Val)
{
	/*Check the Port ID and Pin value are valid*/
	if((Port_ID <= PORTD)&&(Pin_no <= PIN_7))
	{
		/*Set the Pin value*/
		if(Pin_Val==LOW)
		{
			/*Set The corresponding Pin value to Low*/
			switch(Port_ID)
			{
			case PORTA:
				/*Set the required pin in PortA to low*/
				/*Add your code here*/
				CLR_BIT(PORTA_REG,Pin_no);
				break;
			case PORTB:
				/*Set the required pin in PortB to low*/
				/*Add your code here*/
				CLR_BIT(PORTB_REG,Pin_no);
				break;
			case PORTC:
				/*Set the required pin in PortC to low*/
				/*Add your code here*/
				CLR_BIT(PORTC_REG,Pin_no);
				break;
			case PORTD:
				/*Set the required pin in PortD to low*/
				/*Add your code here*/
				CLR_BIT(PORTD_REG,Pin_no);
				break;
			}
		}
		else if(Pin_Val==HIGH)
		{
			/*Set The corresponding Pin value to High*/
			switch(Port_ID)
			{
			case PORTA:
				/*Set the required pin in PortA to high*/
				/*Add your code here*/
				SET_BIT(PORTA_REG,Pin_no);
				break;
			case PORTB:
				/*Set the required pin in PortB to high*/
				/*Add your code here*/
				SET_BIT(PORTB_REG,Pin_no);
				break;
			case PORTC:
				/*Set the required pin in PortC to high*/
				/*Add your code here*/
				SET_BIT(PORTC_REG,Pin_no);
				break;
			case PORTD:
				/*Set the required pin in PortD to high*/
				/*Add your code here*/
				SET_BIT(PORTD_REG,Pin_no);
				break;
			}
		}
		else
		{
			/* DO Nothing Invalid pin value*/
		}
	}
	else
	{
		/*Do nothing wrong Port ID or Pin no*/
	}
}
/**************End of DIO_SetPinVal***************/

/*****************DIO_GetPinVal*******************/
u8 DIO_GetPinVal(u8 Port_ID, u8 Pin_no)
{
	u8 pin_value;
	/*Local variable to return the pin value*/
	/*Set the return value to 0xFF in case */
	/*of wrong PORT or PIN*/
	/*Add your code here*/
	/*Check the Port ID and Pin value are valid*/
	
	if((Port_ID <= PORTD)&&(Pin_no <= PIN_7))
	{

		switch(Port_ID)
		{
		case PORTA:
			/*Get the Pin value from Port A*/
			/*Add your code here*/
			pin_value = GET_BIT(PINA_REG,Pin_no);
			break;
		case PORTB:
			/*Get the Pin value from Port B*/
			/*Add your code here*/
			pin_value = GET_BIT(PINB_REG,Pin_no);
			break;
		case PORTC:
			/*Get the Pin value from Port C*/
			/*Add your code here*/
			pin_value = GET_BIT(PINC_REG,Pin_no);
			break;
		case PORTD:
			/*Get the Pin value from Port D*/
			/*Add your code here*/
			pin_value = GET_BIT(PIND_REG,Pin_no);
			break;
		}
	}
	else
	{
		/*Do nothing wrong Port ID or Pin no*/
	}
/*Reurn the Pin value*/
return pin_value;
}
/**************End of DIO_GetPinVal***************/

/*****************DIO_SetPortDir******************/
void DIO_SetPortDir(u8 Port_ID, u8 Port_Dir)
{
	/*Check the Port ID and Pin value are valid*/
	if(Port_ID <= PORTD)
	{
		switch(Port_ID)
		{
		case PORTA:
			/*Set whole PortA direction*/
			/*Add your code here*/
			DDRA_REG=Port_Dir;
			break;
		case PORTB:
			/*Set whole PortB direction*/
			/*Add your code here*/
			DDRB_REG=Port_Dir;
			break;
		case PORTC:
			/*Set whole PortC direction*/
			/*Add your code here*/
			DDRC_REG=Port_Dir;
			break;
		case PORTD:
			/*Set whole PortD direction*/
			/*Add your code here*/
			DDRD_REG=Port_Dir;
			break;
		}
	}
	else
	{
		/*Do nothing wrong Port ID*/
	}
}
/**************End of DIO_SetPortDir************/

/*****************DIO_SetPortVal******************/
void DIO_SetPortVal(u8 Port_ID, u8 Port_val)
{
	/*Check the Port ID and Pin value are valid*/
	if((Port_ID <= PORTD)/*&&(Port_val == (u8)0||Port_val == (u8)1)*/)
	{
		switch(Port_ID)
		{
		case PORTA:
			/*Set whole PortA value*/
			/*Add your code here*/
			PORTA_REG=Port_val;
			break;
		case PORTB:
			/*Set whole PortB value*/
			/*Add your code here*/
			PORTB_REG=Port_val;
			break;
		case PORTC:
			/*Set whole PortC value*/
			/*Add your code here*/
			PORTC_REG=Port_val;
			break;
		case PORTD:
			/*Set whole PortD value*/
			/*Add your code here*/
			PORTD_REG=Port_val;
			break;
		}
	}
	else
	{
		/*Do nothing wrong Port ID*/
	}
}
/**************End of DIO_SetPortVal************/
