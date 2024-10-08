CC = gcc
CFLAGS = -g -Wall

TARGET = io_flush
RESULT = ./result*.txt

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET) $(RESULT)