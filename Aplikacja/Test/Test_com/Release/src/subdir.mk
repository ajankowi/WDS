################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CRC8.cpp \
../src/main.cpp \
../src/nadawanie.cpp \
../src/odbieranie.cpp \
../src/transparam.cpp 

OBJS += \
./src/CRC8.o \
./src/main.o \
./src/nadawanie.o \
./src/odbieranie.o \
./src/transparam.o 

CPP_DEPS += \
./src/CRC8.d \
./src/main.d \
./src/nadawanie.d \
./src/odbieranie.d \
./src/transparam.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


