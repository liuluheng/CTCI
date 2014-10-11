CC = clang
CFLAGS = -g -O2 -Wall
LDFLAG =

all: insertion-sort \
	 mergesort \
	 mergesort2 \
	 heapsort \
	 prioque \
	 quicksort \
	 clean

insertion-sort: insertion-sort.o
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
	$(CC) $(LDFLAG) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o
