CC=gcc
flags=-O0 -std=c11

all: createfolders build/main build/test runTests

build/main: bin/main.o bin/reader.o bin/parser.o bin/sort.o
	$(CC) $(flags) -o build/main bin/main.o bin/reader.o bin/parser.o bin/sort.o

bin/main.o: src/main.c 
	$(CC) $(flags) -c -o bin/main.o src/main.c

bin/reader.o: src/reader.c src/reader.h
	$(CC) $(flags) -c -o bin/reader.o src/reader.c

bin/parser.o: src/parser.c src/parser.h
	$(CC) $(flags) -c -o bin/parser.o src/parser.c

bin/sort.o: src/sort.h src/sort.c
	$(CC) $(flags) -c -o bin/sort.o src/sort.c

build/test: bin/test.o bin/sort.o bin/parser.o bin/reader.o
	gcc $(flags) -o build/test bin/test.o bin/sort.o bin/parser.o bin/reader.o

bin/test.o: test/test.c
	gcc $(flags) -o bin/test.o -c test/test.c -Ithirdparty -Isrc

createfolders: bin/ build/

runTests:
	./build/test

bin/: 
	mkdir bin/

build/:
	mkdir build/

clean:
	rm -rf bin/
	rm -rf build/
