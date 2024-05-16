#ifndef _SPI_H
#define _SPI_H

sbit SPI_SCLK = P3^0;
sbit SPI_MOSI = P3^1;
sbit SPI_MISO = P3^2;
sbit SPI_SS		= P3^3;


void delay_ms(unsigned char ms);
void SPI_Init();
void SPI_SendByte(unsigned int b);
unsigned char SPI_ReceiveByte();
unsigned char SPI_SendAndReceiByte(unsigned char b);

#endif