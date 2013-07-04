# Makefile for unit tests

CC=g++
OUTFILE="tests"

CFLAGS= -Wall -o $(OUTFILE)

all:
	$(CC) $(CFLAGS) *.c

debug:
	$(CC) $(CFLAGS) -g *.c

clean:
	rm $(OUTFILE)