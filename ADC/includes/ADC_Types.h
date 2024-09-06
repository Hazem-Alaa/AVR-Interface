/*
* ADC_Types.h
*
* Created: 22 - 11 - 2023 12  :  04  :  08 AM
*  Author: Abu_El_A7ZaaM
*/


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_
#include "ADC.h"

enum ACD_ChannalTypes{
	ADC_Channal0=0,
	ADC_Channal1,
	ADC_Channal2,
	ADC_Channal3,
	ADC_Channal4,
	ADC_Channal5,
	ADC_Channal6,
	ADC_Channal7
};
typedef enum ACD_ChannalTypes ACD_ChannalTypes;


enum ACD_PrescaletTypes{
	ADC_Prescaler2=1,
	ADC_Prescaler4,
	ADC_Prescaler8,
	ADC_Prescaler16,
	ADC_Prescaler32,
	ADC_Prescaler64,
	ADC_Prescaler128
};
typedef enum ACD_PrescaletTypes ACD_PrescaletTypes;


enum ACD_VrefTypes{
	ADC_Vef_Aref,
	ADC_Vef_Avcc,
	ADC_Vef_Reserved,
	ADC_Vef_Internal
};
typedef enum ACD_VrefTypes ACD_VrefTypes;


struct ADC_InitTypes{
	ACD_PrescaletTypes adcClk;
	ACD_VrefTypes adcVef;
};
typedef struct ADC_InitTypes ADC_InitTypes;


#endif /* ADC_TYPES_H_ */