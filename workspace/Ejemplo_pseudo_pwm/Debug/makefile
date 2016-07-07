################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
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
all: Ejemplo_pseudo_pwm.axf

# Tool invocations
Ejemplo_pseudo_pwm.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/workspace/LPC_BaseBoardBB1769_R02/Debug" -L"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/workspace/LibFreeRTOS_8.2.3/Debug" -L"/media/pablo/Disco_Auxiliar/UTN/UTN 2016/Digitales 2/TD II/Ejemplos FreeRTOS/workspace/lpc_chip_175x_6x/Debug" -Xlinker -Map="Ejemplo_pseudo_pwm.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "Ejemplo_pseudo_pwm_Debug.ld" -o "Ejemplo_pseudo_pwm.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Ejemplo_pseudo_pwm.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Ejemplo_pseudo_pwm.axf"; # arm-none-eabi-objcopy -v -O binary "Ejemplo_pseudo_pwm.axf" "Ejemplo_pseudo_pwm.bin" ; # checksum -p LPC1769 -d "Ejemplo_pseudo_pwm.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
