################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_GPIO.c \
../src/FW_InitOscilador.c \
../src/UART.c \
../src/board.c \
../src/board_sysinit.c \
../src/lpc_phy_smsc87x0.c 

OBJS += \
./src/FW_GPIO.o \
./src/FW_InitOscilador.o \
./src/UART.o \
./src/board.o \
./src/board_sysinit.o \
./src/lpc_phy_smsc87x0.o 

C_DEPS += \
./src/FW_GPIO.d \
./src/FW_InitOscilador.d \
./src/UART.d \
./src/board.d \
./src/board_sysinit.d \
./src/lpc_phy_smsc87x0.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M3 -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/lpc_chip_175x_6x/inc" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/td2_board_1769/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


