#include "debutton.h"

unsigned long Switch_Input(unsigned long PORT){
  return (GPIO_PORTA_DATA_R & 0x20); // 0x20(not pressed) or 0(pressed)
}

// Delay function
void Delay (void){
	unsigned long volatile time; 
	time = 290896; // 0.2 sec
	while(time){
		time--; 
	}
}

// SysInit
void SystemInit(void){

}
// Main fn 
unsigned int count;

void Decrease(unsigned long PORT){
	unsigned char state; 
	state = Switch_Input(PORT);
		while(1){
			if (state == 0){
				count--; 
				do {
					state = Switch_Input(PORT);
				}while(state == 0);
			}
		}
}