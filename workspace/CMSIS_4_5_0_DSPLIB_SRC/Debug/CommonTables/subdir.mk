################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CommonTables/arm_common_tables.c \
../CommonTables/arm_const_structs.c 

OBJS += \
./CommonTables/arm_common_tables.o \
./CommonTables/arm_const_structs.o 

C_DEPS += \
./CommonTables/arm_common_tables.d \
./CommonTables/arm_const_structs.d 


# Each subdirectory must supply rules for building sources it contributes
CommonTables/%.o: ../CommonTables/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_4_5_0_DSPLIB_SRC/Include" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


