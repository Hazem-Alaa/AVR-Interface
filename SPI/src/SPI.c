/*
* SPI.c
*
* Created: 6 - 8 - 2024 2  :  04  :  41 AM
*  Author: Abu_El_A7ZaaM
*/

#include "SPI.h"
#include "BIT_math.h"

void SPI_INIT(SPI_OPTTIONS * options)
{
	SPCR_Reg |= ((options->dataorder)<<DORD_bit);
	SPCR_Reg |= ((options->outhorty)<<MSTR_bit);
	SPCR_Reg |= ((options->clockpolarity)<<CPOL_bit);
	SPCR_Reg |= ((options->clockphase)<<CPHA_bit);
	
	switch(options->speed)
	{
		case SPI_F_4:
		CLEAR_BIT(SPCR_Reg,SPR0_bit);
		CLEAR_BIT(SPCR_Reg,SPR1_bit);
		CLEAR_BIT(SPSR_Reg,SPI2X_bit);
		break;
		
		case SPI_F_16:
		SET_BIT(SPCR_Reg,SPR0_bit);
		CLEAR_BIT(SPCR_Reg,SPR1_bit);
		CLEAR_BIT(SPSR_Reg,SPI2X_bit);
		break;
		
		case SPI_F_64:
		CLEAR_BIT(SPCR_Reg,SPR0_bit);
		SET_BIT(SPCR_Reg,SPR1_bit);
		CLEAR_BIT(SPSR_Reg,SPI2X_bit);
		break;
		
		case SPI_F_128:
		SET_BIT(SPCR_Reg,SPR0_bit);
		SET_BIT(SPCR_Reg,SPR1_bit);
		CLEAR_BIT(SPSR_Reg,SPI2X_bit);
		break;
		
		case SPI_F_2:
		CLEAR_BIT(SPCR_Reg,SPR0_bit);
		CLEAR_BIT(SPCR_Reg,SPR1_bit);
		SET_BIT(SPSR_Reg,SPI2X_bit);
		break;
		
		case SPI_F_8:
		SET_BIT(SPCR_Reg,SPR0_bit);
		CLEAR_BIT(SPCR_Reg,SPR1_bit);
		SET_BIT(SPSR_Reg,SPI2X_bit);
		break;

		case SPI_F_32:
		CLEAR_BIT(SPCR_Reg,SPR0_bit);
		SET_BIT(SPCR_Reg,SPR1_bit);
		SET_BIT(SPSR_Reg,SPI2X_bit);
		break;
		
	}
	
}
void SPI_TRANSMITTER(u8 DATA)
{
	SET_BIT(SPCR_Reg,SPE_bit);
}
u8 SPI_RECIEVE(void)
{
	SET_BIT(SPCR_Reg,SPE_bit);
}