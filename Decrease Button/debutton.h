#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"

#define DEC_PUSH_BUTTON_PA5   (*((volatile unsigned long *)0x40004080))

unsigned long switch_Input(uint32_t PORT);
void Delay (void); 
void decrease(uint32_t PORT);