/*
 * LCD.h
 *
 * Created: 10 - 10 - 2023 9  :  16  :  42 PM
 *  Author: Abu_El_A7ZaaM
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "clock.h"

#define LCD_RS DIO_ChannalB1
#define LCD_RW DIO_ChannalB2
#define LCD_E DIO_ChannalB3

#define LCD_DataPort DIO_PortA

void LCD_Init(void);
void LCD_Cmd(u8 command);
void LCD_Char(s8 data);
void LCD_String(u8 string[]);
void LCD_SetPos(u8 row,u8 colum);
void LCD_CustomChar(u8 loc,u8 data[]);
void LCD_Clear(void);

#endif /* LCD_H_ */