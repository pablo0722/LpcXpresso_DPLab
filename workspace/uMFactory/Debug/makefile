################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Devices/Utiles/Drivers/LPC1769/subdir.mk
-include src/Devices/Temporizador/Primitivas/subdir.mk
-include src/Devices/Temporizador/Drivers/LPC1769/subdir.mk
-include src/Devices/Temporizador/subdir.mk
-include src/Devices/Teclado/Primitivas/subdir.mk
-include src/Devices/Teclado/Drivers/LPC1769/subdir.mk
-include src/Devices/Teclado/subdir.mk
-include src/Devices/Seg7/Primitivas/subdir.mk
-include src/Devices/Seg7/Drivers/LPC1769/subdir.mk
-include src/Devices/Seg7/subdir.mk
-include src/Devices/PLL/Drivers/LPC1769/subdir.mk
-include src/Devices/LEDs/Primitivas/subdir.mk
-include src/Devices/LEDs/Drivers/LPC1769/subdir.mk
-include src/Devices/LEDs/subdir.mk
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
all: uMFactory_05_15.axf

# Tool invocations
uMFactory_05_15.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="uMFactory_05_15.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "uMFactory_05_15_Debug.ld" -o "uMFactory_05_15.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) uMFactory_05_15.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "uMFactory_05_15.axf"; # arm-none-eabi-objcopy -O binary "uMFactory_05_15.axf" "uMFactory_05_15.bin" ; checksum -p LPC1769 -d "uMFactory_05_15.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
