/*
* PWM.c
*
* Created: 4 - 8 - 2024 10  :  14  :  38 AM
*  Author: Abu_El_A7ZaaM
*/

#include "PWM.h"

void PWM_Generate_COM1A(u8 duty)
{
	DIO_ConfigChannal(DIO_ChannalD5,Output);
	u16 ICR_VALUE = 0xFFFF;
	u16 OCR1A_VALUE = (u16)((((float)duty/100)*((u32)ICR_VALUE+1))-1);
	TIMER_OCR1A_SETVALUE(OCR1A_VALUE);
	TIMER_ICR1_SETVALUE(ICR_VALUE);
	TIMER_INITTYPES options = {Timmer_Fast_PWM1,clk_64,COM1A_NON_INVERTING,COM1A_DISable};
	TIMER1_Init(&options);
}

void PWM_Generate_COM1B(u16 duty)
{
	DIO_ConfigChannal(DIO_ChannalD4,Output);
	u16 ICR_VALUE = 0XFFFF;
	u16 OCR_VALUE = (u16)((((float)duty/100)*((u32)ICR_VALUE+1))-1);
	TIMER_OCR1B_SETVALUE(OCR_VALUE);
	TIMER_ICR1_SETVALUE(ICR_VALUE);
	TIMER_INITTYPES options = {Timmer_Fast_PWM1,clk_64,COM1B_DISable,COM1B_NON_INVERTING};
	TIMER1_Init(&options);
}