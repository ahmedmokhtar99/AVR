################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../EXTI_programe.c \
../GIE_programe.c \
../PORT_Programe.c \
../TIMERS_programe.c \
../main.c 

OBJS += \
./DIO_program.o \
./EXTI_programe.o \
./GIE_programe.o \
./PORT_Programe.o \
./TIMERS_programe.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./EXTI_programe.d \
./GIE_programe.d \
./PORT_Programe.d \
./TIMERS_programe.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


