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
project26_SW_ICU.lss \

FLASH_IMAGE += \
project26_SW_ICU.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: project26_SW_ICU.elf secondary-outputs

# Tool invocations
project26_SW_ICU.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,project26_SW_ICU.map -mmcu=atmega32 -o "project26_SW_ICU.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

project26_SW_ICU.lss: project26_SW_ICU.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S project26_SW_ICU.elf  >"project26_SW_ICU.lss"
	@echo 'Finished building: $@'
	@echo ' '

project26_SW_ICU.hex: project26_SW_ICU.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex project26_SW_ICU.elf  "project26_SW_ICU.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: project26_SW_ICU.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 project26_SW_ICU.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) project26_SW_ICU.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
