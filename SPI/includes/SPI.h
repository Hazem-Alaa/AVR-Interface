/*
 * SPI.h
 *
 * Created: 6 - 8 - 2024 2  :  03  :  02 AM
 *  Author: Abu_El_A7ZaaM
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "STD_types.h"


void SPI_INIT(void);
void SPI_TRANSMITTER(u8 DATA);
u8 SPI_RECIEVE(void);

#endif /* SPI_H_ */