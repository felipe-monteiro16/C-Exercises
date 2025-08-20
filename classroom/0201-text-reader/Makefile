CC = gcc
CFLAGS = -Wall -O2
SRC = src/main.c
TARGET = text_app

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
