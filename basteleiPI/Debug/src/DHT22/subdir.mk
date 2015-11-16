################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DHT22/dhtHelper.cpp 

C_SRCS += \
../src/DHT22/common_dht_read.c \
../src/DHT22/pi_2_dht_read.c \
../src/DHT22/pi_2_mmio.c \
../src/DHT22/test_dht_read.c 

OBJS += \
./src/DHT22/common_dht_read.o \
./src/DHT22/dhtHelper.o \
./src/DHT22/pi_2_dht_read.o \
./src/DHT22/pi_2_mmio.o \
./src/DHT22/test_dht_read.o 

C_DEPS += \
./src/DHT22/common_dht_read.d \
./src/DHT22/pi_2_dht_read.d \
./src/DHT22/pi_2_mmio.d \
./src/DHT22/test_dht_read.d 

CPP_DEPS += \
./src/DHT22/dhtHelper.d 


# Each subdirectory must supply rules for building sources it contributes
src/DHT22/%.o: ../src/DHT22/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/DHT22/%.o: ../src/DHT22/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/rapidjson -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


