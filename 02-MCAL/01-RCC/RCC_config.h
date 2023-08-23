/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   27/01/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options :  RCC_HSE_CRYSTAL
			  RCC_HSE_RC
			  RCC_HSI
			  RCC_PLL           */
#define RCC_CLOCK_TYPE  RCC_HSE_CRYSTAL

/* Note : Select only if you choose PLL as an input clock source*/
#if RCC_CLOCK_TYPE == RCC_PLL
/* Options :  RCC_PLL_IN_HSI_DIV_2
			  RCC_PLL_IN_HSE_DIV_2
			  RCC_PLL_IN_HSE       */
#define RCC_PLL_INPUT   RCC_PLL_IN_HSI_DIV_2

/* Options 2 : 16 */
#define RCC_PLL_MUL_VAL 4

#endif


#endif