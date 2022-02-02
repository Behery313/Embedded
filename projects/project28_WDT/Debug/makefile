################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
project28_WDT.lss \

FLASH_IMAGE += \
project28_WDT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: project28_WDT.elf secondary-outputs

# Tool invocations
project28_WDT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,project28_WDT.map -mmcu=atmega32 -o "project28_WDT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

project28_WDT.lss: project28_WDT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S project28_WDT.elf  >"project28_WDT.lss"
	@echo 'Finished building: $@'
	@echo ' '

project28_WDT.hex: project28_WDT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex project28_WDT.elf  "project28_WDT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: project28_WDT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 project28_WDT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) project28_WDT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
