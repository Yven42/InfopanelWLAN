/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_Pin GPIO_PIN_13
#define BUTTON_GPIO_Port GPIOC
#define BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define Battery_ADC_Pin GPIO_PIN_0
#define Battery_ADC_GPIO_Port GPIOC
#define Buzzer_PWM_Pin GPIO_PIN_1
#define Buzzer_PWM_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define WLAN_POWER_Pin GPIO_PIN_6
#define WLAN_POWER_GPIO_Port GPIOA
#define ADC_EN_Battery_Pin GPIO_PIN_0
#define ADC_EN_Battery_GPIO_Port GPIOB
#define ENABLE_POLOLU_Pin GPIO_PIN_1
#define ENABLE_POLOLU_GPIO_Port GPIOB
#define DISPLAY_POWER_Pin GPIO_PIN_2
#define DISPLAY_POWER_GPIO_Port GPIOB
#define PWR_Display_Pin GPIO_PIN_13
#define PWR_Display_GPIO_Port GPIOB
#define Debug_Pin_Pin GPIO_PIN_8
#define Debug_Pin_GPIO_Port GPIOC
#define EN_WLAN_Pin GPIO_PIN_8
#define EN_WLAN_GPIO_Port GPIOA
#define RST_WLAN_Pin GPIO_PIN_9
#define RST_WLAN_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define RST_Pin GPIO_PIN_4
#define RST_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_5
#define DC_GPIO_Port GPIOB
#define SPI_CS_Pin GPIO_PIN_6
#define SPI_CS_GPIO_Port GPIOB
#define BUSY_Pin GPIO_PIN_7
#define BUSY_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
enum Infopanel_State
{
	ERROR_MODE,
	CONFIG_MODE,
	NORMAL_MODE
};

struct Infopanel
{
	enum Infopanel_State eState;
	uint8_t u8Device_Name[20];
	uint8_t u8WLAN_Name[20];
	uint8_t u8WLAN_Password[70];
	uint8_t u8Domain[40];
	uint8_t u8Server_IP[16];
	uint16_t u16Server_Port;
};
extern struct Infopanel Infopanel_MetaData;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
