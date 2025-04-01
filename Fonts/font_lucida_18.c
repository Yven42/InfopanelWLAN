/**
  ******************************************************************************
  * @file    font20.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-February-2014
  * @brief   This file provides text font20 for STM32xx-EVAL's LCD driver. 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fonts.h"

// Character bitmaps for Courier New 15pt
const uint8_t Font_Lucida_18_Table[] =
{
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x20 (32: ' ')
		0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x21 (33: '!')
		0x00,0x00,0x1E,0x3C,0x1E,0x3C,0x1E,0x3C,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x22 (34: '"')
		0x00,0x00,0x00,0x00,0x03,0x18,0x03,0x18,0x06,0x30,0x06,0x30,0x06,0x30,0x1F,0xFC,
		0x3F,0xFC,0x0C,0x60,0x0C,0x60,0x0C,0x60,0x0C,0x60,0x7F,0xF8,0x7F,0xF8,0x18,0xC0,
		0x18,0xC0,0x18,0xC0,0x31,0x80,0x31,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x23 (35: '#')
		0x00,0x00,0x01,0x00,0x07,0xE0,0x0F,0xF0,0x1D,0x10,0x19,0x00,0x19,0x00,0x19,0x00,
		0x0D,0x00,0x0F,0x00,0x03,0x80,0x01,0xC0,0x01,0xE0,0x01,0x70,0x01,0x30,0x01,0x30,
		0x01,0x30,0x19,0x60,0x1F,0xE0,0x0F,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x24 (36: '$')
		0x00,0x00,0x00,0x00,0x38,0x0C,0x6C,0x18,0xC6,0x10,0xC6,0x30,0xC6,0x60,0xC6,0x40,
		0x6C,0xC0,0x39,0x80,0x03,0x00,0x03,0x00,0x06,0x70,0x0C,0xD8,0x09,0x8C,0x19,0x8C,
		0x31,0x8C,0x21,0x8C,0x60,0xD8,0xC0,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x25 (37: '%')
		0x00,0x00,0x00,0x00,0x07,0x80,0x0F,0xC0,0x1C,0xE0,0x18,0x60,0x18,0x60,0x18,0xC0,
		0x0D,0x80,0x0F,0x00,0x3E,0x00,0x66,0x0C,0xC3,0x0C,0xC3,0x8C,0xC1,0x88,0xC0,0xD8,
		0xE0,0xF0,0x70,0xF0,0x3F,0xF8,0x1F,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x26 (38: '&')
		0x00,0x00,0x07,0x80,0x07,0x80,0x07,0x80,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x27 (39: ''')
		0x00,0x00,0x00,0x30,0x00,0xF0,0x01,0xC0,0x03,0x80,0x03,0x00,0x06,0x00,0x06,0x00,
		0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
		0x06,0x00,0x06,0x00,0x03,0x00,0x03,0x80,0x01,0xC0,0x00,0xF0,0x00,0x30,0x00,0x00,
		0x00,0x00, // Character 0x28 (40: '(')
		0x00,0x00,0x30,0x00,0x3C,0x00,0x0E,0x00,0x07,0x00,0x03,0x00,0x01,0x80,0x01,0x80,
		0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,
		0x01,0x80,0x01,0x80,0x03,0x00,0x07,0x00,0x0E,0x00,0x3C,0x00,0x30,0x00,0x00,0x00,
		0x00,0x00, // Character 0x29 (41: ')')
		0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x3B,0x70,0x04,0x80,
		0x00,0x80,0x04,0x80,0x0C,0xC0,0x08,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x2a (42: '*')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x7F,0xF8,0x7F,0xF8,0x03,0x00,
		0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x2b (43: '+')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x03,0x00,0x03,0x00,0x02,0x00,0x04,0x00,
		0x00,0x00, // Character 0x2c (44: ',')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE0,0x3F,0xE0,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x2d (45: '-')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x2e (46: '.')
		0x00,0x00,0x00,0x18,0x00,0x18,0x00,0x30,0x00,0x30,0x00,0x60,0x00,0x60,0x00,0xC0,
		0x00,0xC0,0x01,0x80,0x01,0x80,0x03,0x00,0x03,0x00,0x06,0x00,0x06,0x00,0x0C,0x00,
		0x0C,0x00,0x18,0x00,0x18,0x00,0x30,0x00,0x30,0x00,0x60,0x00,0x60,0x00,0x00,0x00,
		0x00,0x00, // Character 0x2f (47: '/')
		0x00,0x00,0x00,0x00,0x07,0x00,0x1F,0xC0,0x18,0xC0,0x30,0x60,0x30,0x60,0x60,0x30,
		0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x30,0x60,
		0x30,0x60,0x18,0xC0,0x1F,0xC0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x30 (48: '0')
		0x00,0x00,0x00,0x00,0x01,0x80,0x0F,0x80,0x31,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
		0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
		0x01,0x80,0x01,0x80,0x3F,0xFC,0x3F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x31 (49: '1')
		0x00,0x00,0x00,0x00,0x1F,0x00,0x3F,0xC0,0x20,0xC0,0x00,0x60,0x00,0x60,0x00,0x60,
		0x00,0x60,0x00,0xC0,0x00,0xC0,0x01,0x80,0x03,0x00,0x06,0x00,0x0C,0x00,0x08,0x00,
		0x18,0x00,0x30,0x00,0x3F,0xE0,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x32 (50: '2')
		0x00,0x00,0x00,0x00,0x1F,0x80,0x3F,0xC0,0x20,0xE0,0x00,0x60,0x00,0x60,0x00,0x60,
		0x01,0xC0,0x1F,0x80,0x1F,0x80,0x01,0xC0,0x00,0xE0,0x00,0x60,0x00,0x60,0x00,0x60,
		0x00,0x60,0x20,0xC0,0x3F,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x33 (51: '3')
		0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0xC0,0x03,0xC0,0x03,0xC0,0x06,0xC0,0x06,0xC0,
		0x0C,0xC0,0x18,0xC0,0x18,0xC0,0x30,0xC0,0x60,0xC0,0x7F,0xF0,0x7F,0xF0,0x00,0xC0,
		0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x34 (52: '4')
		0x00,0x00,0x00,0x00,0x1F,0xE0,0x1F,0xE0,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
		0x1F,0x00,0x1F,0x80,0x01,0xC0,0x00,0xE0,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,
		0x00,0xE0,0x10,0xC0,0x1F,0x80,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x35 (53: '5')
		0x00,0x00,0x00,0x00,0x03,0xE0,0x07,0xF0,0x0C,0x10,0x18,0x00,0x18,0x00,0x30,0x00,
		0x33,0xC0,0x37,0xE0,0x3C,0x70,0x30,0x38,0x30,0x18,0x30,0x18,0x30,0x18,0x10,0x18,
		0x18,0x30,0x1C,0x30,0x0F,0xE0,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x36 (54: '6')
		0x00,0x00,0x00,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0x30,0x00,0x60,0x00,0x40,0x00,0xC0,
		0x00,0x80,0x01,0x80,0x01,0x00,0x03,0x00,0x02,0x00,0x06,0x00,0x06,0x00,0x0C,0x00,
		0x0C,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x37 (55: '7')
		0x00,0x00,0x00,0x00,0x03,0xE0,0x0F,0xF0,0x1C,0x38,0x18,0x18,0x18,0x18,0x18,0x18,
		0x0E,0x30,0x0F,0xE0,0x07,0xC0,0x0D,0xF0,0x18,0x70,0x30,0x38,0x30,0x18,0x30,0x18,
		0x30,0x18,0x18,0x30,0x1F,0xE0,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x38 (56: '8')
		0x00,0x00,0x00,0x00,0x07,0xC0,0x0F,0xE0,0x18,0x70,0x18,0x30,0x30,0x10,0x30,0x18,
		0x30,0x18,0x30,0x18,0x38,0x18,0x1C,0x78,0x0F,0xD8,0x07,0x98,0x00,0x18,0x00,0x30,
		0x00,0x30,0x10,0x60,0x1F,0xC0,0x0F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x39 (57: '9')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x07,0x00,0x07,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x3a (58: ':')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x07,0x00,0x07,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x03,0x00,0x03,0x00,0x02,0x00,0x04,0x00,
		0x00,0x00, // Character 0x3b (59: ';')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x08,0x00,0x38,0x00,0xF0,0x03,0xC0,0x0F,0x00,0x3C,0x00,0x3C,0x00,0x0F,0x00,
		0x03,0xC0,0x00,0xF0,0x00,0x38,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x3c (60: '<')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xF8,0x7F,0xF8,0x00,0x00,0x00,0x00,0x7F,0xF8,
		0x7F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x3d (61: '=')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x40,0x00,0x70,0x00,0x3C,0x00,0x0F,0x00,0x03,0xC0,0x00,0xF0,0x00,0xF0,0x03,0xC0,
		0x0F,0x00,0x3C,0x00,0x70,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x3e (62: '>')
		0x00,0x00,0x00,0x00,0x1F,0xC0,0x3F,0xE0,0x30,0x70,0x30,0x30,0x00,0x30,0x00,0x30,
		0x00,0x60,0x00,0xC0,0x01,0x80,0x03,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x06,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x3f (63: '?')
		0x00,0x00,0x00,0x00,0x03,0xE0,0x0F,0xF0,0x1C,0x38,0x18,0x18,0x30,0xD8,0x33,0x38,
		0x63,0x18,0x66,0x18,0x66,0x18,0x66,0x38,0x66,0x38,0x66,0x58,0x63,0xDC,0x33,0x9C,
		0x38,0x00,0x1C,0x20,0x0F,0xE0,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x40 (64: '@')
		0x00,0x00,0x00,0x00,0x03,0x00,0x07,0x80,0x07,0x80,0x07,0x80,0x0F,0xC0,0x0C,0xC0,
		0x0C,0xC0,0x1C,0xE0,0x18,0x60,0x18,0x60,0x38,0x70,0x3F,0xF0,0x3F,0xF0,0x70,0x38,
		0x60,0x18,0x60,0x18,0xE0,0x1C,0xC0,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x41 (65: 'A')
		0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xE0,0x30,0x70,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x60,0x30,0xE0,0x3F,0x80,0x3F,0xC0,0x30,0x70,0x30,0x38,0x30,0x18,0x30,0x18,
		0x30,0x18,0x30,0x38,0x3F,0xF0,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x42 (66: 'B')
		0x00,0x00,0x00,0x00,0x03,0xF0,0x0F,0xF8,0x1C,0x08,0x38,0x00,0x30,0x00,0x30,0x00,
		0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x70,0x00,0x30,0x00,
		0x38,0x00,0x1E,0x08,0x0F,0xF8,0x03,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x43 (67: 'C')
		0x00,0x00,0x00,0x00,0x3F,0x80,0x3F,0xE0,0x30,0xF0,0x30,0x30,0x30,0x30,0x30,0x18,
		0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x30,
		0x30,0x70,0x30,0xE0,0x3F,0xC0,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x44 (68: 'D')
		0x00,0x00,0x00,0x00,0x1F,0xF0,0x1F,0xF0,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
		0x18,0x00,0x1F,0xE0,0x1F,0xE0,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
		0x18,0x00,0x18,0x00,0x1F,0xF8,0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x45 (69: 'E')
		0x00,0x00,0x00,0x00,0x1F,0xF8,0x1F,0xF8,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
		0x18,0x00,0x18,0x00,0x1F,0xF0,0x1F,0xF0,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
		0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x46 (70: 'F')
		0x00,0x00,0x00,0x00,0x03,0xF0,0x0F,0xF8,0x1C,0x08,0x38,0x00,0x30,0x00,0x30,0x00,
		0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x18,0x60,0x18,0x70,0x18,0x30,0x18,
		0x38,0x18,0x1E,0x18,0x0F,0xF8,0x03,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x47 (71: 'G')
		0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x30,0x3F,0xF0,0x3F,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x48 (72: 'H')
		0x00,0x00,0x00,0x00,0x3F,0xF0,0x3F,0xF0,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x49 (73: 'I')
		0x00,0x00,0x00,0x00,0x1F,0xC0,0x1F,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,
		0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,
		0x00,0xC0,0x21,0x80,0x3F,0x80,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x4a (74: 'J')
		0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x60,0x30,0x40,0x30,0xC0,0x31,0x80,0x31,0x00,
		0x33,0x00,0x36,0x00,0x3C,0x00,0x3C,0x00,0x36,0x00,0x33,0x00,0x31,0x80,0x31,0x80,
		0x30,0xC0,0x30,0x60,0x30,0x30,0x30,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x4b (75: 'K')
		0x00,0x00,0x00,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
		0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
		0x18,0x00,0x18,0x00,0x1F,0xF8,0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x4c (76: 'L')
		0x00,0x00,0x00,0x00,0x70,0x38,0x70,0x38,0x78,0x78,0x78,0x78,0x78,0x78,0x6C,0xD8,
		0x6C,0xD8,0x6C,0xD8,0x6F,0xD8,0x67,0x98,0x67,0x98,0x67,0x98,0x63,0x18,0x60,0x18,
		0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x4d (77: 'M')
		0x00,0x00,0x00,0x00,0x60,0x30,0x70,0x30,0x70,0x30,0x78,0x30,0x78,0x30,0x6C,0x30,
		0x6C,0x30,0x66,0x30,0x66,0x30,0x63,0x30,0x63,0x30,0x61,0xB0,0x61,0xB0,0x60,0xF0,
		0x60,0xF0,0x60,0x70,0x60,0x70,0x60,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x4e (78: 'N')
		0x00,0x00,0x00,0x00,0x07,0x80,0x1F,0xE0,0x18,0x60,0x30,0x30,0x30,0x30,0x60,0x18,
		0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x30,0x30,
		0x30,0x30,0x18,0x60,0x1F,0xE0,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x4f (79: 'O')
		0x00,0x00,0x00,0x00,0x1F,0xE0,0x1F,0xF0,0x18,0x38,0x18,0x18,0x18,0x18,0x18,0x18,
		0x18,0x18,0x18,0x38,0x18,0x70,0x1F,0xE0,0x1F,0x80,0x18,0x00,0x18,0x00,0x18,0x00,
		0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x50 (80: 'P')
		0x00,0x00,0x00,0x00,0x07,0x80,0x1F,0xE0,0x18,0x60,0x30,0x30,0x30,0x30,0x60,0x18,
		0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x30,0x30,
		0x30,0x30,0x18,0x60,0x1F,0xE0,0x07,0xC0,0x00,0xF0,0x00,0x3C,0x00,0x18,0x00,0x00,
		0x00,0x00, // Character 0x51 (81: 'Q')
		0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xE0,0x30,0x60,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x30,0x30,0x60,0x30,0xE0,0x3F,0xC0,0x3F,0x80,0x31,0xC0,0x30,0xC0,0x30,0x60,
		0x30,0x60,0x30,0x30,0x30,0x38,0x30,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x52 (82: 'R')
		0x00,0x00,0x00,0x00,0x07,0xE0,0x1F,0xF0,0x38,0x10,0x30,0x00,0x30,0x00,0x30,0x00,
		0x1C,0x00,0x0F,0x00,0x07,0xC0,0x00,0xE0,0x00,0x30,0x00,0x18,0x00,0x18,0x00,0x18,
		0x00,0x18,0x30,0x30,0x3F,0xE0,0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x53 (83: 'S')
		0x00,0x00,0x00,0x00,0xFF,0xFC,0xFF,0xFC,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x54 (84: 'T')
		0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x30,0x18,0x60,0x1F,0xE0,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x55 (85: 'U')
		0x00,0x00,0x00,0x00,0xC0,0x0C,0xE0,0x1C,0x60,0x18,0x60,0x18,0x70,0x38,0x30,0x30,
		0x30,0x30,0x38,0x70,0x18,0x60,0x18,0x60,0x1C,0xE0,0x0C,0xC0,0x0C,0xC0,0x0F,0xC0,
		0x07,0x80,0x07,0x80,0x07,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x56 (86: 'V')
		0x00,0x00,0x00,0x00,0xC0,0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,0x0C,0x40,0x08,0x63,0x08,
		0x63,0x88,0x67,0x98,0x67,0x98,0x67,0x98,0x64,0x98,0x64,0xD8,0x6C,0xD8,0x2C,0xD0,
		0x3C,0xF0,0x38,0x70,0x38,0x70,0x38,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x57 (87: 'W')
		0x00,0x00,0x00,0x00,0x30,0x18,0x30,0x30,0x18,0x30,0x18,0x60,0x0C,0xE0,0x0C,0xC0,
		0x07,0x80,0x03,0x80,0x03,0x00,0x03,0x80,0x07,0x80,0x0C,0xC0,0x0C,0xC0,0x18,0x60,
		0x18,0x60,0x30,0x30,0x70,0x18,0x60,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x58 (88: 'X')
		0x00,0x00,0x00,0x00,0x60,0x06,0x70,0x0E,0x30,0x0C,0x18,0x18,0x18,0x18,0x0C,0x30,
		0x06,0x60,0x06,0x60,0x03,0xC0,0x03,0xC0,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
		0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x59 (89: 'Y')
		0x00,0x00,0x00,0x00,0x3F,0xF8,0x3F,0xF8,0x00,0x38,0x00,0x30,0x00,0x60,0x00,0xE0,
		0x00,0xC0,0x01,0x80,0x03,0x00,0x03,0x00,0x06,0x00,0x0C,0x00,0x1C,0x00,0x18,0x00,
		0x30,0x00,0x70,0x00,0x7F,0xF8,0x7F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x5a (90: 'Z')
		0x00,0x00,0x07,0xF0,0x07,0xF0,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
		0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
		0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x07,0xF0,0x07,0xF0,0x00,0x00,
		0x00,0x00, // Character 0x5b (91: '[')
		0x00,0x00,0x60,0x00,0x60,0x00,0x30,0x00,0x30,0x00,0x18,0x00,0x18,0x00,0x0C,0x00,
		0x0C,0x00,0x06,0x00,0x06,0x00,0x03,0x00,0x03,0x00,0x01,0x00,0x01,0x80,0x00,0x80,
		0x00,0xC0,0x00,0x40,0x00,0x60,0x00,0x60,0x00,0x30,0x00,0x30,0x00,0x18,0x00,0x00,
		0x00,0x00, // Character 0x5c (92: '\')
		0x00,0x00,0x3F,0x80,0x3F,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
		0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
		0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x3F,0x80,0x3F,0x80,0x00,0x00,
		0x00,0x00, // Character 0x5d (93: ']')
		0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x03,0x80,0x03,0x80,0x06,0xC0,
		0x06,0xC0,0x0C,0x60,0x0C,0x60,0x08,0x20,0x18,0x30,0x18,0x30,0x30,0x18,0x30,0x18,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x5e (94: '^')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFC,0xFF,0xFC,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x5f (95: '_')
		0x00,0x00,0x00,0x00,0x03,0x00,0x01,0x80,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x60 (96: '`')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,
		0x3F,0xC0,0x30,0xE0,0x00,0x60,0x00,0x60,0x00,0x60,0x0F,0xE0,0x30,0x60,0x60,0x60,
		0x60,0x60,0x70,0xE0,0x3F,0x78,0x1E,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x61 (97: 'a')
		0x00,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x31,0xC0,
		0x37,0xF0,0x3C,0x30,0x38,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,
		0x30,0x30,0x38,0x70,0x2F,0xE0,0x27,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x62 (98: 'b')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xE0,
		0x0F,0xF0,0x1C,0x10,0x18,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,
		0x18,0x00,0x1C,0x10,0x0F,0xF0,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x63 (99: 'c')
		0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x0F,0x30,
		0x1F,0xB0,0x38,0x70,0x30,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,
		0x60,0x70,0x30,0xF0,0x3F,0xB0,0x0E,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x64 (100: 'd')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,
		0x1F,0xE0,0x38,0x60,0x20,0x30,0x60,0x30,0x7F,0xF0,0x7F,0xF0,0x60,0x00,0x60,0x00,
		0x30,0x00,0x38,0x10,0x1F,0xF0,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x65 (101: 'e')
		0x00,0x00,0x03,0xF8,0x07,0xF8,0x0E,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x7F,0xF8,
		0x7F,0xF8,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
		0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x66 (102: 'f')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x30,
		0x1F,0xB0,0x38,0x70,0x30,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,
		0x60,0x70,0x30,0xF0,0x3F,0xB0,0x0F,0x30,0x00,0x30,0x00,0x30,0x20,0x60,0x3F,0xC0,
		0x1F,0x80, // Character 0x67 (103: 'g')
		0x00,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x31,0xC0,
		0x37,0xE0,0x3C,0x70,0x38,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x68 (104: 'h')
		0x00,0x00,0x00,0x00,0x01,0x80,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,
		0x3F,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
		0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x69 (105: 'i')
		0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xC0,
		0x1F,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,
		0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x21,0xC0,0x3F,0x80,
		0x1F,0x00, // Character 0x6a (106: 'j')
		0x00,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x18,
		0x18,0x30,0x18,0x60,0x18,0xC0,0x19,0x80,0x1F,0x00,0x1B,0x80,0x19,0xC0,0x18,0xC0,
		0x18,0x60,0x18,0x70,0x18,0x38,0x18,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x6b (107: 'k')
		0x00,0x00,0x3F,0x80,0x3F,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
		0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
		0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x6c (108: 'l')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x66,0x30,
		0x6F,0x78,0x73,0x98,0x63,0x18,0x63,0x18,0x63,0x18,0x63,0x18,0x63,0x18,0x63,0x18,
		0x63,0x18,0x63,0x18,0x63,0x18,0x63,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x6d (109: 'm')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x31,0xC0,
		0x37,0xE0,0x3C,0x70,0x38,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x6e (110: 'n')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,
		0x1F,0xE0,0x38,0x70,0x30,0x30,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,
		0x30,0x30,0x38,0x70,0x1F,0xE0,0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x6f (111: 'o')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x31,0xC0,
		0x37,0xF0,0x3C,0x30,0x38,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,
		0x30,0x30,0x38,0x70,0x37,0xE0,0x33,0xC0,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,
		0x30,0x00, // Character 0x70 (112: 'p')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x30,
		0x1F,0xB0,0x38,0x70,0x30,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,
		0x60,0x70,0x30,0xF0,0x3F,0xB0,0x0E,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,
		0x00,0x30, // Character 0x71 (113: 'q')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xF0,
		0x1B,0xF0,0x1E,0x30,0x1C,0x30,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
		0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x72 (114: 'r')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,
		0x1F,0xE0,0x38,0x00,0x30,0x00,0x38,0x00,0x1F,0x00,0x0F,0xC0,0x00,0xF0,0x00,0x30,
		0x00,0x30,0x30,0x70,0x3F,0xE0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x73 (115: 's')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x7F,0xF0,
		0x7F,0xF0,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
		0x0C,0x00,0x0E,0x00,0x07,0xF0,0x03,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x74 (116: 't')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,
		0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x70,0x38,0xF0,0x1F,0xB0,0x0E,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x75 (117: 'u')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x18,
		0x30,0x30,0x30,0x30,0x30,0x30,0x18,0x60,0x18,0x60,0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,
		0x07,0x80,0x07,0x80,0x07,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x76 (118: 'v')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,
		0xC3,0x0C,0x43,0x08,0x63,0x88,0x63,0x88,0x64,0x88,0x24,0x90,0x24,0x90,0x24,0xD0,
		0x34,0xD0,0x38,0x70,0x18,0x60,0x18,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x77 (119: 'w')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x38,
		0x30,0x30,0x18,0x60,0x0C,0xC0,0x0F,0xC0,0x07,0x80,0x03,0x00,0x07,0x80,0x0F,0xC0,
		0x0C,0xC0,0x18,0x60,0x30,0x30,0x70,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x78 (120: 'x')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x18,
		0x30,0x18,0x18,0x30,0x18,0x30,0x18,0x30,0x0C,0x60,0x0C,0x60,0x06,0xC0,0x06,0xC0,
		0x07,0xC0,0x03,0x80,0x03,0x80,0x03,0x00,0x03,0x00,0x03,0x00,0x06,0x00,0x3E,0x00,
		0x38,0x00, // Character 0x79 (121: 'y')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xF0,
		0x7F,0xF0,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,
		0x38,0x00,0x70,0x00,0x7F,0xF0,0x7F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x7a (122: 'z')
		0x00,0x00,0x00,0xF0,0x01,0xF0,0x03,0x00,0x02,0x00,0x02,0x00,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x07,0x00,0x1E,0x00,0x1E,0x00,0x07,0x00,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x02,0x00,0x02,0x00,0x03,0x00,0x01,0xF0,0x00,0xF0,0x00,0x00,
		0x00,0x00, // Character 0x7b (123: '{')
		0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,
		0x00,0x00, // Character 0x7c (124: '|')
		0x00,0x00,0x3C,0x00,0x3E,0x00,0x03,0x00,0x01,0x00,0x01,0x00,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x03,0x80,0x01,0xE0,0x01,0xE0,0x03,0x80,0x03,0x00,0x03,0x00,
		0x03,0x00,0x03,0x00,0x01,0x00,0x01,0x00,0x03,0x00,0x3E,0x00,0x3C,0x00,0x00,0x00,
		0x00,0x00, // Character 0x7d (125: '}')
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x18,0x3F,0x18,0x63,0xF0,0x60,0xF0,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x7e (126: '~')
		0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x60,0x0C,0x60,0x00,0x00,0x00,0x00,0x1F,0x80,
		0x3F,0xC0,0x30,0xE0,0x00,0x60,0x00,0x60,0x00,0x60,0x0F,0xE0,0x30,0x60,0x60,0x60,
		0x60,0x60,0x70,0xE0,0x3F,0x78,0x1E,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x7f (127)
		0x18,0x60,0x18,0x60,0x03,0x00,0x07,0x80,0x07,0x80,0x07,0x80,0x0F,0xC0,0x0C,0xC0,
		0x0C,0xC0,0x1C,0xE0,0x18,0x60,0x18,0x60,0x38,0x70,0x3F,0xF0,0x3F,0xF0,0x70,0x38,
		0x60,0x18,0x60,0x18,0xE0,0x1C,0xC0,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x80 (128)
		0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xC0,0x18,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,
		0x1F,0xE0,0x38,0x70,0x30,0x30,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,
		0x30,0x30,0x38,0x70,0x1F,0xE0,0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x81 (129)
		0x30,0x30,0x30,0x30,0x07,0x80,0x1F,0xE0,0x18,0x60,0x30,0x30,0x30,0x30,0x60,0x18,
		0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x30,0x30,
		0x30,0x30,0x18,0x60,0x1F,0xE0,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x82 (130)
		0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xC0,0x18,0xC0,0x00,0x00,0x00,0x00,0x30,0x30,
		0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x70,0x38,0xF0,0x1F,0xB0,0x0E,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x83 (131)
		0x18,0xC0,0x18,0xC0,0x00,0x00,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0x30,0x18,0x60,0x1F,0xE0,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x84 (132)
		0x00,0x00,0x0F,0x00,0x1F,0x80,0x38,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x80,0x31,0x80,
		0x33,0x00,0x33,0x00,0x33,0x80,0x31,0xC0,0x30,0xE0,0x30,0x70,0x30,0x38,0x30,0x18,
		0x30,0x18,0x32,0x38,0x33,0xF0,0x31,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00, // Character 0x85 (133)
};


sFONT Font_Lucida_18 = {
  Font_Lucida_18_Table,
  16, /* Width */
  25, /* Height */
};


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
