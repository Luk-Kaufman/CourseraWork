# Compiler flags
COMMON_CFLAGS = -Wall -Werror -g -O0 -std=c99

# Platform-Specific Flags
ifeq ($(PLATFORM),HOST)
    CC = gcc
    CPPFLAGS = -DHOST
    LDFLAGS = 
    SOURCES = src/main.c src/memory.c
    INCLUDES = -Iinclude/common
else ifeq ($(PLATFORM),MSP432)
    CC = arm-none-eabi-gcc
    CPPFLAGS = -DMSP432
    LDFLAGS = -T msp432p401r.lds
    CFLAGS += -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
    SOURCES = src/main.c src/memory.c src/interrupts_msp432p401r_gcc.c src/startup_msp432p401r_gcc.c src/system_msp432p401r.c
    INCLUDES = -Iinclude/common -Iinclude/msp432 -Iinclude/CMSIS
else
    $(error PLATFORM must be specified as HOST or MSP432)
endif

CFLAGS += $(COMMON_CFLAGS) $(CPPFLAGS)
OBJS = $(SOURCES:.c=.o)

# Output files
TARGET = c1m2.out
MAP = c1m2.map

# Phony targets
.PHONY: compile-all build clean

# Default target
all: build

# Compile all object files
compile-all: $(OBJS)

# Build target
build: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(TARGET) -Wl,-Map=$(MAP)
	size $(TARGET)

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET) $(MAP) *.i *.asm

# Preprocessed output
%.i: %.c
	$(CC) $(CFLAGS) -E $< -o $@

# Assembly output
%.asm: %.c
	$(CC) $(CFLAGS) -S $< -o $@

# Object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

