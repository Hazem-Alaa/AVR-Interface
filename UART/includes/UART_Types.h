/*
* UART_Types.h
*
* Created: 5 - 8 - 2024 3  :  19  :  34 PM
*  Author: Abu_El_A7ZaaM
*/


#ifndef UART_TYPES_H_
#define UART_TYPES_H_
#include "STD_types.h"
#include "UART.h"
#include "UART_Config.h"
#include "UART_Reg.h"

typedef struct
{
	u8 RXC_bit:1;
	u8 TXC_bit:1;
	u8 UDRE_bit:1;
	u8 FE_bit:1;
	u8 DOR_bit:1;
	u8 PE_bit:1;
	u8 U2X_bit:1;
	u8 MPCM_bit:1;
}UART_UCSRA;

typedef struct
{
	u8 RXCIE_bit:1;
	u8 TXCIE_bit:1;
	u8 UDRIE_bit:1;
	u8 RXEN_bit:1;
	u8 TXEN_bit:1;
	u8 UCSZ2_bit:1;
	u8 RXB8_bit:1;
	u8 TXB8_bit:1;
}UART_UCSRB;

typedef struct
{
	u8 URSEL_bit:1;
	u8 UMSEL_bit:1;
	u8 UPM1_bit:1;
	u8 UPM0_bit:1;
	u8 USBS_bit:1;
	u8 UCSZ1_bit:1;
	u8 UCSZ0_bit:1;
	u8 UCPOL_bit:1;
}UART_UCSRC;

typedef union
{
	u8 UCSRA_ALLBITS;
	UART_UCSRA BIT;
	
}UART_UCSRA_BITS;

typedef union
{
	u8 UCSRB_ALLBITS;
	UART_UCSRB BIT;
	
}UART_UCSRB_BITS;

typedef union
{
	u8 UCSRC_ALLBITS;
	UART_UCSRC BIT;
	
}UART_UCSRC_UBRRH_BITS;

typedef enum
{
	TX_Disable=0,
	TX_ENABLE
}UART_TX;

typedef enum
{
	RX_Disable=0,
	RX_ENABLE
}UART_RX;

typedef enum
{
	UART_5_bit,
	UART_6_bit,
	UART_7_bit,
	UART_8_bit,
	UART_Reserved1,
	UART_Reserved2,
	UART_Reserved3,
	UART_9_bit
}UART_SelectDataSize;
 
typedef enum
{
	UART_Disabled,
	UART_Reserved,
	UART_Enabled_Even_Parity,
	UART_Enabled_Odd_Parity
}UART_SelecParity;

typedef enum
{
	UART_1BIT_Stop,
	UART_2BIT_Stop
}UART_SelecStopBit;

typedef enum
{
	UART_BaudRate_2400=2400,
	UART_BaudRate_4800=4800,
	UART_BaudRate_9600=9600,
	UART_BaudRate_14400=14400,
	UART_BaudRate_19200=19200,
	UART_BaudRate_28800=28800,
	UART_BaudRate_38400=38400,
	UART_BaudRate_57600=57600,
	UART_BaudRate_76800=76800
	
}UART_BaudRate;

typedef enum
{
	UART_NORMAL,
	UART_DOUBLE
}UART_DOUBLE_SPEED;

typedef enum
{
	UART_Asynchronous,
	UART_Synchronous
}UART_SelecModeOperation;

typedef struct
{
	UART_BaudRate BaudRate;
	UART_DOUBLE_SPEED Doublespeed ;
	UART_SelectDataSize SelectDataSize;
	UART_SelecParity SelectParity;
	UART_SelecStopBit SelectStopBit;
	UART_TX TXMODE;
	UART_RX RXMODE;
	
}UART_INIT_options;

typedef struct
{
	u8 UBRRL_Reg;
	UART_UCSRB_BITS UCSRB_Reg;
	UART_UCSRA_BITS UCSRA_Reg;
	u8 UDR_Reg;
	u8 RESERVED[19];
	UART_UCSRC_UBRRH_BITS UCSRC_Reg;
}UART_Registers;
#endif /* UART_TYPES_H_ */