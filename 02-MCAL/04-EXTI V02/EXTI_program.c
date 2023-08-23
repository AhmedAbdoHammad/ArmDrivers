/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   21/02/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

static void (*EXTI_CallBack[16]) (void) = {};

void MEXTI_voidInit()
{
	SET_BIT(EXTI->IMR , EXTI_LINE);
	/*#if     EXTI_LINE == LINE0
	SET_BIT(EXTI->IMR , 0);
	#elseif EXTI_LINE == LINE1
	SET_BIT(EXTI->IMR , 1);
	#elseif EXTI_LINE == LINE2
	SET_BIT(EXTI->IMR , 2);
	#elseif EXTI_LINE == LINE3
	SET_BIT(EXTI->IMR , 3);
	#elseif EXTI_LINE == LINE4
	SET_BIT(EXTI->IMR , 4);
	#elseif EXTI_LINE == LINE5
	SET_BIT(EXTI->IMR , 5);
	#elseif EXTI_LINE == LINE6
	SET_BIT(EXTI->IMR , 6);
	#elseif EXTI_LINE == LINE7
	SET_BIT(EXTI->IMR , 7);
	#elseif EXTI_LINE == LINE8
	SET_BIT(EXTI->IMR , 8);
	#elseif EXTI_LINE == LINE9
	SET_BIT(EXTI->IMR , 9);
	#elseif EXTI_LINE == LINE10
	SET_BIT(EXTI->IMR , 10);
	#elseif EXTI_LINE == LINE11
	SET_BIT(EXTI->IMR , 11);
	#elseif EXTI_LINE == LINE12
	SET_BIT(EXTI->IMR , 12);
	#elseif EXTI_LINE == LINE13
	SET_BIT(EXTI->IMR , 13);
	#elseif EXTI_LINE == LINE14
	SET_BIT(EXTI->IMR , 14);
	#elseif EXTI_LINE == LINE15
	SET_BIT(EXTI->IMR , 15);
	#else #error ("Wrong Line and Mode Choice!")
	#endif
	*/
	#if     EXTI_Mode == RISING
	SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#elseif EXTI_Mode == FALLING
	SET_BIT(EXTI -> FTSR, EXTI_LINE);
	#elseif EXTI_Mode == ON_CHANGE
	SET_BIT(EXTI -> RTSR, EXTI_LINE);
	SET_BIT(EXTI -> FTSR, EXTI_LINE);
	#else #error ("Wrong Line and Mode Choice!")
	#endif
	
	/*Disable Interrupt*/
	CLR_BIT(EXTI -> IMR,EXTI_LINE);
}


void MEXTI_voidEnableEXTI(u8 copy_u8Line)
{
	SET_BIT(EXTI -> IMR, copy_u8Line);
}


void MEXTI_voidDisableEXTI(u8 copy_u8Line)
{
	CLR_BIT(EXTI -> IMR, copy_u8Line);
}


void MEXTI_voidSwTrigger(u8 copy_u8Line)
{
	CLR_BIT(EXTI -> IMR  , copy_u8Line);
	CLR_BIT(EXTI -> PR   , copy_u8Line);
	SET_BIT(EXTI -> SWIER, copy_u8Line);
}

void MEXTI_voidSetSignalLatch(u8 copy_u8Line , u8 copy_u8Mode)
{
	switch(copy_u8Mode)
	{
		case RISING    : SET_BIT(EXTI -> RTSR, copy_u8Line); break;
		case FALLING   : SET_BIT(EXTI -> FTSR, copy_u8Line); break;
		case ON_CHANGE : SET_BIT(EXTI -> RTSR, copy_u8Line);
						 SET_BIT(EXTI -> FTSR, copy_u8Line); break;
	}
	
}

void MEXTI_voidSetCallBack(void (*copy_ptr) (void))
{
	EXTI_CallBack[0] = copy_ptr ;

}

void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	/*Clear Pending Bit*/
	SET_BIT(EXTI->PR, 0);
}

