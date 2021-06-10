################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Service/HEATER_CONTROL/heater_control.c 

OBJS += \
./Service/HEATER_CONTROL/heater_control.o 

C_DEPS += \
./Service/HEATER_CONTROL/heater_control.d 


# Each subdirectory must supply rules for building sources it contributes
Service/HEATER_CONTROL/%.o: ../Service/HEATER_CONTROL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


