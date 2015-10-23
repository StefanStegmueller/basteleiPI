################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GpioHelper.cpp \
../src/basteleiPI.cpp 

C_SRCS += \
../src/_Raspberry_Pi_2_Driver.c \
../src/_Test_Driver.c \
../src/common_dht_read.c \
../src/pi_2_dht_read.c \
../src/pi_2_mmio.c \
../src/test_dht_read.c 

OBJS += \
./src/GpioHelper.o \
./src/_Raspberry_Pi_2_Driver.o \
./src/_Test_Driver.o \
./src/basteleiPI.o \
./src/common_dht_read.o \
./src/pi_2_dht_read.o \
./src/pi_2_mmio.o \
./src/test_dht_read.o 

C_DEPS += \
./src/_Raspberry_Pi_2_Driver.d \
./src/_Test_Driver.d \
./src/common_dht_read.d \
./src/pi_2_dht_read.d \
./src/pi_2_mmio.d \
./src/test_dht_read.d 

CPP_DEPS += \
./src/GpioHelper.d \
./src/basteleiPI.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


