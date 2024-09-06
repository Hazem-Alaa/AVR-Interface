/*
 * ADC.h
 *
 * Created: 22 - 11 - 2023 12  :  03  :  05 AM
 *  Author: Abu_El_A7ZaaM
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "DIO.h"
#include "ADC_Types.h"
#include "ADC_Reg.h"

void ADC_Init(ADC_InitTypes * options);
u16 ADC_Read(ACD_ChannalTypes ChannalID);


#endif /* ADC_H_ */