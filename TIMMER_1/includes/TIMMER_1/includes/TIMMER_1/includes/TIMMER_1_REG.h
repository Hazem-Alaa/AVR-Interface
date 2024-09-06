/*
 * TIMMER_1_REG.h
 *
 * Created: 28 - 7 - 2024 5  :  17  :  17 PM
 *  Author: Abu_El_A7ZaaM
 */ 


#ifndef TIMMER_1_REG_H_
#define TIMMER_1_REG_H_

#include "STD_types.h"


#define Timer1_TCCR1A_Reg (*(volatile Timer_TCCR1Atypes*) 0x4F)   
#define Timer1_TCCR1B_Reg (*(volatile Timer_TCCR1Btypes*) 0x4E) 
#define Timer1_OCR1A_Reg (*(volatile u8*) 0x4A)
#define Timer1_OCR1B_Reg (*(volatile u8*) 0x48)
#define Timer1_ICR1_Reg (*(volatile u8*) 0x46)
#define Timer1_TIMSK_Reg (*(volatile u8*) 0x59)

#endif /* TIMMER_1_REG_H_ */