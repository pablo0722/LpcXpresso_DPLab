################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/sysinit.c \
../src/testfft.c 

OBJS += \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/sysinit.o \
./src/testfft.o 

C_DEPS += \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/sysinit.d \
./src/testfft.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_LPCOPEN -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM3 -D__LPC17XX__ -D__REDLIB__ -I"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\lpc_board_nxp_lpcxpresso_1769\inc" -I"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\CMSIS_DSPLIB_SRC\inc" -I"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\CMSIS_DSPLIB_SRC\inc_cmsis" -I"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\lpc_chip_175x_6x\inc" -I"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\CMSIS_DSPLIB_CM3\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


