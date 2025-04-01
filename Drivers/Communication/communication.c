/*
 * communication.c
 *
 *  Created on: Dec 8, 2023
 *      Author: yvenv
 */

#include "communication.h"
#include "jsmn.h"
#include "skins.h"
#include "Wifi.h"
#include "device.h"

extern RTC_HandleTypeDef hrtc;
extern uint16_t u16BatteryVoltage();

//#######################################################################################

//#######################################################################################

void Wifi_UserProcess(void)
{
  static uint8_t last=0;
  static WifiConnectionStatus_t TCP_State = WifiConnectionStatus_Disconnected;

  //New Connect
  if((Wifi.TcpIpConnections[0].status == WifiConnectionStatus_Connected) && (TCP_State == WifiConnectionStatus_Disconnected))
  {
	  TCP_State = WifiConnectionStatus_Connected;
	  u8Pull_Request();
  }
  if(Wifi.TcpIpConnections[0].status == WifiConnectionStatus_Disconnected)
  {
	  TCP_State = WifiConnectionStatus_Disconnected;
  }

  if(strstr(Wifi.MyIP,"0.0.0.0")!=NULL)
  {
    if(last!=1)
	{

	}
    last=1;
  }
  else
  {
    if(last!=2)
    {
    	Wifi_TcpIp_StartTcpConnection(1,Infopanel_MetaData.u8Server_IP , Infopanel_MetaData.u16Server_Port, 2000);
    	//HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1);
    	osDelay(500);
    	//HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 0);
    	//Wifi_TcpIp_SetEnableTcpServer(1111);
    }
    last=2;
  }

  if(Wifi.TcpIpConnections[0].status == WifiConnectionStatus_Disconnected)
  {
		Wifi_TcpIp_StartTcpConnection(1,Infopanel_MetaData.u8Server_IP , Infopanel_MetaData.u16Server_Port, 2000);
		//HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1);
		osDelay(100);
		//HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 0);
  }

  if( Wifi.GotNewData==true)
  {
	  Wifi.GotNewData=false;
	  HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 0);
	  osDelay(1000);
	  //uint8_t u8Buffer[1024] = {0};
	  //strncpy((char *)u8Buffer,(const char *)Wifi.RxBufferForData,1024);
	  u8Use_Data(Wifi.RxBufferForData);

	  //HAL_GPIO_WritePin(EN_WLAN_GPIO_Port, EN_WLAN_Pin, GPIO_PIN_RESET);
	  /*DEV_Module_Init();
	  EPD_7IN5_V2_Init();
	  EPD_7IN5_V2_Clear();
	  osDelay(500);
	  for (int iCount = 0; iCount < 20;iCount++)
	  {
		  if ((u8Buffer[iCount] == '\n')||(u8Buffer[iCount] == '\r'))
		  {
			  u8Buffer[iCount] = 0;
		  }
	  }
	  //vPrint_Skin_1(u8Buffer);

	  GPIOA->BSRR = 0xFFFF0000;
	  HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 0);
	  HAL_SuspendTick();
	  HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 100, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
	  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	  HAL_PWR_EnterSTANDBYMode();*/
  }
}
//#######################################################################################
void  Wifi_UserGetUdpData(uint8_t LinkId,uint16_t DataLen,uint8_t *Data)
{
  Wifi_TcpIp_SendDataUdp(LinkId,2,(uint8_t*)"OK");
}
//#######################################################################################
void  Wifi_UserGetTcpData(uint8_t LinkId,uint16_t DataLen,uint8_t *Data)
{
  Wifi_TcpIp_SendDataTcp(LinkId,2,(uint8_t*)"OK");
}
//#######################################################################################


void Wifi_UserInit(void)
{
	if(Infopanel_MetaData.eState == CONFIG_MODE)
	{
		vConfig_Screen();
		sEEPROM_Data_t Data;
		Data = WLAN_Web_Start(&Wifi);

		bool test = ee_format((bool)0);
		ee_write(0, sizeof(Data), (uint8_t*)&Data);
		ee_commit();
		vConfig_Done_Screen(&Data, Wifi.MAC_Adress);

		HAL_GPIO_WritePin(EN_WLAN_GPIO_Port, EN_WLAN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RST_WLAN_GPIO_Port, RST_WLAN_Pin, GPIO_PIN_RESET);
		HAL_SuspendTick();
		__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
		HAL_PWR_EnterSTANDBYMode();
	}
	else
	{
		int i = 0;
		Wifi_SetMode(WifiMode_Station);

		while (Wifi_Station_ConnectToAp(Infopanel_MetaData.u8WLAN_Name,Infopanel_MetaData.u8WLAN_Password,NULL) == false)
		{
			i++;
		}
	}

}

uint8_t u8Connection_Loop()
{
	return 0;
}

static int jsoneq(const char* json, jsmntok_t* tok, const char* s)
{
    if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start && strncmp(json + tok->start, s, tok->end - tok->start) == 0)
    {
        return 0;
    }
    return -1;
}


uint8_t u8Waiting_For_Reply()
{
	return 0;
}

