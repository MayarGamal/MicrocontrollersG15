#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "tm4c123gh6pm.h"
#include "string.h"

void SystemInit(){}
void delay_Micro(int n){
		int i,j ;
		for (i=0 ; i<n ;i++ ){
		for (j=0 ; j<3 ;j++ ){}
		}
}
void LCD_command(int com)
{
GPIO_PORTE_DATA_R &= ~0x0F;//rs=0,rw=0,enable=0
GPIO_PORTB_DATA_R = com;
GPIO_PORTE_DATA_R |= 0x08; //enable =1
delay_Micro(230); //230microsec
GPIO_PORTE_DATA_R &= ~0x0F;//enable =0

}
void LCDWrite(unsigned char[] T)
{
	data[] = T;
	//strcpy(data,"123");
	int k =0;
  init();

	while (1)
	{

		LCD_command(0x84);
		while(k<3)
		{
		LCD_data(data[k]);
    k++;
		}
	}

}
