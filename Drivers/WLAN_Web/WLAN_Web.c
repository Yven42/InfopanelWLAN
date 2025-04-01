/*
 * WLAN_Web.c
 *
 *  Created on: May 16, 2024
 *      Author: Yven Vogt
 */

#include "WLAN_Web.h"
#include "string.h"

char htmlContent[] = "<!DOCTYPE html><html lang=\"de\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Netzwerk-Konfiguration</title><style>body{font-family:Arial,sans-serif;background-color:#f0f0f0;display:flex;flex-direction:column;justify-content:center;align-items:center;height:100vh;margin:0}.container{background-color:#ffffff;padding:20px;border-radius:8px;box-shadow:0 0 10px rgba(0,0,0,0.1);width:300px}h1{font-size:24px;margin-bottom:20px;text-align:center}.form-group{margin-bottom:15px;text-align:left}.form-group label{display:block;margin-bottom:5px;font-weight:bold}.form-group input{width:100%;padding:8px;box-sizing:border-box;border:1px solid #ccc;border-radius:4px}.form-group input[readonly]{background-color:#e9ecef;cursor:not-allowed}.form-group button{width:100%;padding:10px;background-color:#007bff;color:#ffffff;border:none;border-radius:4px;font-size:16px;cursor:pointer}.form-group button:hover{background-color:#0056b3}.message{margin-top:15px;color:#333}</style></head><body><h1>Konfiguration Infopanel</h1><div class=\"container\"><form id=\"config-form\"><div class=\"form-group\"><label for=\"device-name\">Gerätename:</label><input type=\"text\" id=\"device-name\" name=\"dev\"></div><div class=\"form-group\"><label for=\"wlan-name\">WLAN-Name:</label><input type=\"text\" id=\"wlan-name\" name=\"wlan\"></div><div class=\"form-group\"><label for=\"wlan-password\">WLAN-Passwort:</label><input type=\"password\" id=\"wlan-password\" name=\"passw\"></div><div class=\"form-group\"><label for=\"domain\">Domain:</label><input type=\"text\" id=\"domain\" name=\"dom\"></div><div class=\"form-group\"><label for=\"tcp-server-ip\">TCP-Server-IP:</label><input type=\"text\" id=\"tcp-server-ip\" name=\"t-ip\"></div><div class=\"form-group\"><label for=\"tcp-server-port\">TCP-Server-Port:</label><input type=\"text\" id=\"tcp-server-port\" name=\"t-port\"></div><div class=\"form-group\"><label for=\"mac-address\">MAC-Adresse:</label><input type=\"text\" id=\"mac\" name=\"mac-address\" value=\"ff:ff:ff:ff:ff:ff\" readonly></div><div class=\"form-group\"><button type=\"submit\">Senden</button></div></form><div id=\"message\" class=\"message\"></div></div><script>document.getElementById('config-form').addEventListener('submit',function(event){event.preventDefault();const formData=new FormData(event.target);let dataString='';formData.forEach((value,key)=>{dataString+=`${key}=${value};`});dataString=dataString.slice(0,-1);console.log(dataString);fetch('your-server-endpoint',{method:'POST',headers:{'Content-Type':'text/plain'},body:dataString}).then(response=>response.text()).then(data=>{console.log('Success:',data);document.getElementById('message').innerText=data.includes('report=')?data.split('report=')[1]:'Unbekannte Rückmeldung';}).catch((error)=>{console.error('Error:',error);document.getElementById('message').innerText='Fehler beim Senden der Daten';});});</script></body></html>";
char htmlContent2[] = "<!DOCTYPE html>\
<html lang=\"de\">\
<head>\
<meta charset=\"UTF-8\">\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\
<title>Netzwerk-Konfiguration</title>\
<style>\
body { font-family: Arial, sans-serif; background-color: #f0f0f0; display: flex; flex-direction: column; justify-content: center; align-items: center; height: 100vh; margin: 0; }\
.container { background-color: #ffffff; padding: 20px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); width: 300px; text-align: center; }\
h1 { font-size: 24px; margin-bottom: 20px; }\
p { font-size: 18px; margin: 0; }\
</style>\
</head>\
<body>\
<h1>Konfiguration Infopanel</h1>\
<div class=\"container\">\
<p>Die Konfiguration ist abgeschlossen, das Gerät fährt nun herunter.</p>\
</div>\
</body>\
</html>";

