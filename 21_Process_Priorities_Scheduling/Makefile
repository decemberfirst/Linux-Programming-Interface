# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Executable file
TARGET = main

# Source Files
SRC = ResetSchedulingForChild.c

# Build all (compile, clean previous build, and run with args)
all: $(TARGET) # build target
	./$(TARGET) arg1 arg2
	@rm -f $(TARGET)

# Linking (compile and link)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
