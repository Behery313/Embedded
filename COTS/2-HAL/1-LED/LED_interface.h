/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	HAL				**********************/
/**************		SWC:	LED				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/

#ifndef LED_interface_H_
#define LED_interface_H_

/*************STATES***************/
#define LED_u8StateON		(u8) 1
#define LED_u8StateOFF		(u8) 0

/*******Connection type************/
#define LED_u8ConnSink		(u8) 0
#define LED_u8ConnSource	(u8) 1

/**********INPUT STRUCT************/
typedef struct LED_t{
	u8 LED_u8Port;//PORT to which led is connected
	u8 LED_u8Pin; //PIN to which led is connected
	u8 LED_u8Conn;//either sink or source connection
}LED_t;//led type


/**********Function Prototypes*****/
u8 LED_u8TurnON(LED_t * ptrStructLEDn);
u8 LED_u8TurnOFF(LED_t* ptrStructLEDn);


#endif
