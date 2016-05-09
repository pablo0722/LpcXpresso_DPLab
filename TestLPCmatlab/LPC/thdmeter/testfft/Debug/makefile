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
all: testfft.axf

# Tool invocations
testfft.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\lpc_board_nxp_lpcxpresso_1769\Debug" -L"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\lpc_chip_175x_6x\Debug" -L"B:\Dropbox\TestLPCmatlab\LPC\thdmeter\CMSIS_DSPLIB_CM3\lib" -Xlinker -Map="testfft.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "testfft_Debug.ld" -o "testfft.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) testfft.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "testfft.axf"; # arm-none-eabi-objcopy -v -O binary "testfft.axf" "testfft.bin" ; # checksum -p LPC1769 -d "testfft.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