void vReplaceMacAddress(char* htmlContent, const char* newMacAddress)
{
    const char* macAddressPlaceholder = "ff:ff:ff:ff:ff:ff";
    char* pos = strstr(htmlContent, macAddressPlaceholder);

    if (pos)
    {
        // Ensure newMacAddress fits in the placeholder space
        if (strlen(newMacAddress) == strlen(macAddressPlaceholder))
        {
            memcpy(pos, newMacAddress, strlen(macAddressPlaceholder));
        } else
        {
        }
    } else
    {
    }
}

uint8_t u8ParseMacAddress()
{
    uint8_t *mac_start = (uint8_t *)strstr((char *)Wifi.RxBuffer+100, "+CIFSR:APMAC");
    if (mac_start)
    {
        mac_start += strlen("+CIFSR:STAMAC,\"");
        char *mac_end = strstr((char *)mac_start, "\"");
        if (mac_end)
        {
            *mac_end = '\0';  // String terminieren
            strcpy((char *)Wifi.MAC_Adress, (char *)mac_start-1);
            for (int i = 0; i<17 ; i++)
            {
            	if(Wifi.MAC_Adress[i] > 96)
            	{
            		Wifi.MAC_Adress[i] -= 32;
            	}
            }
            return (uint8_t)1;
        }
    }
    return 0;
}

uint8_t u8WifiMAC()
{
	char *command = "AT+CIFSR\r\n";
	HAL_UART_Transmit(&huart3, (uint8_t *)command, strlen(command), HAL_MAX_DELAY);
	osDelay(100);
	return u8ParseMacAddress();
}

