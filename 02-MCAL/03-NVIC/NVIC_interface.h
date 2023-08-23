/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   16/02/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_VoidEnableInterrupt  (u8 Copy_u8IntNumber);
void MNVIC_VoidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_VoidSetPendingFlag   (u8 Copy_u8IntNumber);
void MNVIC_VoidClearPendingFlag (u8 Copy_u8IntNumber);
u8 MNVIC_VoidGetActiveFlag      (u8 Copy_u8IntNumber);
void MNVIC_VoidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32GROUP);
void MNVIC_voidInit(void);
void MNVIC_voidSetPriority(u8 copy_u8PeripheralIdx, u8 copy_u8Priority);

#define Gruop3        0x05FA0300   // 4 bits for Groups (IPR) => Group
#define Gruop4        0x05FA0400   // 3 bits for Groups and 1 bit for Sub
#define Gruop5        0x05FA0500   // 2 bits for Groups and 2 bit for Sub
#define Gruop6        0x05FA0600   // 1 bits for Groups and 3 bit for Sub
#define Gruop7        0x05FA0700   // 4 bits for Sub

#endif