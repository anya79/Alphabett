CC=gcc
flags=-O0

all: createfolders build/main

build/main: bin/main.o
	$(CC) $(flags) -o build/main bin/main.o bin/reader.o

bin/main.o: src/main.c bin/reader.o
	$(CC) $(flags) -c -o bin/main.o src/main.c

bin/reader.o: src/reader.c src/reader.h
	$(CC) $(flags) -c -o bin/reader.o src/reader.c

createfolders: bin/ build/

bin/: 
	mkdir bin/

build/:
	mkdir build/

clean:
	rm -rf bin/
	rm -rf build/
