################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Devices/Temporizador/temporizador_buffer.c 

OBJS += \
./src/Devices/Temporizador/temporizador_buffer.o 

C_DEPS += \
./src/Devices/Temporizador/temporizador_buffer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Devices/Temporizador/%.o: ../src/Devices/Temporizador/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"D:\UTN\uMFactory\uMFactory\Workspace_ uMFactory\uMFactory_05_15\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


