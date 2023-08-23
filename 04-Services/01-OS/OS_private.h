/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   08/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct
{
	u16 Priodicity;
	void (*Fptr) (void);
	u8 FirstDelay;
	u8 State;
	
}Task;



#endif