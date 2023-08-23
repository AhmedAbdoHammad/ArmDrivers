/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   07/03/2022                  */
/*             Version  :   V04                         */
/********************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
					{
						if(copy_u8PIN <= 7)
						{
							MGPIOA -> CRL &= ~((0b1111) << (copy_u8PIN * 4));
							MGPIOA -> CRL |= ((copy_u8Mode) << (copy_u8PIN * 4));
						}else if(copy_u8PIN <= 15)
						{
							copy_u8PIN = copy_u8PIN - 8;
							MGPIOA -> CRL &= ~((0b1111)<< (copy_u8PIN * 4));
							MGPIOA -> CRH |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}
					}
					break;
		case GPIOB :
					{
						if(copy_u8PIN <= 7)
						{
							MGPIOB -> CRL &= ~((0b1111)<< (copy_u8PIN * 4));
							MGPIOB -> CRL |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}else if(copy_u8PIN <= 15)
						{
							copy_u8PIN = copy_u8PIN - 8;
							MGPIOB -> CRH &= ~((0b1111)<< (copy_u8PIN * 4));
							MGPIOB -> CRH |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}
					}
					break;
		case GPIOC :
					{
						if(copy_u8PIN <= 7)
						{
							MGPIOC -> CRL &= ~((0b1111)<< (copy_u8PIN * 4));
							MGPIOC -> CRL |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}else if(copy_u8PIN <= 15)
						{
							copy_u8PIN = copy_u8PIN - 8;
							MGPIOC -> CRH &= ~((0b1111)<< (copy_u8PIN * 4));
							MGPIOC -> CRH |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}
					}
					break;					
	}
}
void MGPIO_voidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							MGPIOA->BSRR = 1<<copy_u8PIN;
						}else if(copy_u8Value == GPIO_LOW)
						{
							copy_u8PIN += 16;
							MGPIOA->BSRR = 1<<copy_u8PIN;
						}
					}
					break;
		case GPIOB :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							MGPIOB->BSRR = 1<<copy_u8PIN;
						}else if(copy_u8Value == GPIO_LOW)
						{
							copy_u8PIN += 16;
							MGPIOC->BSRR = 1<<copy_u8PIN;
						}
					}
					break;
		case GPIOC :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							MGPIOC->BSRR = 1<<copy_u8PIN;
						}else if(copy_u8Value == GPIO_LOW)
						{
							copy_u8PIN += 16;
							MGPIOC->BSRR = 1<<copy_u8PIN;
						}
					}
					break;
		default    : break; 
	}
	
}
u8 MGPIO_voidgetPinValue(u8 copy_u8PORT, u8 copy_u8PIN)
{
	u8 LOC_u8Result = 0;
	switch(copy_u8PORT)
	{
		case GPIOA : LOC_u8Result = GET_BIT(MGPIOA -> IDR , copy_u8PIN);
					 break;
		case GPIOB : LOC_u8Result = GET_BIT(MGPIOB -> IDR , copy_u8PIN);
					 break;
		case GPIOC : LOC_u8Result = GET_BIT(MGPIOC -> IDR , copy_u8PIN);
					 break;
		default    : break; 
	}
	return 	LOC_u8Result;
}

void MGPIO_voidSetPortValue(u8 copy_u8PORT, u8 copy_u8Value)
{
	u8 Local_u8Bit = 0;
	for(u8 PIN = 0; PIN < 8; PIN++)
	{
		Local_u8Bit = GET_BIT(copy_u8Value,PIN);
		MGPIO_voidSetPinValue(copy_u8PORT, PIN , Local_u8Bit);
	}
}

void MGPIO_voidLockPin(u8 copy_u8PORT, u8 copy_u8PIN)
{
	switch(copy_u8PORT)
	{
		case GPIOA : SET_BIT(MGPIOA->LCKR, copy_u8PIN);
					 break;
		case GPIOB : SET_BIT(MGPIOB->LCKR, copy_u8PIN);
					 break;
		case GPIOC : SET_BIT(MGPIOC->LCKR, copy_u8PIN);
					 break;
		default    : break; 
	}
}

void MGPIO_voidUnlockPin(u8 copy_u8PORT, u8 copy_u8PIN)
{
	switch(copy_u8PORT)
	{
		case GPIOA : CLR_BIT(MGPIOA->LCKR, copy_u8PIN);
					 break;
		case GPIOB : CLR_BIT(MGPIOB->LCKR, copy_u8PIN);
					 break;
		case GPIOC : CLR_BIT(MGPIOC->LCKR, copy_u8PIN);
					 break;
		default    : break; 
	}
}

void MGPIO_voidSetPortDirection(u8 copy_u8PORT, u8 copy_u8Mode)
{
	for(u8 PIN = 0; PIN < 8; PIN++)
	{
		MGPIO_voidSetPinDirection(copy_u8PORT, PIN , copy_u8Mode);
	}
}