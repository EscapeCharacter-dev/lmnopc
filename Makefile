# Makefile for the LLMNOP compiler
CC=tcc # Tiny C Compiler
LD=tcc # Linker
TARGET=bin/llmc.exe

CFLAGS=-g -c -O2 -I./inc

SRCS=$(wildcard src/*.c)
OBJS=$(patsubst src/%.c, obj/%.o, $(SRCS))

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@
	
all: $(OBJS)
	$(LD) $^ -o $(TARGET)