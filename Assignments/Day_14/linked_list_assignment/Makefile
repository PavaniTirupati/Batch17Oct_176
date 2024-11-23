# Compiler and flags
CC = gcc
CFLAGS = -c -Wall -g
INCLUDEPATH = ./include
SRCPATH = ./src
OBJPATH = ./obj
BINPATH = ./bin

# Target to create the executable
$(BINPATH)/exe: $(OBJPATH)/main.o $(OBJPATH)/functions.o
	$(CC) -Wall -g -o $(BINPATH)/exe $(OBJPATH)/main.o $(OBJPATH)/functions.o

# Rule to compile main.o
$(OBJPATH)/main.o: $(SRCPATH)/main.c $(INCLUDEPATH)/header.h
	$(CC) $(CFLAGS) $(SRCPATH)/main.c -I $(INCLUDEPATH)/
	mv main.o $(OBJPATH)/

# Rule to compile functions.o
$(OBJPATH)/functions.o: $(SRCPATH)/functions.c $(INCLUDEPATH)/header.h
	$(CC) $(CFLAGS) $(SRCPATH)/functions.c -I $(INCLUDEPATH)/
	mv functions.o $(OBJPATH)/

# Clean up the build
clear:
	rm -f $(BINPATH)/exe $(OBJPATH)/main.o $(OBJPATH)/functions.o

