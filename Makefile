driver.out: MMheap.o Driver.o
	g++ -ansi -Wall MMheap.o Driver.o -o Driver.out

driver.o: Driver.cpp MMheap.cpp
	g++ -ansi -Wall -c Driver.cpp MMheap.cpp

clean:
	rm -f *.o *.out *~ *.gch

run:
	./Driver.out $(INPUT)