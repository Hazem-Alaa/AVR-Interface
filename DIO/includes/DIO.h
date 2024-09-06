/*
* DIO.h
*
* Created: 30 - 9 - 2023 12  :  08  :  21 PM
*  Author: Abu_El_A7ZaaM
*/


#ifndef DIO_H_
#define DIO_H_

#include "DIO_types.h"
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_Reg.h"
#include "DIO.h"

// for pins
void DIO_ConfigChannal(DIO_ChannalTypes ChannalId,DIO_LevelTypes direction);
void DIO_WriteChannal(DIO_ChannalTypes ChannalId,STD_LevelTypes Level);
STD_LevelTypes DIO_ReadChannal(DIO_ChannalTypes ChannalId);
void DIO_ToggleChannal(DIO_ChannalTypes ChannalId);

//for ports
void DIO_WritePort(DIO_PortTypes PortId,STD_LevelTypes Level);
u8 DIO_ReadPort(DIO_PortTypes PortId); 
void DIO_WriteData(DIO_PortTypes PortId,u8 masked,u8 PortValue);

#endif /* DIO_H_ */