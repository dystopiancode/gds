################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Example_ArraySet.c \
../SampleObject.c \
../main.c 

OBJS += \
./Example_ArraySet.o \
./SampleObject.o \
./main.o 

C_DEPS += \
./Example_ArraySet.d \
./SampleObject.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/bogdan/Ubuntu One/Eclipse/gds/gds" -I"/home/bogdan/Ubuntu One/Eclipse/gds/gds/Debug" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


