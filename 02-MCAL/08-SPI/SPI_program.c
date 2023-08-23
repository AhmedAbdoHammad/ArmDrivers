/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   13/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI_voidInit(void);
{
	#if CLOCK_PHASE == READ_FIRST
		CLR_BIT(MSPI1->CR1 , 0);
	#elif CLOCK_PHASE == WRITE_FIRST
		SET_BIT(MSPI1->CR1 , 0);
	#endif
	
	#if CLOCK_POLARITY == LOW
		CLR_BIT(MSPI1->CR1 , 1);
	#elif CLOCK_POLARITY == HIGH
		SET_BIT(MSPI1->CR1 , 1);
	#endif
	
	#if TYPE == MASTER
		SET_BIT(MSPI1->CR1,2);
	#elif TYPE == SLAVE
		CLR_BIT(MSPI1->CR1,2);
	#endif
	
	#if FREQUANCY == F_DIV_BY_2
		CLR_BIT(MSPI1->CR1 , 3);
		CLR_BIT(MSPI1->CR1 , 4);
		CLR_BIT(MSPI1->CR1 , 5);
	#elif FREQUANCY == F_DIV_BY_4
		SET_BIT(MSPI1->CR1 , 3);
		CLR_BIT(MSPI1->CR1 , 4);
		CLR_BIT(MSPI1->CR1 , 5);
	#elif FREQUANCY == F_DIV_BY_8
		CLR_BIT(MSPI1->CR1 , 3);
		SET_BIT(MSPI1->CR1 , 4);
		CLR_BIT(MSPI1->CR1 , 5);
	#elif FREQUANCY == F_DIV_BY_16
		SET_BIT(MSPI1->CR1 , 3);
		SET_BIT(MSPI1->CR1 , 4);
		CLR_BIT(MSPI1->CR1 , 5);
	#elif FREQUANCY == F_DIV_BY_32
		CLR_BIT(MSPI1->CR1 , 3);
		CLR_BIT(MSPI1->CR1 , 4);
		SET_BIT(MSPI1->CR1 , 5);
	#elif FREQUANCY == F_DIV_BY_64
		SET_BIT(MSPI1->CR1 , 3);
		CLR_BIT(MSPI1->CR1 , 4);
		SET_BIT(MSPI1->CR1 , 5);
	#elif FREQUANCY == F_DIV_BY_128
		CLR_BIT(MSPI1->CR1 , 3);
		SET_BIT(MSPI1->CR1 , 4);
		SET_BIT(MSPI1->CR1 , 5);
	#elif FREQUANCY == F_DIV_BY_256
		SET_BIT(MSPI1->CR1 , 3);
		SET_BIT(MSPI1->CR1 , 4);
		SET_BIT(MSPI1->CR1 , 5);
	#endif
	
	/*Enable SPI1*/
	SET_BIT(MSPI1->CR1 , 6);
	
	#if DATA_ORDER == LSB
		SET_BIT(MSPI1->CR1,7);
	#elif DATA_ORDER == MSB
		CLR_BIT(MSPI1->CR1,7);
	#endif
	
	#if SLAVE_SELECT_MODE == MANUAL
		SET_BIT(MSPI1->CR1,9);
		#if SLAVE_SELECT_INTERNAL == MASTER
			SET_BIT(MSPI1->CR1,8);
		#elif SLAVE_SELECT_INTERNAL == SLAVE
			CLR_BIT(MSPI1->CR1,8);
		#endif
	#elif SLAVE_SELECT_MODE == AUTO
		CLR_BIT(MSPI1->CR1,8);
		CLR_BIT(MSPI1->CR1,9);
	#endif
	
	CLR_BIT(MSPI1->CR1,10);
	
	#if DATA_SIZE == 16
		SET_BIT(MSPI1->CR1,11);
	#elif DATA_SIZE == 8
		CLR_BIT(MSPI1->CR1,11);
	#endif
	
	CLR_BIT(MSPI1->CR1,12);
	CLR_BIT(MSPI1->CR1,13);
	CLR_BIT(MSPI1->CR1,14);
	CLR_BIT(MSPI1->CR1,15);	
}


void MSPI1_voidSendReceiveSynch(u8 copy_u8DataToSend, u8 *copy_u8DataToReceive)
{
	/*Clear slave select pin*/
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_LOW);
	
	/*Send Data*/
	MSPI1->DR = copy_u8DataToSend;
	
	/*Wait Busy flag*/
	while(GET_BIT(MSPI1->SR,7) == 1);
	
	/*Return to the received Data*/
	*copy_u8DataToReceive = MSPI1->DR; 
	
	/*Set slave select pin*/
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_HIGH);
}

void MSPI1_voidSendReceiveASynch(u8 copy_u8DataToSend, void (*CallBack)(u8))
{
	/*Clear slave select pin*/
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_LOW);
	
	/*Send Data*/
	MSPI1->DR = copy_u8DataToSend; 
	
	/*Set slave select pin*/
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_HIGH);
}

void SPI1_IRQHandler(void)
{
	CallBack(MSPI1->DR);
	
}