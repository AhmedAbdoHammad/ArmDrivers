/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   07/03/2022                  */
/*             Version  :   V02                         */
/********************************************************/ 
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

typedef struct 
{
	volatile u32 ISER [32];
	volatile u32 ICER [32];
	volatile u32 ISPR [32];
	volatile u32 ICPR [32];
	volatile u32 IAPR [32];
	volatile u32 IPR  [32];
}NVIC;

#define MNVIC  ((volatile NVIC*)0xE000E100)

#define SCB_AIRCR     *((volatile u32*) 0xE000ED0C)





#endif