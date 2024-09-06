/*
 * LM35.h
 *
 * Created: 1 - 12 - 2023 9  :  18  :  37 AM
 *  Author: Abu_El_A7ZaaM
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "ADC.h"

void LM35_Iint(ADC_InitTypes * options);
u16 LM35_Read(ACD_ChannalTypes ChannalID);



#endif /* LM35_H_ */