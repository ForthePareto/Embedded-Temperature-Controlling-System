################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER2/test_timer2.c \
../MCAL/TIMER2/timer2.c 

OBJS += \
./MCAL/TIMER2/test_timer2.o \
./MCAL/TIMER2/timer2.o 

C_DEPS += \
./MCAL/TIMER2/test_timer2.d \
./MCAL/TIMER2/timer2.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER2/%.o: ../MCAL/TIMER2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