const char* puParseStringToStruct(const char* input, sEEPROM_Data_t* data)
{
    // Ensure the struct is zeroed out
    memset(data, 0, sizeof(sEEPROM_Data_t));

    // Buffers to accumulate error messages
    static char errorMessage[256];
    errorMessage[0] = '\0';  // Clear the error message buffer

    // Pointers to the beginning of each relevant substring
    const char* deviceNamePtr = strstr(input, "dev=");
    const char* wlanNamePtr = strstr(input, "wlan=");
    const char* wlanPasswordPtr = strstr(input, "passw=");
    const char* serverIpPtr = strstr(input, "t-ip=");
    const char* serverPortPtr = strstr(input, "t-port=");
    const char* domainPtr = strstr(input, "dom=");

    // Extract and copy device name
    if (deviceNamePtr) {
        deviceNamePtr += strlen("dev=");
        sscanf(deviceNamePtr, "%19[^;]", data->u8Device_Name);
        if (strlen((char*)data->u8Device_Name) < 1) {
            strcat(errorMessage, "Kein Namen eingetragen; ");
        }
    } else {
        strcat(errorMessage, "Kein Namen eingetragen; ");
    }

    // Extract and copy WLAN name
    if (wlanNamePtr) {
        wlanNamePtr += strlen("wlan=");
        sscanf(wlanNamePtr, "%19[^;]", data->u8WLAN_Name);
        if (strlen((char*)data->u8WLAN_Name) < 1) {
            strcat(errorMessage, "Kein WLAN-Namen eingetragen; ");
        }
    } else {
        strcat(errorMessage, "Kein WLAN-Namen eingetragen; ");
    }

    // Extract and copy WLAN password
    if (wlanPasswordPtr) {
        wlanPasswordPtr += strlen("passw=");
        sscanf(wlanPasswordPtr, "%69[^;]", data->u8WLAN_Password);
    }

    // Extract and copy Domain
    if (domainPtr) {
    	domainPtr += strlen("dom=");
        sscanf(domainPtr, "%39[^;]", data->u8Domain);
    }

    // Extract and convert server IP
    if (serverIpPtr) {
        serverIpPtr += strlen("t-ip=");
        unsigned int ip[4];
        int parsedItems = sscanf(serverIpPtr, "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);
        if (parsedItems != 4 || ip[0] > 255 || ip[1] > 255 || ip[2] > 255 || ip[3] > 255) {
            strcat(errorMessage, "IP Adresse ist unzulässig; ");
        } else {
            for (int i = 0; i < 4; i++) {
                data->u8Server_IP[i] = (uint8_t)ip[i];
            }
        }
    } else {
        strcat(errorMessage, "IP Adresse ist unzulässig; ");
    }

    // Extract and convert server port
    if (serverPortPtr) {
        serverPortPtr += strlen("t-port=");
        unsigned int port;
        int parsedItems = sscanf(serverPortPtr, "%u", &port);
        if (parsedItems != 1 || port > 65535) {
            strcat(errorMessage, "Port unzulässig; ");
        } else {
            data->u8Server_Port = (uint16_t)port;
        }
    } else {
        strcat(errorMessage, "Port unzulässig; ");
    }

    // Return the appropriate message
    if (strlen(errorMessage) == 0) {
        return "Übertragung erfolgreich";
    } else {
        // Remove the last "; " from the error message
        errorMessage[strlen(errorMessage) - 2] = '\0';
        return errorMessage;
    }
}

uint8_t u8Send_HTML (uint8_t u8Channel, const char* pcHTML, uint16_t u16Size)
{
	uint8_t* pcSend = (uint8_t*)pcHTML;
	//sprintf((char *)pcSend,(char *)pcHTML,Wifi.MAC_Adress);
	uint8_t cBuffer [50];
	while(u16Size > 0)
	{
		if(u16Size >= 512)
		{
        	sprintf((char *)cBuffer,"AT+CIPSEND=%d,512\r\n", u8Channel);
        	Wifi_SendRaw(cBuffer, strlen((char *)cBuffer));
        	osDelay(100);
        	Wifi_SendRaw(pcSend,(uint16_t) 512);
        	pcSend += 512;
			u16Size -= 512;
			osDelay(100);
		}
		else
		{
        	sprintf((char *)cBuffer,"AT+CIPSEND=%d,%d\r\n", u8Channel, u16Size);
        	Wifi_SendRaw(cBuffer, strlen((char *)cBuffer));
        	osDelay(100);
        	Wifi_SendRaw(pcSend, u16Size);
        	osDelay(100);
        	u16Size = 0;
		}
	}
	sprintf((char *)cBuffer,"AT+CIPCLOSE=%d\r\n", u8Channel);
	Wifi_SendRaw(cBuffer, strlen((char *)cBuffer));
	return 0;
}

sEEPROM_Data_t WLAN_Web_Start(Wifi_t* Wifi)
{
	sEEPROM_Data_t sData;
	uint8_t u8HTML_Loop = 1;

    Wifi_SetMode(WifiMode_SoftAp);
  	Wifi_SoftAp_Create("Infopanel-Konfig", "infopanel", 1, WifiEncryptionType_WPA2_PSK, 4, 0);
    Wifi_SendRaw((uint8_t*)"AT+CIPSERVER=1,80\r\n", 19);

    Wifi_GetMyIp();
    u8WifiMAC();
    vReplaceMacAddress(htmlContent,(const char*)Wifi->MAC_Adress);
    while (u8HTML_Loop)
    {
    	Wifi_SoftAp_GetConnectedDevices();
        if(Wifi->GotNewData==true)
        {

        	if (strstr((char*)Wifi->RxBufferForData, "GET") != NULL)
        	{
        		u8Send_HTML(Wifi->RxDataConnectionNumber, htmlContent, strlen(htmlContent));
        	}
        	else if (strstr((char*)Wifi->RxBufferForData, "POST") != NULL)
        	{
        		u8HTML_Loop = u8SendReport((const char*) Wifi->RxBufferForData, &sData, Wifi->RxDataConnectionNumber);
        	}

        	Wifi->GotNewData=false;
        }
        HAL_Delay(100);
    }
    return sData;
}

uint8_t u8SendReport(const char* Rx_Buffer, sEEPROM_Data_t* sData, uint8_t u8Channel)
{
	uint8_t u8Return = 1;
	uint8_t cBuffer [100];
	const char* pcReturn = puParseStringToStruct(Rx_Buffer, sData);
	osDelay(100);
	if (strstr(pcReturn, "Übertragung erfolgreich"))
	{
		uint8_t u8SendString[] = "Die Konfiguration ist abgeschlossen, das Gerät fährt nun herunter.";
		sprintf((char *)cBuffer,"AT+CIPSEND=%d,%d\r\n", u8Channel, strlen(u8SendString)+7);
		Wifi_SendRaw(cBuffer, strlen((char *)cBuffer));
		osDelay(100);
		sprintf((char *)cBuffer,"report=%s", u8SendString);
		Wifi_SendRaw((uint8_t *)cBuffer,(uint16_t) strlen((char*)cBuffer));
		osDelay(100);
		u8Return = 0;
	}
	else
	{
		sprintf((char *)cBuffer,"AT+CIPSEND=%d,%d\r\n", u8Channel, strlen(pcReturn)+7);
		Wifi_SendRaw(cBuffer, strlen((char *)cBuffer));
		osDelay(100);
		sprintf((char *)cBuffer,"report=%s", pcReturn);
		Wifi_SendRaw((uint8_t *)cBuffer,(uint16_t) strlen((char*)cBuffer));
		osDelay(100);
	}
	sprintf((char *)cBuffer,"AT+CIPCLOSE=%d\r\n", u8Channel);
	Wifi_SendRaw(cBuffer, strlen((char *)cBuffer));
	return u8Return;
}
