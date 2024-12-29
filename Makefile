# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable
TARGET = main

# Source files
SRCS = main.c neuron.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)
	@./$(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	@rm -f $(OBJS) $(TARGET)

.PHONY: all clean
