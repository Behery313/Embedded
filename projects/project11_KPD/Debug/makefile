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
project11_KPD.lss \

FLASH_IMAGE += \
project11_KPD.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: project11_KPD.elf secondary-outputs

# Tool invocations
project11_KPD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,project11_KPD.map -mmcu=atmega32 -o "project11_KPD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

project11_KPD.lss: project11_KPD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S project11_KPD.elf  >"project11_KPD.lss"
	@echo 'Finished building: $@'
	@echo ' '

project11_KPD.hex: project11_KPD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex project11_KPD.elf  "project11_KPD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: project11_KPD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 project11_KPD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) project11_KPD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
