 /*******************************************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - PORT Driver
 *
 * Author: Youssef Behery
 *
 *Date:30/3/2022
 *******************************************************************************************************/
 
 #include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Port_ConfigChannel * PORT_Channels = NULL_PTR;
STATIC uint8 PORT_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module.
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
	}
	else
#endif
	{
		/*pointer to point the base address of the specified port*/
		volatile uint32 * Port_Ptr = NULL_PTR; 
		
		/*delay variable to give time for starting clock on the specified port*/
		volatile uint32 delay = ZERO;
		
		/*array flags indicating which clk is active it is ordered by the port IDs i.e.:	1st element for the PORTA clock status
																							2nd element for the PORTB clock status
																							3rd element for the PORTC clock status
																							4th element for the PORTD clock status
																							5th element for the PORTE clock status
																							6th element for the PORTF clock status
																							*/
		uint8 CLK_InitFlags[]={CLK_INACTIVE, CLK_INACTIVE, CLK_INACTIVE, CLK_INACTIVE, CLK_INACTIVE, CLK_INACTIVE};
		
		
		/*set the global port status to initialized*/
		PORT_Status=PORT_INITIALIZED;
		
		/*set the global pointer to the first element in the configuration array*/
		PORT_Channels= ConfigPtr->Channels;
		
		/*for loop on the array of structures initializing the registers*/
		for(uint8 i=ZERO;i<PORT_Configured_Channels;i++)
		{
			/*detecting port number and enabling clock */
			switch(PORT_Channels[i].port_num)
			{
				case PORT_A_ID:
					Port_Ptr=(volatile uint32*)GPIO_PORTA_BASE_ADDRESS; //Setting the port pointer to PORTA
				break;
				case PORT_B_ID:
					Port_Ptr=(volatile uint32*)GPIO_PORTB_BASE_ADDRESS; //Setting the port pointer to PORTB
				break;
				case PORT_C_ID:
					Port_Ptr=(volatile uint32*)GPIO_PORTC_BASE_ADDRESS;	//Setting the port pointer to PORTC			
				break;
				case PORT_D_ID:
					Port_Ptr=(volatile uint32*)GPIO_PORTD_BASE_ADDRESS;	//Setting the port pointer to PORTD
				break;
				case PORT_E_ID:
					Port_Ptr=(volatile uint32*)GPIO_PORTE_BASE_ADDRESS;	//Setting the port pointer to PORTE
				break;
				case PORT_F_ID:
					Port_Ptr=(volatile uint32*)GPIO_PORTF_BASE_ADDRESS;	//Setting the port pointer to PORTF
				break;
			}
			/*Enabling clock for the required port before writing on the registers*/
			if(CLK_InitFlags[PORT_Channels[i].port_num]==CLK_INACTIVE) //Checking on the status of the clock to avoid enabling clock multiple times
			{	
				CLK_InitFlags[PORT_Channels[i].port_num]=CLK_ACTIVE;  	//Set the status for the clock as active
				SYSCTL_REGCGC2_REG |= (1<<PORT_Channels[i].port_num); 	//Enabling the clock
				delay = SYSCTL_REGCGC2_REG;							//Inserting delay to allow the clock to be initialized
			}
			else
			{
				//DO NOTHING:exist only for misra rules//
			}
			/*Unlock commit register in PD7  and PF0*/
			if( ((PORT_Channels[i].port_num == PORT_D_ID) && (PORT_Channels[i].pin_num == PORT_D7_ID)) || ((PORT_Channels[i].port_num == PORT_F_ID) && (PORT_Channels[i].pin_num == PORT_F0_ID)) ) /* PD7 or PF0 */
			{
				*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;     		       		/* Unlock the GPIOCR register */   
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET) , PORT_Channels[i].pin_num); /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
			}
			else
			{
				//DO NOTHING
			}	
			
			if( (PORT_Channels[i].port_num == PORT_C_ID) && (PORT_Channels[i].pin_num <= PORT_C3_ID) ) /* PC0 to PC3 */
			{
				/* Do Nothing ...  this is the JTAG pins */
			}
			else //all pins except JTAG are initialized
			{
				/*Configuring mode registers*/
				if((PORT_Channels[i].PinMode==PORT_PIN_MODE_ADC)||(PORT_Channels[i].PinMode==PORT_PIN_MODE_DIO)) /*ADC mode or the DIO mode*/
				{
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_Channels[i].pin_num);             		/* Disable Alternative function*/
					*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (PORT_Channels[i].pin_num * 4));     		/* Clear the PMCx*/
					if(PORT_Channels[i].PinMode==PORT_PIN_MODE_ADC) /*ADC MODE*/
					{							
						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr   + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_Channels[i].pin_num);      	/* Disable Digital functionality*/
						SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_Channels[i].pin_num);      		/* Enable analog functionality*/
					}
					else /*DIO MODE*/
					{
						SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr   + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_Channels[i].pin_num);    		/* Enable Digital functionality*/
						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_Channels[i].pin_num);   		/* Disable analog functionality*/
					}
				}
				else /*Mode configuration for any other mode (UART,SPI,CAN,....)*/
				{
					SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr   + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_Channels[i].pin_num);      			/* Enable Digital functionality*/
					
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_Channels[i].pin_num);      		/* Disable analog functionality*/
					
					SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_Channels[i].pin_num);             			/* Enable Alternative function*/
					
					*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (PORT_Channels[i].pin_num * 4));     		/* Clear the PMCx*/
					*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (PORT_Channels[i].PinMode << (PORT_Channels[i].pin_num * 4));   /* Set the PMCx bits as specified by the mode in the config struct*/
				}
				/*Configuring PIN Direction*/
				if(PORT_Channels[i].PinDirection==PORT_PIN_IN) 
				{
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PORT_Channels[i].pin_num); /*Clearing port DIR register to be INPUT*/
					
					/*Configuring internal resistor*/
					if(PORT_Channels[i].InternalResistor==OFF) /*No internal resistor*/
					{
						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , PORT_Channels[i].pin_num); 		/*Clearing bit in PULLUP register to disable PULLUP*/
						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PORT_Channels[i].pin_num);	/*Clearing bit in PULLDOWN register to disable PULLDOWN*/
					}
					else if(PORT_Channels[i].InternalResistor==PULLUP)	/*Pullup internal resistor*/
					{
						SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , PORT_Channels[i].pin_num); 		/*Setting bit in PULLUP register to enable PULLUP*/
						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PORT_Channels[i].pin_num);	/*Clearing bit in PULLDOWN register to disable PULLDOWN*/
						
					}	
					else if(PORT_Channels[i].InternalResistor==PULLDOWN)	/*Pulldown internal resistor*/
					{
						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , PORT_Channels[i].pin_num); 		/*Clearing bit in PULLUP register to disable PULLUP*/
						SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PORT_Channels[i].pin_num);		/*Setting bit in PULLDOWN register to enable PULLDOWN*/
					}
					else
					{
						/*DO NOTHING*/
					}
				}
				else if(PORT_Channels[i].PinDirection==PORT_PIN_OUT)	/*Direction is output*/
				{
					/*Setting OUTPUT level on the latch before setting direction as OUTPUT as stated by (PORT055)*/
					if(PORT_Channels[i].PinLevelInitValue==PORT_PIN_LEVEL_HIGH)	/*Output level is high*/
					{
						SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , PORT_Channels[i].pin_num);		/*Setting output level to HIGH*/
					}
					else if(PORT_Channels[i].PinLevelInitValue==PORT_PIN_LEVEL_LOW)
					{
						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , PORT_Channels[i].pin_num); 	/*Setting output level to LOW*/
					}
					else
					{
						/*DO NOTHING*/
					}
					SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PORT_Channels[i].pin_num); /*Setting port DIR register to be OUTPUT*/
				}	
				else
				{
					/*DO NOTHING*/
				}
			}	
		}
	}
}
/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 	1)PIN: Pin id number
*					2)Direction: Pin direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the port pin direction.
************************************************************************************/
#if(PORT_SET_PIN_DIRECTION_API==STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction)
{
	/*pointer to point the base address of the specified port*/
	volatile uint32 * Port_Ptr = NULL_PTR; 	
	boolean error = FALSE;
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	
	if(PORT_Status==PORT_NOT_INITIALIZED) /*Check if the Port driver was initialized*/
	{
		error=TRUE;
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
	}
	else
	{
		
	}
	if ( (Pin > PORT_F4_CHID) && (error==FALSE) ) /*Check on pin ID if it is valid this is only checked when the previous check didn't fail as stated by (PORT077)*/
	{
		error=TRUE;
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
	}
	else
	{

	}
	/*Check if the direction is changeable this is only checked when the previous check didn't fail as stated by (PORT077) */
	if( (PORT_Channels[Pin].PinDirectionChangeable==STD_OFF) && (error==FALSE) )
	{
		error=TRUE;
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
	}
	else
	{
		
	}
	#endif
	/*if previous checks didn't fail proceed but in case one failed functionality will be skipped (PORT087)*/
	if(error ==FALSE)
	{
		
		/*detecting port number and enabling clock */
		switch(PORT_Channels[Pin].port_num)
		{
			case PORT_A_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTA_BASE_ADDRESS; //Setting the port pointer to PORTA
			break;
			case PORT_B_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTB_BASE_ADDRESS; //Setting the port pointer to PORTB
			break;
			case PORT_C_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTC_BASE_ADDRESS;	//Setting the port pointer to PORTC			
			break;
			case PORT_D_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTD_BASE_ADDRESS;	//Setting the port pointer to PORTD
			break;
			case PORT_E_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTE_BASE_ADDRESS;	//Setting the port pointer to PORTE
			break;
			case PORT_F_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTF_BASE_ADDRESS;	//Setting the port pointer to PORTF
			break;
		}
		/*Unlock commit register in PD7  and PF0*/
		if( ((PORT_Channels[Pin].port_num == PORT_D_ID) && (PORT_Channels[Pin].pin_num == PORT_D7_ID)) || ((PORT_Channels[Pin].port_num == PORT_F_ID) && (PORT_Channels[Pin].pin_num == PORT_F0_ID)) ) /* PD7 or PF0 */
		{
			*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;     		       		/* Unlock the GPIOCR register */   
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET) , PORT_Channels[Pin].pin_num); /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
		}
		else
		{
			//DO NOTHING
		}
		if(Direction==PORT_PIN_OUT) 	/*Direction is output*/
		{
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PORT_Channels[Pin].pin_num); /*Setting port DIR register to be OUTPUT*/
		}	
		else if(Direction==PORT_PIN_IN)	/*Direction is input*/	
		{
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PORT_Channels[Pin].pin_num); /*Clearing port DIR register to be INPUT*/
		}
		else
		{
			/*DO NOTHING*/
		}
	}
}
#endif 
/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to refresh the port direction.
************************************************************************************/
void Port_RefreshPortDirection(void)
{
	/*pointer to point the base address of the specified port*/
	volatile uint32 * Port_Ptr = NULL_PTR; 	
	
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	
	if(PORT_Status==PORT_NOT_INITIALIZED) /*Check if the Port driver was initialized*/
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
	}
	else
	#endif
	{
		for(uint8 i=ZERO;i<PORT_Configured_Channels;i++) /*loop on all pins*/
		{
			if(PORT_Channels[i].PinDirectionChangeable==STD_OFF) /*Direction is unchangeable then refresh*/
			{
				switch(PORT_Channels[i].port_num)
				{
					case PORT_A_ID:
						Port_Ptr=(volatile uint32*)GPIO_PORTA_BASE_ADDRESS; //Setting the port pointer to PORTA
					break;
					case PORT_B_ID:
						Port_Ptr=(volatile uint32*)GPIO_PORTB_BASE_ADDRESS; //Setting the port pointer to PORTB
					break;
					case PORT_C_ID:
						Port_Ptr=(volatile uint32*)GPIO_PORTC_BASE_ADDRESS;	//Setting the port pointer to PORTC			
					break;
					case PORT_D_ID:
						Port_Ptr=(volatile uint32*)GPIO_PORTD_BASE_ADDRESS;	//Setting the port pointer to PORTD
					break;
					case PORT_E_ID:
						Port_Ptr=(volatile uint32*)GPIO_PORTE_BASE_ADDRESS;	//Setting the port pointer to PORTE
					break;
					case PORT_F_ID:
						Port_Ptr=(volatile uint32*)GPIO_PORTF_BASE_ADDRESS;	//Setting the port pointer to PORTF
					break;
				}
				if(PORT_Channels[i].PinDirection == PORT_PIN_OUT) 	/*Direction is output*/
				{
					SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PORT_Channels[i].pin_num); /*Setting port DIR register to be OUTPUT*/
				}	
				else if(PORT_Channels[i].PinDirection == PORT_PIN_IN)	/*Direction is input*/	
				{
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , PORT_Channels[i].pin_num); /*Clearing port DIR register to be INPUT*/
				}
			}
			else /*Direction is unchangeable*/
			{
				/*DO NOTHING*/
			}
		}
	}
}
/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo( pointer to where to store the version information
* Return value: None
* Description: Function to return the version information of this module.
************************************************************************************/
#if(PORT_VERSION_INFO_API==STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	boolean error =FALSE;
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if(PORT_Status==PORT_NOT_INITIALIZED)	/*check if Port was initialized*/
	{
		error=TRUE;
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT);
	}
	else
	{
		
	}
	/* Check if input pointer is not Null pointer */
	if( (NULL_PTR == versioninfo) && (error==FALSE) )
	{
		error=TRUE;
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
	{
		
	}
#endif 
	if(error==FALSE)
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
	else
	{
		
	}
}
#endif
/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 	1)PIN: Port pin ID number
					2)MODE: New pin mode to be set on the pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set the port pin mode.
