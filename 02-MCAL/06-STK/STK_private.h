/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   03/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}SysTick;

#define MSTK ((volatile SysTick*)0xE000E010)


#endif