#include <REGX51.H>
#include "spi.h"

void main()
{
	SPI_Init();
	SPI_SS = 0;
	
	while(1)
	{
		
		SPI_SendByte(0x99);
		delay_ms(500);
	}
}