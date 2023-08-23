/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   13/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#define LOW            0
#define HIGH           1

#define READ_FIRST     0
#define WRITE_FIRST    0

#define F_DIV_BY_2     0
#define F_DIV_BY_4     1
#define F_DIV_BY_8     2
#define F_DIV_BY_16    3
#define F_DIV_BY_32    4
#define F_DIV_BY_64    5
#define F_DIV_BY_128   6
#define F_DIV_BY_256   7 

#define SLAVE          0
#define MASTER         1

#define AUTO           0
#define MANUAL         1


void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(u8 copy_u8DataToSend, u8 *copy_u8DataToReceive);
void MSPI1_voidSendReceiveASynch(u8 copy_u8DataToSend, void (*CallBack)(u8));


#endif