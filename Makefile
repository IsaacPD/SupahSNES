CC=gcc
CCFLAGS=-std=c++11

test: test.o
	$(CC) -o "$@" "$<" $(CCFLAGS)

test.o: test.cc
	$(CC) -c -o "$@" "$<" $(CCFLAGS)

clean:
	rm *.o *.exe