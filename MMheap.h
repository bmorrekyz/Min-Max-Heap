/*****************************************
** File:    MMheap.h
** Project: CMSC 341 Project 4, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/22/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This file contains the interface of the MMheap class.
***********************************************/

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <vector>
#include <math.h> 

using namespace std;

template <typename Comparable>
class MMheap
{
public:

	/*	Description:    MMheap
		Pre-condition:  none
		Post-condition:	constructs a default MMheap object
	*/
	MMheap();

	/*	Description:    MMheap( const vector<Comparable> &v )
		Pre-condition:  vector containing the initial items
		Post-condition:	constructs 
	*/	
	// MMheap( const vector<Comparable> &v );

	/*	Description:    ~MMheap
		Pre-condition:  none
		Post-condition:	destroys the MMheap object
	*/
	~MMheap();

	/*	Description:    size()
		Pre-condition:  none
		Post-condition:	returns current heap size
	*/	
	int size(); 

	/*	Description:    dump()
		Pre-condition:  none
		Post-condition:	displays heap data (size, min, max, last level, items)
	*/
	void dump();

	/*	Description:    insert(const Comparable &x)
		Pre-condition:  a valid data element
		Post-condition:	an element is inserted into the heap
	*/
	void insert(const Comparable &x);

	/*	Description:    getMin()
		Pre-condition:  none
		Post-condition:	returns the min item in the heap
	*/
	Comparable getMin();

	/*	Description:    getMax()
		Pre-condition:  none
		Post-condition:	returns the max item in the heap
	*/
	Comparable getMax();

	/*	Description:    deleteMin()
		Pre-condition:  none
		Post-condition:	returns the deleted min item in a heap
	*/
	Comparable deleteMin();

	/*	Description:    deleteMax()
		Pre-condition:  none
		Post-condition:	returns the max item from a heap
	*/	
	Comparable deleteMax();

	

private:

	/* DATA MEMBERS */

	int m_size;

	vector<Comparable> m_heap;

	void buildHeap();

	void percolateDown( int hole );
	
	void percolateUp( int hole ); 

	void percolateUpMin(int hole);

	void percolateUpMax(int hole);

	int getLevel(int hole);

	bool isMinLevel(int hole);

	bool isMaxLevel(int hole);

	int getParent(int hole);

	bool hasParent(int hole);

	void swap(int hole, int parent);
	
};

#include "MMheap.cpp"

#endif

