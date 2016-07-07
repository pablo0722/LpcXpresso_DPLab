################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ejemplo_pseudo_pwm.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/sysinit.c 

OBJS += \
./src/Ejemplo_pseudo_pwm.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/sysinit.o 

C_DEPS += \
./src/Ejemplo_pseudo_pwm.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_LPCOPEN -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/My_workspace/Ejemplo_pseudo_pwm/inc" -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/workspace/LibFreeRTOS_8.2.3/src/portable/GCC/ARM_CM3" -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/workspace/LibFreeRTOS_8.2.3/inc" -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/workspace/LibFreeRTOS_8.2.3/src/demo_code" -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/workspace/LPC_BaseBoardBB1769_R02/inc" -I"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/workspace/lpc_chip_175x_6x/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


