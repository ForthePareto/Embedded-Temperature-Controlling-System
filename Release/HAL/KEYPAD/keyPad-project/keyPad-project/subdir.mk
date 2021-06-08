################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD/keyPad-project/keyPad-project/main.c 

OBJS += \
./HAL/KEYPAD/keyPad-project/keyPad-project/main.o 

C_DEPS += \
./HAL/KEYPAD/keyPad-project/keyPad-project/main.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KEYPAD/keyPad-project/keyPad-project/%.o: ../HAL/KEYPAD/keyPad-project/keyPad-project/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


