
#include "MyPort.h"
#include "stdio.h"
#include "stdlib.h"
#include "LCD.h"
#define GPIO_PF0_M					0x01U		// Pin 1 is connected to red
#define GPIO_PF4_M					0x10U		// Pin 4 is connected to switch
#define GPIO_PD0_M					0x001U		
#define GPIO_PA4_M					0x10U		
#define GPIO_PA2_M					0x04U	
#define GPIO_PA3_M					0x08U	


void Init_Button(uint8_t port_index, uint8_t pins_mask ,Port_PinDirectionType pins_direction,uint8_t enable){
port_Init(port_index);
Port_SetPinDirection(port_index,pins_mask,pins_direction);
Port_SetPinPullUp(port_index,pins_mask,enable);
}

void delay_milli(int n){
int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<3180;j++)
	{}
}
void delay(int t){
	int i;   
 SYSCTL_RCGCTIMER_R |=SYSCTL_RCGCTIMER_R0;     /* enable clock to Timer Block 0 */
    TIMER0_CTL_R &= ~0x01 ;	/* disable Timer before initialization */
	  TIMER0_CFG_R |=0x04;       /* 16-bit option */
    TIMER0_TAMR_R |= 0x02;        /* periodic mode and down-counter */
    TIMER0_TAILR_R = 3200;  /* Timer A interval load value register */
    TIMER0_ICR_R &= ~TIMER_ICR_TATOCINT;         /* clear the TimerA timeout flag*/
    TIMER0_CTL_R |=TIMER_CTL_TAEN ;      /* enable Timer A after initialization */
 
    for(i = 0; i < t; i++) { while ((TIMER0_RIS_R & 0x1) == 0) ;      /* wait for TimerA timeout flag */
        TIMER0_ICR_R &= ~TIMER_ICR_TATOCINT;      /* clear the TimerA timeout flag */
    }
		TIMER0_CTL_R &= ~0x01 ;	/* disable Timer before initialization */
}
