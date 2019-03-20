
#include "DIO.h"


uint8_t DIO_ReadPort(uint8_t port_index,uint8_t pins_mask)
{  
	uint8_t pins_level;
	
	if( port_index <= 3)
	{
		pins_level = (*(volatile uint32_t *)( (port_index * 0x00001000 ) + 0x400043FC)) & pins_mask ;
		return pins_level;
	
	  }
	else 
	{                                                 
		pins_level =(*(volatile uint32_t *)( ((port_index-4) * 0x00001000) + 0x400243FC)) & pins_mask;
		return pins_level;
	}
	
       
		 
	 
	 }
void DIO_WritePort( uint8_t port_index,uint8_t pins_mask, DIO_LEVELTYPE pins_level)
	{

		
		if( pins_level==STD_HIGH)
		{
			if( port_index <= 3)
				(*(volatile uint32_t *)		((port_index * 0x00001000)  +0x400043FC)) |= pins_mask  ;
		else 
			(*(volatile uint32_t *)(((port_index-4) * 0x00001000) + 0x400243FC)) |= pins_mask  ;			
		}
	else
	{
		if( port_index <=3)
			(*(volatile uint32_t *)((port_index * 0x00001000) + 0x400043FC)) &= ~pins_mask  ;
		else
			(*(volatile uint32_t *)(((port_index-4) * 0x00001000) + 0x400243FC)) &= ~pins_mask  ;	
	}


  }
	
	void DIO_FlipPort( uint8_t port_index,uint8_t pins_mask)
	{if( port_index <= 3)
	{
	 (*(volatile uint32_t *)( (port_index * 0x00001000 ) + 0x400043FC)) ^= pins_mask ;
		
	
	  }
	else 
	{                                                 
		(*(volatile uint32_t *)( ((port_index-4) * 0x00001000) + 0x400243FC)) ^= pins_mask;
	
	}
	
	}
	
