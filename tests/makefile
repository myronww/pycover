
RM := rm -rf

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += branch_counts.c 

OBJS += branch_counts.o 

C_DEPS += branch_counts.d 

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: html_ref

html_ref: branch_counts_ref.info
	genhtml.pl -o html_ref ./branch_counts_ref.info	

branch_counts_ref.info: %.gcda
	geninfo.pl . -o branch_counts_ref.info

%.gcda: branch_counts
	./branch_counts

# Tool invocations
branch_counts: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C Linker'
	gcc -ftest-coverage -fprofile-arcs -o "branch_counts" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Each subdirectory must supply rules for building sources it contributes
%.o: %.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -ftest-coverage -fprofile-arcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) branch_counts *.gcno *.gcda *.c.gcov *.h.gcov *.info html_ref
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
