/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   14/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/* Options :8_BITS
			9_BITS */
#define WORD_LENGTH 8_BITS

/* Options :1_SEC
			0.5_SEC
			2_SEC
			1.5_SEC*/
#define STOP_TIME 1_SEC
/* Options :4800_BPS
			9600_BPS
			115200_BPS */
#define BAUD_RATE 9600_BPS
/* Options :  LOW
			  HIGH    */
#define CLOCK_POLARITY  LOW

/* Options :  READ_FIRST
			  WRITE_FIRST    */
#define CLOCK_PHASE  WRITE_FIRST

/* Options :  SYNCHORONOUS
			  ASYNCHORONOUS    */
#define CONNECTION ASYNCHORONOUS

/* Options :  ENABLE
			  DISABLE    */
#define PARITY DISABLE
/* Options :  ODD
			  EVEN    */
#define PARITY_MODE ODD

#endif