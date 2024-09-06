/*
 * SSD.h
 *
 * Created: 17 - 10 - 2023 3  :  36  :  30 AM
 *  Author: Abu_El_A7ZaaM
 */ 


#ifndef SSD_H_
#define SSD_H_

#include "SSD_Config.h"
#include "DIO.h"

void SDD_Init(void);
void SDD_DisPlay(u8 num);
void SDD_DisPlay_With_Delay(u8 num ,u8 delay);


#endif /* SSD_H_ */