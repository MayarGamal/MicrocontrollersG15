
#include "button.h"
#include "PORT.h"



void SystemInit()
{}
	
int main()
{

	SYSCTL_RCGCGPIO_R	|= 0x02 ; // Clock = 000 0001 = PORT_A enable
	while((SYSCTL_PRGPIO_R & 0x02) == 0);

	button_Init( PORTB ,3 );
	button_Init( PORTB ,4 );


	while (1)
	{
		
	}
}
