/*
 * EXT_INT_Reg.h
 *
 * Created: 5 - 11 - 2023 8  :  55  :  48 PM
 *  Author: Abu_El_A7ZaaM
 */ 
#include "STD_types.h"

#ifndef EXT_INT_REG_H_
#define EXT_INT_REG_H_

#define EXT_INT_MCUCR (*(volatile u8*)0x55)
#define EXT_INT_MCUCSR (*(volatile u8*)0x54)
#define EXT_INT_GICR (*(volatile u8*)0x5B)
#define EXT_INT_GIFR (*(volatile u8*)0x5A)



#endif /* EXT_INT_REG_H_ */