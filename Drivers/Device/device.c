/*
 * device.c
 *
 *  Created on: Jan 8, 2025
 *      Author: yvogt
 */

#include "device.h"
#include "WLAN_Web.h"


uint32_t BackupRegister;

static void _Standby(uint32_t Seconds)
{
	HAL_GPIO_WritePin(EN_WLAN_GPIO_Port, EN_WLAN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RST_WLAN_GPIO_Port, RST_WLAN_Pin, GPIO_PIN_RESET);

	HAL_SuspendTick();
	HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, Seconds, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	HAL_PWR_EnterSTANDBYMode();
}

void StandbyStart(uint32_t Seconds, uint8_t Normal)
{
	// Zugriff auf Backup-Register aktivieren
	HAL_PWR_EnableBkUpAccess();
	__HAL_RCC_BACKUPRESET_FORCE();
	__HAL_RCC_BACKUPRESET_RELEASE();
	__HAL_RCC_RTC_ENABLE();

	if(Normal == 1)
	{
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x1000);
		_Standby(Seconds);
	}
	else
	{
		BackupRegister = BackupRegister & 0xF0FF;
		if (BackupRegister > (0x1000 + Connection_Attempts - 1))
		{
			_Standby(86400); //the device tries again after one day
		}
		else
		{
			BackupRegister++;
			HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, BackupRegister);
			_Standby(3600); //the device will try again in one hour
		}
	}
}

void HardwareResetCheck(void)
{
	HAL_PWR_EnableBkUpAccess(); // Zugriff auf Backup-Register aktivieren
	BackupRegister = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1);
	if ((BackupRegister & 0x0100) > 0)
	{
	  //Hardware reset detected
	  Buzzer(200);
	  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x1000);
	}
	else
	{
	  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, BackupRegister | 0x1100);
	}
}

void StartWlanModule()
{
	HAL_GPIO_WritePin(WLAN_POWER_GPIO_Port, WLAN_POWER_Pin, 0);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(EN_WLAN_GPIO_Port, EN_WLAN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RST_WLAN_GPIO_Port, RST_WLAN_Pin, GPIO_PIN_RESET);
	osDelay(1000);
	for (int i=0; i<4000000;i++);
	HAL_GPIO_WritePin(EN_WLAN_GPIO_Port, EN_WLAN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RST_WLAN_GPIO_Port, RST_WLAN_Pin, GPIO_PIN_SET);
	osDelay(500);
}

void Buzzer(uint32_t MilliSecond)
{
	HAL_TIM_PWM_Start_IT(&htim5,TIM_CHANNEL_2);
	HAL_Delay(MilliSecond);
	HAL_TIM_PWM_Stop_IT(&htim5,TIM_CHANNEL_2);
}

void VirtualEepromInit()
{
	if(HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin) == GPIO_PIN_SET)
	{
		ee_format((bool)0);
		Infopanel_MetaData.eState = CONFIG_MODE;
	}
	else
	{
		sEEPROM_Data_t Data;
		memset(&Data,0,sizeof(Data));
		ee_read(0, sizeof(Data), (uint8_t*)&Data);

		Infopanel_MetaData.eState = NORMAL_MODE;
		strcpy((char*)Infopanel_MetaData.u8Device_Name,(char*)Data.u8Device_Name);
		strcpy((char*)Infopanel_MetaData.u8WLAN_Name,(char*)Data.u8WLAN_Name);
		strcpy((char*)Infopanel_MetaData.u8WLAN_Password,(char*)Data.u8WLAN_Password);
		strcpy((char*)Infopanel_MetaData.u8Domain,(char*)Data.u8Domain);
		sprintf((char *)Infopanel_MetaData.u8Server_IP,"%d.%d.%d.%d",Data.u8Server_IP[0],Data.u8Server_IP[1],Data.u8Server_IP[2],Data.u8Server_IP[3]);
		Infopanel_MetaData.u16Server_Port = Data.u8Server_Port;
	}
}

void VirtualEepromInitStatic()
{
	sEEPROM_Data_t Data;
	strcpy((char*)Data.u8Device_Name,(char*)"Beta");
	strcpy((char*)Data.u8WLAN_Name,(char*)"door-info");
	strcpy((char*)Data.u8WLAN_Password,(char*)"xeos4Aev8ohvaht8pohl0Jasobiyahjuuqu6cohl7ao3os0OoShoh1mi0je3ahT");
	Data.u8Server_IP[0] = 141;
	Data.u8Server_IP[1] = 79;
	Data.u8Server_IP[2] = 71;
	Data.u8Server_IP[3] = 207;
	Data.u8Server_Port = 1234;
	strcpy((char*)Data.u8Domain,(char*)"aa94229c-e0f8-4a73-9461-a295d0390b7c");

	Infopanel_MetaData.eState = NORMAL_MODE;
	strcpy((char*)Infopanel_MetaData.u8Device_Name,(char*)Data.u8Device_Name);
	strcpy((char*)Infopanel_MetaData.u8WLAN_Name,(char*)Data.u8WLAN_Name);
	strcpy((char*)Infopanel_MetaData.u8WLAN_Password,(char*)Data.u8WLAN_Password);
	strcpy((char*)Infopanel_MetaData.u8Domain,(char*)Data.u8Domain);
	sprintf((char *)Infopanel_MetaData.u8Server_IP,"%d.%d.%d.%d",Data.u8Server_IP[0],Data.u8Server_IP[1],Data.u8Server_IP[2],Data.u8Server_IP[3]);
	Infopanel_MetaData.u16Server_Port = Data.u8Server_Port;
}

void DisplayOutput(DriplayPrintMode_t Mode, struct sCommunication Com)
{
	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 1);
	HAL_Delay(100);
	DEV_Module_Init();
	HAL_Delay(100);
	EPD_7IN5_V2_Init();

	switch(Mode)
	{
		case Office:
			vPrint_Skin_Office(&Com);
		case LectureRoom:
			vPrint_Skin_Lecture_Room(&Com);
	}

	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 0);
	DEV_Module_Exit();
}
