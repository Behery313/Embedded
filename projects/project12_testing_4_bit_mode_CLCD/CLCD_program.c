/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	HAL				**********************/
/**************		SWC:	CLCD			**********************/
/**************		Version:1.00			**********************/
/**************		Date:17/1/2022			**********************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

static u8 Global_u8SendDataCounter=0;//counter to each time send data is called to know when to write to the second row

/*Send data counter is number of times that function send data was called .The number
 *specifies the position of the next character to be written on the first row */

/*send command in 4 bit mode operate on 4 bits only when using it send 4 bits ONLY*/
void CLCD_VoidSendCommand(u8 Copy_u8Command)
{
	/**********SET RS to 0 for command*************/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8LOW);
	
	/**********SET RW to 0 to write****************/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8LOW);
	
	/**********SET DATA Value**********************/

	/*8 BIT OPERATION*/
#if CLCD_WORKING_MODE==PRE_EIGHT_BIT_MODE
	DIO_u8SetPortValue(CLCD_8_BIT_DATA_PORT,Copy_u8Command);

	/*4 BIT OPERATION*/
#elif CLCD_WORKING_MODE==PRE_FOUR_BIT_MODE

	/*send the 4 bits received*/
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_0,GET_BIT(Copy_u8Command,0));
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_1,GET_BIT(Copy_u8Command,1));
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_2,GET_BIT(Copy_u8Command,2));
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_3,GET_BIT(Copy_u8Command,3));
//CHECK/*****************************************************************************************************************************/
//CHECK	/*send enable pulse*/
//CHECK DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8HIGH);//set enable pin to high for the microcontroller on the lcd to read the data sent to it
//CHECK		_delay_ms(2);//max delay value specified by the initializations after sending the command
//CHECK		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8LOW);
	/*****************************************************************************************************************************/
	/*send the 4 LSBs*/
//	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_0,GET_BIT(Copy_u8Command,0));
//	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_1,GET_BIT(Copy_u8Command,1));
//	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_2,GET_BIT(Copy_u8Command,2));
//	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_3,GET_BIT(Copy_u8Command,3));
#endif
	
	/**********Send enable pulse********************/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8HIGH);//set enable pin to high for the microcontroller on the lcd to read the data sent to it
	_delay_ms(2);//max delay value specified by the initializations after sending the command
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8LOW);
}

/*send data can work in 4 bit mode while sending 8 bit data*/
void CLCD_VoidSendData(u8 Copy_u8Data)
{
	/*check if the function is called 16 times the first row is completely filled then write to the second row*/
	if(Global_u8SendDataCounter==MAX_COLUMNS)
	{
		CLCD_VoidGoToXY(1,0);
	}
	/**********SET RS to 1 for DATA****************/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8HIGH);
	/**********SET RW to 0 to write****************/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8LOW);
	/**********SET DATA Value**********************/
	/*8 BIT OPERATION*/
#if CLCD_WORKING_MODE==PRE_EIGHT_BIT_MODE
	DIO_u8SetPortValue(CLCD_8_BIT_DATA_PORT,Copy_u8Data);

	/*4 BIT OPERATION*/
	#elif CLCD_WORKING_MODE==PRE_FOUR_BIT_MODE
	/*send the 4 MSBs */
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_0,GET_BIT(Copy_u8Data,4));
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_1,GET_BIT(Copy_u8Data,5));
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_2,GET_BIT(Copy_u8Data,6));
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_3,GET_BIT(Copy_u8Data,7));
//CHECK*/*****************************************************************************************************************************/
//CHECK	/*send enable pulse*/
/*CHECK*/ DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8HIGH);//set enable pin to high for the microcontroller on the lcd to read the data sent to it
/*CHECK*/		_delay_ms(2);//max delay value specified by the initializations after sending the command
/*CHECK*/	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8LOW);
	/*****************************************************************************************************************************/
	/*send the 4 LSBs*/
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_0,GET_BIT(Copy_u8Data,0));
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_1,GET_BIT(Copy_u8Data,1));
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_2,GET_BIT(Copy_u8Data,2));
	DIO_u8SetPinValue(CLCD_4_BIT_DATA_PORT,CLCD_4_BIT_DATA_PIN_3,GET_BIT(Copy_u8Data,3));
