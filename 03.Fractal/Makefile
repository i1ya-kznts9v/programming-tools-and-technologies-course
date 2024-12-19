CC = gcc
CFLAGS = -Wall -g
RM = rm -f

RESULT = ./*.pgm

TARGET = fractal
SRC = main.c image.c fractal.c
OBJ = $(SRC:.c=.o)

TEST_TARGET = test_fractal
TEST_SRC = test_main.c image.c fractal.c
TEST_OBJ = $(TEST_SRC:.c=.o)

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) -lm

$(TEST_TARGET): $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -o $(TEST_TARGET) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -lm

clean:
	$(RM) $(TARGET) $(OBJ) $(TEST_TARGET) $(TEST_OBJ) $(RESULT)

depend: $(SRC)
	makedepend $(SRC)