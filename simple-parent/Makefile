SRCS := main.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

run : simple-parent
	./simple-parent

simple-parent : $(OBJS)
	g++ -o $@ $<

%.o : %.cpp
	g++ -c -g3 -std=c++11 -Wall -o $@ $<
