################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SupportFunctions/arm_copy_f32.c \
../SupportFunctions/arm_copy_q15.c \
../SupportFunctions/arm_copy_q31.c \
../SupportFunctions/arm_copy_q7.c \
../SupportFunctions/arm_fill_f32.c \
../SupportFunctions/arm_fill_q15.c \
../SupportFunctions/arm_fill_q31.c \
../SupportFunctions/arm_fill_q7.c \
../SupportFunctions/arm_float_to_q15.c \
../SupportFunctions/arm_float_to_q31.c \
../SupportFunctions/arm_float_to_q7.c \
../SupportFunctions/arm_q15_to_float.c \
../SupportFunctions/arm_q15_to_q31.c \
../SupportFunctions/arm_q15_to_q7.c \
../SupportFunctions/arm_q31_to_float.c \
../SupportFunctions/arm_q31_to_q15.c \
../SupportFunctions/arm_q31_to_q7.c \
../SupportFunctions/arm_q7_to_float.c \
../SupportFunctions/arm_q7_to_q15.c \
../SupportFunctions/arm_q7_to_q31.c 

OBJS += \
./SupportFunctions/arm_copy_f32.o \
./SupportFunctions/arm_copy_q15.o \
./SupportFunctions/arm_copy_q31.o \
./SupportFunctions/arm_copy_q7.o \
./SupportFunctions/arm_fill_f32.o \
./SupportFunctions/arm_fill_q15.o \
./SupportFunctions/arm_fill_q31.o \
./SupportFunctions/arm_fill_q7.o \
./SupportFunctions/arm_float_to_q15.o \
./SupportFunctions/arm_float_to_q31.o \
./SupportFunctions/arm_float_to_q7.o \
./SupportFunctions/arm_q15_to_float.o \
./SupportFunctions/arm_q15_to_q31.o \
./SupportFunctions/arm_q15_to_q7.o \
./SupportFunctions/arm_q31_to_float.o \
./SupportFunctions/arm_q31_to_q15.o \
./SupportFunctions/arm_q31_to_q7.o \
./SupportFunctions/arm_q7_to_float.o \
./SupportFunctions/arm_q7_to_q15.o \
./SupportFunctions/arm_q7_to_q31.o 

C_DEPS += \
./SupportFunctions/arm_copy_f32.d \
./SupportFunctions/arm_copy_q15.d \
./SupportFunctions/arm_copy_q31.d \
./SupportFunctions/arm_copy_q7.d \
./SupportFunctions/arm_fill_f32.d \
./SupportFunctions/arm_fill_q15.d \
./SupportFunctions/arm_fill_q31.d \
./SupportFunctions/arm_fill_q7.d \
./SupportFunctions/arm_float_to_q15.d \
./SupportFunctions/arm_float_to_q31.d \
./SupportFunctions/arm_float_to_q7.d \
./SupportFunctions/arm_q15_to_float.d \
./SupportFunctions/arm_q15_to_q31.d \
./SupportFunctions/arm_q15_to_q7.d \
./SupportFunctions/arm_q31_to_float.d \
./SupportFunctions/arm_q31_to_q15.d \
./SupportFunctions/arm_q31_to_q7.d \
./SupportFunctions/arm_q7_to_float.d \
./SupportFunctions/arm_q7_to_q15.d \
./SupportFunctions/arm_q7_to_q31.d 


# Each subdirectory must supply rules for building sources it contributes
SupportFunctions/%.o: ../SupportFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_4_5_0_DSPLIB_SRC/Include" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


