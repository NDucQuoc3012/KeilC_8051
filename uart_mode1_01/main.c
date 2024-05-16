#include <REGX52.H>
#include "..\library\uart_mode1_lib\uart_mode1.h"
#define freq_ocs 11059200



void main ()
{
	unsigned char a;
	
	uart_init();
	
	while(1)
	{
		uart_write_text("nhap vao chu cai in thuong: ");
		while(RI == 0);
		a = uart_read();
		a = a-32;
		uart_write_text("->");
		uart_write(a);
		uart_write('\r');
	}
}