CC = gcc
CFLAGS = -Wall
TARGET = main
SRC = GetResourceUsage.c

all: $(TARGET)
	./$(TARGET)
	@rm -f $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
