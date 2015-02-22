SRCS := main.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

run: shared_ptr
	./shared_ptr

shared_ptr: $(OBJS)
	g++ -o $@ $<

%.o : %.cpp
	$(CXX) -g3 -c -std=c++11 -Wall -o $@ $<

clean:
	rm -rf shared_ptr $(OBJS)
