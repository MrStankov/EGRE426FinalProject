CC = g++

CFLAGS=-O3 -std=c++0x 

MAIN = pipelining

all: main

main:
	$(CC) $(CFLAGS) main.cpp global.cpp parser.cpp arithmatic.cpp data-transfer.cpp instruction-fetch.cpp instruction-decode.cpp execution.cpp memory-access.cpp write-back.cpp

clean: 
	$(RM) count *.o *~
