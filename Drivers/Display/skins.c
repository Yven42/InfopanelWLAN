/*
 * skins.c
 *
 *  Created on: Dec 8, 2023
 *      Author: yvenv
 */

#include "skins.h"
#include "Images.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void UmlautCheck(uint8_t* String)
{
    uint8_t* StringWork = String;
    uint8_t CachString[51] = {0};
    uint8_t* pCachString = CachString;

    while (*StringWork)
    {
        // Prüfen auf die Unicode-Sequenz \u0026
        if (*StringWork == '\\' && *(StringWork + 1) == 'u' &&
            *(StringWork + 2) == '0' && *(StringWork + 3) == '0' &&
            *(StringWork + 4) == '2' && *(StringWork + 5) == '6')
        {
            *pCachString = '&'; // Ersetze \u0026 durch &
            //pCachString++;
            StringWork += 5; // Überspringe die gesamte Sequenz
        }
        else if (*StringWork >= 127)
        {
        	if (*StringWork == 195)
			{
				StringWork++;
				switch (*StringWork)
				{
					case 0xa4: // ä
						*pCachString = 127;
						break;
					case 0x84: // Ä
						*pCachString = 128;
						break;
					case 0xb6: // ö
						*pCachString = 129;
						break;
					case 0x96: // Ö
						*pCachString = 130;
						break;
					case 0xbc: // ü
						*pCachString = 131;
						break;
					case 0x9c: // Ü
						*pCachString = 132;
						break;
					case 0x9f: // ß
						*pCachString = 133;
						break;
					default:
						*pCachString = 32; // Alle anderen durch Leerzeichen ersetzen
				}
			}
        	else if (*StringWork == 132) //ä
        	{
        		*pCachString = 127;
        	}
        	else if (*StringWork == 142) //Ä
        	{
        		*pCachString = 128;
        	}
        	else if (*StringWork == 148) //ö
        	{
        		*pCachString = 129;
        	}
        	else if (*StringWork == 153) //Ö
        	{
        		*pCachString = 130;
        	}
        	else if (*StringWork == 154) //Ü
        	{
        		*pCachString = 132;
        	}
        	else if (*StringWork == 129) //ü
        	{
        		*pCachString = 131;
        	}
        	else if (*StringWork == 225) //ß
        	{
        		*pCachString = 133;
        	}
        }
        else
        {
            *pCachString = *StringWork;
        }

        pCachString++;
        StringWork++;
    }

    strcpy((char*)String, (char*)CachString);
}


void vPrint_Config_Screen()
{
	UBYTE *BlackImage;
	BlackImage = (UBYTE *)malloc(4736U);

	Paint_NewImage(BlackImage, EPD_7IN5_V2_WIDTH, EPD_7IN5_V2_HEIGHT, 0, WHITE);
	Paint_SelectImage(BlackImage);
	Paint_Clear(WHITE);

	Paint_DrawRectangle(0, 0, 800, 70, BLACK, 1, DRAW_FILL_FULL);
	Paint_DrawString_EN(40, 20, "Konfiguration Infopanel", &Font_Lucida_24b, BLACK, WHITE);

	Paint_DrawString_EN(40, 120, "1. Stellen Sie sicher, dass der Modusschalter auf Konfig steht", &Font_Lucida_12, WHITE, BLACK);
	Paint_DrawString_EN(40, 160, "2. Verbinden Sie sich mit dem WLAN des Infopanels", &Font_Lucida_12, WHITE, BLACK);
	Paint_DrawString_EN(40, 200, " - WLAN-Name: Infopanel-Konfig", &Font_Lucida_12, WHITE, BLACK);
	Paint_DrawString_EN(40, 240, " - Passwort : infopanel", &Font_Lucida_12, WHITE, BLACK);
	Paint_DrawString_EN(40, 280, "3. Rufen Sie im Browser die Seite http://192.168.4.1 auf", &Font_Lucida_12, WHITE, BLACK);
	Paint_DrawString_EN(40, 320, "4. Geben Sie die Daten ein und klicken Sie auf Senden", &Font_Lucida_12, WHITE, BLACK);
	Paint_DrawString_EN(40, 360, "5. Wenn die Daten auf dem Display erscheinen, ist die Konfiguration fertig", &Font_Lucida_12, WHITE, BLACK);
	Paint_DrawString_EN(40, 400, "6. Stellen Sie den Modusschalter nun auf Betrieb", &Font_Lucida_12, WHITE, BLACK);
	EPD_7IN5_V2_Display(BlackImage);
	free(BlackImage);
}
void vPrint_Config_Done_Screen(sEEPROM_Data_t* pData, uint8_t* pu8MAC)
{
	UBYTE *BlackImage;
	uint8_t cBuffer [50];
	BlackImage = (UBYTE *)malloc(4736U);

	Paint_NewImage(BlackImage, EPD_7IN5_V2_WIDTH, EPD_7IN5_V2_HEIGHT, 0, WHITE);
	Paint_SelectImage(BlackImage);
	Paint_Clear(WHITE);

	Paint_DrawRectangle(0, 0, 800, 140, BLACK, 1, DRAW_FILL_FULL);
	Paint_DrawString_EN(40, 20, pData->u8Device_Name, &Font_Lucida_80b, BLACK, WHITE);

    sprintf((char *)cBuffer,"WLAN-Name      : %s", pData->u8WLAN_Name);
    Paint_DrawString_EN(40, 180, cBuffer, &Font_Lucida_18, WHITE, BLACK);

    sprintf((char *)cBuffer,"TCP-Server-IP  : %d.%d.%d.%d", pData->u8Server_IP[0], pData->u8Server_IP[1], pData->u8Server_IP[2], pData->u8Server_IP[3]);
    Paint_DrawString_EN(40, 220, cBuffer, &Font_Lucida_18, WHITE, BLACK);

    sprintf((char *)cBuffer,"TCP-Server-Port: %d", pData->u8Server_Port);
    Paint_DrawString_EN(40, 260, cBuffer, &Font_Lucida_18, WHITE, BLACK);

    sprintf((char *)cBuffer,"Domain         : %s", pData->u8Domain);
    Paint_DrawString_EN(40, 300, cBuffer, &Font_Lucida_18, WHITE, BLACK);

    sprintf((char *)cBuffer,"MAC-Adresse    : %s", pu8MAC);
    Paint_DrawString_EN(40, 340, cBuffer, &Font_Lucida_18, WHITE, BLACK);

	EPD_7IN5_V2_Display(BlackImage);
	free(BlackImage);
}


