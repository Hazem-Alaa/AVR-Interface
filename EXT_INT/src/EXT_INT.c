/*
* EXT_INT.c
*
* Created: 5 - 11 - 2023 8  :  56  :  22 PM
*  Author: Abu_El_A7ZaaM
*/

#include "EXT_INT.h"

void (*ExtFunCopy0ptr)(void) = 0;
void (*ExtFunCopy1ptr)(void) = 0;
void (*ExtFunCopy2ptr)(void) = 0;

void EXT_INT_Enable(EXT_INT INTID)
{
	switch(INTID)
	{
		case EXT_INT0:
		SET_BIT(EXT_INT_GICR,EXT_INT0_BIT);
		break;
		case EXT_INT1:
		SET_BIT(EXT_INT_GICR,EXT_INT1_BIT);
		break;
		case EXT_INT2:
		SET_BIT(EXT_INT_GICR,EXT_INT2_BIT);
		break;
		
	}
}

void EXT_INT_Disable(EXT_INT INTID)
{
	switch(INTID)
	{
		case EXT_INT0:
		CLEAR_BIT(EXT_INT_GICR,EXT_INT0_BIT);
		break;
		case EXT_INT1:
		CLEAR_BIT(EXT_INT_GICR,EXT_INT1_BIT);
		break;
		case EXT_INT2:
		CLEAR_BIT(EXT_INT_GICR,EXT_INT2_BIT);
		break;
		
	}
}

void EXT_INT_Sncontrol(EXT_INT INTID,EXT_MODE mode)
{
	switch(INTID)
	{
		case EXT_INT0:
		EXT_INT_MCUCR= (EXT_INT_MCUCR | (mode<<0));
		break;
		case EXT_INT1:
		EXT_INT_MCUCR= (EXT_INT_MCUCR | (mode<<2));
		break;
		case EXT_INT2:
		if(mode==EXT_MODE_Falling)
		{
			CLEAR_BIT(EXT_INT_MCUCSR,EXT_INT2_Sncontrol_BIT);
		}
		else if(mode==EXT_MODE_Rising)
		{
			SET_BIT(EXT_INT_MCUCSR,EXT_INT2_Sncontrol_BIT);
		}
		else
		{
			//Do Nothing
		}
		break;
	}
}

void EXT_INT_SetCallBack(EXT_INT INTID,void (*ExtFunCopy)(void))
{
	switch(INTID)
	{
		case EXT_INT0:
		ExtFunCopy0ptr=ExtFunCopy;
		break;
		case EXT_INT1:
		ExtFunCopy1ptr=ExtFunCopy;
		break;
		case EXT_INT2:
		ExtFunCopy2ptr=ExtFunCopy;
		break;
	}
}


ISR(INT0_vect)
{
	ExtFunCopy0ptr();
}

ISR(INT1_vect)
{
	ExtFunCopy1ptr();
}

ISR(INT2_vect)
{
	ExtFunCopy2ptr();
}