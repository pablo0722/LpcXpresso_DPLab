################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MatrixFunctions/arm_mat_add_f32.c \
../MatrixFunctions/arm_mat_add_q15.c \
../MatrixFunctions/arm_mat_add_q31.c \
../MatrixFunctions/arm_mat_cmplx_mult_f32.c \
../MatrixFunctions/arm_mat_cmplx_mult_q15.c \
../MatrixFunctions/arm_mat_cmplx_mult_q31.c \
../MatrixFunctions/arm_mat_init_f32.c \
../MatrixFunctions/arm_mat_init_q15.c \
../MatrixFunctions/arm_mat_init_q31.c \
../MatrixFunctions/arm_mat_inverse_f32.c \
../MatrixFunctions/arm_mat_inverse_f64.c \
../MatrixFunctions/arm_mat_mult_f32.c \
../MatrixFunctions/arm_mat_mult_fast_q15.c \
../MatrixFunctions/arm_mat_mult_fast_q31.c \
../MatrixFunctions/arm_mat_mult_q15.c \
../MatrixFunctions/arm_mat_mult_q31.c \
../MatrixFunctions/arm_mat_scale_f32.c \
../MatrixFunctions/arm_mat_scale_q15.c \
../MatrixFunctions/arm_mat_scale_q31.c \
../MatrixFunctions/arm_mat_sub_f32.c \
../MatrixFunctions/arm_mat_sub_q15.c \
../MatrixFunctions/arm_mat_sub_q31.c \
../MatrixFunctions/arm_mat_trans_f32.c \
../MatrixFunctions/arm_mat_trans_q15.c \
../MatrixFunctions/arm_mat_trans_q31.c 

OBJS += \
./MatrixFunctions/arm_mat_add_f32.o \
./MatrixFunctions/arm_mat_add_q15.o \
./MatrixFunctions/arm_mat_add_q31.o \
./MatrixFunctions/arm_mat_cmplx_mult_f32.o \
./MatrixFunctions/arm_mat_cmplx_mult_q15.o \
./MatrixFunctions/arm_mat_cmplx_mult_q31.o \
./MatrixFunctions/arm_mat_init_f32.o \
./MatrixFunctions/arm_mat_init_q15.o \
./MatrixFunctions/arm_mat_init_q31.o \
./MatrixFunctions/arm_mat_inverse_f32.o \
./MatrixFunctions/arm_mat_inverse_f64.o \
./MatrixFunctions/arm_mat_mult_f32.o \
./MatrixFunctions/arm_mat_mult_fast_q15.o \
./MatrixFunctions/arm_mat_mult_fast_q31.o \
./MatrixFunctions/arm_mat_mult_q15.o \
./MatrixFunctions/arm_mat_mult_q31.o \
./MatrixFunctions/arm_mat_scale_f32.o \
./MatrixFunctions/arm_mat_scale_q15.o \
./MatrixFunctions/arm_mat_scale_q31.o \
./MatrixFunctions/arm_mat_sub_f32.o \
./MatrixFunctions/arm_mat_sub_q15.o \
./MatrixFunctions/arm_mat_sub_q31.o \
./MatrixFunctions/arm_mat_trans_f32.o \
./MatrixFunctions/arm_mat_trans_q15.o \
./MatrixFunctions/arm_mat_trans_q31.o 

C_DEPS += \
./MatrixFunctions/arm_mat_add_f32.d \
./MatrixFunctions/arm_mat_add_q15.d \
./MatrixFunctions/arm_mat_add_q31.d \
./MatrixFunctions/arm_mat_cmplx_mult_f32.d \
./MatrixFunctions/arm_mat_cmplx_mult_q15.d \
./MatrixFunctions/arm_mat_cmplx_mult_q31.d \
./MatrixFunctions/arm_mat_init_f32.d \
./MatrixFunctions/arm_mat_init_q15.d \
./MatrixFunctions/arm_mat_init_q31.d \
./MatrixFunctions/arm_mat_inverse_f32.d \
./MatrixFunctions/arm_mat_inverse_f64.d \
./MatrixFunctions/arm_mat_mult_f32.d \
./MatrixFunctions/arm_mat_mult_fast_q15.d \
./MatrixFunctions/arm_mat_mult_fast_q31.d \
./MatrixFunctions/arm_mat_mult_q15.d \
./MatrixFunctions/arm_mat_mult_q31.d \
./MatrixFunctions/arm_mat_scale_f32.d \
./MatrixFunctions/arm_mat_scale_q15.d \
./MatrixFunctions/arm_mat_scale_q31.d \
./MatrixFunctions/arm_mat_sub_f32.d \
./MatrixFunctions/arm_mat_sub_q15.d \
./MatrixFunctions/arm_mat_sub_q31.d \
./MatrixFunctions/arm_mat_trans_f32.d \
./MatrixFunctions/arm_mat_trans_q15.d \
./MatrixFunctions/arm_mat_trans_q31.d 


# Each subdirectory must supply rules for building sources it contributes
MatrixFunctions/%.o: ../MatrixFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_4_5_0_DSPLIB_SRC/Include" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


