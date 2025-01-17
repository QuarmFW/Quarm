# Python version
PYTHON_VERSION = 3.10  # Replace with your Python version, e.g., 3.10

# Compiler and linker flags
CC = gcc
CFLAGS = -I/usr/include/python$(PYTHON_VERSION)  # Path to Python headers
LDFLAGS = -lpython$(PYTHON_VERSION)  # Link against the correct Python library

# List of C source files (all .c files in the current directory)
SRCS = $(wildcard *.c)

# Output binary
TARGET = quarm.bin

# Default target: compile all C files and create the executable
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

# Clean up build artifacts
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