void vPrint_Skin_Office(struct sCommunication* Com)
{
	UBYTE *BlackImage;

	BlackImage = (UBYTE *)malloc(4736U);

	Paint_NewImage(BlackImage, EPD_7IN5_V2_WIDTH, EPD_7IN5_V2_HEIGHT, 0, WHITE);
	Paint_SelectImage(BlackImage);
	Paint_Clear(WHITE);
	////
	Paint_DrawBitMap_Paste(Background_Office, 0, 0, 800, 480, BLACK);

	//Room Nr.
	UmlautCheck(Com->u8L1);
	Com->u8L1[5]=0x00;
	Paint_DrawString_EN(40, 33, (const char *)Com->u8L1, &Font_Lucida_80b, BLACK, WHITE);

	//Name
	UmlautCheck(Com->u8L2);
	Com->u8L2[34]=0x00;
	Paint_DrawString_EN(40, 170, (const char *)Com->u8L2, &Font_Lucida_24b, WHITE, BLACK);

	//Name2
	UmlautCheck(Com->u8L3);
	Com->u8L3[34]=0x00;
	Paint_DrawString_EN(40, 205, (const char *)Com->u8L3, &Font_Lucida_24b, WHITE, BLACK);

	//Person Point 1
	UmlautCheck(Com->u8L4);
	Com->u8L4[32]=0x00;
	Paint_DrawString_EN(40, 245, (const char *)Com->u8L4, &Font_Lucida_18, WHITE, BLACK);

	//Person Point 2
	UmlautCheck(Com->u8L5);
	Com->u8L5[32]=0x00;
	Paint_DrawString_EN(40, 273, (const char *)Com->u8L5, &Font_Lucida_18, WHITE, BLACK);

	//Person Point 3
	UmlautCheck(Com->u8L6);
	Com->u8L6[32]=0x00;
	Paint_DrawString_EN(40, 301, (const char *)Com->u8L6, &Font_Lucida_18, WHITE, BLACK);

	//Person Point 4
	UmlautCheck(Com->u8L7);
	Com->u8L7[32]=0x00;
	Paint_DrawString_EN(40, 329, (const char *)Com->u8L7, &Font_Lucida_18, WHITE, BLACK);

	//Info Bar
	UmlautCheck(Com->u8L8);
	Com->u8L8[32]=0x00;
	Paint_DrawString_EN(40, 363, (const char *)Com->u8L8, &Font_Lucida_18b, BLACK, WHITE);

	//Info1
	UmlautCheck(Com->u8L9);
	Com->u8L9[32]=0x00;
	Paint_DrawString_EN(40, 400, (const char *)Com->u8L9, &Font_Lucida_18, WHITE, BLACK);

	//Info2
	UmlautCheck(Com->u8L10);
	Com->u8L10[32]=0x00;
	Paint_DrawString_EN(40, 430, (const char *)Com->u8L10, &Font_Lucida_18, WHITE, BLACK);

	if (Com->u8G_ID == 9)
	{
		Paint_DrawBitMap_Paste(QR_Code_A212, 561, 243, 224, 224, BLACK);
	}

	if (Com->u8G_ID == 1)
	{
		Paint_DrawBitMap_Paste(piktogramm_buero, 561, 243, 224, 224, BLACK);
	}

	if (Com->u8G_ID == 2)
	{
		Paint_DrawBitMap_Paste(piktogramm_chip, 561, 243, 224, 224, BLACK);
	}

	if (Com->u8G_ID == 3)
	{
		Paint_DrawBitMap_Paste(piktogramm_leise, 561, 243, 224, 224, BLACK);
	}

	if (Com->u8G_ID == 4)
	{
		Paint_DrawBitMap_Paste(piktogramm_vorlesung, 561, 243, 224, 224, BLACK);
	}

	//Paint_DrawLine(0, 0, 800, 480, 0x00, DOT_PIXEL_5X5, LINE_STYLE_SOLID);
	////
	EPD_7IN5_V2_Display(BlackImage);
	free(BlackImage);
}

