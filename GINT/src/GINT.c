/*
* GINT.c
*
* Created: 4 - 11 - 2023 8  :  24  :  17 PM
*  Author: Abu_El_A7ZaaM
*/


#include "GINT.h"


void EnableAllGNIT(void)
{
	SET_BIT(GINT_SREG_Reg,GINT_IBIT);
}
void DisableAllGNIT(void)
{
	CLEAR_BIT(GINT_SREG_Reg,GINT_IBIT);
}