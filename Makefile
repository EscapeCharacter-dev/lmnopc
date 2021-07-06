# Makefile for the LMNOP compiler
#CC=tcc # Tiny C Compiler
#LD=tcc # Linker
TARGET=bin/lmnc	# target (NOT .exe)

CFLAGS=-g -O3

ifeq ($(OS),Windows_NT)
	CFLAGS+=-luser32
endif

bin/lmnc:
	$(CC) $(CFLAGS) src/main.c src/lex.c src/failsafe.c -o bin/lmnc

clean:
	rm -f bin/*
