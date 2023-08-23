/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   12/02/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SevenSegment_interface.h"
#include "SevenSegment_private.h"
#include "SevenSegment_config.h"

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

void SevenSegment_voidDisplay(u8 SEVEN_TYPE, u8 Number)
{
u8 Numbers [7][10] = 
{{ SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE,!SEVEN_TYPE},
 {!SEVEN_TYPE,!SEVEN_TYPE,!SEVEN_TYPE,!SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE,!SEVEN_TYPE},
 { SEVEN_TYPE, SEVEN_TYPE,!SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE,!SEVEN_TYPE, SEVEN_TYPE},
 { SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE,!SEVEN_TYPE,!SEVEN_TYPE, SEVEN_TYPE},
 {!SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE,!SEVEN_TYPE,!SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE},
 { SEVEN_TYPE,!SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE,!SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE},
 { SEVEN_TYPE,!SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE},
 { SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE,!SEVEN_TYPE,!SEVEN_TYPE,!SEVEN_TYPE,!SEVEN_TYPE},
 { SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE},
 { SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE,!SEVEN_TYPE, SEVEN_TYPE, SEVEN_TYPE}};
 
 MGPIO_voidSetDirection(PORTA , PIN0, OUTPUT_SPEED_2MHZ_PP);
 MGPIO_voidSetDirection(PORTA , PIN1, OUTPUT_SPEED_2MHZ_PP);
 MGPIO_voidSetDirection(PORTA , PIN2, OUTPUT_SPEED_2MHZ_PP);
 MGPIO_voidSetDirection(PORTA , PIN3, OUTPUT_SPEED_2MHZ_PP);
 MGPIO_voidSetDirection(PORTA , PIN4, OUTPUT_SPEED_2MHZ_PP);
 MGPIO_voidSetDirection(PORTA , PIN5, OUTPUT_SPEED_2MHZ_PP);
 MGPIO_voidSetDirection(PORTA , PIN6, OUTPUT_SPEED_2MHZ_PP);
 
 MGPIO_voidSetValue(PORTA , PIN0, Numbers[Number][A]);
 MGPIO_voidSetValue(PORTA , PIN1, Numbers[Number][B]);
 MGPIO_voidSetValue(PORTA , PIN2, Numbers[Number][C]);
 MGPIO_voidSetValue(PORTA , PIN3, Numbers[Number][D]);
 MGPIO_voidSetValue(PORTA , PIN4, Numbers[Number][E]);
 MGPIO_voidSetValue(PORTA , PIN5, Numbers[Number][F]);
 MGPIO_voidSetValue(PORTA , PIN6, Numbers[Number][G]);
}