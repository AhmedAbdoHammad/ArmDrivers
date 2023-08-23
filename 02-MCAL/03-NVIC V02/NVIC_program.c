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
	//#define SCB_AIRCR     *((volatile u32*) 0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}


void MNVIC_VoidEnableInterrupt (u8 Copy_u8IntNumber)
{
	MNVIC->ISER[Copy_u8IntNumber/32] = (1 << Copy_u8IntNumber%32);	
}


void MNVIC_VoidDisableInterrupt (u8 Copy_u8IntNumber)
{
	MNVIC->ICER[Copy_u8IntNumber/32] = (1 << Copy_u8IntNumber%32);
}


void MNVIC_VoidSetPendingFlag(u8 Copy_u8IntNumber)
{
	MNVIC->ISPR[Copy_u8IntNumber/32] = (1 << Copy_u8IntNumber%32);	
}

void MNVIC_VoidClearPendingFlag(u8 Copy_u8IntNumber)
{
	MNVIC->ICPR[Copy_u8IntNumber/32] = (1 << Copy_u8IntNumber%32);	
}


u8 MNVIC_VoidGetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result = 0;
	Local_u8Result = GET_BIT((NVIC->IAPR[Copy_u8IntNumber/32]) , (Copy_u8IntNumber%32));	
	return Local_u8Result;
}

void MNVIC_VoidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32GROUP)
{
	u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority<<(Copy_u32GROUP - 0x05FA0300)/256);
	/*Core peripheral    */ 
	
	/*External Peripheral*/
	if(Copy_s8IntID >= 0)
	{
		NVIC->IPR[Copy_s8IntID] = Local_u8Priority << 4;
	}
	SCB_AIRCR = Copy_u32GROUP;
}