uint8_t  u8Pull_Request()
{
	uint8_t cSendString [256];
	sprintf ((char *)cSendString, (const char *)"{\n \"version\": 1,\n \"msg_type\": 2,\n \"data\": {\n   \"name\": \"%s\",\n   \"nr\": \"%ld\",\n   \"domain\": \"%s\",\n   \"os_version\": \"0.20\",\n   \"type\": \"Solar\",\n   \"volt\": \"%.2lfV\",\n   \"status\": \"ok\"\n }\n}\n",Infopanel_MetaData.u8Device_Name, HAL_GetUIDw0(), Infopanel_MetaData.u8Domain,(float)u16BatteryVoltage()/1000.0);
	Wifi_TcpIp_SendDataTcp(1, strlen((const char *)cSendString), (uint8_t *)cSendString);
	return 0;
}

uint8_t u8Use_Data(uint8_t* u8Data)
{
	struct sCommunication Com = {0};
	unsigned char *u8Pixmap;
	u8Pixmap = (unsigned char *)malloc(6U);
    int i;
    int r;
    jsmn_parser p;
    jsmntok_t t[128]; /* We expect no more than 128 tokens */
    jsmn_init(&p);
    r = jsmn_parse(&p, (const char*)u8Data, (const size_t)strlen((const char *)u8Data), t, (const unsigned int)sizeof(t)/sizeof(t[0]));
    for (i = 1; i < r; i++)
    {
        if (jsoneq((const char*)u8Data, &t[i], "msg_type") == 0)
        {
        	uint8_t u8Cache[30] = {0};
        	sprintf((char*)u8Cache,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
        	Com.u8MSG_Type = atoi((const char *)u8Cache);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "sleep_time") == 0)
        {
        	uint8_t u8Cache[30] = {0};
        	sprintf((char*)u8Cache,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);

			uint8_t u8CacheHou[10] = {0};
			uint8_t u8CacheMin[5] = {0};
			uint8_t u8CacheSec[5] = {0};
			sscanf((const char *)u8Cache, "%9[0-9]:%2[0-9]:%2[0-9]", u8CacheHou, u8CacheMin, u8CacheSec);
			Com.u32Sleep_Time = (uint32_t)atoi((const char *)u8CacheSec)+(uint32_t)atoi((const char *)u8CacheMin)*60+(uint32_t)atoi((const char *)u8CacheHou)*3600;
			i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "version") == 0)
        {
        	uint8_t u8Cache[30] = {0};
        	sprintf((char*)u8Cache,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
        	Com.u8Version = (uint8_t)atoi((const char *)u8Cache);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "type") == 0)
        {
        	uint8_t u8Cache[30] = {0};
        	sprintf((char*)u8Cache,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
        	Com.u8Type = (uint8_t)atoi((const char *)u8Cache);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l1") == 0)
        {
        	sprintf((char*)Com.u8L1,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l2") == 0)
        {
        	sprintf((char*)Com.u8L2,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l3") == 0)
        {
        	sprintf((char*)Com.u8L3,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l4") == 0)
        {
        	sprintf((char*)Com.u8L4,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l5") == 0)
        {
        	sprintf((char*)Com.u8L5,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l6") == 0)
        {
        	sprintf((char*)Com.u8L6,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l7") == 0)
        {
        	sprintf((char*)Com.u8L7,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l8") == 0)
        {
        	sprintf((char*)Com.u8L8,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l9") == 0)
        {
        	sprintf((char*)Com.u8L9,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l10") == 0)
        {
        	sprintf((char*)Com.u8L10,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "g_id") == 0)
        {
        	uint8_t u8Cache[30] = {0};
        	sprintf((char*)u8Cache,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
        	Com.u8G_ID = (uint8_t)atoi((const char *)u8Cache);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "template") == 0)
        {
        	sprintf((char*)u8Pixmap,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
    }
	HAL_GPIO_WritePin(EN_WLAN_GPIO_Port, EN_WLAN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RST_WLAN_GPIO_Port, RST_WLAN_Pin, GPIO_PIN_RESET);

    if(Com.u8Version == 1)
    {
    	if((Com.u8MSG_Type == 3) && (Com.u8Type == 1))//Print Office Screen
		{
    		DisplayOutput(Office, Com);
		}
		if((Com.u8MSG_Type == 3) && (Com.u8Type == 2))//Print LectureRoom Screen
		{
			DisplayOutput(LectureRoom, Com);
		}
		//sleep mode
		if(Com.u8MSG_Type == 3)
		{
			StandbyStart(Com.u32Sleep_Time, true);
		}
    }
    if(Com.u8Version == 2)
    {
		HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 1);
		HAL_Delay(100);
		DEV_Module_Init();
		HAL_Delay(100);
		EPD_7IN5_V2_Init();
		vPrint_Pixmap(u8Pixmap);
		HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 0);
		DEV_Module_Exit();

		StandbyStart(Com.u32Sleep_Time, true);
    }

	return 0;
}

void vConfig_Screen()
{
	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 1);
	HAL_Delay(100);
	DEV_Module_Init();
	HAL_Delay(100);
	EPD_7IN5_V2_Init();
	vPrint_Config_Screen();
	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 0);
	DEV_Module_Exit();
}

void vConfig_Done_Screen(sEEPROM_Data_t* pData, uint8_t* pu8MAC)
{
	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 1);
	HAL_Delay(100);
	DEV_Module_Init();
	HAL_Delay(100);
	EPD_7IN5_V2_Init();
	vPrint_Config_Done_Screen(pData, pu8MAC);
	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 0);
	DEV_Module_Exit();
}
