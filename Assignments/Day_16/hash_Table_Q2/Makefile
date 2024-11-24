# Makefile for hash table program

CC = gcc
CFLAGS = -Wall -g -Iinclude
OBJFILES = src/main.o src/functions.o
TARGET = hashtable

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

src/main.o: src/main.c include/header.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/functions.o: src/functions.c include/header.h
	$(CC) $(CFLAGS) -c src/functions.c -o src/functions.o

clean:
	rm -f $(OBJFILES) $(TARGET)

