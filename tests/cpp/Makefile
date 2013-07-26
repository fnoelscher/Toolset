# Makefile for unit tests / c++

CC=g++
INCLUDES= -I ../../basics/ -I ../../algos/
CFLAGS= -Wall $(INCLUDES) --std=c++0x

all: cstyleMatrixTest fileops

# change this
debug:
	$(CC) $(CFLAGS) -g *.cpp

clean:
	rm *.bin


cstyleMatrixTest:
	$(CC) $(CFLAGS) -o matrix_cstyle.bin matrix_cstyle.cpp


matrixTest:
	$(CC) $(CFLAGS) -o matrix.bin matrix.cpp

fileops:
	$(CC) $(CFLAGS) -o fileops.bin fileops.cpp

