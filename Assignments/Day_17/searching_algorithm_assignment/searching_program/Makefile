# Makefile for the binary search project

CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = binary_search
INCLUDE = include
SRC = src

OBJS = $(SRC)/main.o $(SRC)/function.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(SRC)/main.o: $(SRC)/main.c $(INCLUDE)/header.h
	$(CC) $(CFLAGS) -c $(SRC)/main.c -I $(INCLUDE) -o $(SRC)/main.o

$(SRC)/function.o: $(SRC)/function.c $(INCLUDE)/header.h
	$(CC) $(CFLAGS) -c $(SRC)/function.c -I $(INCLUDE) -o $(SRC)/function.o

clean:
	rm -f $(SRC)/*.o $(TARGET)

