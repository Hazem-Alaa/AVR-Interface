/*
* KAYPAD.c
*
* Created: 15 - 10 - 2023 11  :  06  :  22 PM
*  Author: Abu_El_A7ZaaM
*/

#include "DIO.h"
#include "KEYPAD.h"
#include "KEYPAD_Config.h"

void KEYPAD_Init(void)
{
	for(u8 i=0 ;i<RowsCount ;i++)
	{
		// rows -> output & 5V
		DIO_ConfigChannal(KeypadRows[i],Output);//rows -> output
		DIO_WriteChannal(KeypadRows[i],STD_High);//5V
	}
	
	for(u8 i=0 ;i<ColsCount ;i++)
	{
		// cols -> input & connect pull up Res.
		DIO_ConfigChannal(KeypadCols[i],Input);// cols -> input
		DIO_WriteChannal(KeypadCols[i],STD_High);//connect pull up Res
	}
}

u8 GetKey(void)
{
	for(u8 i = 0; i<RowsCount ;i++)
	{
		DIO_WriteChannal(KeypadRows[i],STD_Low);
		for(u8 j =0; j<ColsCount ;j++)
		{
			if(DIO_ReadChannal(KeypadCols[j])==STD_Low)
			{
				while(DIO_ReadChannal(KeypadCols[j])==STD_Low); // TO AVOID BUG (WRITE THE CHAR MORE THAN ONE )
				return keypadstr[i][j];
			}
		}
		DIO_WriteChannal(KeypadRows[i],STD_High);
	}
	return STD_Low;
}