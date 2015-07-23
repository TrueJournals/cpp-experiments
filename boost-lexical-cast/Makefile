SRCS := main.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
CXXFLAGS = -std=c++11 -Wall

run: boost-lexical-cast
	./boost-lexical-cast

boost-lexical-cast: $(OBJS)
	$(CXX) -pthread -o $@ $<

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	rm -rf boost-lexical-cast $(OBJS)
