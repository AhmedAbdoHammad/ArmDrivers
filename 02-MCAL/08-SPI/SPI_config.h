/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   13/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Options :  LOW
			  HIGH    */
#define CLOCK_POLARITY  HIGH

/* Options :  READ_FIRST
			  WRITE_FIRST    */
#define CLOCK_PHASE  WRITE_FIRST

/* Options :  F_DIV_BY_2
			  F_DIV_BY_4
			  F_DIV_BY_8
			  F_DIV_BY_16
			  F_DIV_BY_32
			  F_DIV_BY_64
			  F_DIV_BY_128
			  F_DIV_BY_256
			      */
#define FREQUANCY  F_DIV_BY_2

/* Options :  MASTER
			  SLAVE    */
#define TYPE  MASTER

/* Options :  8
			  16    */
#define DATA_SIZE  8

/* Options :  MSB
			  LSB    */
#define DATA_ORDER  MSB

/* Options :  AUTO
			  MANUAL    */
#define SLAVE_SELECT_MODE  AUTO

/* Options :  SLAVE
			  MASTER    */
#define SLAVE_SELECT_INTERNAL  AUTO

/* Options :  MSB
			  LSB    */
#define DATA_ORDER  MSB

/*Write it on pairs Port,Pin*/
#define MSPI1_SLAVE_PIN GPIOA,PIN0



#endif