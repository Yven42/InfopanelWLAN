/*
 * skins.h
 *
 *  Created on: Dec 8, 2023
 *      Author: yvenv
 */

#ifndef DISPLAY_SKINS_H_
#define DISPLAY_SKINS_H_

#include "main.h"
#include "EPD_7in5_V2.h"
#include "GUI_Paint.h"
#include "../../Fonts/fonts.h"
#include "communication.h"
#include "WLAN_Web.h"


void vStringNr(uint8_t u8StringNr, uint8_t* pu8String_Src, uint8_t* pu8String_Des);

void vPrint_Skin_Office(struct sCommunication* Com);
void vPrint_Skin_Lecture_Room(struct sCommunication* Com);
void vPrint_Pixmap(unsigned char* u8Pixmap);

void vPrint_Config_Screen();
void vPrint_Config_Done_Screen(sEEPROM_Data_t* pData, uint8_t* pu8MAC);

#endif /* DISPLAY_SKINS_H_ */
