/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   14/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUSART1_voidInit(void)
{
	MUSART1->SR = 0;
	SET_BIT(MUSART1->CR1 , 13);
	
	#if WORD_LENGTH == 8_BITS
		CLR_BIT(MUSART1->CR1 , 12);
	#elif WORD_LENGTH == 9_BITS
		SET_BIT(MUSART1->CR1 , 12);
	#endif
	
	#if PARITY == ENABLE
		SET_BIT(MUSART1->CR1,10);
		#if PARITY_MODE == ODD
		SET_BIT(MUSART1->CR1,9);
		#elif PARITY_MODE == EVEN
		CLR_BIT(MUSART1->CR1,9);
		#endif
	#elif TYPE == DISABLE
		CLR_BIT(MUSART1->CR1,10);
	#endif
	
	#if BAUD_RATE == 4800_BPS
		MUSART1->BRR = 0x341;
	#elif BAUD_RATE == 9600_BPS
		MUSART1->BRR = 0x341;
	#elif BAUD_RATE == 115200_BPS
		MUSART1->BRR = 0x341;
	#endif
	
	#if STOP == 1_SEC
		CLR_BIT(MUSART1->CR2 , 12);
		CLR_BIT(MUSART1->CR2 , 13);
	#elif STOP == 0.5_SEC
		SET_BIT(MUSART1->CR2 , 12);
		CLR_BIT(MUSART1->CR2 , 13);
	#elif STOP == 2_SEC
		CLR_BIT(MUSART1->CR2 , 12);
		SET_BIT(MUSART1->CR2 , 13);
	#elif STOP == 1.5_SEC
		SET_BIT(MUSART1->CR2 , 12);
		SET_BIT(MUSART1->CR2 , 13);
	#endif
	
	#if CLOCK_PHASE == READ_FIRST
		CLR_BIT(MUSART1->CR2 , 9);
	#elif CLOCK_PHASE == WRITE_FIRST
		SET_BIT(MUSART1->CR2 , 9);
	#endif
	
	#if CLOCK_POLARITY == LOW
		CLR_BIT(MUSART1->CR1 , 10);
	#elif CLOCK_POLARITY == HIGH
		SET_BIT(MUSART1->CR1 , 10);
	#endif
	
}
void MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while(arr[i] != '\0')
	{
		MUSART1 -> DR = arr[i];
		/*Wait till transmission complete*/
		while(GET_BIT(MUSART1 -> SR, 6) == 0);
		i++;
	}
}
u8   MUSART1_voidReceive(void)
{
	/*Wait till Receive complete*/
	while(GET_BIT(MUSART1 -> SR, 5) == 0);
	/*To ensure the return is only 8 bits*/
	return(0xFF & (MUSART1 -> DR));
	
	
}
