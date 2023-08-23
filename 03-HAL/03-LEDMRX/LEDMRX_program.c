/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   06/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void HLEDMRX_voidInit(void)
{
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN , OUTPUT_SPEED_2MHZ_PP);
	
	
	MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN , OUTPUT_SPEED_2MHZ_PP);
	
	
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_HIGH);
}

void HLEDMRX_voidDisplay (u32 *copy_u32Data)
{
	while(1)
	{
		/*Column 0*/
		DisableAllColumns();
		SetRowValues(u8 copy_u32Data[0]);
		MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
		/*Column 1*/
		DisableAllColumns();
		SetRowValues(u8 copy_u32Data[1]);
		MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
		/*Column 2*/
		DisableAllColumns();
		SetRowValues(u8 copy_u32Data[2]);
		MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
		/*Column 3*/
		DisableAllColumns();
		SetRowValues(u8 copy_u32Data[3]);
		MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
		/*Column 4*/
		DisableAllColumns();
		SetRowValues(u8 copy_u32Data[4]);
		MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
		/*Column 5*/
		DisableAllColumns();
		SetRowValues(u8 copy_u32Data[5]);
		MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
		/*Column 6*/
		DisableAllColumns();
		SetRowValues(u8 copy_u32Data[6]);
		MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
		/*Column 7*/
		DisableAllColumns();
		SetRowValues(u8 copy_u32Data[7]);
		MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
	}
}

static void DisableAllColumns(void)
{
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_HIGH);
	
}

static void SetRowValues(u8 copy_u8Value)
{
	u8 Local_u8Bit = 0;
	Local_u8Bit = GET_BIT(copy_u8Value,0);
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN, Local_u8Bit);
	Local_u8Bit = GET_BIT(copy_u8Value,1);
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN, Local_u8Bit);
	Local_u8Bit = GET_BIT(copy_u8Value,2);
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN, Local_u8Bit);
	Local_u8Bit = GET_BIT(copy_u8Value,3);
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN, Local_u8Bit);
	Local_u8Bit = GET_BIT(copy_u8Value,4);
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN, Local_u8Bit);
	Local_u8Bit = GET_BIT(copy_u8Value,5);
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN, Local_u8Bit);
	Local_u8Bit = GET_BIT(copy_u8Value,6);
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN, Local_u8Bit);
	Local_u8Bit = GET_BIT(copy_u8Value,7);
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN, Local_u8Bit);
	
	
}


