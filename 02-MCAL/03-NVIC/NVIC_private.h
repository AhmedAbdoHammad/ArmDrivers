/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   16/02/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* 0xE000E100 Base Adderss */
#define NVIC_ISER0    *((u32*) 0xE000E100)  /*Enable External interrupts from 0 to 31*/
#define NVIC_ISER1    *((u32*) 0xE000E104)  /*Enable External interrupts from 32 to 63*/

#define NVIC_ICER0    *((u32*) 0xE000E180)  /*Disable External interrupts from 0 to 31*/
#define NVIC_ICER1    *((u32*) 0xE000E184)  /*Disable External interrupts from 32 to 63*/

#define NVIC_ISPR0    *((u32*) 0xE000E200)  /*Set Pending Flag interrupts from 00 to 31*/
#define NVIC_ISPR1    *((u32*) 0xE000E204)  /*Set Pending Flag interrupts from 32 to 63*/

#define NVIC_ICPR0    *((u32*) 0xE000E280)  /*Clear Pending Flag interrupts from 00 to 31*/
#define NVIC_ICPR1    *((u32*) 0xE000E284)  /*Clear Pending Flag interrupts from 32 to 63*/

#define NVIC_IAPR0    *((volatile u32*) 0xE000E300)  /*Read Active Flags interrupts from 32 to 63*/
#define NVIC_IAPR1    *((volatile u32*) 0xE000E304)  /*Read Active Flags interrupts from 32 to 63*/

#define NVIC_IPR      ((volatile u8*) 0xE000E400)
#define SCB_AIRCR     *((volatile u32*) 0xE000ED0C)





#endif