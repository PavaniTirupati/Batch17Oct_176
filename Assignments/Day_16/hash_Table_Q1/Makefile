# Makefile for Hash Table Program

CC = gcc
CFLAGS = -Wall -g -Iinclude
SRC = src/main.c src/functions.c
OBJ = $(SRC:.c=.o)
TARGET = hashtable

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

