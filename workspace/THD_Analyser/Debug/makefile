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
all: THD_Analyser.axf

# Tool invocations
THD_Analyser.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/dplab/git/LpcXpresso_DPLab/workspace/CMSIS_DSPLIB_CM3/lib" -L"/home/dplab/git/LpcXpresso_DPLab/workspace/lpc_chip_175x_6x/Debug" -L"/home/dplab/git/LpcXpresso_DPLab/workspace/td2_board_1769/Debug" -Xlinker -Map="THD_Analyser.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "THD_Analyser_Debug.ld" -o "THD_Analyser.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) THD_Analyser.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "THD_Analyser.axf"; # arm-none-eabi-objcopy -v -O binary "THD_Analyser.axf" "THD_Analyser.bin" ; # checksum -p LPC1769 -d "THD_Analyser.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
