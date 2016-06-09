CC=g++
CFLAGS=-std=c++11 -Wall -g -c
LDFLAGS=
SOURCES=$(shell find . -name '*.cpp')
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=foffc

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(shell find . -name '*.o') $(EXECUTABLE)
