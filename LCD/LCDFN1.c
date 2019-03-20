#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "tm4c123gh6pm.h"
#include "string.h"
#include "LCD.h"

void SystemInit(){}	

void LCD_data(unsigned char data)
{
GPIO_PORTE_DATA_R &= ~0x0F; //rs=0,rw=0,enable=0
GPIO_PORTE_DATA_R |= 0x02;	//rs=1
GPIO_PORTB_DATA_R = data;
GPIO_PORTE_DATA_R |= 0x08; //enable =1
delay_Micro(230); //230microsec	
GPIO_PORTE_DATA_R &= ~0x0F; //rs=1,rw=0,enable=0
GPIO_PORTE_DATA_R |= 0x02;
	
}	
void init (void)
{
SYSCTL_RCGCGPIO_R |= 0x12; //enable clock to port B &E
GPIO_PORTB_LOCK_R = 0x4C4F434B;
GPIO_PORTE_LOCK_R = 0x4C4F434B;
GPIO_PORTB_CR_R = 0xFF;
GPIO_PORTE_CR_R = 0x0E;	
GPIO_PORTB_DIR_R = 0xFF;   //all pins port B are output
GPIO_PORTB_DEN_R = 0xFF;   //all pins port B are digital enable
GPIO_PORTE_DIR_R = 0x0E;   //pins 3,2,1 are output portE  00001110
GPIO_PORTE_DEN_R = 0x0E;   //pins 3,2,1 are digital enable portE
GPIO_PORTB_AFSEL_R = 0;
GPIO_PORTB_PCTL_R = 0;
GPIO_PORTB_AMSEL_R = 0;
GPIO_PORTE_AFSEL_R = 0;
GPIO_PORTE_PCTL_R = 0;
GPIO_PORTE_AMSEL_R = 0;	

LCD_command(0x30);
LCD_command(0x0F);
LCD_command(0x01);
LCD_command(0x38);	
LCD_command(0x06);	
}
