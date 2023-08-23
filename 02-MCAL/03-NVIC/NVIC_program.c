/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   16/02/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
	#define SCB_AIRCR     *((volatile u32*) 0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

void MNVIC_voidSetPriority(u8 copy_u8PeripheralIdx, u8 copy_u8Priority)
{
	if(copy_u8PeripheralIdx < 60)
	{
		NVIC_IPR[copy_u8PeripheralIdx] = copy_u8Priority;
	}else
	{
		/*Return error*/
	}
}

void MNVIC_VoidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}else 
	{
		/* Return Error */
	}	
}


void MNVIC_VoidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}else 
	{
		/* Return Error */
	}	
}


void MNVIC_VoidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}else 
	{
		/* Return Error */
	}	
}

void MNVIC_VoidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}else 
	{
		/* Return Error */
	}	
}


u8 MNVIC_VoidGetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result = 0;
	if(Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IAPR0 , Copy_u8IntNumber);
	}else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IAPR1 , Copy_u8IntNumber);
	}else 
	{
		/* Return Error */
	}	
	return Local_u8Result;
}

void MNVIC_VoidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32GROUP)
{
	u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority<<(Copy_u32GROUP - 0x05FA0300)/256);
	/*Core peripheral    */ 
	
	/*External Peripheral*/
	if(Copy_s8IntID >= 0)
	{
		NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4;
	}
	SCB_AIRCR = Copy_u32GROUP;
}