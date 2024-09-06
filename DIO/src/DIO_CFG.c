/*
* DIO_CFG.c
*
* Created: 30 - 9 - 2023 6  :  16  :  29 PM
*  Author: Abu_El_A7ZaaM
*/

#include "DIO.h"
#include "DIO_CFG.h"

PortPin PinCfg[]={
	
	//PORTA
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTB
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTC
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTD
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High}
};


void DIO_INIT(void)//this function for (DDR REGISTER)
{
	DIO_ChannalTypes count =DIO_ChannalA0;
	for(count =DIO_ChannalA0; count<PINCOUNT ;count++)
	{
		//DIO_ConfigChannal(count,PinCfg[count].direction); //this is anothor way
		DIO_PortTypes Portx =count/8;
		DIO_ChannalTypes BitNo =count%8;
		switch(Portx)
		{
			case DIO_PortA:
			if(PinCfg[count].direction==Output)
			{
				SET_BIT(DDRA_Reg,BitNo);
			}
			else
			{
				CLEAR_BIT(DDRA_Reg,BitNo);
			}
			break;
			
			case DIO_PortB:
			if(PinCfg[count].direction==Output)
			{
				SET_BIT(DDRB_Reg,BitNo);
			}
			else
			{
				CLEAR_BIT(DDRB_Reg,BitNo);
			}
			break;
			
			case DIO_PortC:
			if(PinCfg[count].direction==Output)
			{
				SET_BIT(DDRC_Reg,BitNo);
			}
			else
			{
				CLEAR_BIT(DDRC_Reg,BitNo);
			}
			break;
			
			case DIO_PortD:
			if(PinCfg[count].direction==Output)
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
}


void DIO_INITPort(void)//this function for (Port REGISTER)
{
	DIO_ChannalTypes count =DIO_ChannalA0;
	for(count =DIO_ChannalA0; count<PINCOUNT ;count++)
	{
		//DIO_ConfigChannal(count,PinCfg[count].direction); //this is anothor way
		DIO_PortTypes Portx =count/8;
		DIO_ChannalTypes BitNo =count%8;
		switch(Portx)
		{
			case DIO_PortA:
			if(PinCfg[count].level==STD_High)
			{
				SET_BIT(PORTA_Reg,BitNo);
			}
			else
			{
				CLEAR_BIT(PORTA_Reg,BitNo);
			}
			break;
			
			case DIO_PortB:
			if(PinCfg[count].level==STD_High)
			{
				SET_BIT(PORTB_Reg,BitNo);
			}
			else
			{
				CLEAR_BIT(PORTB_Reg,BitNo);
			}
			break;
			
			case DIO_PortC:
			if(PinCfg[count].level==STD_High)
			{
				SET_BIT(PORTC_Reg,BitNo);
			}
			else
			{
				CLEAR_BIT(PORTC_Reg,BitNo);
			}
			break;
			
			case DIO_PortD:
			if(PinCfg[count].level==STD_High)
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
}