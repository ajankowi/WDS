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
USART_COM.lss \

FLASH_IMAGE += \
USART_COM.hex \

EEPROM_IMAGE += \
USART_COM.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: USART_COM.elf secondary-outputs

# Tool invocations
USART_COM.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,USART_COM.map -mmcu=atmega16 -o "USART_COM.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

USART_COM.lss: USART_COM.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S USART_COM.elf  >"USART_COM.lss"
	@echo 'Finished building: $@'
	@echo ' '

USART_COM.hex: USART_COM.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex USART_COM.elf  "USART_COM.hex"
	@echo 'Finished building: $@'
	@echo ' '

USART_COM.eep: USART_COM.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex USART_COM.elf  "USART_COM.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: USART_COM.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 USART_COM.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) USART_COM.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