void vPrint_Pixmap(unsigned char* u8Pixmap)
{
	UBYTE *BlackImage;

	BlackImage = (UBYTE *)malloc(4736U);

	Paint_NewImage(BlackImage, EPD_7IN5_V2_WIDTH, EPD_7IN5_V2_HEIGHT, 0, WHITE);
	Paint_SelectImage(BlackImage);
	Paint_Clear(WHITE);

	Paint_DrawBitMap_Paste(u8Pixmap, 0, 0, 800, 480, BLACK);

	EPD_7IN5_V2_Display(BlackImage);
	free(BlackImage);
}

void vPrint_Skin_Lecture_Room(struct sCommunication* Com)
{
	UBYTE *BlackImage;

	BlackImage = (UBYTE *)malloc(4736U);

	Paint_NewImage(BlackImage, EPD_7IN5_V2_WIDTH, EPD_7IN5_V2_HEIGHT, 0, WHITE);
	Paint_SelectImage(BlackImage);
	Paint_Clear(WHITE);
	////

	Paint_DrawBitMap_Paste(Background_Lecture_Room, 0, 0, 800, 480, BLACK);

	//Room Nr.
	UmlautCheck(Com->u8L1);

	//strcpy(Com->u8L1, "A212");

	Com->u8L1[5] = 0;
	Paint_DrawString_EN(40, 33, (const char *)Com->u8L1, &Font_Lucida_80b, BLACK, WHITE);

	//1. Clock
	Com->u8L2[14] = 0;
	Paint_DrawString_EN(40, 175, (const char *)Com->u8L2, &Font_Lucida_24b, WHITE, BLACK);
	//1. Titel
	UmlautCheck(Com->u8L3);
	Com->u8L3[28] = 0;
	Paint_DrawString_EN(40, 217, (const char *)Com->u8L3, &Font_Lucida_30b, WHITE, BLACK);
	//1. Name
	UmlautCheck(Com->u8L4);
	Com->u8L4[28] = 0;
	Paint_DrawString_EN(330, 182, (const char *)Com->u8L4, &Font_Lucida_18, WHITE, BLACK);


	//2. Clock
	Com->u8L5[14] = 0;
	Paint_DrawString_EN(40, 275, (const char *)Com->u8L5, &Font_Lucida_24b, WHITE, BLACK);
	//2. Titel
	UmlautCheck(Com->u8L6);
	Com->u8L6[28] = 0;
	Paint_DrawString_EN(40, 317, (const char *)Com->u8L6, &Font_Lucida_30b, WHITE, BLACK);
	//2. Name
	UmlautCheck(Com->u8L7);
	Com->u8L7[28] = 0;
	Paint_DrawString_EN(330, 282, (const char *)Com->u8L7, &Font_Lucida_18, WHITE, BLACK);


	//3. Clock
	Com->u8L8[14] = 0;
	Paint_DrawString_EN(40, 375, (const char *)Com->u8L8, &Font_Lucida_24b, WHITE, BLACK);
	//3. Titel
	UmlautCheck(Com->u8L9);
	Com->u8L9[28] = 0;
	Paint_DrawString_EN(40, 417, (const char *)Com->u8L9, &Font_Lucida_30b, WHITE, BLACK);
	//3. Name
	UmlautCheck(Com->u8L10);
	Com->u8L10[28] = 0;
	Paint_DrawString_EN(330, 382, (const char *)Com->u8L10, &Font_Lucida_18, WHITE, BLACK);


	//Paint_DrawLine(0, 0, 800, 480, 0x00, DOT_PIXEL_5X5, LINE_STYLE_SOLID);
	////
	EPD_7IN5_V2_Display(BlackImage);
	free(BlackImage);
}

void vStringNr(uint8_t u8StringNr, uint8_t* pu8String_Src, uint8_t* pu8String_Des)
{
	uint8_t* pu8String_Cache = pu8String_Src;
	for(int iCount = 0; iCount < u8StringNr; iCount++)
	{
		while(*pu8String_Cache != ';')
		{
			pu8String_Cache++;
		}
		pu8String_Cache++;
	}
	while(*pu8String_Cache != ';')
	{
		*pu8String_Des = *pu8String_Cache;
		pu8String_Cache++;
		pu8String_Des++;
	}
	*pu8String_Des = 0;
}
