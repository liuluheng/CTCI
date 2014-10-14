CC = clang
CXX = clang++
CFLAGS = -g -O2 -Wall
CXXFLAGS = -g -O2 -Wall -stdlib=libc++ -std=c++11
LDFLAG = -lc++ -lc++abi

all: insertionsort \
	 mergesort \
	 mergesort2 \
	 heapsort \
	 prioque \
	 quicksort \
	 clean

insertionsort: insertionsort.o
	$(CC) $(LDFLAG) -o $@ $^

mergesort: mergesort.o
	$(CC) $(LDFLAG) -o $@ $^

mergesort2: mergesort2.o
	$(CC) $(LDFLAG) -o $@ $^

heapsort: heapsort.o
	$(CC) $(LDFLAG) -o $@ $^

prioque: prioque.o
	$(CC) $(LDFLAG) -o $@ $^

quicksort: quicksort.o
	$(CXX) $(LDFLAG) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.cc.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f *.o
