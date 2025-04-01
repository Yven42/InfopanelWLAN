/*
 * communication.h
 *
 *  Created on: Dec 8, 2023
 *      Author: yvenv
 */

#ifndef COMMUNICATION_COMMUNICATION_H_
#define COMMUNICATION_COMMUNICATION_H_

#include "main.h"
#include "skins.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "WLAN_Web.h"

extern SPI_HandleTypeDef hspi3;
extern RTC_HandleTypeDef hrtc;

uint8_t u8Pull_Request();
uint8_t u8Waiting_For_Reply();
uint8_t u8Use_Data(uint8_t*);
uint8_t u8Connection_Loop();
void vConfig_Screen();

void vConfig_Done_Screen(sEEPROM_Data_t* pData, uint8_t* pu8MAC);

struct sCommunication
{
	uint8_t u8Version;
	uint8_t u8MSG_Type;
	uint32_t u32Sleep_Time;
	uint8_t u8Type;
	uint8_t u8IP[16];
	uint8_t u8Port[5];
	uint8_t u8L1[50];
	uint8_t u8L2[50];
	uint8_t u8L3[50];
	uint8_t u8L4[50];
	uint8_t u8L5[50];
	uint8_t u8L6[50];
	uint8_t u8L7[50];
	uint8_t u8L8[50];
	uint8_t u8L9[50];
	uint8_t u8L10[50];
	uint8_t u8L11[50];
	uint8_t u8G_ID;
}typedef sCommunication_t;

#endif /* COMMUNICATION_COMMUNICATION_H_ */
