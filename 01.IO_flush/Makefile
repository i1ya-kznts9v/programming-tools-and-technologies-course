CC = gcc
CFLAGS = -g -Wall

TARGET = experiment
RESULT = ./result.txt

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET) $(RESULT)