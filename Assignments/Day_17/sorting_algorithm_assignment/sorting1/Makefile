# Makefile for Sorting Program
CC = gcc
CFLAGS = -Wall -g -Iinclude
SRC = src/main.c src/function.c
OBJ = src/main.o src/function.o
TARGET = sort_program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

src/main.o: src/main.c include/header.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/function.o: src/function.c include/header.h
	$(CC) $(CFLAGS) -c src/function.c -o src/function.o

clean:
	rm -f src/*.o $(TARGET)

