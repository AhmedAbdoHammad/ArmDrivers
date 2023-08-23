/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   08/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "OS_interface.h"
#include "GPIO_interface.h"

#include "STK_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);

int main(void)
{
	/*Clock Init*/
	RCC_voidInitSysClock();
	/*GPIOA Init    Direction*/
	RCC_voidEnableClock(RCC_APB2 , 2);
	
	MGPIO_voidSetPinDirection(GPIOA, PIN0, INPUT_PULL_UP_DOWN);
	
	SOS_voidCreateTask(0, 1000,LED1);
	SOS_voidCreateTask(1, 2000,LED2);
	SOS_voidCreateTask(2, 3000,LED3);
	
	SOS_voidStart();
	while(1)
	{
		
		
		
	}
	return 0;
}

void LED1(void)
{
	static u8 Local_u8Pin0 = 0;
	TOG_BIT(Local_u8Pin0 , 0);
	MGPIO_voidSetPinValue(GPIOA, PIN0, Local_u8Pin0);
}

void LED2(void)
{
	static u8 Local_u8Pin1 = 0;
	TOG_BIT(Local_u8Pin1 , 0);
	MGPIO_voidSetPinValue(GPIOA, PIN1, Local_u8Pin0);
}

void LED3(void)
{
	static u8 Local_u8Pin2 = 0;
	TOG_BIT(Local_u8Pin2 , 0);
	MGPIO_voidSetPinValue(GPIOA, PIN2, Local_u8Pin0);
}

