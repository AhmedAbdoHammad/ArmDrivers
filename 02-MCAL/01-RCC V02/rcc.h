/*
 * rcc.h
 *
 *  Created on: 
 *      Author: 
 */

#ifndef _RCC_H_
#define _RCC_H_
/******************************************INCLUDES****************************************************/
#include "bit_math.h"
#include "rcc.h"

/*******************************************MACROS*****************************************************/



/*****************************************PROTOTYPES***************************************************/
void RCC_VidSystemClockInit(ClkSrc);
void RCC_VidEnableClock(BusId, PerId);
void RCC_VidDisableClock(BusId, PerId);

#endif /* _RCC_H_ */
