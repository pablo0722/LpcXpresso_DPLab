################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ControllerFunctions/arm_pid_init_f32.c \
../ControllerFunctions/arm_pid_init_q15.c \
../ControllerFunctions/arm_pid_init_q31.c \
../ControllerFunctions/arm_pid_reset_f32.c \
../ControllerFunctions/arm_pid_reset_q15.c \
../ControllerFunctions/arm_pid_reset_q31.c \
../ControllerFunctions/arm_sin_cos_f32.c \
../ControllerFunctions/arm_sin_cos_q31.c 

OBJS += \
./ControllerFunctions/arm_pid_init_f32.o \
./ControllerFunctions/arm_pid_init_q15.o \
./ControllerFunctions/arm_pid_init_q31.o \
./ControllerFunctions/arm_pid_reset_f32.o \
./ControllerFunctions/arm_pid_reset_q15.o \
./ControllerFunctions/arm_pid_reset_q31.o \
./ControllerFunctions/arm_sin_cos_f32.o \
./ControllerFunctions/arm_sin_cos_q31.o 

C_DEPS += \
./ControllerFunctions/arm_pid_init_f32.d \
./ControllerFunctions/arm_pid_init_q15.d \
./ControllerFunctions/arm_pid_init_q31.d \
./ControllerFunctions/arm_pid_reset_f32.d \
./ControllerFunctions/arm_pid_reset_q15.d \
./ControllerFunctions/arm_pid_reset_q31.d \
./ControllerFunctions/arm_sin_cos_f32.d \
./ControllerFunctions/arm_sin_cos_q31.d 


# Each subdirectory must supply rules for building sources it contributes
ControllerFunctions/%.o: ../ControllerFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_4_5_0_DSPLIB_SRC/Include" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


