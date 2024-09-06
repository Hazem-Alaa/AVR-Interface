/*
 * LM35.c
 *
 * Created: 1 - 12 - 2023 9  :  35  :  13 AM
 *  Author: Abu_El_A7ZaaM
 */ 

#include "LM35.h"

void LM35_Iint(ADC_InitTypes * options)
{
	ADC_Init(options);
}
u16 LM35_Read(ACD_ChannalTypes ChannalID)
{
	u16 readvalue= 0;
	readvalue = ADC_Read(ChannalID);
	readvalue =readvalue/4;
	
	return readvalue;
	
}