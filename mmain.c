#include "MyButtonDriver.h"
#include "string.h"

void delay_milli(int n);
unsigned char DIO_ReadPort (void);
unsigned char DIO_ReadPort2 (void);
unsigned char DIO_ReadPortInc (void);
unsigned char DIO_ReadPortDec (void);
unsigned char DIO_ReadPortReset (void);
void LCDWrite( char[]);
void SystemInit(void){
	Init_Button(0,0x1C,PORT_PIN_IN,1); // pin A0,A1,A2 as switch
}
int __main(void){
 
	unsigned char increase=0;
unsigned char reset=0;
unsigned char decrease=0;
	unsigned int count=11;
 char cstr[3];
cstr[0]='0';
cstr[1]='0';
cstr[2]='0'; 
	LCDWrite(cstr);
	while(1){
increase=DIO_ReadPortInc();
	reset=DIO_ReadPortReset();
	decrease=DIO_ReadPortDec();
		////////////////////////////increase
	if(increase!=GPIO_PA2_M){	
		count++;
		sprintf(cstr,"%d",count);
		LCDWrite(cstr);
		do{delay_milli(200);
			increase=DIO_ReadPortInc();
			if(increase!=GPIO_PA2_M){	
				count++;
				sprintf(cstr,"%d",count);
		LCDWrite(cstr);
				}
		}while(increase!=GPIO_PA2_M);
	}
	////////////////////reset
	if(reset!=GPIO_PA3_M){	
		while(reset!=GPIO_PA3_M){reset=DIO_ReadPortReset();}
			count=000;
	sprintf(cstr,"%d",count);
		LCDWrite(cstr);
	}
	
	//////////////////////decrease
	if (decrease!=GPIO_PA4_M){
		if (count == 0){
			count =000; 
			sprintf(cstr,"%d",count);
			LCDWrite(cstr);
		}else{
			count--; 
			sprintf(cstr,"%d",count);
		LCDWrite(cstr);
		}
		do{
			decrease=DIO_ReadPortDec();
		}while(decrease!=GPIO_PA4_M);
	}
}
//	return 0;
}
void delay_milli(int n){
int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<3180;j++)
	{}
}
unsigned char DIO_ReadPort (void){
	return GPIO_PORTF_DATA_R&GPIO_PF4_M;
}

unsigned char DIO_ReadPort2 (void){
	return GPIO_PORTF_DATA_R&GPIO_PF0_M;
}

unsigned char DIO_ReadPortReset (void){
	return GPIO_PORTA_DATA_R&GPIO_PA3_M;
}

unsigned char DIO_ReadPortDec (void){
	return GPIO_PORTA_DATA_R&GPIO_PA4_M;
}

	
unsigned char DIO_ReadPortInc (void){
	return GPIO_PORTA_DATA_R&GPIO_PA2_M;}

	
	