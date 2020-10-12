all: main

main: main.o libfoo.so
	g++ -Wall -L . -Wl,-rpath=. main.o -o main -lfoo

main.o: main.cpp
	g++ -c main.cpp

foo.o: foo.cpp
	g++ -c -fPIC foo.cpp

libfoo.so: foo.o
	gcc -shared -fPIC -o libfoo.so foo.o

clean:
	rm -rf *.o
