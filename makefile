CC=g++
TARGET=dsa

MKDIR=mkdir -p

FLAGS=-std=c++11 -Wall -g -L.

INCLUDES=-Ilibrary \
			-Ilibrary/exceptions \
			-Itests \
			-Ilibrary/types \
			-Ilibrary/containers
			
LIBS=-ldsatypes

OBJECTS=tests/obj/dsa_test.o

DEPENDENCIES=dsa_test.o

SOURCES=main.cpp
	
TSOURCES=library/types/strings.cpp

%.o: tests/%.cpp
	$(MKDIR) tests/obj
	$(CC) $(FLAGS) $(INCLUDES) -c -o tests/obj/$@ $^
	
tests: $(DEPENDENCIES)
	$(CC) $(FLAGS) $(INCLUDES) -o $(TARGET) $(SOURCES) $(OBJECTS) $(LIBS)
	
types:
	$(CC) $(FLAGS) -shared $(INCLUDES) -o dsatypes.dll $(TSOURCES)
	
all: types tests