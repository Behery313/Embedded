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
project17_ADC.lss \

FLASH_IMAGE += \
project17_ADC.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: project17_ADC.elf secondary-outputs

# Tool invocations
project17_ADC.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,project17_ADC.map -mmcu=atmega32 -o "project17_ADC.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

project17_ADC.lss: project17_ADC.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S project17_ADC.elf  >"project17_ADC.lss"
	@echo 'Finished building: $@'
	@echo ' '

project17_ADC.hex: project17_ADC.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex project17_ADC.elf  "project17_ADC.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: project17_ADC.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 project17_ADC.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) project17_ADC.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
