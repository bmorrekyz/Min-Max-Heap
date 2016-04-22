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

	/*	Description:    insert()
		Pre-condition:  a valid data element
		Post-condition:	an element is inserted into the heap
	*/
	void insert(Comparable x);

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

	/* Node class for a MinMaxHeap */
	class MMNode
	{
		Comparable data;
		MMNode *leftChild;
		MMNode *rightChild;
		MMNode *parent;
		int index, leftChildIndex, rightChildIndex;
		int level;
		int parentLevel;

		/* default constructor */
		MMNode() 
		{	
			data = NULL;
			leftChild = NULL;
			rightChild = NULL;
			parent = NULL;
			index = 0;
			leftChildIndex = NULL;
			rightChildIndex = NULL;
			level = 0;
			parentLevel = NULL;
		}

	};

	/* DATA MEMBERS */

	MMNode *dummyNode;

	int m_size;

	vector<MMNode*> m_heap;

};

#include "MMheap.cpp"

#endif

