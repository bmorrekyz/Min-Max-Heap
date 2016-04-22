driver.out: MMHeap.o Driver.o
	g++ -ansi -Wall MMHeap.o Driver.o -o driver.out

driver.o: Driver.cpp MMHeap.cpp
	g++ -ansi -Wall -c Driver.cpp MMHeap.cpp


clean:
	rm -f *.o *.out *~ *.gch

run:
	./driver.out