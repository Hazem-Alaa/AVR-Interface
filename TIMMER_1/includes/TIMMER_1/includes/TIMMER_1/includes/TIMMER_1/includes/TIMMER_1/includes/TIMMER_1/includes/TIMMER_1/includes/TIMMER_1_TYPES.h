/*
* TIMMER_1_TYPES.h
*
* Created: 28 - 7 - 2024 5  :  18  :  04 PM
*  Author: Abu_El_A7ZaaM
*/


#ifndef TIMMER_1_TYPES_H_
#define TIMMER_1_TYPES_H_


typedef enum
{
	NoClock, // timmer off
	NoPrescaling, // no prescaling
	clk_8,
	clk_64,
	clk_1024,
	clk_EXt_falling,
	clk_EXt_rising,
}Timer1_PrescailngTypes;

typedef enum
{
	DISable=0 ,
	NON_INVERTING=2,
	INVERTING,
}Timer1_COM1A;

typedef enum
{
	DISable=0 ,
	NON_INVERTING=2,
	INVERTING,
}Timer1_COM1B;

typedef enum
{
	Timmer_Normal,
	Timmer_PWM_Phase_Correct_8bit,
	Timmer_PWM_Phase_Correct_9bit,
	Timmer_PWM_Phase_Correct_10bit,
	Timmer_CTC1,
	Timmer_Fast_PWM_8bit,
	Timmer_Fast_PWM_9bit,
	Timmer_Fast_PWM_10bit,
	Timmer_PWM_Phase_and_Frequency_Correct1,
	Timmer_PWM_Phase_and_Frequency_Correct2,
	Timmer_PWM_Phase_Correct1,
	Timmer_PWM_Phase_Correct2,
	Timmer_CTC2,
	Timmer_Reserved,
	Timmer_Fast_PWM1,
	Timmer_Fast_PWM2,
}Timer_ModeTypes;



typedef struct {
	
	u8 Timer_WGM10_Bit:1;
	u8 Timer_WGM11_Bit:1;
	u8 Timer_FOC1B_Bit:1;
	u8 Timer_FOC1A_Bit:1;
	u8 Timer_COM1B0_Bit:1;
	u8 Timer_COM1B1_Bit:1;
	u8 Timer_COM1A0_Bit:1;
	u8 Timer_COM1A0_Bit:1;
	
}Timer_TCCR1ABit;

typedef struct {
	
	u8 Timer_CS10_Bit:1;
	u8 Timer_CS11_Bit:1;
	u8 Timer_CS12_Bit:1;
	u8 Timer_WGM12_Bit:1;
	u8 Timer_WGM13_Bit:1;
	u8 Timer_RESERVED_Bit:1;
	u8 Timer_ICES1_Bit:1;
	u8 Timer_ICNC1_Bit:1;
	
}Timer_TCCR1BBit;

typedef union
{
	u8 allsetbit;
	Timer_TCCR1ABit bit;
	
}Timer_TCCR1Atypes;

typedef union
{
	u8 allsetbit;
	Timer_TCCR1BBit bit;
	
}Timer_TCCR1Btypes;

typedef struct
{
	Timer1_PrescailngTypes prescaling ;
	Timer_ModeTypes mode;
	Timer1_COM1A COM1A_MODE;
	Timer1_COM1B COM1B_MODE;
};


#endif /* TIMMER_1_TYPES_H_ */