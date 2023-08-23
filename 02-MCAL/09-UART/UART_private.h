/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   14/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTBR;	
}UART_t;

#define MUSART1 ((volatile UART_t *)0x40013800)



#endif