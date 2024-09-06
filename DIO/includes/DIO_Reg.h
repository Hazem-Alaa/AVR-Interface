/*
* DIO_Geg.h
*
* Created: 30 - 9 - 2023 11  :  50  :  08 AM
*  Author: Abu_El_A7ZaaM
*/



#ifndef DIO_REG_H_
#define DIO_REG_H_

#include "STD_types.h"

#define PIND_Reg (*(volatile u8*)0x30)
#define DDRD_Reg (*(volatile u8*)0x31)
#define PORTD_Reg (*(volatile u8*)0x32)

#define PINC_Reg (*(volatile u8*)0x33)
#define DDRC_Reg (*(volatile u8*)0x34)
#define PORTC_Reg (*(volatile u8*)0x35)

#define PINB_Reg (*(volatile u8*)0x36)
#define DDRB_Reg (*(volatile u8*)0x37)
#define PORTB_Reg (*(volatile u8*)0x38)

#define PINA_Reg (*(volatile u8*)0x39)
#define DDRA_Reg (*(volatile u8*)0x3A)
#define PORTA_Reg (*(volatile u8*)0x3B)




#endif /* DIO_GEG_H_ */