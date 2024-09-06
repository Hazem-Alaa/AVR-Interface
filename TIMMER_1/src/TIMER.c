/*
* TIMER.c
*
* Created: 28 - 7 - 2024 11  :  46  :  28 PM
*  Author: Abu_El_A7ZaaM
*/

#include "TIMER.h"

void TIMER1_Init(TIMER_INITTYPES * options)
{
	switch(options->mode)
	{
		case Timmer_Normal:
		Timer1_TCCR1A_Reg.bit.Timer_WGM10_Bit=0;
		Timer1_TCCR1A_Reg.bit.Timer_WGM11_Bit=0;
		Timer1_TCCR1B_Reg.bit.Timer_WGM12_Bit=0;
		Timer1_TCCR1B_Reg.bit.Timer_WGM13_Bit=0;
		break;
		
		case Timmer_CTC1:
		Timer1_TCCR1A_Reg.bit.Timer_WGM10_Bit=0;
		Timer1_TCCR1A_Reg.bit.Timer_WGM11_Bit=0;
		Timer1_TCCR1B_Reg.bit.Timer_WGM12_Bit=1;
		Timer1_TCCR1B_Reg.bit.Timer_WGM13_Bit=0;
		break;
		
		case Timmer_Fast_PWM1:
		Timer1_TCCR1A_Reg.bit.Timer_WGM10_Bit=0;
		Timer1_TCCR1A_Reg.bit.Timer_WGM11_Bit=1;
		Timer1_TCCR1B_Reg.bit.Timer_WGM12_Bit=1;
		Timer1_TCCR1B_Reg.bit.Timer_WGM13_Bit=1;
		break;

		case Timmer_PWM_Phase_Correct1:
		Timer1_TCCR1A_Reg.bit.Timer_WGM10_Bit=0;
		Timer1_TCCR1A_Reg.bit.Timer_WGM11_Bit=1;
		Timer1_TCCR1B_Reg.bit.Timer_WGM12_Bit=0;
		Timer1_TCCR1B_Reg.bit.Timer_WGM13_Bit=1;
		break;
	}
	Timer1_TCCR1B_Reg.allsetbit |= (options->prescaling);
	Timer1_TCCR1A_Reg.allsetbit |= ((options->COM1A_MODE)<<6);
	Timer1_TCCR1A_Reg.allsetbit |= ((options->COM1B_MODE)<<4);
}

void TIMER_OCR1A_SETVALUE(u16 value)
{
	Timer1_OCR1A_Reg=value;
}

void TIMER_OCR1B_SETVALUE(u16 value)
{
	Timer1_OCR1B_Reg=value;
}

void TIMER_ICR1_SETVALUE(u16 value)
{
	Timer1_ICR1_Reg=value;
}