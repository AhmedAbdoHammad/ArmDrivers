/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   26/02/2022                  */
/*             Version  :   V03                         */
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
							SET_BIT(MGPIOA -> ODR , copy_u8PIN);
						}else if(copy_u8Value == GPIO_LOW)
						{
							CLR_BIT(MGPIOA -> ODR , copy_u8PIN);
						}
					}
					break;
		case GPIOB :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							SET_BIT(MGPIOB -> ODR , copy_u8PIN);
						}else if(copy_u8Value == GPIO_LOW)
						{
							CLR_BIT(MGPIOB -> ODR , copy_u8PIN);
						}
					}
					break;
		case GPIOC :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							SET_BIT(MGPIOC -> ODR , copy_u8PIN);
						}else if(copy_u8Value == GPIO_LOW)
						{
							CLR_BIT(MGPIOC -> ODR , copy_u8PIN);
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
