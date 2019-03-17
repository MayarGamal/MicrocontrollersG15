#include "button.h"

void button_Init ( unsigned long  port , char pin )
{	
	(*(volatile uint32_t *)(port + 0x0400)) |= 0<<pin  ;//DIR = Input 
	(*(volatile uint32_t *)(port + 0x0420)) = 0 ;//AFSEL
	(*(volatile uint32_t *)(port + 0x0528)) = 0 ;//AMSEL_R
	(*(volatile uint32_t *)(port + 0x052C)) = 0 ;//PCTL
	(*(volatile uint32_t *)(port + 0x0510)) |= 1 << pin ;//PUR
	(*(volatile uint32_t *)(port + 0x051C)) |= 1 <<pin ;//DEN
	(*(volatile uint32_t *)(port + 0x0520)) = 0x4C4F434B;//LOCK
	(*(volatile uint32_t *)(port + 0x0524)) |= 1<<pin ;//CR
}

