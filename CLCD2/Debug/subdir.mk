################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_main.c \
../CLCD_programe.c \
../DIO_program.c \
../PORT_Programe.c 

OBJS += \
./CLCD_main.o \
./CLCD_programe.o \
./DIO_program.o \
./PORT_Programe.o 

C_DEPS += \
./CLCD_main.d \
./CLCD_programe.d \
./DIO_program.d \
./PORT_Programe.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


