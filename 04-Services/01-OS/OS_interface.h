/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   08/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void SOS_voidCreateTask(u8 copy_u8ID, u16 copy_u16Priodicity, void (*ptr)(void), u8 copy_u8FirstDelay);
void SOS_voidStart(void);
void SOS_voidSuspendTask(u8 copy_u8ID);
void SOS_voidResumeTask (u8 copy_u8ID);
void SOS_voidDeleteTask (u8 copy_u8ID);


#define READY   1
#define SUSPEND 0
#endif