#endif
	/**********Send enable pulse********************/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8HIGH);//set enable pin to high for the microcontroller on the lcd to read the data sent to it
	_delay_ms(2);//delay value specified by the datasheet
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8LOW);

	/*increment the static variable so if it reaches 15*/
		Global_u8SendDataCounter++;
}
void CLCD_VoidInit(void)
{
	/*8 bit initialization*/
	/*wait for 30 ms from power on*/
	_delay_ms(30);
#if CLCD_WORKING_MODE==PRE_EIGHT_BIT_MODE
	/*function set : set the DATA port to specified value from datasheet */
	/*N:number of lines used in the LCD '0' for 1 line and '1' for 2 lines*/
	/*F:charachter size either 5x8 or 5x11'0' for 5x8 and '1' for 5x11*/
	/*note that charachter is displayed in either 5x10 or 5x7 the extra row is for the cursor*/
	//while(1)
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,1);
	//_delay_ms(1000);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN_0,0);
	CLCD_VoidSendCommand(0b00111000);//use 5x8 and 2 lines

	/*Display ON/OFF control:control whether to turn on or off the display*/
	/*D:display on or off to save power '0' for off '1' for on*/
	/*C:cursor on or off '0' for off '1' for on*/
	/*B:cursor blinks or not '0' for nonblinking '1' for blinking*/
	CLCD_VoidSendCommand(0b00001101);

	/*clear display*/
	CLCD_VoidSendCommand(0b00000001);
#elif CLCD_WORKING_MODE==PRE_FOUR_BIT_MODE
	/*function set : set the DATA port to specified value from datasheet */
	/*N:number of lines used in the LCD '0' for 1 line and '1' for 2 lines*/
	/*F:charachter size either 5x8 or 5x11 '0' for 5x8 and '1' for 5x11*/
	/*note that character is displayed in either 5x10 or 5x7 the extra row is for the cursor*/
	CLCD_VoidSendCommand(0b0010);//use 5x8 and 2 lines
	CLCD_VoidSendCommand(0b0010);
	CLCD_VoidSendCommand(0b1000);

	/*Display ON/OFF control:control whether to turn on or off the display*/
	/*D:display on or off to save power '0' for off '1' for on*/
	/*C:cursor on or off '0' for off '1' for on*/
	/*B:cursor blinks or not '0' for nonblinking '1' for blinking*/
	CLCD_VoidSendCommand(0b0000);
	CLCD_VoidSendCommand(0b1101);
	
	/*clear display*/
	CLCD_VoidSendCommand(0b0000);
	CLCD_VoidSendCommand(0b0001);
#endif
	
}
void CLCD_VoidSendString(const char * CLCD_pcString)
{

	for(u8 i=0;*(CLCD_pcString+i)!='\0';i++)
	{
		CLCD_VoidSendData(CLCD_pcString[i]);
	}
}
void CLCD_VoidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	/* we have DDRAM(display data ram used to store values which are shown on the LCD) 2 rows with visible window of 16 columns */
	/*it starts from address 0 till address 40 on the first row the second row starts from address 0x40*/
	/*we notice that if row =0 address = Y and if X=1 Address = 0x40+Y*/
	u8 Local_u8Address;
	/*location in first line*/
	if(Copy_u8XPos==0)
	{
		Local_u8Address=Copy_u8YPos;
	}
	/*location 2nd line*/
	else if(Copy_u8XPos==1)
	{
		Local_u8Address=Copy_u8YPos+0x40;
	}
	/*setting address and 7th bit to one*/
	/**/
#if CLCD_WORKING_MODE==PRE_EIGHT_BIT_MODE
	CLCD_VoidSendCommand(Local_u8Address|1<<7);

#elif CLCD_WORKING_MODE==PRE_FOUR_BIT_MODE
	/*send the 4 MSBs. Make the MSBs to make them LSBs as function copies the 4 LSBs*/
	CLCD_VoidSendCommand((Local_u8Address|1<<7)>>4);
	/*send the 4 LSBs we don't care about the value of the 4MSBs as function only operates on the LSBs so we dont need to set MSBs to 0*/
	/*we don't need to set the 6th bit to high as we are sending the LSBs and we don't care about the MSBs*/
	CLCD_VoidSendCommand(Local_u8Address);
