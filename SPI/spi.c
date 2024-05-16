#include <REGX52.H>
#include <stdio.h>
#include <stdlib.h>
#include "spi.h"


//SPI


void SPI_Init(){
	SPI_SS 	 = 1; 	//set SS o muc cao khi ranh, va keo xuong de truyen tin hieu
	SPI_SCLK = 0; 	//set SCLK o muc thap, SPOL = 0 - muc thap o che do idle 
	SPI_MISO = 1; 	//set duong vao master o che do cao, san sang nhan tin hieu tu thiet bi Slave 

}
void SPI_SendByte(unsigned char b){
	unsigned char i;
	for(i=0;i<8;i++){ //1 byte = 8 bits
		SPI_SCLK = 0; 	//keo xung clock xuong muc thap de chuan bi gui di
		if(b&0x80)			//lay bit cao nhat cua b
			SPI_MOSI = 1;	//neu bit xet la 1 thi gui 1 di
		else
			SPI_MOSI = 0;	//neu khong phai 1 thi gui 0 di
		SPI_SCLK = 1;		//keo xung clock len de bat dau gui du lieu di (rising)
		b<<=1;					//dich trai 1 bit => xoa bit da gui
		SPI_SCLK = 0; 	//keo xung clock xuong muc thap de cho gui di
	}
}

unsigned char SPI_ReceiveByte(){
	unsigned char i, b;
	for(i=0;i<8;i++){
		b<<=1;					//b dich trai 1 bits => chuan bi cho qua trinh nhan 1 bit thap
		SPI_SCLK = 1; 	//Keo xung clock len => bat dau nhan tin hieu (rising)
		if(SPI_MISO)		//Neu tin hieu nhan duoc = 1
			b|=0x01;			// set gia tri bits thap nhat len 1
		SPI_SCLK = 0; 	//Keo xung clock xuong, che do cho
	}
	return b;					//Tra ve tin hieu vua nhan duoc
}

unsigned char SPI_SendAndReceiByte(unsigned char b){
	unsigned char i, temp;
	for(i=0;i<8;i++){
		SPI_SCLK = 0; 	//keo xung clock xuong muc thap de cho gui/nhan data
		if(b&0x80)				//SEND: lay bit cao nhat cua b
			SPI_MOSI = 1;		//SEND: neu bit xet la 1 thi gui 1 di
		else
			SPI_MOSI = 0;		//SEND:neu khong phai 1 thi gui 0 di
		temp<<=1;					//RECEIVE: temp dich trai 1 bits => chuan bi cho qua trinh nhan 1 bit thap
		SPI_SCLK = 1;		//keo xung clock len de bat dau gui/nhan du lieu di (rising)
		b<<=1;						//SEND: dich trai 1 bit => xoa bit da gui
		
		if(SPI_MISO)			//RECEIVE: Neu tin hieu nhan duoc = 1
			temp|=0x01;			//RECEIVE: set gia tri bits thap nhat len 1
		
		SPI_SCLK = 0; 	//keo xung clock xuong muc thap de cho gui di
	}
	return temp;			//Tra ve tin hieu vua nhan duoc
}

void delay_ms(unsigned int ms) {
    unsigned int i, j; 
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 114; j++);
    }
}


