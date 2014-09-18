CC = clang
CFLAGS = -g -O2 -Wall

CXX = clang++
CXXFLAGS = -g -O2 -Wall -stdlib=libc++ -std=c++11
CXXLDFLAGS = -lc++ -lc++abi

src = $(wildcard *.cc)
obj = $(src:.cc=.o)

all: matrix

matrix: $(obj)
	$(CXX) -o $@ $^ $(CXXLDFLAGS)

.cc.o:
	$(CXX) -o $@ $(CXXFLAGS) -c $<

clean:
	$(RM) -rf *.o *~ *.c.gcov *.gcda *.gcno

indent:
	indent -kr -l120 -br -ce -npsl -nut -i4 *.[hcc]
	rm -rf *~

