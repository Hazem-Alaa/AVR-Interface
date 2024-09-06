/*
* LCD.c
*
* Created: 11 - 10 - 2023 10  :  49  :  05 AM
*  Author: Abu_El_A7ZaaM
*/
#include "DIO.h"
#include "LCD.h"

void LCD_Init(void)
{
	DIO_WriteChannal(LCD_RW,STD_Low);
	DIO_WriteChannal(LCD_E,STD_High);
	_delay_ms(20);
	LCD_Cmd(0x33);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);//4Bit Mode & 2Line & 5*8 Pixels
	LCD_Cmd(0x06);//Entry Mode Move to Right
	LCD_Cmd(0x0C);//Display ON & Cursor OFF & No Blink
}
void LCD_Cmd(u8 command)
{
	DIO_WriteChannal(LCD_RS,STD_Low);
	u8 PortValue=DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F)|(command & 0xF0);
	DIO_WritePort(LCD_DataPort,PortValue);
	DIO_WriteChannal(LCD_E,STD_Low);
	_delay_us(10);//instruction from datasheet
	DIO_WriteChannal(LCD_E,STD_High);
	
	_delay_us(5);
	
	PortValue=DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F)|(command << 4);
	DIO_WritePort(LCD_DataPort,PortValue);
	DIO_WriteChannal(LCD_E,STD_Low);
	_delay_us(10);
	DIO_WriteChannal(LCD_E,STD_High);
	
	_delay_us(2);//instruction from datasheet
}

void LCD_Char(s8 data)
{
	DIO_WriteChannal(LCD_RS,STD_High);
	u8 PortValue=DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F)|(data & 0xF0);
	DIO_WritePort(LCD_DataPort,PortValue);
	DIO_WriteChannal(LCD_E,STD_Low);
	_delay_us(10);
	DIO_WriteChannal(LCD_E,STD_High);
	
	_delay_us(5);
	
	PortValue=DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F)|(data << 4);
	DIO_WritePort(LCD_DataPort,PortValue);
	DIO_WriteChannal(LCD_E,STD_Low);
	_delay_us(10);
	DIO_WriteChannal(LCD_E,STD_High);
	
	_delay_us(2);
}

void LCD_String(u8 string[])
 {
	for(u8 i=0 ; string[i]!= '\0' ; i++)
	{
		LCD_Char(string[i]);
	}
}

void LCD_SetPos(u8 row,u8 colum)
{
	if(colum<8)
	{
		switch(row)
		{
			case 1:
			LCD_Cmd((0x80) |(colum & 0x0F));
			break;
			case 2:
			LCD_Cmd((0xC0) |(colum &0x0F));
			break;
		}
	}

}
void LCD_CustomChar(u8 loc,u8 data[])
{
	if(loc <8)
	{
		LCD_Cmd((0x40)+(loc*8));
		for(u8 i=0;i<8;i++)
		{
			LCD_Char(data[i]);
		}
	}
	
}
void LCD_Clear(void)
{
	LCD_Cmd(0x01);
}