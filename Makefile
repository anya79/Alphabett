CC=gcc
flags=-O3

all: createfolders build/main

build/main: bin/main.o
	$(CC) $(flags) -o build/main bin/main.o

bin/main.o: src/main.c
	$(CC) $(flags) -c -o bin/main.o src/main.c

createfolders: bin/ build/

bin/: 
	mkdir bin/

build/:
	mkdir build/

clean:
	rm -rf bin/
	rm -rf build/
