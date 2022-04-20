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
libUART_COM.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: libUART_COM.a secondary-outputs

# Tool invocations
libUART_COM.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR Archiver'
	avr-ar -r  "libUART_COM.a" $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

libUART_COM.lss: libUART_COM.a
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S libUART_COM.a  >"libUART_COM.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: libUART_COM.a
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 libUART_COM.a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(ARCHIVES)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) libUART_COM.a
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
