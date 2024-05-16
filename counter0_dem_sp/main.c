#include <REGX52.H>
#include "..\library\delay_lib\delay.h"

unsigned char code a[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void display(unsigned int n)
{
	unsigned char don_vi, chuc, tram, ngan, chuc_ngan;
	chuc_ngan = n / 10000;
	n = n%10000;
	ngan = n / 1000;
	n = n%1000;
	tram = n / 100;
	n = n%100;
	chuc = n / 10;
	n = n%10;
	don_vi = n;
	
	P0 = a[chuc_ngan];
	P2_1 = 0;
	delayMs(1);
	P2_1 = 1;
	
	P0 = a[ngan];
	P2_2 = 0;
	delayMs(1);
	P2_2 = 1;
	
	P0 = a[tram];
	P2_3 = 0;
	delayMs(1);
	P2_3 = 1;
	
	P0 = a[chuc];
	P2_4 = 0;
	delayMs(1);
	P2_4 = 1;
	
	P0 = a[don_vi];
	P2_5 = 0;
	delayMs(1);
	P2_5 = 1;
	
}

void main()
{
	unsigned int n;
	TMOD &= 0xF0;
	TMOD |= 0x05;
	TR0 = 1;
	
	while(1)
	{
		do{
			n = TH0;
			n = n << 8;
			n = n | TL0;
		}while( (n>>8) != TH0);
		
		display(n);
	}
}