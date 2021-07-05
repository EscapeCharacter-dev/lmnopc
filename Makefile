# Makefile for the LMNOP compiler
CC=tcc # Tiny C Compiler
LD=tcc # Linker
TARGET=bin/lmnc	# target (NOT .exe)

CFLAGS=-g -c -O2 -I./include

SRCS=$(wildcard src/*.c)
OBJS=$(patsubst src/%.c, obj/%.o, $(SRCS))



obj/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@
	mv *.o obj/
	
all: $(OBJS)
	$(LD) $^ -o $(TARGET)

clean:
	rm -f *.o *.out *.exe main bin/*
