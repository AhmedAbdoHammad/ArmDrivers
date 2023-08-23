/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   03/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

u8 IntervalType = Single;
u32 Ticks = 0;

void (*MSTK_CallBack)(void);

void MSTK_voidInit(void)
{
	#if CLOCK_TYPE  == AHB
		MSTK -> CTRL = 0x00000002;
	#elif   CLOCK_TYPE  == AHB_DIV_BY_8
		MSTK -> CTRL = 0x00000006;
	#endif
}

void MSTK_voidSetBusyWait(u32 copy_u32Ticks)
{
	MSTK->LOAD = copy_u32Ticks;
	MSTK->VAL = 0;
	SET_BIT(MSTK->CTRL, 0);
	while(MSTK_u8ReadFlag() == 0);
	CLR_BIT(MSTK->CTRL, 0);
	MSTK->LOAD = 0;
	MSTK->VAL  = 0;
}

u8 MSTK_u8ReadFlag( void ){

	return (GET_BIT( MSTK->CTRL , 16));

}

void SysTick_Handler(void){

	MSTK_CallBack();
	if(IntervalType == Single)
	{
		asm("NOP");
	}else if(IntervalType == Periodic)
	{
		MSTK_voidSetIntervalPeriodic(Ticks , MSTK_CallBack);
	}
}

void MSTK_VidSetCallBack( void (*ptr)(void) ){

	MSTK_CallBack = ptr;
}


void MSTK_voidSetIntervalSingle  (u32 copy_u32Ticks, void *(copy_ptr) (void))
{
	/*Disable Timer*/
	CLR_BIT(MSTK->CTRL,0);
	MSTK->VAL = 0;
	
	IntervalType = Single;
	
	MSTK->LOAD = copy_u32Ticks;
	SET_BIT(MSTK->CTRL, 0);
	
	MSTK_CallBack = copy_ptr;
	SET_BIT(MSTK->CTRL,1);
}

void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void *(copy_ptr) (void))
{
	/*Disable Timer*/
	CLR_BIT(MSTK->CTRL,0);
	MSTK->VAL = 0;
	
	IntervalType = Periodic;
	Ticks = copy_u32Ticks;
	
	MSTK->LOAD = copy_u32Ticks;
	SET_BIT(MSTK->CTRL, 0);
	MSTK_CallBack = copy_ptr;
	SET_BIT(MSTK->CTRL,1);
}

void MSTK_voidStopTimer(void)
{
	MSTK->LOAD = 0;
	MSTK->VAL  = 0;
	CLR_BIT(MSTK->CTRL, 0);
}

u32 MSTK_voidGetElapsedTime(void)
{
	u32 Local_u32ElapsedTime = MSTK->LOAD - MSTK->VAL;
	return Local_u32ElapsedTime;
}

u32 MSTK_voidGetRemainingTime(void)
{
	u32 Local_u32RemainingTime = MSTK->VAL;
	return Local_u32RemainingTime;
}