************************************************************************************/

#if (PORT_SET_PIN_MODE_API==STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
	/*pointer to point the base address of the specified port*/
	volatile uint32 * Port_Ptr = NULL_PTR; 	
	boolean error = FALSE;
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	
	if(PORT_Status==PORT_NOT_INITIALIZED) /*Check if the Port driver was initialized*/
	{
		error=TRUE;
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
	}
	else
	{
		
	}
	if ( (Pin > PORT_F4_CHID) && (error==FALSE) ) /*Check on pin ID if it is valid this is only checked when the previous check didn't fail as stated by (PORT077)*/
	{
		error=TRUE;
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
	}
	else
	{

	}
	/*Check if the mode is changeable this is only checked when the previous check didn't fail as stated by (PORT077) */
	if( (PORT_Channels[Pin].PinModeChangeable==STD_OFF) && (error==FALSE) )
	{
		error=TRUE;
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
	}
	else
	{
		
	}
	#endif
	/*if no error is found proceed*/
	if(error==FALSE)
	{
		switch(PORT_Channels[Pin].port_num)
		{
			case PORT_A_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTA_BASE_ADDRESS; //Setting the port pointer to PORTA
			break;
			case PORT_B_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTB_BASE_ADDRESS; //Setting the port pointer to PORTB
			break;
			case PORT_C_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTC_BASE_ADDRESS;	//Setting the port pointer to PORTC			
			break;
			case PORT_D_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTD_BASE_ADDRESS;	//Setting the port pointer to PORTD
			break;
			case PORT_E_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTE_BASE_ADDRESS;	//Setting the port pointer to PORTE
			break;
			case PORT_F_ID:
				Port_Ptr=(volatile uint32*)GPIO_PORTF_BASE_ADDRESS;	//Setting the port pointer to PORTF
			break;
		}
		/*Configuring mode registers*/
		if((Mode==PORT_PIN_MODE_ADC)||(Mode==PORT_PIN_MODE_DIO)) /*ADC mode or the DIO mode*/
		{
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_Channels[Pin].pin_num);             		/* Disable Alternative function*/
			*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (PORT_Channels[Pin].pin_num * 4));     		/* Clear the PMCx*/
			if(Mode==PORT_PIN_MODE_ADC) /*ADC MODE*/
			{							
				CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr   + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_Channels[Pin].pin_num);      	/* Disable Digital functionality*/
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_Channels[Pin].pin_num);      		/* Enable analog functionality*/
			}
			else /*DIO MODE*/
			{
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr   + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_Channels[Pin].pin_num);    		/* Enable Digital functionality*/
				CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_Channels[Pin].pin_num);   		/* Disable analog functionality*/
			}
		}
		else /*Mode configuration for any other mode (UART,SPI,CAN,....)*/
		{
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr   + PORT_DIGITAL_ENABLE_REG_OFFSET) , PORT_Channels[Pin].pin_num);      			/* Enable Digital functionality*/
			
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PORT_Channels[Pin].pin_num);      		/* Disable analog functionality*/
			
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PORT_Channels[Pin].pin_num);             			/* Enable Alternative function*/
			
			*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (PORT_Channels[Pin].pin_num * 4));     		/* Clear the PMCx*/
			*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (Mode << (PORT_Channels[Pin].pin_num * 4));   /* Set the PMCx bits as specified by the mode in the config struct*/
		}
	}
}
#endif