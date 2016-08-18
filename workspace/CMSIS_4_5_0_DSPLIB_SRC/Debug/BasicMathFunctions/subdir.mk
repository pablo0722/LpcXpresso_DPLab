################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BasicMathFunctions/arm_abs_f32.c \
../BasicMathFunctions/arm_abs_q15.c \
../BasicMathFunctions/arm_abs_q31.c \
../BasicMathFunctions/arm_abs_q7.c \
../BasicMathFunctions/arm_add_f32.c \
../BasicMathFunctions/arm_add_q15.c \
../BasicMathFunctions/arm_add_q31.c \
../BasicMathFunctions/arm_add_q7.c \
../BasicMathFunctions/arm_dot_prod_f32.c \
../BasicMathFunctions/arm_dot_prod_q15.c \
../BasicMathFunctions/arm_dot_prod_q31.c \
../BasicMathFunctions/arm_dot_prod_q7.c \
../BasicMathFunctions/arm_mult_f32.c \
../BasicMathFunctions/arm_mult_q15.c \
../BasicMathFunctions/arm_mult_q31.c \
../BasicMathFunctions/arm_mult_q7.c \
../BasicMathFunctions/arm_negate_f32.c \
../BasicMathFunctions/arm_negate_q15.c \
../BasicMathFunctions/arm_negate_q31.c \
../BasicMathFunctions/arm_negate_q7.c \
../BasicMathFunctions/arm_offset_f32.c \
../BasicMathFunctions/arm_offset_q15.c \
../BasicMathFunctions/arm_offset_q31.c \
../BasicMathFunctions/arm_offset_q7.c \
../BasicMathFunctions/arm_scale_f32.c \
../BasicMathFunctions/arm_scale_q15.c \
../BasicMathFunctions/arm_scale_q31.c \
../BasicMathFunctions/arm_scale_q7.c \
../BasicMathFunctions/arm_shift_q15.c \
../BasicMathFunctions/arm_shift_q31.c \
../BasicMathFunctions/arm_shift_q7.c \
../BasicMathFunctions/arm_sub_f32.c \
../BasicMathFunctions/arm_sub_q15.c \
../BasicMathFunctions/arm_sub_q31.c \
../BasicMathFunctions/arm_sub_q7.c 

OBJS += \
./BasicMathFunctions/arm_abs_f32.o \
./BasicMathFunctions/arm_abs_q15.o \
./BasicMathFunctions/arm_abs_q31.o \
./BasicMathFunctions/arm_abs_q7.o \
./BasicMathFunctions/arm_add_f32.o \
./BasicMathFunctions/arm_add_q15.o \
./BasicMathFunctions/arm_add_q31.o \
./BasicMathFunctions/arm_add_q7.o \
./BasicMathFunctions/arm_dot_prod_f32.o \
./BasicMathFunctions/arm_dot_prod_q15.o \
./BasicMathFunctions/arm_dot_prod_q31.o \
./BasicMathFunctions/arm_dot_prod_q7.o \
./BasicMathFunctions/arm_mult_f32.o \
./BasicMathFunctions/arm_mult_q15.o \
./BasicMathFunctions/arm_mult_q31.o \
./BasicMathFunctions/arm_mult_q7.o \
./BasicMathFunctions/arm_negate_f32.o \
./BasicMathFunctions/arm_negate_q15.o \
./BasicMathFunctions/arm_negate_q31.o \
./BasicMathFunctions/arm_negate_q7.o \
./BasicMathFunctions/arm_offset_f32.o \
./BasicMathFunctions/arm_offset_q15.o \
./BasicMathFunctions/arm_offset_q31.o \
./BasicMathFunctions/arm_offset_q7.o \
./BasicMathFunctions/arm_scale_f32.o \
./BasicMathFunctions/arm_scale_q15.o \
./BasicMathFunctions/arm_scale_q31.o \
./BasicMathFunctions/arm_scale_q7.o \
./BasicMathFunctions/arm_shift_q15.o \
./BasicMathFunctions/arm_shift_q31.o \
./BasicMathFunctions/arm_shift_q7.o \
./BasicMathFunctions/arm_sub_f32.o \
./BasicMathFunctions/arm_sub_q15.o \
./BasicMathFunctions/arm_sub_q31.o \
./BasicMathFunctions/arm_sub_q7.o 

C_DEPS += \
./BasicMathFunctions/arm_abs_f32.d \
./BasicMathFunctions/arm_abs_q15.d \
./BasicMathFunctions/arm_abs_q31.d \
./BasicMathFunctions/arm_abs_q7.d \
./BasicMathFunctions/arm_add_f32.d \
./BasicMathFunctions/arm_add_q15.d \
./BasicMathFunctions/arm_add_q31.d \
./BasicMathFunctions/arm_add_q7.d \
./BasicMathFunctions/arm_dot_prod_f32.d \
./BasicMathFunctions/arm_dot_prod_q15.d \
./BasicMathFunctions/arm_dot_prod_q31.d \
./BasicMathFunctions/arm_dot_prod_q7.d \
./BasicMathFunctions/arm_mult_f32.d \
./BasicMathFunctions/arm_mult_q15.d \
./BasicMathFunctions/arm_mult_q31.d \
./BasicMathFunctions/arm_mult_q7.d \
./BasicMathFunctions/arm_negate_f32.d \
./BasicMathFunctions/arm_negate_q15.d \
./BasicMathFunctions/arm_negate_q31.d \
./BasicMathFunctions/arm_negate_q7.d \
./BasicMathFunctions/arm_offset_f32.d \
./BasicMathFunctions/arm_offset_q15.d \
./BasicMathFunctions/arm_offset_q31.d \
./BasicMathFunctions/arm_offset_q7.d \
./BasicMathFunctions/arm_scale_f32.d \
./BasicMathFunctions/arm_scale_q15.d \
./BasicMathFunctions/arm_scale_q31.d \
./BasicMathFunctions/arm_scale_q7.d \
./BasicMathFunctions/arm_shift_q15.d \
./BasicMathFunctions/arm_shift_q31.d \
./BasicMathFunctions/arm_shift_q7.d \
./BasicMathFunctions/arm_sub_f32.d \
./BasicMathFunctions/arm_sub_q15.d \
./BasicMathFunctions/arm_sub_q31.d \
./BasicMathFunctions/arm_sub_q7.d 


# Each subdirectory must supply rules for building sources it contributes
BasicMathFunctions/%.o: ../BasicMathFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_4_5_0_DSPLIB_SRC/Include" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


