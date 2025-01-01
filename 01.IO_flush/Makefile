CC = gcc
CFLAGS = -g -Wall
RM = rm -f

TARGET = io_flush
RESULT = ./result*.txt

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET) $(RESULT)