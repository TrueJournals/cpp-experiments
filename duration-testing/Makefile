SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

.PHONY : run

run : main
	./main

main : $(OBJS)
	g++ -o $@ $<

%.o : %.cpp
	g++ -c -std=c++11 -o $@ $<
