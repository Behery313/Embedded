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
project22_TIMER.lss \

FLASH_IMAGE += \
project22_TIMER.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: project22_TIMER.elf secondary-outputs

# Tool invocations
project22_TIMER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,project22_TIMER.map -mmcu=atmega32 -o "project22_TIMER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

project22_TIMER.lss: project22_TIMER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S project22_TIMER.elf  >"project22_TIMER.lss"
	@echo 'Finished building: $@'
	@echo ' '

project22_TIMER.hex: project22_TIMER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex project22_TIMER.elf  "project22_TIMER.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: project22_TIMER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 project22_TIMER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) project22_TIMER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
