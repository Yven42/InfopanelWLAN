/*
 * device.h
 *
 *  Created on: Jan 8, 2025
 *      Author: yvogt
 */

#ifndef DEVICE_DEVICE_H_
#define DEVICE_DEVICE_H_

#include "main.h"
#include "communication.h"

#define Connection_Attempts 3

extern TIM_HandleTypeDef htim5;
extern RTC_HandleTypeDef hrtc;

enum DriplayPrintMode
{
	Office,
	LectureRoom,
}typedef DriplayPrintMode_t;

void StandbyStart(uint32_t Seconds, uint8_t Normal);
void Buzzer(uint32_t MilliSecond);
static void _Standby(uint32_t Seconds);
void HardwareResetCheck(void);
void StartWlanModule(void);
void VirtualEepromInit(void);
void VirtualEepromInitStatic(void);
void DisplayOutput(DriplayPrintMode_t Mode, struct sCommunication Com);


#endif /* DEVICE_DEVICE_H_ */
