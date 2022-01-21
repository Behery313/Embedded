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
project13_dcmotor_and_switch.lss \

FLASH_IMAGE += \
project13_dcmotor_and_switch.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: project13_dcmotor_and_switch.elf secondary-outputs

# Tool invocations
project13_dcmotor_and_switch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,project13_dcmotor_and_switch.map -mmcu=atmega32 -o "project13_dcmotor_and_switch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

project13_dcmotor_and_switch.lss: project13_dcmotor_and_switch.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S project13_dcmotor_and_switch.elf  >"project13_dcmotor_and_switch.lss"
	@echo 'Finished building: $@'
	@echo ' '

project13_dcmotor_and_switch.hex: project13_dcmotor_and_switch.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex project13_dcmotor_and_switch.elf  "project13_dcmotor_and_switch.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: project13_dcmotor_and_switch.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 project13_dcmotor_and_switch.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) project13_dcmotor_and_switch.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
