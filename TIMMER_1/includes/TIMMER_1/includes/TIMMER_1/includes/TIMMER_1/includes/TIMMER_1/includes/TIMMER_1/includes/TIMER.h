/*
 * TIMER.h
 *
 * Created: 28 - 7 - 2024 11  :  46  :  12 PM
 *  Author: Abu_El_A7ZaaM
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "TIMER1_REG.h"
#include "TIMER1_TYPES.h"


void TIMER1_Init(TIMER_INITTYPES * options);
void TIMER_OCR1A_SETVALUE(u16 value);
void TIMER_OCR1B_SETVALUE(u16 value);
void TIMER_ICR1_SETVALUE(u16 value);

#endif /* TIMER_H_ */