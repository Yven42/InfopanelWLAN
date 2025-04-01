/*
 * WLAN_Web.h
 *
 *  Created on: May 16, 2024
 *      Author: yvenv
 */

#ifndef INC_WLAN_WEB_H_
#define INC_WLAN_WEB_H_

#include "main.h"
#include "Wifi.h"

typedef struct sEEPROM_Data
{
	uint8_t u8Device_Name[20];
	uint8_t u8WLAN_Name[20];
	uint8_t u8WLAN_Password[70];
	uint8_t u8Domain[40];
	uint8_t u8Server_IP[4];
	uint16_t u8Server_Port;
}sEEPROM_Data_t;

sEEPROM_Data_t WLAN_Web_Start(Wifi_t* Wifi);
uint8_t u8Send_HTML (uint8_t u8Channel, const char* pcHTML, uint16_t u16Size);
const char* pcParseStringToStruct(const char* input, sEEPROM_Data_t* data);
uint8_t u8WifiMAC();
uint8_t u8ParseMacAddress();
void vReplaceMacAddress(char* htmlContent, const char* newMacAddress);
uint8_t u8SendReport(const char* Rx_Buffer, sEEPROM_Data_t* sData, uint8_t u8Channel);



#endif /* INC_WLAN_WEB_H_ */
