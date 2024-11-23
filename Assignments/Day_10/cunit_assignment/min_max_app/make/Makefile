CC = gcc
CFLAGS = -I../include -Wall -g
SRCS = ../src/min_max.c ../test/minmax_test.c
OBJS = ../obj/min_max.o ../obj/minmax_test.o
TARGET = ../bin/minmax_test

all: $(TARGET)

../obj/%.o: ../src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

../obj/%.o: ../test/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm -f ../obj/*.o ../bin/minmax_test

