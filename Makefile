driver.out: MinHeap.h driver.o
	g++ -ansi -Wall MinHeap.h driver.o -o driver.out

driver.o: driver.cpp
	g++ -ansi -Wall -c driver.cpp


clean:
	rm -f *.o *.out *~ *.gch

run:
	./driver.out