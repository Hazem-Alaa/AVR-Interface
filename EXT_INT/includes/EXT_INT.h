/*
* EXT_INT.h
*
* Created: 5 - 11 - 2023 8  :  52  :  57 PM
*  Author: Abu_El_A7ZaaM
*/


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "DIO.h"
#include "EXT_INT_Reg.h"
#include "EXT_INT_Types.h"
#include <avr/interrupt.h>

#define EXT_INT0_BIT 6
#define EXT_INT1_BIT 7
#define EXT_INT2_BIT 5

#define EXT_INT2_Sncontrol_BIT 6

void EXT_INT_Enable(EXT_INT INTID);
void EXT_INT_Disable(EXT_INT INTID);
void EXT_INT_Sncontrol(EXT_INT INTID,EXT_MODE mode);
void EXT_INT_SetCallBack(EXT_INT INTID,void (*ExtFunCopy)(void));


#endif /* EXT_INT_H_ */