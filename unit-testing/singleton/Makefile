CXX := g++
CXXFLAGS := -std=c++11 -Wall
LDFLAGS := -pthread
INCLUDES := -I../googlemock/include -I../googletest/include
CXXFLAGS += $(INCLUDES)

CPP_SRC := MySingleton.cpp main.cpp DependsOnSingleton.cpp
OBJS := $(patsubst %.cpp,%.o,$(CPP_SRC))

TEST_SRC := DependsOnSingleton.cpp MockMySingleton.cpp TestDependsOnSingleton.cpp ../googlemock/make/gmock_main.a
TEST_OBJS := $(patsubst %.cpp,%.o,$(TEST_SRC))

.PHONY: all clean

all: main

main: $(OBJS)
	g++ $(LDFLAGS) -o $@ $^

test: $(TEST_OBJS)
	g++ $(LDFLAGS) -o $@ $^

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf main $(OBJS)
