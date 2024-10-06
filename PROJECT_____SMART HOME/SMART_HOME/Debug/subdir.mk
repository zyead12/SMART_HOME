################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../app.c \
../buzzer.c \
../dc_motor.c \
../flame.c \
../gpio.c \
../lcd.c \
../ldr.c \
../led.c \
../pwm.c \
../sensor_lm36.c 

OBJS += \
./adc.o \
./app.o \
./buzzer.o \
./dc_motor.o \
./flame.o \
./gpio.o \
./lcd.o \
./ldr.o \
./led.o \
./pwm.o \
./sensor_lm36.o 

C_DEPS += \
./adc.d \
./app.d \
./buzzer.d \
./dc_motor.d \
./flame.d \
./gpio.d \
./lcd.d \
./ldr.d \
./led.d \
./pwm.d \
./sensor_lm36.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


