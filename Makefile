driver.out: MMheap.o Driver.o
	g++ -ansi -Wall MMheap.o Driver.o -o driver.out

driver.o: Driver.cpp MMheap.cpp
	g++ -ansi -Wall -c Driver.cpp MMheap.cpp

clean:
	rm -f *.o *.out *~ *.gch

run:
	./driver.out $(INPUT)