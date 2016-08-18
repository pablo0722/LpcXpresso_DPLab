################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TransformFunctions/arm_bitreversal.c \
../TransformFunctions/arm_cfft_f32.c \
../TransformFunctions/arm_cfft_q15.c \
../TransformFunctions/arm_cfft_q31.c \
../TransformFunctions/arm_cfft_radix2_f32.c \
../TransformFunctions/arm_cfft_radix2_init_f32.c \
../TransformFunctions/arm_cfft_radix2_init_q15.c \
../TransformFunctions/arm_cfft_radix2_init_q31.c \
../TransformFunctions/arm_cfft_radix2_q15.c \
../TransformFunctions/arm_cfft_radix2_q31.c \
../TransformFunctions/arm_cfft_radix4_f32.c \
../TransformFunctions/arm_cfft_radix4_init_f32.c \
../TransformFunctions/arm_cfft_radix4_init_q15.c \
../TransformFunctions/arm_cfft_radix4_init_q31.c \
../TransformFunctions/arm_cfft_radix4_q15.c \
../TransformFunctions/arm_cfft_radix4_q31.c \
../TransformFunctions/arm_cfft_radix8_f32.c \
../TransformFunctions/arm_dct4_f32.c \
../TransformFunctions/arm_dct4_init_f32.c \
../TransformFunctions/arm_dct4_init_q15.c \
../TransformFunctions/arm_dct4_init_q31.c \
../TransformFunctions/arm_dct4_q15.c \
../TransformFunctions/arm_dct4_q31.c \
../TransformFunctions/arm_rfft_f32.c \
../TransformFunctions/arm_rfft_fast_f32.c \
../TransformFunctions/arm_rfft_fast_init_f32.c \
../TransformFunctions/arm_rfft_init_f32.c \
../TransformFunctions/arm_rfft_init_q15.c \
../TransformFunctions/arm_rfft_init_q31.c \
../TransformFunctions/arm_rfft_q15.c \
../TransformFunctions/arm_rfft_q31.c 

S_UPPER_SRCS += \
../TransformFunctions/arm_bitreversal2.S 

OBJS += \
./TransformFunctions/arm_bitreversal.o \
./TransformFunctions/arm_bitreversal2.o \
./TransformFunctions/arm_cfft_f32.o \
./TransformFunctions/arm_cfft_q15.o \
./TransformFunctions/arm_cfft_q31.o \
./TransformFunctions/arm_cfft_radix2_f32.o \
./TransformFunctions/arm_cfft_radix2_init_f32.o \
./TransformFunctions/arm_cfft_radix2_init_q15.o \
./TransformFunctions/arm_cfft_radix2_init_q31.o \
./TransformFunctions/arm_cfft_radix2_q15.o \
./TransformFunctions/arm_cfft_radix2_q31.o \
./TransformFunctions/arm_cfft_radix4_f32.o \
./TransformFunctions/arm_cfft_radix4_init_f32.o \
./TransformFunctions/arm_cfft_radix4_init_q15.o \
./TransformFunctions/arm_cfft_radix4_init_q31.o \
./TransformFunctions/arm_cfft_radix4_q15.o \
./TransformFunctions/arm_cfft_radix4_q31.o \
./TransformFunctions/arm_cfft_radix8_f32.o \
./TransformFunctions/arm_dct4_f32.o \
./TransformFunctions/arm_dct4_init_f32.o \
./TransformFunctions/arm_dct4_init_q15.o \
./TransformFunctions/arm_dct4_init_q31.o \
./TransformFunctions/arm_dct4_q15.o \
./TransformFunctions/arm_dct4_q31.o \
./TransformFunctions/arm_rfft_f32.o \
./TransformFunctions/arm_rfft_fast_f32.o \
./TransformFunctions/arm_rfft_fast_init_f32.o \
./TransformFunctions/arm_rfft_init_f32.o \
./TransformFunctions/arm_rfft_init_q15.o \
./TransformFunctions/arm_rfft_init_q31.o \
./TransformFunctions/arm_rfft_q15.o \
./TransformFunctions/arm_rfft_q31.o 

C_DEPS += \
./TransformFunctions/arm_bitreversal.d \
./TransformFunctions/arm_cfft_f32.d \
./TransformFunctions/arm_cfft_q15.d \
./TransformFunctions/arm_cfft_q31.d \
./TransformFunctions/arm_cfft_radix2_f32.d \
./TransformFunctions/arm_cfft_radix2_init_f32.d \
./TransformFunctions/arm_cfft_radix2_init_q15.d \
./TransformFunctions/arm_cfft_radix2_init_q31.d \
./TransformFunctions/arm_cfft_radix2_q15.d \
./TransformFunctions/arm_cfft_radix2_q31.d \
./TransformFunctions/arm_cfft_radix4_f32.d \
./TransformFunctions/arm_cfft_radix4_init_f32.d \
./TransformFunctions/arm_cfft_radix4_init_q15.d \
./TransformFunctions/arm_cfft_radix4_init_q31.d \
./TransformFunctions/arm_cfft_radix4_q15.d \
./TransformFunctions/arm_cfft_radix4_q31.d \
./TransformFunctions/arm_cfft_radix8_f32.d \
./TransformFunctions/arm_dct4_f32.d \
./TransformFunctions/arm_dct4_init_f32.d \
./TransformFunctions/arm_dct4_init_q15.d \
./TransformFunctions/arm_dct4_init_q31.d \
./TransformFunctions/arm_dct4_q15.d \
./TransformFunctions/arm_dct4_q31.d \
./TransformFunctions/arm_rfft_f32.d \
./TransformFunctions/arm_rfft_fast_f32.d \
./TransformFunctions/arm_rfft_fast_init_f32.d \
./TransformFunctions/arm_rfft_init_f32.d \
./TransformFunctions/arm_rfft_init_q15.d \
./TransformFunctions/arm_rfft_init_q31.d \
./TransformFunctions/arm_rfft_q15.d \
./TransformFunctions/arm_rfft_q31.d 


# Each subdirectory must supply rules for building sources it contributes
TransformFunctions/%.o: ../TransformFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_4_5_0_DSPLIB_SRC/Include" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TransformFunctions/%.o: ../TransformFunctions/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -g3 -mcpu=cortex-m3 -mthumb -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


