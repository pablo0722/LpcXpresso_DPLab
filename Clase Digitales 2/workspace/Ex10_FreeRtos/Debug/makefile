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
all: Ex10_FreeRtos.axf

# Tool invocations
Ex10_FreeRtos.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\nxp\workspace2\lpc_board_nxp_lpcxpresso_1769\Debug" -L"C:\nxp\workspace2\LibFreeRTOS_8.2.3\Debug" -L"C:\nxp\workspace2\lpc_chip_175x_6x\Debug" -Xlinker -Map="Ex10_FreeRtos.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "Ex1_FreeRtos_Debug.ld" -o "Ex10_FreeRtos.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Ex10_FreeRtos.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Ex10_FreeRtos.axf"; # arm-none-eabi-objcopy -v -O binary "Ex10_FreeRtos.axf" "Ex10_FreeRtos.bin" ; # checksum -p LPC1769 -d "Ex10_FreeRtos.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
