################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include example/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Ex_Uart_V1.axf

# Tool invocations
Ex_Uart_V1.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/workspace/lpc_chip_175x_6x/Debug" -L"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/workspace/LPC_BaseBoardBB1769_R02/Debug" -Xlinker -Map="Ex_Uart_V1.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "Ex_Uart_V1_Debug.ld" -o "Ex_Uart_V1.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Ex_Uart_V1.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Ex_Uart_V1.axf"; # arm-none-eabi-objcopy -v -O binary "Ex_Uart_V1.axf" "Ex_Uart_V1.bin" ; # checksum -p LPC1769 -d "Ex_Uart_V1.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
