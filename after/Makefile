SRCS := main.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

run: after
	./after

after: $(OBJS)
	g++ -pthread -o $@ $<

%.o : %.cpp
	$(CXX) -g3 -c -std=c++11 -Wall -o $@ $<

clean:
	rm -rf cpp-after $(OBJS)
