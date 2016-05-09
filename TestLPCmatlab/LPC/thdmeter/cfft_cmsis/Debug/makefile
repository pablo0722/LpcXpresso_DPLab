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
all: cfft_cmsis.axf

# Tool invocations
cfft_cmsis.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\lpc_board_nxp_lpcxpresso_1769\Debug" -L"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\lpc_chip_175x_6x\Debug" -L"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\CMSIS_DSPLIB_CM3\lib" -Xlinker -Map="cfft_cmsis.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "cfft_cmsis_Debug.ld" -o "cfft_cmsis.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) cfft_cmsis.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "cfft_cmsis.axf"; # arm-none-eabi-objcopy -v -O binary "cfft_cmsis.axf" "cfft_cmsis.bin" ; # checksum -p LPC1769 -d "cfft_cmsis.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
