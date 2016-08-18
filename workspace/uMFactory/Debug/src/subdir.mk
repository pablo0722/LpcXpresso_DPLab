################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc176x.c \
../src/funciones.c \
../src/main.c \
../src/maquina_de_estados.c 

OBJS += \
./src/cr_startup_lpc176x.o \
./src/funciones.o \
./src/main.o \
./src/maquina_de_estados.o 

C_DEPS += \
./src/cr_startup_lpc176x.d \
./src/funciones.d \
./src/main.d \
./src/maquina_de_estados.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"D:\UTN\uMFactory\uMFactory\Workspace_ uMFactory\uMFactory_05_15\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


