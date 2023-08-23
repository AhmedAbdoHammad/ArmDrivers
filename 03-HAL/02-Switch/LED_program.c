/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   12/02/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void MGPIO_voidSetDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
					{
						if(copy_u8PIN <= 7)
						{
							GPIOA_CRL &= ~((0b1111)<< (copy_u8PIN * 4));
							GPIOA_CRL |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}else if(copy_u8PIN <= 15)
						{
							copy_u8PIN = copy_u8PIN - 8;
							GPIOA_CRH &= ~((0b1111)<< (copy_u8PIN * 4));
							GPIOA_CRH |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}
					}
					break;
		case GPIOB :
					{
						if(copy_u8PIN <= 7)
						{
							GPIOB_CRL &= ~((0b1111)<< (copy_u8PIN * 4));
							GPIOB_CRL |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}else if(copy_u8PIN <= 15)
						{
							copy_u8PIN = copy_u8PIN - 8;
							GPIOB_CRH &= ~((0b1111)<< (copy_u8PIN * 4));
							GPIOB_CRH |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}
					}
					break;
		case GPIOC :
					{
						if(copy_u8PIN <= 7)
						{
							GPIOC_CRL &= ~((0b1111)<< (copy_u8PIN * 4));
							GPIOC_CRL |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}else if(copy_u8PIN <= 15)
						{
							copy_u8PIN = copy_u8PIN - 8;
							GPIOC_CRH &= ~((0b1111)<< (copy_u8PIN * 4));
							GPIOC_CRH |= ((copy_u8Mode)<< (copy_u8PIN * 4));
						}
					}
					break;					
	}
}
void MGPIO_voidSetValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							SET_BIT(GPIOA_ODR , copy_u8PIN);
						}else if(copy_u8Value == GPIO_LOW)
						{
							CLR_BIT(GPIOA_ODR , copy_u8PIN);
						}
					}
					break;
		case GPIOB :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							SET_BIT(GPIOB_ODR , copy_u8PIN);
						}else if(copy_u8Value == GPIO_LOW)
						{
							CLR_BIT(GPIOB_ODR , copy_u8PIN);
						}
					}
					break;
		case GPIOC :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							SET_BIT(GPIOC_ODR , copy_u8PIN);
						}else if(copy_u8Value == GPIO_LOW)
						{
							CLR_BIT(GPIOC_ODR , copy_u8PIN);
						}
					}
					break;
		default    : break; 
	}
	
}

void MGPIO_voidLED_ON (u8 copy_u8PORT, u8 copy_u8PIN)
{
	MGPIO_voidSetDirection(u8 copy_u8PORT, u8 copy_u8PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetValue(u8 copy_u8PORT, u8 copy_u8PIN, GPIO_HIGH);
}
void MGPIO_voidLED_OFF(u8 copy_u8PORT, u8 copy_u8PIN)
{
	MGPIO_voidSetDirection(u8 copy_u8PORT, u8 copy_u8PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetValue(u8 copy_u8PORT, u8 copy_u8PIN, GPIO_LOW);
	
}
void MGPIO_voidLED_TOG(u8 copy_u8PORT, u8 copy_u8PIN)
{
	u32 Time = 500;
	MGPIO_voidSetDirection(u8 copy_u8PORT, u8 copy_u8PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetValue(u8 copy_u8PORT, u8 copy_u8PIN, GPIO_HIGH);
	for(int i = 0; i < Time; i++)
	{
		for(int i = 0; i < Time; i++)
		{
			asm("NOP");
		}
	}
	MGPIO_voidSetDirection(u8 copy_u8PORT, u8 copy_u8PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetValue(u8 copy_u8PORT, u8 copy_u8PIN, GPIO_LOW);
	
	
}