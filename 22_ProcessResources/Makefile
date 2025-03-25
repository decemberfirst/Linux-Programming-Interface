CC = gcc
CFLAGS = -Wall
TARGET = main
SRC = RlimitOptions.c

all: $(TARGET)
	./$(TARGET) i
	@rm -f $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
