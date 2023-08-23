/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   11/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"



void MDMA_voidChannelInit(void)
{
	/*
		1- mem to mem
		2- Priority very high
		3- Source and Destination size = 32Bits
		4- MINC, PINC activated
		5- No Circular
		6- Direction: 
		7- Transfer Interrupt Enable
	*/
	MDMA->Channel[ChannelID -1].CCR = 0x00007ADF;
}

void MDMA_voidChannelStart(u32 copy_Pu32ScourceAddress, u32 copy_Pu32DestinationAddress, u16 copy_u16BlockLength)
{
	/*Make Sure Channel is Disabled*/
	CLR_BIT(MDMA->Channel[ChannelID -1].CCR,0);
	/*Write the Address*/
	MDMA->Channel[ChannelID -1].CPAR  = copy_Pu32ScourceAddress;
	MDMA->Channel[ChannelID -1].CMAR  = copy_Pu32DestinationAddress;
	/*Write Block Length*/
	MDMA->Channel[ChannelID -1].CNDTR = copy_u16BlockLength;
	/*Channel Eable*/
	SET_BIT(MDMA->Channel[ChannelID -1].CCR,0);
}
