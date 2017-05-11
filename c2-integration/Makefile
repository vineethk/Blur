compile: bin bin/image.o bin/filter.o bin/main.o
	gcc bin/image.o bin/filter.o bin/main.o -lm -oblur

bin: 
	mkdir bin/

bin/image.o: image.c
	gcc -o bin/image.o -c image.c

bin/filter.o: filter.c
	gcc -o bin/filter.o -c filter.c -std=c99

bin/main.o: main.c
	gcc -o bin/main.o -c main.c

clean_compile: compile
	rm -rf bin
exec: compile
	./blur

