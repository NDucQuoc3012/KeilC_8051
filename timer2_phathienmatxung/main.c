#include <REGX52.H>

void main()
{
	T2MOD = 0x00;
	EXEN2 = 1;
	
	RCAP2H = 0x3C;
	RCAP2L = 0xB0;
	
	EA = 1;
	ET2 = 1;
	
	P2 = 0x00;
	while(1)
	{
		
	}
}

void timer2overflow(void)  interrupt 5
{
	if(EXF2)
	{
		TR2 = 1;
		EXF2 = 0;
	}
	else
	{
		TR2 = 0;
		P2++;
		TF2 = 0;
	}
}