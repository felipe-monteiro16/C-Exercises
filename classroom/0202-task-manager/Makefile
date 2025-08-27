CC = gcc
CFLAGS = -Wall -O2 -Wno-unused-result
SRC = src/main.c
TARGET = program

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
