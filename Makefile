driver.out: MMHeap.o driver.o
	g++ -ansi -Wall MMHeap.o driver.o -o driver.out

driver.o: driver.cpp MMHeap.cpp
	g++ -ansi -Wall -c driver.cpp MMHeap.cpp


clean:
	rm -f *.o *.out *~ *.gch

run:
	./driver.out