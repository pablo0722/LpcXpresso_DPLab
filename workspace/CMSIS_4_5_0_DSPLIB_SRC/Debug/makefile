################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TransformFunctions/subdir.mk
-include SupportFunctions/subdir.mk
-include StatisticsFunctions/subdir.mk
-include MatrixFunctions/subdir.mk
-include FilteringFunctions/subdir.mk
-include FastMathFunctions/subdir.mk
-include ControllerFunctions/subdir.mk
-include ComplexMathFunctions/subdir.mk
-include CommonTables/subdir.mk
-include BasicMathFunctions/subdir.mk
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
all: CMSIS_4_5_0_DSPLIB_SRC.axf

# Tool invocations
CMSIS_4_5_0_DSPLIB_SRC.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="CMSIS_4_5_0_DSPLIB_SRC.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "CMSIS_4_5_0_DSPLIB_SRC_Debug.ld" -o "CMSIS_4_5_0_DSPLIB_SRC.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) CMSIS_4_5_0_DSPLIB_SRC.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "CMSIS_4_5_0_DSPLIB_SRC.axf"; # arm-none-eabi-objcopy -v -O binary "CMSIS_4_5_0_DSPLIB_SRC.axf" "CMSIS_4_5_0_DSPLIB_SRC.bin" ; # checksum -p LPC1769 -d "CMSIS_4_5_0_DSPLIB_SRC.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
