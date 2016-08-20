################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/IRQ_funcs.c \
../src/THD_Analyser.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/funciones.c \
../src/main.c \
../src/sysinit.c \
../src/variables_y_constantes.c 

OBJS += \
./src/IRQ_funcs.o \
./src/THD_Analyser.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/funciones.o \
./src/main.o \
./src/sysinit.o \
./src/variables_y_constantes.o 

C_DEPS += \
./src/IRQ_funcs.d \
./src/THD_Analyser.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/funciones.d \
./src/main.d \
./src/sysinit.d \
./src/variables_y_constantes.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -DCORE_M3 -D__USE_LPCOPEN -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM3 -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_DSPLIB_SRC/inc_cmsis" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_DSPLIB_SRC/inc" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/lpc_chip_175x_6x/inc" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/THD_Analyser/inc" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_DSPLIB_CM3/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


