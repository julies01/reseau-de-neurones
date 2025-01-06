# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g 

# Target executable and build directory
TARGET_DIR = build/Debug
TARGET = $(TARGET_DIR)/outDebug

# Source files
SRCS = main.c neuron.c debug.c user.c ntwrk.c

# Object files (output in the same directory as sources)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)
	@echo "Build successful! Executable is located at $(TARGET)"

# Link object files to create the executable
$(TARGET): $(OBJS)
	@mkdir -p $(TARGET_DIR)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	@rm -f $(OBJS)
	@rm -f $(TARGET)
	@rmdir --ignore-fail-on-non-empty $(TARGET_DIR) 2>/dev/null || true
	@echo "Cleaned up build files."

.PHONY: all clean