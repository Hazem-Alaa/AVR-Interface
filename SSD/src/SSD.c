/*
* SSD.c
*
* Created: 17 - 10 - 2023 3  :  36  :  43 AM
*  Author: Abu_El_A7ZaaM
*/
#include "SSD.h"
#include "DIO.h"
#include "clock.h"

void SDD_Init(void)
{
	// set pins enable --> OutPut & Off
	DIO_ConfigChannal(SSD_Pin_E1,Output);
	DIO_ConfigChannal(SSD_Pin_E2,Output);
	DIO_WriteChannal(SSD_Pin_E1,STD_Low);
	DIO_WriteChannal(SSD_Pin_E2,STD_Low);
	
	// set pins data --> OutPut
	DIO_ConfigChannal(SSD_Pin_D,Output);
	DIO_ConfigChannal(SSD_Pin_C,Output);
	DIO_ConfigChannal(SSD_Pin_B,Output);
	DIO_ConfigChannal(SSD_Pin_A,Output);
	
	// set DP--> OutPut
	DIO_ConfigChannal(SSD_Pin_DP,Output);

}

void SDD_DisPlay(u8 num)
{
	u8 SSD_first_digit =(num%10)<<4;
	u8 SSD_secound_digit=(num/10)<<4;
	if(num<100)
	{
		// enable SSD1
		DIO_WriteChannal(SSD_Pin_E1,STD_High);
		// Disable SSD2
		DIO_WriteChannal(SSD_Pin_E2,STD_Low);
		// Write first digit
		DIO_WriteData(DIO_PortA,0xF0,SSD_first_digit);
		
		_delay_ms(1);
		
		DIO_WriteChannal(SSD_Pin_E1,STD_Low);
		DIO_WriteChannal(SSD_Pin_E2,STD_High);
		DIO_WriteData(DIO_PortA,0xF0,SSD_secound_digit);
		
		_delay_ms(1);
	}
}

void SDD_DisPlay_With_Delay(u8 num ,u8 delay)
{
	for(u32 i=0;i<delay;i+=3)
	{
		SDD_DisPlay(num);
		_delay_ms(10);
	}
}