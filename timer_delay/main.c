#include <REGX52.H>

void delay_ms_timer0(unsigned int time)
{
	do{
		TH0 = 0xFC;
		TL0 = 0x18;
		TR0 = 1;
		while(!TF0);
		TR0 = 0;
		TF0 = 0;
		
		time--;
	}
	while(time != 0);
}


void main ()
{
	//cau hinh mode 1 cho timer 0;
	TMOD &= 0xF0;
	TMOD |= 0x01;
	
	while(1)
	{
		P2_0 = !P2_0;
		delay_ms_timer0(1000);
	}
}
