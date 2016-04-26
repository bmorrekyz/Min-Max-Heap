/*****************************************
** File:    MMheap.h
** Project: CMSC 341 Project 4, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/22/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This file contains the interface of the MMheap class.
** MMheap has a structure property where even levels represent a min heap.
** Whereas, odd levels represent a max heap. 
***********************************************/

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <vector>
#include <math.h> 
#include <cstdlib>

#include "MyException.h"

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

	/*	Description:    insert(const Comparable &x)
		Pre-condition:  a valid data element
		Post-condition:	an element is inserted into the heap
	*/
	void insert(const Comparable &x);

	/*	Description:    dump()
		Pre-condition:  none
		Post-condition:	displays heap data (size, min, max, last level, items)
	*/
	void dump();

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


	/* --- PERCOLATION methods used in insert() --- */ 
	
	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	void percolateUp( int hole ); 

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	void percolateUpMin(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	void percolateUpMax(int hole);


	/* --- TRICKLE DOWN methods used in deleteMin(), deleteMax() --- */

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	void trickleDown(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	void trickleDownMin(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	void trickleDownMax(int hole);


	/* --- HELPER functions --- */

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	void swap(int hole, int parent);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	bool isSmaller(int hole1, int hole2);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	int getLevel(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	bool isMinLevel(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	bool isMaxLevel(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	bool hasParent(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	int getParent(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	bool hasLeftChild(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	bool hasRightChild(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	bool hasOneLeftGrandChild(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	bool hasTwoLeftGrandChildren(int hole);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	bool hasOneRightGrandChild(int hole); 

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	bool hasTwoRightGrandChildren(int hole);
};

#include "MMheap.cpp"

#endif