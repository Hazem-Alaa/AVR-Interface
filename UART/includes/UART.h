/*
 * UART.h
 *
 * Created: 5 - 8 - 2024 3  :  18  :  51 PM
 *  Author: Abu_El_A7ZaaM
 */ 


#ifndef UART_H_
#define UART_H_

#include "UART_Types.h"
#include "UART_Config.h"
#include "UART_Reg.h"
#include "STD_types.h"

//void UART_INIT(UART_INIT_options * options);
void UART_TRANSMITER(u8 data);
void UART_TRANSMITER_STRING(s8 * string);
u8 UART_RECEIVE(void);


#endif /* UART_H_ */