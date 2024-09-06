/*
* DIO.c
*
* Created: 30 - 9 - 2023 2  :  24  :  35 PM
*  Author: Abu_El_A7ZaaM
*/


#include "DIO.h"


void DIO_WriteChannal(DIO_ChannalTypes ChannalId,STD_LevelTypes Level)
{
	DIO_ChannalTypes BitNo= ChannalId %8;
	DIO_PortTypes Portx= ChannalId /8;
	switch(Portx)
	{
		case DIO_PortA:
		if(Level == STD_High)
		{
			SET_BIT(PORTA_Reg,BitNo);
		}
		else
		{
			CLEAR_BIT(PORTA_Reg,BitNo);
		}
		break;
		
		case DIO_PortB:
		if(Level ==STD_High)
		{
			SET_BIT(PORTB_Reg,BitNo);
		}
		else
		{
			CLEAR_BIT(PORTB_Reg,BitNo);
		}
		break;
		
		case DIO_PortC:
		if(Level ==STD_High)
		{
			SET_BIT(PORTC_Reg,BitNo);
		}
		else
		{
			CLEAR_BIT(PORTC_Reg,BitNo);
		}
		break;
		
		case DIO_PortD:
		if(Level ==STD_High)
		{
			SET_BIT(PORTD_Reg,BitNo);
		}
		else
		{
			CLEAR_BIT(PORTD_Reg,BitNo);
		}
		break;
		
	}
	
}


STD_LevelTypes DIO_ReadChannal(DIO_ChannalTypes ChannalId)
{
	DIO_ChannalTypes BitNo= ChannalId%8;
	DIO_PortTypes Portx= ChannalId/8;
	STD_LevelTypes BIT_Res=STD_Low;
	switch(Portx)
	{
		case DIO_PortA:
		BIT_Res=GET_BIT(PINA_Reg,BitNo);
		break;
		
		case DIO_PortB:
		BIT_Res=GET_BIT(PINB_Reg,BitNo);
		break;
		
		case DIO_PortC:
		BIT_Res=GET_BIT(PINC_Reg,BitNo);
		break;
		
		case DIO_PortD:
		BIT_Res=GET_BIT(PIND_Reg,BitNo);
		break;
	}
	return BIT_Res;
}

void DIO_ToggleChannal(DIO_ChannalTypes ChannalId)
{
	DIO_ChannalTypes BitNo= ChannalId%8;
	DIO_PortTypes Portx= ChannalId/8;

	switch(Portx)
	{
		case DIO_PortA:
		TOGGLE_BIT(PORTA_Reg,BitNo);
		break;
		
		case DIO_PortB:
		TOGGLE_BIT(PORTB_Reg,BitNo);
		break;
		
		case DIO_PortC:
		TOGGLE_BIT(PORTC_Reg,BitNo);
		break;
		
		case DIO_PortD:
		TOGGLE_BIT(PORTD_Reg,BitNo);
		break;
	}
}

void DIO_ConfigChannal(DIO_ChannalTypes ChannalId , DIO_LevelTypes direction)
{
	DIO_ChannalTypes BitNo= ChannalId%8;
	DIO_PortTypes Portx= ChannalId/8;
	switch(Portx)
	{
		case DIO_PortA:
		if(direction ==Output)
		{
			SET_BIT(DDRA_Reg,BitNo);
		}
		else
		{
			CLEAR_BIT(DDRA_Reg,BitNo);
		}
		break;
		
		case DIO_PortB:
		if(direction ==Output)
		{
			SET_BIT(DDRB_Reg,BitNo);
		}
		else
		{
			CLEAR_BIT(DDRB_Reg,BitNo);
		}
		break;
		
		case DIO_PortC:
		if(direction ==Output)
		{
			SET_BIT(DDRC_Reg,BitNo);
		}
		else
		{
			CLEAR_BIT(DDRC_Reg,BitNo);
		}
		break;
		
		case DIO_PortD:
		if(direction ==Output)
		{
			SET_BIT(DDRD_Reg,BitNo);
		}
		else
		{
			CLEAR_BIT(DDRD_Reg,BitNo);
		}
		break;
	}
	
}

void DIO_WritePort(DIO_PortTypes PortId,u8 portvalue)
{
	switch(PortId)
	{
		case DIO_PortA:
		PORTA_Reg=portvalue;
		break;
		
		case DIO_PortB:
		PORTB_Reg=portvalue;
		break;
		
		case DIO_PortC:
		PORTC_Reg=portvalue;
		break;
		
		case DIO_PortD:
		PORTD_Reg=portvalue;
		break;
	}
}

u8 DIO_ReadPort(DIO_PortTypes PortId)
{
	u8 portvalue=STD_Low;
	switch(PortId)
	{
		case DIO_PortA:
		portvalue=PORTA_Reg;
		break;
		case DIO_PortB:
		portvalue=PORTB_Reg;
		break;
		case DIO_PortC:
		portvalue=PORTC_Reg;
		break;
		case DIO_PortD:
		portvalue=PORTD_Reg;
		break;
	}
	return portvalue;
}

void DIO_WriteData(DIO_PortTypes PortId,u8 masked,u8 PortValue)
{
	switch(PortId){
		case DIO_PortA :
		PORTA_Reg =(PortValue & masked) | (PORTA_Reg & ~(masked));
		break;
		case DIO_PortB :
		PORTB_Reg = (PortValue & masked) | (PORTB_Reg & ~(masked));
		break;
		case DIO_PortC :
		PORTC_Reg = (PortValue & masked) | (PORTC_Reg & ~(masked));
		break;
		case DIO_PortD :
		PORTD_Reg = (PortValue & masked) | (PORTD_Reg & ~(masked));
		break;
	}
}