CXX := g++
CXXFLAGS := -std=c++11 -Wall
LDFLAGS := 

CPP_SRC := MySingleton.cpp main.cpp DependsOnSingleton.cpp
OBJS := $(patsubst %.cpp,%.o,$(CPP_SRC))

.PHONY: all clean test

all: main

main: $(OBJS)
	g++ $(LDFLAGS) -o $@ $^

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf main $(OBJS)
