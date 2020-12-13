# Lab2 AK-2
## Screenshots:
#### make:
![Alt text](/lab2/screenshots/make.png?raw=true)
#### cmake:
![Alt text](/lab2/screenshots/cmake.png?raw=true)
## Listing of files:

* Makefile:
``` makefile
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
```

* CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 2.8)

project(hello_world)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB foo.cpp)

add_library(foo STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main foo)
```
* foo.cpp
```c++
#include <iostream>
void hello_world()
{
	std::cout << "Hello, World!" << std::endl;
} 

```
* foo.h
```c++
void hello_world(); 

```
* main.cpp
```c++
#include "foo.h"
int main(int argc, char** argv)
{
	hello_world();
	return 0;
} 

```
