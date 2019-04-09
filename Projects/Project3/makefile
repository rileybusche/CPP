all: runall

runall: main.o split.o
	g++ main.o split.o -o exe

main.o: main.cpp customer.hpp purchase.hpp
	g++ -c -std=c++11 main.cpp

split.o: split.cpp
	g++ -c -std=c++11 split.cpp

clean: 
	rm *.o exe