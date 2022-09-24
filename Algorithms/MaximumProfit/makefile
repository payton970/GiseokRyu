all: p1

program1: program1.o
		g++ program1.o -o program1

program1.o: program1.cpp
		g++ -c program1.cpp

run : program1
		./program1 -m market_price.txt -p price_list.txt

clean:
	rm * -o program1