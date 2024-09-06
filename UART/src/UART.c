/*
* UART.c
*
* Created: 5 - 8 - 2024 3  :  20  :  31 PM
*  Author: Abu_El_A7ZaaM
*/
#include "UART_Config.h"
#include "UART_Reg.h"
#include "UART_Types.h"
#include "UART.h"
#include "clock.h"

void UART_INIT(UART_INIT_options * options)
{
	u8 MyUBBR=0; // Select baud rate and mode of speed
	if (options->Doublespeed == UART_DOUBLE)
	{
		UART_Reg->UCSRA_Reg.BIT.U2X_bit=1;
		MyUBBR = ((F_CPU/8UL*options->BaudRate)-1);
	}
	else
	{
		UART_Reg->UCSRA_Reg.BIT.U2X_bit=0;
		MyUBBR = ((F_CPU/16UL*options->BaudRate)-1);
	}
	UART_Reg->UBRRL_Reg = MyUBBR;
	UART_Reg->UCSRC_Reg.UCSRC_ALLBITS = (MyUBBR>>8);
	
	
	UART_Reg->UCSRB_Reg.BIT.RXEN_bit=options->RXMODE;
	UART_Reg->UCSRB_Reg.BIT.TXEN_bit=options->TXMODE;


	UART_Reg->UCSRC_Reg.UCSRC_ALLBITS = (UCSRC_select) |(options->SelectStopBit<<SHIF_STOP);
	UART_Reg->UCSRC_Reg.UCSRC_ALLBITS = (UCSRC_select) |(options->SelectParity<<SHIF_PARITY);
 

	if (options->SelectDataSize == UART_9_bit)
	{
		UART_Reg->UCSRC_Reg.BIT.UCSZ0_bit=1;
		UART_Reg->UCSRC_Reg.BIT.UCSZ1_bit=1;
		UART_Reg->UCSRB_Reg.BIT.UCSZ2_bit=1;
	}
	else
	{
		UART_Reg->UCSRC_Reg.UCSRC_ALLBITS |= (UCSRC_select) | ((options->SelectDataSize)<<UART_DataSize);
	}
}

void UART_TRANSMITER(u8 data)
{
	while(UART_Reg->UCSRA_Reg.BIT.UDRE_bit==0);
	UART_Reg->UDR_Reg=data;
}
void UART_TRANSMITER_STRING(s8 * string)
{
	u8 i=0;
	while(string[i] != '\0')
	{
		UART_TRANSMITER(string[i]);
		i++;
	}
}
u8 UART_RECEIVE(void)
{
	while(UART_Reg->UCSRA_Reg.BIT.RXC_bit==0);
	return UART_Reg->UDR_Reg;
}

