CC=g++
OPTIONS=-std=c++11 -g
LINK_OPTIONS=-ltbb
all: mergesort.o main.o
	$(CC) $(OPTIONS) main.o mergesort.o -o mergesort $(LINK_OPTIONS)
main.o: 
	g++ $(OPTIONS) -c main.cpp -o main.o
mergesort.o:
	g++ $(OPTIONS) -c mergesort.cpp -o mergesort.o
clean:
	rm -f *o mergesort
