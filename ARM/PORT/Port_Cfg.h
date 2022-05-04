 /*******************************************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - PORT Driver
 *
 * Author: Youssef Behery
 *
 *Date:30/3/2022
 *******************************************************************************************************/
 #ifndef PORT_CFG_H_
 #define PORT_CFG_H_
 
 /*ID of the company*/
#define PORT_VENDOR_ID    (1001U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION           (1U)
#define PORT_CFG_SW_MINOR_VERSION           (0U)
#define PORT_CFG_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION   (3U)

/*Precompile option for error detection*/
#define PORT_DEV_ERROR_DETECT			(STD_ON)

/*Precompile option for set pin direction API*/
#define PORT_SET_PIN_DIRECTION_API		(STD_ON)

/*Precompile option for set pin mode API*/
#define PORT_SET_PIN_MODE_API			(STD_ON)

/*Precompile option for get version info API*/
#define PORT_VERSION_INFO_API			(STD_ON)

/*Number of configured channels in Port structure*/
 #define PORT_Configured_Channels		(43U)
 
 /***************************************************************************************
 *									Channel index def									*
 *							used as index in array of config structures					*
 ****************************************************************************************/
 /*PORTA channel index*/
 #define PORT_A0_CHID 				(Port_PinType)			0x00
 #define PORT_A1_CHID 				(Port_PinType)			0x01
 #define PORT_A2_CHID 				(Port_PinType)			0x02
 #define PORT_A3_CHID 				(Port_PinType)			0x03
 #define PORT_A4_CHID 				(Port_PinType)			0x04
 #define PORT_A5_CHID 				(Port_PinType)			0x05
 #define PORT_A6_CHID 				(Port_PinType)			0x06
 #define PORT_A7_CHID 				(Port_PinType)			0x07
 
 /*PORTB channel index*/
 #define PORT_B0_CHID 				(Port_PinType)			0x08
 #define PORT_B1_CHID 				(Port_PinType)			0x09
 #define PORT_B2_CHID 				(Port_PinType)			0x0A
 #define PORT_B3_CHID 				(Port_PinType)			0x0B
 #define PORT_B4_CHID 				(Port_PinType)			0x0C
 #define PORT_B5_CHID 				(Port_PinType)			0x0D
 #define PORT_B6_CHID 				(Port_PinType)			0x0E
 #define PORT_B7_CHID 				(Port_PinType)			0x0F
 
 /*PORTC channel index*/
 #define PORT_C0_CHID 				(Port_PinType)			0x10
 #define PORT_C1_CHID 				(Port_PinType)			0x11
 #define PORT_C2_CHID 				(Port_PinType)			0x12
 #define PORT_C3_CHID 				(Port_PinType)			0x13
 #define PORT_C4_CHID 				(Port_PinType)			0x14
 #define PORT_C5_CHID 				(Port_PinType)			0x15
 #define PORT_C6_CHID 				(Port_PinType)			0x16
 #define PORT_C7_CHID 				(Port_PinType)			0x17
 
 /*PORTD channel index*/
 #define PORT_D0_CHID 				(Port_PinType)			0x18
 #define PORT_D1_CHID 				(Port_PinType)			0x19
 #define PORT_D2_CHID 				(Port_PinType)			0x1A
 #define PORT_D3_CHID 				(Port_PinType)			0x1B
 #define PORT_D4_CHID 				(Port_PinType)			0x1C
 #define PORT_D5_CHID 				(Port_PinType)			0x1D
 #define PORT_D6_CHID 				(Port_PinType)			0x1E
 #define PORT_D7_CHID 				(Port_PinType)			0x1F
 
 /*PORTE channel index*/
 #define PORT_E0_CHID 				(Port_PinType)			0x20
 #define PORT_E1_CHID 				(Port_PinType)			0x21
 #define PORT_E2_CHID 				(Port_PinType)			0x22
 #define PORT_E3_CHID 				(Port_PinType)			0x23
 #define PORT_E4_CHID 				(Port_PinType)			0x24
 #define PORT_E5_CHID 				(Port_PinType)			0x25
			  
 /*PORTF channel index*/
 #define PORT_F0_CHID 				(Port_PinType)			0x26
 #define PORT_F1_CHID 				(Port_PinType)			0x27
 #define PORT_F2_CHID 				(Port_PinType)			0x28
 #define PORT_F3_CHID 				(Port_PinType)			0x29
 #define PORT_F4_CHID 				(Port_PinType)			0x2A
 
 
 /****************************************************************************************
 *									PORTA PINS											 *
 ****************************************************************************************/
 /*PORTA number of pins*/
 #define PORT_A_PinNum				(Port_PinType)			8
										
 /*PORTA ID*/							
 #define PORT_A_ID					(uint8)					0x00
									
 /*PORTA PIN IDs*/						
 #define PORT_A0_ID					(Port_PinType)			0x00
 #define PORT_A1_ID					(Port_PinType)			0x01
 #define PORT_A2_ID					(Port_PinType)			0x02
 #define PORT_A3_ID					(Port_PinType)			0x03
 #define PORT_A4_ID					(Port_PinType)			0x04
 #define PORT_A5_ID					(Port_PinType)			0x05
 #define PORT_A6_ID					(Port_PinType)			0x06
 #define PORT_A7_ID					(Port_PinType)			0x07
									
 /*PORTA PINs mode Default:PORT_PIN_MODE_DIO*/				
 #define PORT_A0_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_A1_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_A2_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_A3_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_A4_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_A5_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_A6_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_A7_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
									
 /*PORTA PINs direction Default:PORT_PIN_IN*/			
 #define PORT_A0_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_A1_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_A2_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_A3_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_A4_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_A5_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_A6_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_A7_DIR				(Port_PinDirectionType) PORT_PIN_IN
									
 /*PORTA PINs internal resistor Default:OFF*/	
 #define PORT_A0_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_A1_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_A2_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_A3_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_A4_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_A5_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_A6_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_A7_INTRES				(PORT_IntResitorType)	OFF
										
 /*PORTA PINs output level Default:PORT_PIN_LEVEL_LOW*/			
 #define PORT_A0_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_A1_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_A2_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_A3_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_A4_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_A5_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_A6_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_A7_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 
 /*PORTA PINs changeable mode Default:STD_ON*/
 #define PORT_A0_MODE_CHANGE								STD_ON
 #define PORT_A1_MODE_CHANGE								STD_ON
 #define PORT_A2_MODE_CHANGE								STD_ON
 #define PORT_A3_MODE_CHANGE								STD_ON
 #define PORT_A4_MODE_CHANGE								STD_ON
 #define PORT_A5_MODE_CHANGE								STD_ON
 #define PORT_A6_MODE_CHANGE								STD_ON
 #define PORT_A7_MODE_CHANGE								STD_ON
 
 /*PORTA PINs changeable direction Default:STD_ON*/
 #define PORT_A0_DIR_CHANGE									STD_ON
 #define PORT_A1_DIR_CHANGE									STD_ON
 #define PORT_A2_DIR_CHANGE									STD_ON
 #define PORT_A3_DIR_CHANGE									STD_ON
 #define PORT_A4_DIR_CHANGE									STD_ON
 #define PORT_A5_DIR_CHANGE									STD_ON
 #define PORT_A6_DIR_CHANGE									STD_ON
 #define PORT_A7_DIR_CHANGE									STD_ON
 
 /****************************************************************************************
 *									PORTB PINS											 *
 ****************************************************************************************/
 /*PORTB number of pins*/
 #define PORT_B_PinNum				(Port_PinType)			8										
 
 /*PORTB ID*/							
 #define PORT_B_ID					(uint8)					0x01
 
 /*PORTB PIN IDs*/						
 #define PORT_B0_ID					(Port_PinType)			0x00
 #define PORT_B1_ID					(Port_PinType)			0x01
 #define PORT_B2_ID					(Port_PinType)			0x02
 #define PORT_B3_ID					(Port_PinType)			0x03
 #define PORT_B4_ID					(Port_PinType)			0x04
 #define PORT_B5_ID					(Port_PinType)			0x05
 #define PORT_B6_ID					(Port_PinType)			0x06
 #define PORT_B7_ID					(Port_PinType)			0x07
 
 /*PORTB PINs mode Default:PORT_PIN_MODE_DIO*/				
 #define PORT_B0_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_B1_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_B2_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_B3_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_B4_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_B5_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_B6_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_B7_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 
 /*PORTB PINs direction Default:PORT_PIN_IN*/			
 #define PORT_B0_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_B1_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_B2_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_B3_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_B4_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_B5_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_B6_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_B7_DIR				(Port_PinDirectionType) PORT_PIN_IN
 
 /*PORTB PINs internal resistor Default:OFF*/	
 #define PORT_B0_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_B1_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_B2_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_B3_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_B4_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_B5_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_B6_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_B7_INTRES				(PORT_IntResitorType)	OFF
 
 /*PORTB PINs output level Default:PORT_PIN_LEVEL_LOW*/			
 #define PORT_B0_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_B1_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_B2_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_B3_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_B4_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_B5_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_B6_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_B7_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 
 /*PORTB PINs changeable mode Default:STD_ON*/
 #define PORT_B0_MODE_CHANGE								STD_ON
 #define PORT_B1_MODE_CHANGE								STD_ON
 #define PORT_B2_MODE_CHANGE								STD_ON
 #define PORT_B3_MODE_CHANGE								STD_ON
 #define PORT_B4_MODE_CHANGE								STD_ON
 #define PORT_B5_MODE_CHANGE								STD_ON
 #define PORT_B6_MODE_CHANGE								STD_ON
 #define PORT_B7_MODE_CHANGE								STD_ON
 
 /*PORTB PINs changeable direction Default:STD_ON*/
 #define PORT_B0_DIR_CHANGE									STD_ON
 #define PORT_B1_DIR_CHANGE									STD_ON
 #define PORT_B2_DIR_CHANGE									STD_ON
 #define PORT_B3_DIR_CHANGE									STD_ON
 #define PORT_B4_DIR_CHANGE									STD_ON
 #define PORT_B5_DIR_CHANGE									STD_ON
 #define PORT_B6_DIR_CHANGE									STD_ON
 #define PORT_B7_DIR_CHANGE									STD_ON
 /****************************************************************************************
 *									PORTC PINS											 *
 ****************************************************************************************/
 /*PORTC number of pins*/
 #define PORT_C_PinNum				(Port_PinType)			8										
 
 /*PORTC ID*/   							
 #define PORT_C_ID					(uint8)					0x02
 
 /*PORTC PIN  IDs*/						
 #define PORT_C0_ID					(Port_PinType)			0x00//JTAG PIN//
 #define PORT_C1_ID					(Port_PinType)			0x01//JTAG PIN//
 #define PORT_C2_ID					(Port_PinType)			0x02//JTAG PIN//
 #define PORT_C3_ID					(Port_PinType)			0x03//JTAG PIN//
 #define PORT_C4_ID					(Port_PinType)			0x04
 #define PORT_C5_ID					(Port_PinType)			0x05
 #define PORT_C6_ID					(Port_PinType)			0x06
 #define PORT_C7_ID					(Port_PinType)			0x07
 
 /*PORTC PINs mode Default:PORT_PIN_MODE_DIO*/				
 #define PORT_C0_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO//JTAG PIN//
 #define PORT_C1_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO//JTAG PIN//
 #define PORT_C2_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO//JTAG PIN//
 #define PORT_C3_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO//JTAG PIN//
 #define PORT_C4_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_C5_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_C6_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_C7_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 
 /*PORTC PINs direction Default:PORT_PIN_IN*/			
 #define PORT_C0_DIR				(Port_PinDirectionType) PORT_PIN_IN//JTAG PIN//
 #define PORT_C1_DIR				(Port_PinDirectionType) PORT_PIN_IN//JTAG PIN//
 #define PORT_C2_DIR				(Port_PinDirectionType) PORT_PIN_IN//JTAG PIN//
 #define PORT_C3_DIR				(Port_PinDirectionType) PORT_PIN_IN//JTAG PIN//
 #define PORT_C4_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_C5_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_C6_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_C7_DIR				(Port_PinDirectionType) PORT_PIN_IN
 
 /*PORTC PINs internal resistor Default:OFF*/	
 #define PORT_C0_INTRES				(PORT_IntResitorType)	OFF//JTAG PIN//
 #define PORT_C1_INTRES				(PORT_IntResitorType)	OFF//JTAG PIN//
 #define PORT_C2_INTRES				(PORT_IntResitorType)	OFF//JTAG PIN//
 #define PORT_C3_INTRES				(PORT_IntResitorType)	OFF//JTAG PIN//
 #define PORT_C4_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_C5_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_C6_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_C7_INTRES				(PORT_IntResitorType)	OFF
 
 /*PORTC PINs output level Default:PORT_PIN_LEVEL_LOW*/			
 #define PORT_C0_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW//JTAG PIN//
 #define PORT_C1_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW//JTAG PIN//
 #define PORT_C2_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW//JTAG PIN//
 #define PORT_C3_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW//JTAG PIN//
 #define PORT_C4_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_C5_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_C6_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_C7_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 
 /*PORTC PINs changeable mode Default:STD_ON*/
 #define PORT_C0_MODE_CHANGE								STD_ON//JTAG PIN//
 #define PORT_C1_MODE_CHANGE								STD_ON//JTAG PIN//
 #define PORT_C2_MODE_CHANGE								STD_ON//JTAG PIN//
 #define PORT_C3_MODE_CHANGE								STD_ON//JTAG PIN//
 #define PORT_C4_MODE_CHANGE								STD_ON
 #define PORT_C5_MODE_CHANGE								STD_ON
 #define PORT_C6_MODE_CHANGE								STD_ON
 #define PORT_C7_MODE_CHANGE								STD_ON
 
 /*PORTC PINs changeable direction Default:STD_ON*/
 #define PORT_C0_DIR_CHANGE									STD_ON//JTAG PIN//
 #define PORT_C1_DIR_CHANGE									STD_ON//JTAG PIN//
 #define PORT_C2_DIR_CHANGE									STD_ON//JTAG PIN//
 #define PORT_C3_DIR_CHANGE									STD_ON//JTAG PIN//
 #define PORT_C4_DIR_CHANGE									STD_ON
 #define PORT_C5_DIR_CHANGE									STD_ON
 #define PORT_C6_DIR_CHANGE									STD_ON
 #define PORT_C7_DIR_CHANGE									STD_ON
  /****************************************************************************************
 *									PORTD PINS											 *
 ****************************************************************************************/
 /*PORTD number of pins*/
 #define PORT_D_PinNum				(Port_PinType)			8										
 
 /*PORTD ID*/ 							
 #define PORT_D_ID					(uint8)					0x03
 
 /*PORTD PIN IDs*/						
 #define PORT_D0_ID					(Port_PinType)			0x00
 #define PORT_D1_ID					(Port_PinType)			0x01
 #define PORT_D2_ID					(Port_PinType)			0x02
 #define PORT_D3_ID					(Port_PinType)			0x03
 #define PORT_D4_ID					(Port_PinType)			0x04
 #define PORT_D5_ID					(Port_PinType)			0x05
 #define PORT_D6_ID					(Port_PinType)			0x06
 #define PORT_D7_ID					(Port_PinType)			0x07
 
 /*PORTD PINs mode Default:PORT_PIN_MODE_DIO*/				
 #define PORT_D0_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_D1_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_D2_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_D3_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_D4_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_D5_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_D6_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_D7_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 
 /*PORTD PINs direction Default:PORT_PIN_IN*/			
 #define PORT_D0_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_D1_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_D2_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_D3_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_D4_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_D5_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_D6_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_D7_DIR				(Port_PinDirectionType) PORT_PIN_IN
 
 /*PORTD PINs internal resistor Default:OFF*/	
 #define PORT_D0_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_D1_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_D2_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_D3_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_D4_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_D5_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_D6_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_D7_INTRES				(PORT_IntResitorType)	OFF
 
 /*PORTD PINs output level Default:PORT_PIN_LEVEL_LOW*/			
 #define PORT_D0_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_D1_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_D2_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_D3_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_D4_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_D5_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_D6_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_D7_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 
 /*PORTD PINs changeable mode Default:STD_ON*/
 #define PORT_D0_MODE_CHANGE								STD_ON
 #define PORT_D1_MODE_CHANGE								STD_ON
 #define PORT_D2_MODE_CHANGE								STD_ON
 #define PORT_D3_MODE_CHANGE								STD_ON
 #define PORT_D4_MODE_CHANGE								STD_ON
 #define PORT_D5_MODE_CHANGE								STD_ON
 #define PORT_D6_MODE_CHANGE								STD_ON
 #define PORT_D7_MODE_CHANGE								STD_ON
 
 /*PORTD PINs changeable direction Default:STD_ON*/
 #define PORT_D0_DIR_CHANGE									STD_ON
 #define PORT_D1_DIR_CHANGE									STD_ON
 #define PORT_D2_DIR_CHANGE									STD_ON
 #define PORT_D3_DIR_CHANGE									STD_ON
 #define PORT_D4_DIR_CHANGE									STD_ON
 #define PORT_D5_DIR_CHANGE									STD_ON
 #define PORT_D6_DIR_CHANGE									STD_ON
 #define PORT_D7_DIR_CHANGE									STD_ON
 /****************************************************************************************
 *									PORTE PINS											 *
 ****************************************************************************************/
 /*PORTE number of pins*/
 #define PORT_E_PinNum				(Port_PinType)			6										
 
 /*PORTE ID*/ 							
 #define PORT_E_ID					(uint8)					0x04
 
 /*PORTE PIN IDs*/						
 #define PORT_E0_ID					(Port_PinType)			0x00
 #define PORT_E1_ID					(Port_PinType)			0x01
 #define PORT_E2_ID					(Port_PinType)			0x02
 #define PORT_E3_ID					(Port_PinType)			0x03
 #define PORT_E4_ID					(Port_PinType)			0x04
 #define PORT_E5_ID					(Port_PinType)			0x05
 
 /*PORTE PINs mode Default:PORT_PIN_MODE_DIO*/				
 #define PORT_E0_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_E1_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_E2_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_E3_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_E4_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_E5_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 
 /*PORTE PINs direction Default:PORT_PIN_IN*/			
 #define PORT_E0_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_E1_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_E2_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_E3_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_E4_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_E5_DIR				(Port_PinDirectionType) PORT_PIN_IN
 
 /*PORTE PINs internal resistor Default:OFF*/	
 #define PORT_E0_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_E1_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_E2_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_E3_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_E4_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_E5_INTRES				(PORT_IntResitorType)	OFF
 
 /*PORTE PINs output level Default:PORT_PIN_LEVEL_LOW*/			
 #define PORT_E0_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_E1_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_E2_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_E3_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_E4_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_E5_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 
 /*PORTE PINs changeable mode Default:STD_ON*/
 #define PORT_E0_MODE_CHANGE								STD_ON
 #define PORT_E1_MODE_CHANGE								STD_ON
 #define PORT_E2_MODE_CHANGE								STD_ON
 #define PORT_E3_MODE_CHANGE								STD_ON
 #define PORT_E4_MODE_CHANGE								STD_ON
 #define PORT_E5_MODE_CHANGE								STD_ON
 
 /*PORTE PINs changeable direction Default:STD_ON*/
 #define PORT_E0_DIR_CHANGE									STD_ON
 #define PORT_E1_DIR_CHANGE									STD_ON
 #define PORT_E2_DIR_CHANGE									STD_ON
 #define PORT_E3_DIR_CHANGE									STD_ON
 #define PORT_E4_DIR_CHANGE									STD_ON
 #define PORT_E5_DIR_CHANGE									STD_ON


  /****************************************************************************************
 *									PORTF PINS											 *
 ****************************************************************************************/
 /*PORTF number of pins*/
 #define PORT_F_PinNum				(Port_PinType)			5										
 
 /*PORTF ID*/ 							
 #define PORT_F_ID					(uint8)					0x05
 
 /*PORTF PIN IDs*/						
 #define PORT_F0_ID					(Port_PinType)			0x00
 #define PORT_F1_ID					(Port_PinType)			0x01
 #define PORT_F2_ID					(Port_PinType)			0x02
 #define PORT_F3_ID					(Port_PinType)			0x03
 #define PORT_F4_ID					(Port_PinType)			0x04
 
 /*PORTF PINs mode Default:PORT_PIN_MODE_DIO*/				
 #define PORT_F0_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_F1_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_F2_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_F3_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 #define PORT_F4_MODE				(PORT_MODE_ID)			PORT_PIN_MODE_DIO
 
 /*PORTF PINs direction Default:PORT_PIN_IN*/			
 #define PORT_F0_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_F1_DIR				(Port_PinDirectionType) PORT_PIN_OUT
 #define PORT_F2_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_F3_DIR				(Port_PinDirectionType) PORT_PIN_IN
 #define PORT_F4_DIR				(Port_PinDirectionType) PORT_PIN_IN
 
 /*PORTF PINs internal resistor Default:OFF*/	
 #define PORT_F0_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_F1_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_F2_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_F3_INTRES				(PORT_IntResitorType)	OFF
 #define PORT_F4_INTRES				(PORT_IntResitorType)	PULLUP
 
 /*PORTF PINs output level Default:PORT_PIN_LEVEL_LOW*/			
 #define PORT_F0_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_F1_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_F2_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_F3_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 #define PORT_F4_OUTLVL				(Port_PinLevel)			PORT_PIN_LEVEL_LOW
 
 /*PORTF PINs changeable mode Default:STD_ON*/
 #define PORT_F0_MODE_CHANGE								STD_ON
 #define PORT_F1_MODE_CHANGE								STD_ON
 #define PORT_F2_MODE_CHANGE								STD_ON
 #define PORT_F3_MODE_CHANGE								STD_ON
 #define PORT_F4_MODE_CHANGE								STD_ON
 
 /*PORTF PINs changeable direction Default:STD_ON*/
 #define PORT_F0_DIR_CHANGE									STD_ON
 #define PORT_F1_DIR_CHANGE									STD_ON
 #define PORT_F2_DIR_CHANGE									STD_ON
 #define PORT_F3_DIR_CHANGE									STD_ON
 #define PORT_F4_DIR_CHANGE									STD_ON
 
 #endif