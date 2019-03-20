#ifndef LCD_H_
#define LCD_H_

#include "stdint.h"
#include "tm4c123gh6pm.h"

void delay_Micro(int n);
void LCD_command(int com);
void LCD_data(unsigned char data);
void init (void);

	

#endif