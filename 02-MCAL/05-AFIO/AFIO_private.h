/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   22/02/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/* Base Address 0x40010000 */

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_t;

#define     AFIO     ((volatile AFIO_t *) 0x40010000)



#endif