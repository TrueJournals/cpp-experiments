SRCS := main.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
CXXFLAGS = -std=c++11 -Wall

run: tuple-ignore
	./tuple-ignore

tuple-ignore: $(OBJS)
	$(CXX) -pthread -o $@ $<

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	rm -rf tuple-ignore $(OBJS)
