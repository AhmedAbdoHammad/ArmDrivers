/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   14/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "UART_interface.h"

int main(void)
{
	/**          RCC Enable           **/
	RCC_voidInitSysClock();
	/*Enable RCC for GPIOA*/
	RCC_voidEnableClock(RCC_APB2 , 2);
	/*Enable RCC for UART*/
	RCC_voidEnableClock(RCC_APB2 , 14);
	
	/**          GPIO Direction           **/
	/*A9  =====> TX ===> OUTPUT SPEED 50MHZ Push Pull*/
	MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_50MHZ_PP);
	/*A10 =====> RX ===> Input Floating*/
	MGPIO_voidSetPinDirection(GPIOA, PIN10, INPUT_FLOATING);
	/*A0  =====> OUTPUT SPEED 2MHZ Push Pull*/
	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_2MHZ_PP);
	
	MUSART1_voidInit();
	
	u8 x;
	while(1)
	{
		MUSART1_voidTransmit("97"); /*R char*/
		x= MUSART1_voidReceive();
		
		if     (x == '5')
		{
			MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
		}
		else if(x == 'R')
		{
			MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
		}
		
	}

	
	return 0;
}



