SRCS := main.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

run : safe-integer
	./safe-integer

safe-integer : $(OBJS)
	$(CXX) -o $@ $<

%.o : %.cpp
	$(CXX) -c -g3 -std=c++11 -Wall -o $@ $<
