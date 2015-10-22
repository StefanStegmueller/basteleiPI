################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GpioHelper.cpp \
../src/basteleiPI.cpp 

OBJS += \
./src/GpioHelper.o \
./src/basteleiPI.o 

CPP_DEPS += \
./src/GpioHelper.d \
./src/basteleiPI.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -include/usr/local/lib/libwiringPi.so -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


