################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BMP180/bmpHelper.cpp 

C_SRCS += \
../src/BMP180/bmp180.c 

OBJS += \
./src/BMP180/bmp180.o \
./src/BMP180/bmpHelper.o 

C_DEPS += \
./src/BMP180/bmp180.d 

CPP_DEPS += \
./src/BMP180/bmpHelper.d 


# Each subdirectory must supply rules for building sources it contributes
src/BMP180/%.o: ../src/BMP180/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/BMP180/%.o: ../src/BMP180/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/rapidjson -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


