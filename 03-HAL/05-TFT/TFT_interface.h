/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   15/03/2022                  */
/*             Version  :   V01                         */
/********************************************************/ 
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16* copy_Image);
void HTFT_voidFillColor(const u16 copy_u16Color);

#endif