CC=gcc
flags=-O0

all: createfolders build/main

build/main: bin/main.o bin/reader.o bin/parser.o
	$(CC) $(flags) -o build/main bin/main.o bin/reader.o  bin/parser.o

bin/main.o: src/main.c 
	$(CC) $(flags) -c -o bin/main.o src/main.c

bin/reader.o: src/reader.c src/reader.h
	$(CC) $(flags) -c -o bin/reader.o src/reader.c

bin/parser.o: src/parser.c src/parser.h
	$(CC) $(flags) -c -o bin/parser.o src/parser.c

createfolders: bin/ build/

bin/: 
	mkdir bin/

build/:
	mkdir build/

clean:
	rm -rf bin/
	rm -rf build/
