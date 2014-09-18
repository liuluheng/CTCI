CC = clang
CXX = clang++
CFLAGS = -g -O2 -Wall
CXXFLAGS = -g -O2 -Wall -stdlib=libc++ -std=c++11
CXXLDFLAGS = -lc++ -lc++abi

lcs: lcs.o
	$(CC) -o $@ $^

liss: liss.o
	$(CC) -o $@ $^

bst: bst.o
	$(CXX) -o $@ $^

cutrod: cutrod.o
	$(CXX) -o $@ $^ $(CXXLDFLAGS)

clean:
	$(RM) -rf *.o *~ *.c.gcov *.gcda *.gcno

indent:
	indent -kr -l120 -br -ce -npsl -nut -i4 *.[hc]
	rm -rf *~

