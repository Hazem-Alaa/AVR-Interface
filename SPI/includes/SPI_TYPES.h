/*
* SPI_TYPES.h
*
* Created: 6 - 8 - 2024 2  :  03  :  45 AM
*  Author: Abu_El_A7ZaaM
*/


#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_

#include "SPI.h"
#include "SPI_CONFIG.h"
#include "SPI_REG.h"

typedef enum
{
	SPT_MSB,
	SPI_LSB
}SPI_SELECT_DATA_ORDER;

typedef enum
{
	SPT_SLAVE,
	SPI_MASTER
}SPI_SELECT_OUTHOURTY;

typedef enum
{
	SPT_RISING_LEADING,
	SPI_FALLING_LEADING
}SPI_SELECT_CLOCK_POLARITY;

typedef enum
{
	SPT_SAMPLE_LEADING,
	SPI_SETUP_LEADING
}SPI_SELECT_CLOCK_PHASE;

typedef enum
{
	SPI_F_4,
	SPI_F_16,
	SPI_F_64,
	SPI_F_128,
	SPI_F_2,
	SPI_F_8,
	SPI_F_32
}SPI_SELECT_SPEED;



typedef struct
{
	SPI_SELECT_DATA_ORDER dataorder;
	SPI_SELECT_OUTHOURTY outhorty;
	SPI_SELECT_CLOCK_POLARITY clockpolarity;
	SPI_SELECT_CLOCK_PHASE clockphase;
	SPI_SELECT_SPEED speed;
	
}SPI_OPTTIONS;

#endif /* SPI_TYPES_H_ */