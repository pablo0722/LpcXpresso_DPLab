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
all: Blink_FreeRtos_V0.axf

# Tool invocations
Blink_FreeRtos_V0.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\nxp\workspace2\lpc_board_nxp_lpcxpresso_1769\Debug" -L"C:\nxp\workspace2\LibFreeRTOS_8.2.3\Debug" -L"C:\nxp\workspace2\lpc_chip_175x_6x\Debug" -Xlinker -Map="Blink_FreeRtos_V0.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "Blink_FreeRtos_V0_Debug.ld" -o "Blink_FreeRtos_V0.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Blink_FreeRtos_V0.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Blink_FreeRtos_V0.axf"; # arm-none-eabi-objcopy -v -O binary "Blink_FreeRtos_V0.axf" "Blink_FreeRtos_V0.bin" ; # checksum -p LPC1769 -d "Blink_FreeRtos_V0.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
