/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   14/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#define 8_BITS        0
#define	9_BITS        1

#define 1_SEC         0
#define	0.5_SEC       1
#define	2_SEC         2
#define	1.5_SEC       3

#define 4800_BPS      0
#define	9600_BPS      1
#define	115200_BPS    2

#define LOW           0
#define HIGH          1

#define READ_FIRST    0
#define WRITE_FIRST   1

#define SYNCHORONOUS  1
#define ASYNCHORONOUS 0

#define ENABLE 1
#define DISABLE 0

#define ODD 1
#define EVEN 0


void MUSART1_voidInit(void);
void MUSART1_voidTransmit(u8 arr[]);
u8   MUSART1_voidReceive(void);
#endif