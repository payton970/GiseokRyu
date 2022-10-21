all: p2

program2: program2.o CustomHeap.o
	g++ program2.o CustomHeap.o -o program2 -g

program2.o: program2.cpp
	g++ -c program2.cpp

CustomHeap.o : CustomHeap.h CustomHeap.cpp
	g++ -c CustomHeap.cpp

run : program2
	./program2 -m market_price.txt -p price_list.txt

clean:
	rm * -o program2