#endif
}
void CLCD_VoidWriteSpecialChar(const u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	/*read Address counter to keep the position in the DDRAM as DDRAM and CGRAM have same Address counter */
	//u8 Local_u8DDRamAddress;
	/*set DATA PORT to input and make it internally pulled up*/
	//DIO_u8SetPortDirection(CLCD_8_BIT_DATA_PORT,DIO_u8INPUT);
	//DIO_u8SetPortValue(CLCD_8_BIT_DATA_PORT,DIO_u8HIGH);
	/*set RW PIN to high to read from LCD the Address counter*/
	//DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8HIGH);
	/*store the Address counter and the busy flag from LCD in variable(no delay needed during read)*/
	//_delay_ms(1);
	//DIO_u8GetPortValue(CLCD_8_BIT_DATA_PORT,& Local_u8DDRamAddress);
	/*restore the data port*/
	//DIO_u8SetPortDirection(CLCD_8_BIT_DATA_PORT,DIO_u8OUTPUT);
	/*get CGram address from block number*/
	u8 Local_u8CGRamAddress=Copy_u8PatternNumber*8;

	/*send command to specify address in CGRAM to write to*/
#if CLCD_WORKING_MODE==PRE_EIGHT_BIT_MODE
	CLCD_VoidSendCommand(Local_u8CGRamAddress|1<<6);
#elif CLCD_WORKING_MODE==PRE_FOUR_BIT_MODE
	/*send the 4 MSBs. Make the MSBs to make them LSBs as function copies the 4 LSBs*/
		CLCD_VoidSendCommand((Local_u8CGRamAddress|1<<6)>>4);
		/*send the 4 LSBs we don't care about the value of the 4MSBs as function only operates on the LSBs so we dont need to set MSBs to 0*/
		/*we don't need to set the 6th bit to high as we are sending the LSBs and we don't care about the MSBs*/
		CLCD_VoidSendCommand(Local_u8CGRamAddress);
#endif
	for(u8 i=0;i<8;i++)
	{
		/*send special char to CGRAM (Address counter pointer increments automatically)*/
		CLCD_VoidSendData(Copy_pu8Pattern[i]);
	}
	/*restore address counter to the saved value from the DDRAM */
	/*during storing operation we saved Address counter into 7 bits of the DDRAM address and the busy flag is in the 8th bit */
	/*we don't need to discard the 8th bit as it will be ORed with 1 in next step*/
	//CLCD_VoidSendCommand((Local_u8DDRamAddress)|1<<7);
	/*to display char in CGram send data using block number as input*/
	CLCD_VoidGoToXY(Copy_u8XPos,Copy_u8YPos);
	CLCD_VoidSendData(Copy_u8PatternNumber);

	/*configuring the global send data counter to make sure to write to second row after finishing first row*/
	/*Send data counter is number of times that function send data was called the number specifies the position of the next character to be written on the first row */
	if(Copy_u8XPos==0)//write special char in first row
	{

		Global_u8SendDataCounter=Copy_u8YPos+1;
	}
}
u32 u32POWER(u32 Copy_u8Num, u8 Copy_u8pow)
{
	if(Copy_u8pow==0)
		return 1;
	else
		{
		u32 Local_u32Result=Copy_u8Num;
		for(;Copy_u8pow>1;Copy_u8pow--)
		{
			Local_u32Result=Local_u32Result*Copy_u8Num;
		}
		return Local_u32Result;
	}
}
void CLCD_VoidShowNum(u32 Copy_u32Num)
{
	u8 Local_u8DigitCount=1;//at least one digit is given
	u32 Local_u32Temp=Copy_u32Num;
	while((Local_u32Temp/=10)!=0)
	{
		Local_u8DigitCount++;
	}
	while(Local_u8DigitCount!=0)
	{
		Local_u8DigitCount--;
		CLCD_VoidSendData(((Copy_u32Num/(u32POWER(10,Local_u8DigitCount)))%10)+'0');
	}
}
void CLCD_VoidReset_Display(void)
{
	/*send command to reset the display*/
#if CLCD_WORKING_MODE==PRE_EIGHT_BIT_MODE
	CLCD_VoidSendCommand(0b00000001);
#elif CLCD_WORKING_MODE==PRE_FOUR_BIT_MODE
	CLCD_VoidSendCommand(0b0000);
	CLCD_VoidSendCommand(0b0001);
#endif
	/*reset the global counter*/
	Global_u8SendDataCounter=0;
}
