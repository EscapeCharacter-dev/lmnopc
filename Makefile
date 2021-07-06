# Makefile for the LMNOP compiler
#CC=tcc # Tiny C Compiler
#LD=tcc # Linker
TARGET=bin/lmnc	# target (NOT .exe)

CFLAGS=-g -O3

bin/lmnc:
	$(CC) $(CFLAGS) src/main.c -o bin/lmnc

clean:
	rm -f bin/*
