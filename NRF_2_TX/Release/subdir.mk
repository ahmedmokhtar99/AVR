################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../NRF_programe.c \
../PORT_Programe.c \
../SPI_programe.c \
../USART_programe.c \
../main.c 

OBJS += \
./DIO_program.o \
./NRF_programe.o \
./PORT_Programe.o \
./SPI_programe.o \
./USART_programe.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./NRF_programe.d \
./PORT_Programe.d \
./SPI_programe.d \
./USART_programe.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


