SRCS := main.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

run : simple-parent
	./simple-parent

simple-parent : $(OBJS)
	$(CXX) -o $@ $<

%.o : %.cpp
	$(CXX) -c -g3 -std=c++11 -Wall -o $@ $<
