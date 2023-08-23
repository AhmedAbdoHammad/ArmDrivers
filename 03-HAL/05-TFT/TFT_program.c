/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   15/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


void HTFT_voidInit(void)
{
	/*Reset Pulse*/
	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);
	
	/*Sleep Out Command*/
	voidWriteCommand(0x11);
	
	/*Wait 150 msec*/
	MSTK_voidSetBusyWait(150000);
	
	/*Color mode Command*/
	voidWriteCommand(0x3A);
	/*Color mode RGB565*/
	voidWriteData(0x05);
	
	/*Display on mode*/
	voidWriteCommand(0x29);
	
	
}

void HTFT_voidDisplayImage(const u16* copy_Image)
{
	u16 Counter;
	/*Set X Address*/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	
	/*Set Y Address*/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);
	
	/*RAM Write*/
	voidWriteCommand(0x2C);
	voidWriteData(0xffff); /*Lower Right black (First Pixel)*/
	
	for(Counter = 0 ; Counter < 20480; Counter++)
	{
		/*Write the high byte*/
		voidWriteData(copy_Image[Counter] >> 8);
		/*Write the Low byte*/
		voidWriteData(copy_Image[Counter] && 0x00ff);
	}
}

void HTFT_voidFillColor(const u16 copy_u16Color)
{
	u16 Counter;
	/*Set X Address*/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	
	/*Set Y Address*/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);
	
	/*RAM Write*/
	voidWriteCommand(0x2C);
	voidWriteData(0xffff); /*Lower Right black (First Pixel)*/
	
	for(Counter = 0 ; Counter < 20480; Counter++)
	{
		/*Write the high byte*/
		voidWriteData(copy_u16Color >> 8);
		/*Write the Low byte*/
		voidWriteData(copy_u16Color && 0x00ff);
	}
}

void HTFT_voidDrawRectangular(u8 x1, u8 x2, u8 y1, u8 y2, u16 copy_u16Color)
{
	u16 Counter;
	u16 size = (x2 - x1) * (y2 - y1);
	/*Set X Address*/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(x1);
	voidWriteData(0);
	voidWriteData(x2);
	
	/*Set Y Address*/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);
	
	/*RAM Write*/
	voidWriteCommand(0x2C);
	voidWriteData(0xffff); /*Lower Right black (First Pixel)*/
	
	for(Counter = 0 ; Counter < size; Counter++)
	{
		/*Write the high byte*/
		voidWriteData(copy_u16Color >> 8);
		/*Write the Low byte*/
		voidWriteData(copy_u16Color && 0x00ff);
	}
}


static void voidWriteCommand(u8 copy_u8Command)
{
	u8 Local_u8Temp;
	/*Set A0 pin to Low*/
	MGPIO_voidSetPinValue(TFT_A0_PIN, GPIO_LOW);
	
	/*Send command over SPI*/
	MSPI1_voidSendReceiveSynch(copy_u8Command,&Local_u8Temp);
	
}


static void voidWriteData(u8 copy_u8Data)
{
	u8 Local_u8Temp;
	/*Set A0 pin to High*/
	MGPIO_voidSetPinValue(TFT_A0_PIN, GPIO_HIGH);
	
	/*Send data over SPI*/
	MSPI1_voidSendReceiveSynch(copy_u8Data,&Local_u8Temp);
}



