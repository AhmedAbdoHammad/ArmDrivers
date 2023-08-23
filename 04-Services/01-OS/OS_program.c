/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   08/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#include "STK_interface.h"

#define NULL (void *)0

/*Array of Tasks         Array of Structure*/
static Task  OS_Tasks[NUMBER_OF_TASKS] = {};

void SOS_voidCreateTask(u8 copy_u8ID, u16 copy_u16Priodicity, void (*ptr)(void))
{
	OS_Tasks[copy_u8ID].Priodicity = copy_u16Priodicity;
	OS_Tasks[copy_u8ID].Fptr = ptr;
	
}

void SOS_voidStart(void)
{
	/*Initialization*/
	MSTK_voidInit();
	/*Tick = 1 msec*/
	MSTK_voidSetIntervalPeriodic (1000, Scheduler);
	
	
}
/*volatile u16 TickCounts = 0;
void Scheduler(void)
{
	for(u8 i = 0; i<NUMBER_OF_TASKS ;i++)
	{
		if((TickCounts % OS_Tasks[i].Priodicity) == 0)
		{
			OS_Tasks[i].Fptr();
		}
	}
	TickCounts++;
}*/

void Scheduler(void)
{
	for(u8 i = 0; i<NUMBER_OF_TASKS ;i++)
	{
		if((OS_Tasks[i].Fptr()!= NULL) && (OS_Tasks[i].State == READY))
		{
			if((OS_Tasks[i].FirstDelay) == 0)
			{
				OS_Tasks[i].FirstDelay() = OS_Tasks[i].Priodicity;
				OS_Tasks[i].Fptr();
			}
			else
			{
				OS_Tasks[i].FirstDelay()--;
			}
		}
	}
}

void SOS_voidSuspendTask(u8 copy_u8ID)
{
	OS_Tasks[copy_u8ID].State = SUSPEND;
}
void SOS_voidResumeTask (u8 copy_u8ID)
{
	OS_Tasks[copy_u8ID].State = READY;
}

void SOS_voidDeleteTask (u8 copy_u8ID)
{
	OS_Tasks[copy_u8ID].Priodicity = NULL;
	OS_Tasks[copy_u8ID].Fptr       = NULL;
	OS_Tasks[copy_u8ID].FirstDelay = NULL;
	OS_Tasks[copy_u8ID].State      = NULL;
}
