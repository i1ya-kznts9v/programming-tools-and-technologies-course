CC = gcc
CFLAGS = -Wall -g

TARGET = fractal
RESULT = ./*.pgm
RM = rm -f

SRC = main.c image.c fractal.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -lm

clean:
	rm -f $(TARGET) $(OBJ) $(RESULT)

depend: $(SRC)
	makedepend $(SRC)