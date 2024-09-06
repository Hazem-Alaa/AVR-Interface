/*
 * SPI_REG.h
 *
 * Created: 6 - 8 - 2024 2  :  04  :  01 AM
 *  Author: Abu_El_A7ZaaM
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_

#include "STD_types.h"

#define SPCR_Reg (*(volatile u8*)0x2D)
#define SPSR_Reg (*(volatile u8*)0x2E)
#define SPDR_Reg (*(volatile u8*)0x2F)

#endif /* SPI_REG_H_ */