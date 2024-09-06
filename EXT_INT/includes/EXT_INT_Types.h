/*
* EXT_INT_Types.h
*
* Created: 5 - 11 - 2023 8  :  56  :  43 PM
*  Author: Abu_El_A7ZaaM
*/




#ifndef EXT_INT_TYPES_H_
#define EXT_INT_TYPES_H_

#include "EXT_INT_Reg.h"

enum EXT_INT{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2
};
typedef enum EXT_INT EXT_INT;

enum EXT_MODE{
	EXT_MODE_low,
	EXT_MODE_change,
	EXT_MODE_Falling,
	EXT_MODE_Rising
};
typedef enum EXT_MODE EXT_MODE;


#endif /* EXT_INT_TYPES_H_ */