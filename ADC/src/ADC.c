/*
* ADC.c
*
* Created: 22 - 11 - 2023 12  :  45  :  42 AM
*  Author: Abu_El_A7ZaaM
*/

#include "ADC.h"

void ADC_Init(ADC_InitTypes * options)
{
	ADC_ADMUX_Reg = ((options->adcVef)<<6); //set Vref
	ADC_ADCSRA_Reg= (1<<ADC_ADCSRA_ADEN_Bit)|(options->adcClk); //Set Enable & Prescaler
}
u16 ADC_Read(ACD_ChannalTypes ChannalID)
{
	u16 ReadValue =0;
	ADC_ADMUX_Reg =(ADC_ADMUX_Reg & 0b11100000)|(ChannalID & 0b00011111);
	SET_BIT(ADC_ADCSRA_Reg,ADC_ADCSRA_ADSC_Bit);//Start Conv.
	while(GET_BIT(ADC_ADCSRA_Reg,ADC_ADCSRA_ADIF_Bit) ==0); //waiting to finish the conv.
	SET_BIT(ADC_ADCSRA_Reg,ADC_ADCSRA_ADIF_Bit);//clear the flag
	ReadValue = (ADC_ADCL_Reg)|(ADC_ADCH_Reg<<8);
	
	return ReadValue;
}