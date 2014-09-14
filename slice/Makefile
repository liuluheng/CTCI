CXX	= g++
CXXFLAGS = -Wall -O2 -g -std=c++11

SRC = $(wildcard *.cc)
BIN = $(SRC:.cc=)

all: $(BIN)

.cc.o:
	$(CXX) -o $@ $(CXXFLAGS) $<

clean:
	rm -f $(BIN)


#CC = g++
#CPPFLAGS = -Wall
#FILE_SUFFIX = cc
#SRCS := $(wildcard *.$(FILE_SUFFIX))
#EXES := $(patsubst %.$(FILE_SUFFIX),%,$(SRCS))
#
#all: $(EXES)
#	$(EXES): % : %.$(FILE_SUFFIX)
#	$(CC) $(CPPFLAGS) $< -o $@
#
#clean:
#	rm -rf $(EXES)

astype:
	#astyle -s2 -xG -S -O -o -k3 -H -p --style=google *.cpp
	astyle --style=google -s2 *.cc
	rm -f *.orig

