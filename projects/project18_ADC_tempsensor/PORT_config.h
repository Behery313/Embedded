/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	PORT			**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*NOTE*/
/*in case of input pin value is high for pullup or low for floating*/
/*in case of Output Pin value choose the required '1' for high '0' for low*/

/*****************************************************************/
/************************PORTA************************************/
/*****************************************************************/
	/*PORTA DIRECTIONS*/
	#define PORTA_PIN_0_DIR					INPUT  
	#define PORTA_PIN_1_DIR					INPUT  
	#define PORTA_PIN_2_DIR					INPUT  
	#define PORTA_PIN_3_DIR					INPUT  
	#define PORTA_PIN_4_DIR					OUTPUT
	#define PORTA_PIN_5_DIR					OUTPUT
	#define PORTA_PIN_6_DIR					OUTPUT
	#define PORTA_PIN_7_DIR					OUTPUT
	/*PORTA PIN INITIALISATIONS*/
	#define PORTA_PIN_0_InitValue			1
	#define PORTA_PIN_1_InitValue			1
	#define PORTA_PIN_2_InitValue			1
	#define PORTA_PIN_3_InitValue			1
	#define PORTA_PIN_4_InitValue			1
	#define PORTA_PIN_5_InitValue			1
	#define PORTA_PIN_6_InitValue			1
	#define PORTA_PIN_7_InitValue			1
	
/*****************************************************************/
/************************PORTB************************************/
/*****************************************************************/	
	/*PORTB DIRECTIONS*/
	#define PORTB_PIN_0_DIR					OUTPUT
	#define PORTB_PIN_1_DIR					OUTPUT
	#define PORTB_PIN_2_DIR					INPUT  
	#define PORTB_PIN_3_DIR					OUTPUT
	#define PORTB_PIN_4_DIR					INPUT  
	#define PORTB_PIN_5_DIR					INPUT  
	#define PORTB_PIN_6_DIR					INPUT  
	#define PORTB_PIN_7_DIR					INPUT  
	/*PORTB PIN INITIALISATIONS*/
	#define PORTB_PIN_0_InitValue			0
	#define PORTB_PIN_1_InitValue			0
	#define PORTB_PIN_2_InitValue			1
	#define PORTB_PIN_3_InitValue			0
	#define PORTB_PIN_4_InitValue			0
	#define PORTB_PIN_5_InitValue			0
	#define PORTB_PIN_6_InitValue			0
	#define PORTB_PIN_7_InitValue			0
/*****************************************************************/
/************************PORTC************************************/
/*****************************************************************/
	/*PORTC DIRECTIONS*/
	#define PORTC_PIN_0_DIR					OUTPUT
	#define PORTC_PIN_1_DIR					OUTPUT
	#define PORTC_PIN_2_DIR					OUTPUT
	#define PORTC_PIN_3_DIR					INPUT  
	#define PORTC_PIN_4_DIR					INPUT  
	#define PORTC_PIN_5_DIR					INPUT  
	#define PORTC_PIN_6_DIR					INPUT  
	#define PORTC_PIN_7_DIR					INPUT  
	/*PORTC PIN INITIALISATIONS*/
	#define PORTC_PIN_0_InitValue			0  
	#define PORTC_PIN_1_InitValue			0  
	#define PORTC_PIN_2_InitValue			0  
	#define PORTC_PIN_3_InitValue			0  
	#define PORTC_PIN_4_InitValue			0  
	#define PORTC_PIN_5_InitValue			0  
	#define PORTC_PIN_6_InitValue			0  
	#define PORTC_PIN_7_InitValue			0  
/*****************************************************************/
/************************PORTD************************************/
/*****************************************************************/
	/*PORTD DIRECTIONS*/
	#define PORTD_PIN_0_DIR					OUTPUT
	#define PORTD_PIN_1_DIR					OUTPUT
	#define PORTD_PIN_2_DIR					INPUT
	#define PORTD_PIN_3_DIR					INPUT
	#define PORTD_PIN_4_DIR					OUTPUT
	#define PORTD_PIN_5_DIR					OUTPUT
	#define PORTD_PIN_6_DIR					OUTPUT
	#define PORTD_PIN_7_DIR					OUTPUT
	/*PORTD PIN INITIALISATIONS*/
	#define PORTD_PIN_0_InitValue			0  
	#define PORTD_PIN_1_InitValue			0  
	#define PORTD_PIN_2_InitValue			1
	#define PORTD_PIN_3_InitValue			1
	#define PORTD_PIN_4_InitValue			0  
	#define PORTD_PIN_5_InitValue			0  
	#define PORTD_PIN_6_InitValue			0  
	#define PORTD_PIN_7_InitValue			0  
#endif
