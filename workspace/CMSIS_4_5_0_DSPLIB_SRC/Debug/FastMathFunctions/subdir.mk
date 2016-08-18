################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FastMathFunctions/arm_cos_f32.c \
../FastMathFunctions/arm_cos_q15.c \
../FastMathFunctions/arm_cos_q31.c \
../FastMathFunctions/arm_sin_f32.c \
../FastMathFunctions/arm_sin_q15.c \
../FastMathFunctions/arm_sin_q31.c \
../FastMathFunctions/arm_sqrt_q15.c \
../FastMathFunctions/arm_sqrt_q31.c 

OBJS += \
./FastMathFunctions/arm_cos_f32.o \
./FastMathFunctions/arm_cos_q15.o \
./FastMathFunctions/arm_cos_q31.o \
./FastMathFunctions/arm_sin_f32.o \
./FastMathFunctions/arm_sin_q15.o \
./FastMathFunctions/arm_sin_q31.o \
./FastMathFunctions/arm_sqrt_q15.o \
./FastMathFunctions/arm_sqrt_q31.o 

C_DEPS += \
./FastMathFunctions/arm_cos_f32.d \
./FastMathFunctions/arm_cos_q15.d \
./FastMathFunctions/arm_cos_q31.d \
./FastMathFunctions/arm_sin_f32.d \
./FastMathFunctions/arm_sin_q15.d \
./FastMathFunctions/arm_sin_q31.d \
./FastMathFunctions/arm_sqrt_q15.d \
./FastMathFunctions/arm_sqrt_q31.d 


# Each subdirectory must supply rules for building sources it contributes
FastMathFunctions/%.o: ../FastMathFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_4_5_0_DSPLIB_SRC/Include" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


