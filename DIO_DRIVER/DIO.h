#ifndef DIO_H_
#define DIO_H_

#include "stdint.h"
#include "C:/Keil/EE319KwareSpring2016/inc/tm4c123gh6pm.h"
	
	
#define PORTA 	0x40004000
#define PORTB 	0x40005000
#define PORTC 	0x40006000
#define PORTD 	0x40007000
#define PORTE 	0x40024000
#define PORTF 	0x40025000

#define PORTA_Index		0
#define PORTB_Index		1
#define PORTC_Index		2
#define PORTD_Index		3
#define PORTE_Index		4
#define PORTF_Index		5


typedef enum {
STD_LOW = 0 
,STD_HIGH= 1
} DIO_LEVELTYPE;
	
	
	#endif 
