################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../StatisticsFunctions/arm_max_f32.c \
../StatisticsFunctions/arm_max_q15.c \
../StatisticsFunctions/arm_max_q31.c \
../StatisticsFunctions/arm_max_q7.c \
../StatisticsFunctions/arm_mean_f32.c \
../StatisticsFunctions/arm_mean_q15.c \
../StatisticsFunctions/arm_mean_q31.c \
../StatisticsFunctions/arm_mean_q7.c \
../StatisticsFunctions/arm_min_f32.c \
../StatisticsFunctions/arm_min_q15.c \
../StatisticsFunctions/arm_min_q31.c \
../StatisticsFunctions/arm_min_q7.c \
../StatisticsFunctions/arm_power_f32.c \
../StatisticsFunctions/arm_power_q15.c \
../StatisticsFunctions/arm_power_q31.c \
../StatisticsFunctions/arm_power_q7.c \
../StatisticsFunctions/arm_rms_f32.c \
../StatisticsFunctions/arm_rms_q15.c \
../StatisticsFunctions/arm_rms_q31.c \
../StatisticsFunctions/arm_std_f32.c \
../StatisticsFunctions/arm_std_q15.c \
../StatisticsFunctions/arm_std_q31.c \
../StatisticsFunctions/arm_var_f32.c \
../StatisticsFunctions/arm_var_q15.c \
../StatisticsFunctions/arm_var_q31.c 

OBJS += \
./StatisticsFunctions/arm_max_f32.o \
./StatisticsFunctions/arm_max_q15.o \
./StatisticsFunctions/arm_max_q31.o \
./StatisticsFunctions/arm_max_q7.o \
./StatisticsFunctions/arm_mean_f32.o \
./StatisticsFunctions/arm_mean_q15.o \
./StatisticsFunctions/arm_mean_q31.o \
./StatisticsFunctions/arm_mean_q7.o \
./StatisticsFunctions/arm_min_f32.o \
./StatisticsFunctions/arm_min_q15.o \
./StatisticsFunctions/arm_min_q31.o \
./StatisticsFunctions/arm_min_q7.o \
./StatisticsFunctions/arm_power_f32.o \
./StatisticsFunctions/arm_power_q15.o \
./StatisticsFunctions/arm_power_q31.o \
./StatisticsFunctions/arm_power_q7.o \
./StatisticsFunctions/arm_rms_f32.o \
./StatisticsFunctions/arm_rms_q15.o \
./StatisticsFunctions/arm_rms_q31.o \
./StatisticsFunctions/arm_std_f32.o \
./StatisticsFunctions/arm_std_q15.o \
./StatisticsFunctions/arm_std_q31.o \
./StatisticsFunctions/arm_var_f32.o \
./StatisticsFunctions/arm_var_q15.o \
./StatisticsFunctions/arm_var_q31.o 

C_DEPS += \
./StatisticsFunctions/arm_max_f32.d \
./StatisticsFunctions/arm_max_q15.d \
./StatisticsFunctions/arm_max_q31.d \
./StatisticsFunctions/arm_max_q7.d \
./StatisticsFunctions/arm_mean_f32.d \
./StatisticsFunctions/arm_mean_q15.d \
./StatisticsFunctions/arm_mean_q31.d \
./StatisticsFunctions/arm_mean_q7.d \
./StatisticsFunctions/arm_min_f32.d \
./StatisticsFunctions/arm_min_q15.d \
./StatisticsFunctions/arm_min_q31.d \
./StatisticsFunctions/arm_min_q7.d \
./StatisticsFunctions/arm_power_f32.d \
./StatisticsFunctions/arm_power_q15.d \
./StatisticsFunctions/arm_power_q31.d \
./StatisticsFunctions/arm_power_q7.d \
./StatisticsFunctions/arm_rms_f32.d \
./StatisticsFunctions/arm_rms_q15.d \
./StatisticsFunctions/arm_rms_q31.d \
./StatisticsFunctions/arm_std_f32.d \
./StatisticsFunctions/arm_std_q15.d \
./StatisticsFunctions/arm_std_q31.d \
./StatisticsFunctions/arm_var_f32.d \
./StatisticsFunctions/arm_var_q15.d \
./StatisticsFunctions/arm_var_q31.d 


# Each subdirectory must supply rules for building sources it contributes
StatisticsFunctions/%.o: ../StatisticsFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_4_5_0_DSPLIB_SRC/Include" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


