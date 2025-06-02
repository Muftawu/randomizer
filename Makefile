CC = gcc
CFLAGS = -Wall -Wextra -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lraylib -lm
SRCS = main.c
TARGET = program

all: build run

run:
	./$(TARGET)

build: main.c 
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

clean:
	rm -rf $(TARGET) 

