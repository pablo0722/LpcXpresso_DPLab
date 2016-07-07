################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mis_funciones/IRQ_funcs.c \
../mis_funciones/app_funcs.c \
../mis_funciones/init_funcs.c \
../mis_funciones/main.c \
../mis_funciones/uninit_funcs.c \
../mis_funciones/variables_y_constantes.c 

OBJS += \
./mis_funciones/IRQ_funcs.o \
./mis_funciones/app_funcs.o \
./mis_funciones/init_funcs.o \
./mis_funciones/main.o \
./mis_funciones/uninit_funcs.o \
./mis_funciones/variables_y_constantes.o 

C_DEPS += \
./mis_funciones/IRQ_funcs.d \
./mis_funciones/app_funcs.d \
./mis_funciones/init_funcs.d \
./mis_funciones/main.d \
./mis_funciones/uninit_funcs.d \
./mis_funciones/variables_y_constantes.d 


# Each subdirectory must supply rules for building sources it contributes
mis_funciones/%.o: ../mis_funciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -DCORE_M3 -D__USE_LPCOPEN -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM3 -D__LPC17XX__ -D__REDLIB__ -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/THD_Analyser/inc" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_DSPLIB_SRC/inc_cmsis" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_DSPLIB_SRC/inc" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/td2_board_1769/inc" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/lpc_chip_175x_6x/inc" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/CMSIS_DSPLIB_CM3/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


