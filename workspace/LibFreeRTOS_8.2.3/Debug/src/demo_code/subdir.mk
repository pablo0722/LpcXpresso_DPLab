################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/demo_code/basic_io.c \
../src/demo_code/consoleprint.c 

OBJS += \
./src/demo_code/basic_io.o \
./src/demo_code/consoleprint.o 

C_DEPS += \
./src/demo_code/basic_io.d \
./src/demo_code/consoleprint.d 


# Each subdirectory must supply rules for building sources it contributes
src/demo_code/%.o: ../src/demo_code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/My_workspace/LibFreeRTOS_8.2.3/inc" -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/My_workspace/LibFreeRTOS_8.2.3/src/demo_code" -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/My_workspace/LibFreeRTOS_8.2.3/src/portable/GCC/ARM_CM3" -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/My_workspace/lpc_chip_175x_6x/inc" -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/My_workspace/lpc_board_nxp_lpcxpresso_1769/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


