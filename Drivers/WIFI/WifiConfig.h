#ifndef	_WIFICONFIG_H
#define	_WIFICONFIG_H

#include "main.h"

extern UART_HandleTypeDef huart3;

#define		_WIFI_USART							huart3

#define		_WIFI_RX_SIZE						512
#define		_WIFI_RX_FOR_DATA_SIZE				2048
#define		_WIFI_TX_SIZE						4096
#define		_WIFI_TASK_SIZE						600


#define		_WIFI_WAIT_TIME_LOW					1000
#define		_WIFI_WAIT_TIME_MED					10000
#define		_WIFI_WAIT_TIME_HIGH				25000
#define		_WIFI_WAIT_TIME_VERYHIGH			60000



#endif
