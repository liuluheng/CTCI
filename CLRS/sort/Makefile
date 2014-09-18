CC = clang
CFLAGS = -g -O2 -Wall
LDFLAG =

all: insertion-sort \
	 mergesort \
	 merge-sort \
	 heapsort \
	 prioque \
	 quicksort \
	 clean

insertion-sort: insertion-sort.o
	$(CC) $(LDFLAG) -o $@ $^

mergesort: mergesort.o
	$(CC) $(LDFLAG) -o $@ $^

merge-sort: merge-sort.o
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
