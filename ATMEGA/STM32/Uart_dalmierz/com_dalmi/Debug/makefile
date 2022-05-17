################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/VL53L0X/platform/src/subdir.mk
-include Drivers/VL53L0X/core/src/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
com_dalmi.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
com_dalmi.list \

OBJCOPY_BIN += \
com_dalmi.bin \


# All Target
all: com_dalmi.elf secondary-outputs

# Tool invocations
com_dalmi.elf: $(OBJS) $(USER_OBJS) C:\Users\adamj\Desktop\Studia\Semestr_6\WDS\ATMEGA\STM32\Uart_dalmierz\com_dalmi\STM32L476RGTX_FLASH.ld
	arm-none-eabi-gcc -o "com_dalmi.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\adamj\Desktop\Studia\Semestr_6\WDS\ATMEGA\STM32\Uart_dalmierz\com_dalmi\STM32L476RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="com_dalmi.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

com_dalmi.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "com_dalmi.list"
	@echo 'Finished building: $@'
	@echo ' '

com_dalmi.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "com_dalmi.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
