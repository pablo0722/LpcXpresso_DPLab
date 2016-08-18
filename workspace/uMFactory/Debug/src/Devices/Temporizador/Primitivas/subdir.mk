################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Devices/Temporizador/Primitivas/temporizador_PR.c 

OBJS += \
./src/Devices/Temporizador/Primitivas/temporizador_PR.o 

C_DEPS += \
./src/Devices/Temporizador/Primitivas/temporizador_PR.d 


# Each subdirectory must supply rules for building sources it contributes
src/Devices/Temporizador/Primitivas/%.o: ../src/Devices/Temporizador/Primitivas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"D:\UTN\uMFactory\uMFactory\Workspace_ uMFactory\uMFactory_05_15\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


