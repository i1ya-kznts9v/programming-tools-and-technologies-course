CC = gcc
CFLAGS = -g -Wall

TARGET = memory_overcommit

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
