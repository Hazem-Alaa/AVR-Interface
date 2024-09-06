/*
* KEYPAD_Config.h
*
* Created: 15 - 10 - 2023 11  :  06  :  05 PM
*  Author: Abu_El_A7ZaaM
*/


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "STD_types.h"

#define r0 DIO_ChannalD0
#define r1 DIO_ChannalD1
#define r2 DIO_ChannalA0
#define r3 DIO_ChannalD3

#define c0 DIO_ChannalC0
#define c1 DIO_ChannalC1
#define c2 DIO_ChannalA2
#define c3 DIO_ChannalC3

#define ColsCount 4
#define RowsCount 4


u8 KeypadRows[RowsCount]={r0,r1,r2,r3};
u8 KeypadCols[ColsCount]={c0,c1,c2,c3};
u8 keypadstr[RowsCount][ColsCount]={{'7','8','9','/'}
	                                ,{'4','5','6','*'}
									,{'1','2','3','-'}
									,{'C','0','=','+'}};

#endif /* KEYPAD_CONFIG_H_ */