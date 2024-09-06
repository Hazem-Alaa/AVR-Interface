/*
* DIO_types.h
*
* Created: 30 - 9 - 2023 11  :  52  :  59 AM
*  Author: Abu_El_A7ZaaM
*/


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

enum DIO_ChannalTypes
{
	DIO_ChannalA0=0,
	DIO_ChannalA1,
	DIO_ChannalA2,
	DIO_ChannalA3,
	DIO_ChannalA4,
	DIO_ChannalA5,
	DIO_ChannalA6,
	DIO_ChannalA7,
	
	DIO_ChannalB0,
	DIO_ChannalB1,
	DIO_ChannalB2,
	DIO_ChannalB3,
	DIO_ChannalB4,
	DIO_ChannalB5,
	DIO_ChannalB6,
	DIO_ChannalB7,
	
	DIO_ChannalC0,
	DIO_ChannalC1,
	DIO_ChannalC2,
	DIO_ChannalC3,
	DIO_ChannalC4,
	DIO_ChannalC5,
	DIO_ChannalC6,
	DIO_ChannalC7,
	
	DIO_ChannalD0,
	DIO_ChannalD1,
	DIO_ChannalD2,
	DIO_ChannalD3,
	DIO_ChannalD4,
	DIO_ChannalD5,
	DIO_ChannalD6,
	DIO_ChannalD7
};
typedef enum DIO_ChannalTypes DIO_ChannalTypes;



enum DIO_PortTypes
{
	DIO_PortA,
	DIO_PortB,
	DIO_PortC,
	DIO_PortD
};
typedef enum DIO_PortTypes DIO_PortTypes;



enum DIO_LevelTypes //dep on HW
{
	Input=0,
	Output,
	
};
typedef enum DIO_LevelTypes DIO_LevelTypes;


#endif /* DIO_TYPES_H_ */