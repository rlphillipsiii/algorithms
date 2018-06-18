CC=g++

TARGET=dsa

FLAGS=-std=c++11 -Wall

INCLUDES=-Ilibrary -Ilibrary/exceptions
	
SOURCES=main.cpp
	
templates:
	$(CC) $(FLAGS) $(INCLUDES) -o $(TARGET) $(SOURCES) $(LD_PATH)
	
all: templates