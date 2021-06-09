################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/PWM0/pwm0.c \
../MCAL/PWM0/test_pwm0.c 

OBJS += \
./MCAL/PWM0/pwm0.o \
./MCAL/PWM0/test_pwm0.o 

C_DEPS += \
./MCAL/PWM0/pwm0.d \
./MCAL/PWM0/test_pwm0.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/PWM0/%.o: ../MCAL/PWM0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


