all: ArraySpeedSort.o
	g++ -g -Wall -Werror -std=c++14 ArraySpeedSort.o -o ArraySpeedSort

ArraySpeedSort.o: ArraySpeedSort.cpp
	g++ -c -g -Wall -Werror -std=c++14 ArraySpeedSort.cpp -o ArraySpeedSort.o

.PHONY: clean all

clean:
	rm -rf ArraySpeedSort *.o

run: all
	./ArraySpeedSort