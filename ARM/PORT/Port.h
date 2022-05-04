 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Youssef Behery
 *
 * Date: 29/3/2022
 ******************************************************************************/
#ifndef PORT_H_
#define PORT_H_

/*ID of the company*/
#define PORT_VENDOR_ID    (1001U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for PORT Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/*Macros used for clock activation*/
#define CLK_ACTIVE						(0U)
#define CLK_INACTIVE					(1U)

/*zero macro for misra rules*/
#define ZERO							(0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and PORT Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* PORT Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
 
 /*Port_init service ID*/
 #define PORT_INIT_SID						(uint8) 0x00
 
 /*Port_Set_Pin_Direction service ID*/
 #define PORT_SET_PIN_DIRECTION_SID			(uint8) 0x01
 
 /*PORT_REFRESH_PORT_DIRECTION service ID*/
 #define PORT_REFRESH_PORT_DIRECTION_SID	(uint8) 0x02
 
 /*Port_Get_Version_Info service ID*/
 #define PORT_GET_VERSION_INFO_SID			(uint8) 0x03
 
 /*Port_SetPinMode service ID*/
 #define PORT_SET_PIN_MODE_SID				(uint8) 0x04
 
 /*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
 
 /*Det code for invalid pin ID*/
 #define PORT_E_PARAM_PIN 					(uint8) 0x0A
 
 /*Det code for changing direction of pin while direction is unchangeable*/
 #define PORT_E_DIRECTION_UNCHANGEABLE		(uint8) 0x0B
 
 /*Det code for calling Port_Init service with wrong config parameter*/
 #define PORT_E_PARAM_CONFIG				(uint8) 0x0C
 
 /*Det code for passing invalid pin mode*/
 #define PORT_E_PARAM_INVALID_MODE			(uint8) 0x0D
 
 /*Det code for calling Port_SetPinMode service when mode is unchangeable */
 #define PORT_E_MODE_UNCHANGEABLE			(uint8) 0x0E
 
 /*Det code for calling an API service without initializing the module*/
 #define PORT_E_UNINIT						(uint8) 0x0F
 
 /*Det code for calling an API with a NULL pointer as an input parameter*/
 #define PORT_E_PARAM_POINTER				(uint8) 0x10
 
 /*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

 /*typedef of Port_PinType used by the Port APIs*/
 typedef uint8 Port_PinType;
 
 /*typedef of enum holding the values of type Port_PinDirectionType used by the Port APIs*/
 typedef enum
 {
	 PORT_PIN_IN,PORT_PIN_OUT
 }Port_PinDirectionType;
 
 /*typedef of  Port_PinModeType used by the PORT APIs*/
 typedef uint8 Port_PinModeType;
 
 /*
 *typedef of the configuration structure containing:
 *														1)port_num: Port index number
														2)pin_num : Pin index number
														3)PinMode : Desired mode of pin
														4)PinDirection: Desired direction of pin
														5)PinLevelInitValue: Initial value for pin in case of output direction
														6)PinDirectionChangeable: option for changing direction of pin during runtime 
														7)PinModeChangeable: Option for changing mode of pin during runtime
														8)InternalResistor: internal pullup or pulldown in case of input direciton
 */
typedef struct 
{
    uint8 port_num; 
    Port_PinType pin_num;
	Port_PinModeType PinMode; 	
    Port_PinDirectionType PinDirection;
	uint8 PinLevelInitValue;
	uint8 InternalResistor;
	uint8 PinDirectionChangeable;
	uint8 PinModeChangeable;
	
}Port_ConfigChannel;
typedef struct
{
	Port_ConfigChannel Channels[PORT_Configured_Channels]; 
}Port_ConfigType;

/*typedef enum for pin levels to be used in the containers*/
 typedef enum
 {
	PORT_PIN_LEVEL_HIGH,
	PORT_PIN_LEVEL_LOW
 }Port_PinLevel;
 
 /*typedef of enum for modes of pins to be used in the containers , 
  *contains:	1) PORT_PIN_MODE_ADC:ADC mode
				2) PORT_PIN_MODE_CAN:CAN mode
				3) PORT_PIN_MODE_DIO:DIO mode
				4) PORT_PIN_MODE_DIO_GPT:Timers mode
				5) PORT_PIN_MODE_DIO_WDG:Watchdog mode
				6) PORT_PIN_MODE_FLEXRAY:Flexray mode
				7) PORT_PIN_MODE_ICU:Input capture unit mode
				8) PORT_PIN_MODE_LIN:LIN mode
				9) PORT_PIN_MODE_MEM:Memory mode
				10)PORT_PIN_MODE_PWM:PWM mode
				11)PORT_PIN_MODE_SPI:SPI mode
  */
 typedef enum/*examples for modes*/
 {
	PORT_PIN_MODE_ADC,
	PORT_PIN_MODE_CAN,
	PORT_PIN_MODE_DIO,
	PORT_PIN_MODE_DIO_GPT,
	PORT_PIN_MODE_DIO_WDG,
	PORT_PIN_MODE_FLEXRAY,
	PORT_PIN_MODE_ICU,
	PORT_PIN_MODE_LIN,
	PORT_PIN_MODE_MEM,
	PORT_PIN_MODE_PWM,
	PORT_PIN_MODE_SPI
 }PORT_MODE_ID;
 
 /*typedef of enum for internal resistor to be used in the containers (names can be changed not in sws container)*/
 typedef enum 
 {
	 OFF,
	 PULLUP,
	 PULLDOWN
 }PORT_IntResitorType;
 
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/*Function for Port Initialize API*/
void Port_Init(const Port_ConfigType* ConfigPtr);

/*Function for Set Port Direction API only availabe if enabled*/
#if(PORT_SET_PIN_DIRECTION_API==STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction);
#endif 

/*Function for Refresh Port Direction API*/
void Port_RefreshPortDirection(void);

/*Function for Get Version Info API only availabe if enabled*/
#if(PORT_VERSION_INFO_API==STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

/*Function for Set Pin Mode API only availabe if enabled*/
#if (PORT_SET_PIN_MODE_API==STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Port_ConfigType Port_Configuration;

#endif