################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/WIFI/Wifi.c 

OBJS += \
./Drivers/WIFI/Wifi.o 

C_DEPS += \
./Drivers/WIFI/Wifi.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/WIFI/%.o Drivers/WIFI/%.su Drivers/WIFI/%.cyclo: ../Drivers/WIFI/%.c Drivers/WIFI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_WLAN/Drivers/Device" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_WLAN/Drivers/WLAN_Web" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_WLAN/Drivers/EEPROM" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_WLAN/Drivers/WIFI" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_WLAN/Drivers/Communication" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_WLAN/Drivers/JSMN" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_WLAN/Drivers/Display" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-WIFI

clean-Drivers-2f-WIFI:
	-$(RM) ./Drivers/WIFI/Wifi.cyclo ./Drivers/WIFI/Wifi.d ./Drivers/WIFI/Wifi.o ./Drivers/WIFI/Wifi.su

.PHONY: clean-Drivers-2f-WIFI

