# Makefile for unit tests

CC=gcc
OUTFILE="tests"

CFLAGS= -Wall -o $(OUTFILE)

all:
	$(CC) $(CFLAGS) *.c

debug:
	$(CC) $(CFLAGS) -g *.c

clean:
	rm $(OUTFILE)