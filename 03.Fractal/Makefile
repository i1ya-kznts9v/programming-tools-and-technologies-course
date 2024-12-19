CC = gcc
CFLAGS = -Wall -g

TARGET = fractal
RESULT = ./*.pgm
RM = rm -f

SRC = main.c image.c fractal.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ) $(RESULT)

depend: $(SRC)
	makedepend $(SRC)