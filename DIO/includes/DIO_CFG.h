/*
* DIO_CFG.h
*
* Created: 30 - 9 - 2023 6  :  05  :  01 PM
*  Author: Abu_El_A7ZaaM
*/


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"


void DIO_INIT(void);
void DIO_INITPort(void);

#define PINCOUNT 32

struct PortPin
{
	DIO_LevelTypes direction;
	STD_LevelTypes level;
};
typedef struct PortPin PortPin;


#endif /* DIO_CFG_H_ */