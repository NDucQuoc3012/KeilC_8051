#include <REGX51.H>
#include <Thu_Vien_LCD_I2C.H>

unsigned char slave1 = 0X7E; // dia chi cua module 1
unsigned char slave2 = 0X70; // dia chi cua module 2

int dem1=0, dem2=20;

void delay(long time)
{
	time = time * 25;
	while(time--) {}
}
void main(void)
{
	LCD_Slave(slave1);
	LCD_Init();
	LCD_Gotoxy(1,1); // cot dau tien - hang dau tien
	LCD_Send_String("Mandevices");
	LCD_Gotoxy(1,2); // cot dau tien - hang dau tien
	LCD_Send_String("LCD 1");
	
	LCD_Slave(slave2);
	LCD_Init();
	LCD_Gotoxy(1,1); // cot dau tien - hang dau tien
	LCD_Send_String("LIDP");
	LCD_Gotoxy(1,2); // cot dau tien - hang dau tien
	LCD_Send_String("LCD 2");
	
	delay(1000);
	
	LCD_Slave(slave1);
	LCD_Clear();
	LCD_Slave(slave2);
	LCD_Clear();
	
	while(1)
	{
		LCD_Slave(slave1);
		LCD_Gotoxy(1,1); // cot dau tien - hang dau tien
		LCD_Send_String("Len ma xem");
		LCD_Gotoxy(1,2); // cot dau tien - hang dau tien
		LCD_Send_Number(dem1);
		
		LCD_Slave(slave2);
		LCD_Gotoxy(1,1); // cot dau tien - hang dau tien
		LCD_Send_String("youtube");
		LCD_Gotoxy(1,2); // cot dau tien - hang dau tien
		LCD_Send_Number(dem2);
		
		delay(250);
		dem1++; dem2++;
		
	}
}


