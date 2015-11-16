################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/basteleiPI.cpp \
../src/gpioHelper.cpp \
../src/httpRequest.cpp \
../src/jsonWrap.cpp 

OBJS += \
./src/basteleiPI.o \
./src/gpioHelper.o \
./src/httpRequest.o \
./src/jsonWrap.o 

CPP_DEPS += \
./src/basteleiPI.d \
./src/gpioHelper.d \
./src/httpRequest.d \
./src/jsonWrap.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/rapidjson -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/httpRequest.o: ../src/httpRequest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/httpRequest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


