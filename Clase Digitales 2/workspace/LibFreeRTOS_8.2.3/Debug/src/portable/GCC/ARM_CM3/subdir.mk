################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/portable/GCC/ARM_CM3/port.c 

OBJS += \
./src/portable/GCC/ARM_CM3/port.o 

C_DEPS += \
./src/portable/GCC/ARM_CM3/port.d 


# Each subdirectory must supply rules for building sources it contributes
src/portable/GCC/ARM_CM3/%.o: ../src/portable/GCC/ARM_CM3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"C:\nxp\workspace2\LibFreeRTOS_8.2.3\inc" -I"C:\nxp\workspace2\LibFreeRTOS_8.2.3\src\demo_code" -I"C:\nxp\workspace2\LibFreeRTOS_8.2.3\src\portable\GCC\ARM_CM3" -I"C:\nxp\workspace2\lpc_chip_175x_6x\inc" -I"C:\nxp\workspace2\lpc_board_nxp_lpcxpresso_1769\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


