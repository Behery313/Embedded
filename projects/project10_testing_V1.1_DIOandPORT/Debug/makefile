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
project10_testing_V1.1_DIOandPORT.lss \

FLASH_IMAGE += \
project10_testing_V1.1_DIOandPORT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: project10_testing_V1.1_DIOandPORT.elf secondary-outputs

# Tool invocations
project10_testing_V1.1_DIOandPORT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,project10_testing_V1.1_DIOandPORT.map -mmcu=atmega32 -o "project10_testing_V1.1_DIOandPORT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

project10_testing_V1.1_DIOandPORT.lss: project10_testing_V1.1_DIOandPORT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S project10_testing_V1.1_DIOandPORT.elf  >"project10_testing_V1.1_DIOandPORT.lss"
	@echo 'Finished building: $@'
	@echo ' '

project10_testing_V1.1_DIOandPORT.hex: project10_testing_V1.1_DIOandPORT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex project10_testing_V1.1_DIOandPORT.elf  "project10_testing_V1.1_DIOandPORT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: project10_testing_V1.1_DIOandPORT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 project10_testing_V1.1_DIOandPORT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) project10_testing_V1.1_DIOandPORT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
