CC = gcc
CFLAGS = -g -Wall
RM = rm -f

TARGET = memory_overcommit

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)