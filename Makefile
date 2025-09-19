all: test
test: geometry.o test.o
	g++ -o test geometry.o test.o
geometry.o: geometry.cpp geometry.h
	g++ -c geometry.cpp
test.o: test.cpp geometry.h
	g++ -c test.cpp
clean:
	rm -f *.o test
