# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g  # You can remove -g if you don't want debugging symbols

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Target executable
TARGET = main

# Source files in the src folder
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files in the obj folder (same structure as src)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(TARGET)
	@echo "Build successful! Executable is located at $(TARGET)"

# Link object files to create the executable
$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	@rm -f $(OBJS)
	@rm -f $(TARGET)
	@rmdir --ignore-fail-on-non-empty $(OBJ_DIR) 2>/dev/null || true
	@echo "Cleaned up build files."

.PHONY: all clean