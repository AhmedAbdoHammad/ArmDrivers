/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   11/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

void MDMA_voidChannelInit(void);
void MDMA_voidChannelStart(u32 copy_Pu32ScourceAddress, u32 copy_Pu32DestinationAddress, u16 copy_u16BlockLength);

#endif