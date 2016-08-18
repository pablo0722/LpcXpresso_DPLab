################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mis_funciones/app_funcs.c \
../mis_funciones/init_funcs.c \
../mis_funciones/uninit_funcs.c \
../mis_funciones/variables_y_constantes.c 

OBJS += \
./mis_funciones/app_funcs.o \
./mis_funciones/init_funcs.o \
./mis_funciones/uninit_funcs.o \
./mis_funciones/variables_y_constantes.o 

C_DEPS += \
./mis_funciones/app_funcs.d \
./mis_funciones/init_funcs.d \
./mis_funciones/uninit_funcs.d \
./mis_funciones/variables_y_constantes.d 


# Each subdirectory must supply rules for building sources it contributes
mis_funciones/%.o: ../mis_funciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__USE_LPCOPEN -DCORE_M3 -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/lpc_chip_175x_6x/inc" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/td2_board_1769/mis_inc" -I"/media/pablo/Disco_Auxiliar/UTN/LPCXpresso/workspace/td2_board_1769/inc" -O2 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


